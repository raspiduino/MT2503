
#include "spi.h"
#include "spi_internal.h"
#include "spi_define.h"
//#error  SPI_TEST IS COMPLING

#if defined(__MAUI_BASIC__)

#define TOTAL_TEST_AREA_LENGTH   (64 * 1024)
#define SPI_TEST_PATTERN          0x12345678         //0x12345678
#define SPI_TEST_PATTERN_INVERSE  0x78563412   //0x78563412


/****************************TEST_CASE**************************************************/
/****************************TEST_CASE**************************************************/
/****************************TEST_CASE**************************************************/
/****************************TEST_CASE**************************************************/
/****************************TEST_CASE**************************************************/
#pragma arm section rwdata = "NONCACHEDRW", zidata = "NONCACHEDZI"
__align(4) kal_uint8 spi_src_buffer[TOTAL_TEST_AREA_LENGTH];
__align(4) kal_uint8 spi_dest_buffer[TOTAL_TEST_AREA_LENGTH];

#define ESCKEY (0x1b)

kal_int32 spi_id = 0; // select the spi pad 

kal_uint32 spi_test_intr_en_finish = 0;
kal_uint32 spi_test_intr_en_pause = 0;
kal_uint32 spi_test_intr_flag = 0;

kal_bool spi_test_enable_deassert_mode = KAL_FALSE;

typedef enum {
      uart_port1=0,
      uart_port2,
      uart_port3,
      uart_max_port,      
      uart_port_null = 99    /* a uart port for those who uses physical port */
} UART_PORT;


void spi_test_input(kal_uint16 *value,UART_PORT port)
{
	kal_uint32 result = 0;
		kal_uint8 str[30], input, offset;
	
		offset = 0;
	
		while (1)
		{
			input = U_GetUARTByte(port);
	
			if (input == 0x0d || input == 0x0a)
				break;
	
			if (input == ESCKEY)
				return;
	
			str[offset++] = input;
			dbg_print("%c", input);
		}
	
		str[offset] = 0;
	
		dbg_print("\r\n");
		sscanf(str, "%d", value);

}


void spi_test_init_data(SPI_MODE const tx_dma)
{
    int i;
    for (i = 0; i < 32; ++i)
    {
        SPI_TX_FIFO_REG = SPI_TEST_PATTERN;
    }
    memset(spi_dest_buffer, 0, TOTAL_TEST_AREA_LENGTH);
}

kal_bool spi_test_directly_internal(
                           kal_uint32 const length,
                           kal_uint32 const loop,
                           SPI_MLSB const tx_msb,
                           SPI_MLSB const rx_msb,
                           SPI_MODE const tx_dma,
                           SPI_MODE const rx_dma,
                           kal_bool const enable_pause_mode,
                           kal_int32 const times,
                           SPI_CPHA const fmt,
                           kal_bool const tx_endian_reverse,
                           kal_bool const rx_endian_reverse)
{
    spi_attr_t attr;

    //if (times == 0)
    //    spi_reset(spi_id);

    spi_clear_fifo(spi_id, SPI_TX);
    spi_clear_fifo(spi_id, SPI_RX);
    spi_test_init_data(tx_dma);

    /* bigger value means looser clock time. */
    attr.setup_time = 0;
    attr.hold_time =0;
    attr.clk_low = 0;
    attr.clk_high = 0;
    attr.idle_time = 0;

    attr.enable_pause_int = KAL_FALSE;
    attr.enable_finish_int = KAL_FALSE;

    if (-1 == times)
    {
        attr.enable_pause_mode = KAL_FALSE;
    }
    else
    {
        attr.enable_pause_mode = enable_pause_mode;
    }

    attr.enable_deassert_mode = spi_test_enable_deassert_mode;
    attr.tx_mlsb = tx_msb;
    attr.rx_mlsb = rx_msb;
    attr.tx_mode = tx_dma;
    attr.rx_mode = rx_dma;
    attr.clk_polarity = SPI_CPOL_0;  //modify to CPHA=1,CPOL=1
    attr.clk_fmt = fmt;

    spi_config(spi_id, &attr);

    spi_set_endian_reverse(spi_id, SPI_TX, tx_endian_reverse);
    spi_set_endian_reverse(spi_id, SPI_RX, rx_endian_reverse);

    spi_set_desired_size(spi_id, length, loop);

    if (SPI_MODE_DMA == tx_dma)
    {
        ASSERT(length <= 64 * 1024);
        spi_set_rwaddr(spi_id, SPI_TX, spi_src_buffer);
    }
    else
    {
        ASSERT(length <= 32);
    }

    if (SPI_MODE_DMA == rx_dma)
    {
        ASSERT(length <= 64 * 1024);
        spi_set_rwaddr(spi_id, SPI_RX, spi_dest_buffer);
    }
    else
    {
        ASSERT(length <= 32);
    }
    if (spi_test_intr_en_finish)
    {
        spi_set_interrupt(spi_id, SPI_INT_FINISH, SPI_ENABLE);
    }
    else
    {
        spi_set_interrupt(spi_id, SPI_INT_FINISH, SPI_DISABLE);
    }
    if (spi_test_intr_en_pause)
    {
        spi_set_interrupt(spi_id, SPI_INT_PAUSE, SPI_ENABLE);
    }
    else
    {
        spi_set_interrupt(spi_id, SPI_INT_PAUSE, SPI_DISABLE);
    }
    
    spi_test_intr_flag = 0;
    
    if ((KAL_TRUE == enable_pause_mode) && (times != 0)) // time =1 will enter
    {
        spi_resume(spi_id);
        /* Wait SPI controller finished. */
    }
    else
    {
        spi_activate(spi_id);
    }

    if (attr.enable_pause_mode)
    {
        if (spi_test_intr_en_pause)
        {
            while (spi_test_intr_flag == 0) ;
            spi_test_intr_flag = 0;
        }
        else
        {
            while (KAL_TRUE == spi_is_busy())
            	{
            	      dbg_print("SPI status  %d (0--busy,1--idle)\n\r", SPI_STATUS2_REG);
          			dbg_print(" I  am transfering data now, don't disturbe me ^^ \n\r");
            	}
            dbg_print(" pause polling mode: haha, I will have a rest , iam idle \n\r");
		}
    }
    else
    {
        if (spi_test_intr_en_finish)
        {
            while (spi_test_intr_flag == 0) ;
            spi_test_intr_flag = 0;
        }
        else
        {
            while (KAL_TRUE == spi_is_busy()) 
            	{
						  dbg_print("SPI status  %d (0--busy,1--idle)\n\r", SPI_STATUS2_REG);
						dbg_print(" I  am transfering data now, don't disturbe me ^^ \n\r");
					}
				dbg_print(" normal polling mode: haha, I will have a rest , iam idle \n\r");

		}
    }

    {
        int i;
        int const multiple = length / sizeof(kal_uint32);
        int const modulo = length % sizeof(kal_uint32);

        for (i = 0; i < loop; ++i)
        {
            kal_uint32 test_pattern_4_byte;
            kal_uint32 test_pattern_123_byte;

            if (SPI_MODE_DMA == rx_dma)
            {
                if (tx_msb == rx_msb)
                {
                    if (tx_endian_reverse == rx_endian_reverse)
                        test_pattern_4_byte = SPI_TEST_PATTERN;
                    else
                        test_pattern_4_byte = SPI_TEST_PATTERN_INVERSE;
                    test_pattern_123_byte = 0x345678;
                }
                else
                {
                    if (tx_endian_reverse == rx_endian_reverse)
                        test_pattern_4_byte = 0x482C6A1E;
                    else
                        test_pattern_4_byte = 0x1E6A2C48;
                    test_pattern_123_byte = 0x2C6A1E;
                }
            }
            else
            {
                if (tx_msb == rx_msb)
                {
                    test_pattern_4_byte = SPI_TEST_PATTERN;
                    test_pattern_123_byte = 0x345678;
                }
                else
                {
                    test_pattern_4_byte = 0x482C6A1E;
                    test_pattern_123_byte = 0x2C6A1E;
                }
            }

            {
                int j;
                for (j = 0; j < multiple; ++j)
                {
                    kal_uint8 *base_addr;
                    kal_uint32 value;

                    if (SPI_MODE_DMA == rx_dma)
                    {
                        base_addr = (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        value = *((kal_uint32 *)base_addr + j);
                    }
                    else
                    {
                        value = SPI_RX_FIFO_REG;
                    }

                    if (value != test_pattern_4_byte)
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }
                }
            }

            {
                kal_uint8 single_data;
                kal_uint32 fifo_data;

                if (SPI_MODE_FIFO == rx_dma)
                {
                    fifo_data = SPI_RX_FIFO_REG;
                }

                switch (modulo)
                {
                case 3:
                    if (SPI_MODE_DMA == rx_dma)
                    {
                        kal_uint8 * const base_addr =
                            (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        single_data = *((kal_uint8 *)((kal_uint32 *)base_addr + multiple) + 2);
                    }
                    else
                    {
                        single_data = ((fifo_data & 0xFF0000) >> 16);
                    }
                    if (single_data != ((test_pattern_123_byte & 0xFF0000) >> 16))
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }

                case 2:
                    if (SPI_MODE_DMA == rx_dma)
                    {
                        kal_uint8 * const base_addr =
                            (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        single_data = *((kal_uint8 *)((kal_uint32 *)base_addr + multiple) + 1);
                    }
                    else
                    {
                        single_data = ((fifo_data & 0xFF00) >> 8);
                    }
                    if (single_data != ((test_pattern_123_byte & 0xFF00) >> 8))
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }

                case 1:
                    if (SPI_MODE_DMA == rx_dma)
                    {
                        kal_uint8 * const base_addr =
                            (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        single_data = *((kal_uint8 *)((kal_uint32 *)base_addr + multiple) + 0);
                    }
                    else
                    {
                        single_data = (fifo_data & 0xFF);
                    }
                    if (single_data != (test_pattern_123_byte & 0xFF))
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }
                    break;

                case 0:
                    break;

                default:
                    ASSERT(0);
                    break;
                }
                return KAL_TRUE;
            }
        }
    }
}

kal_bool
spi_test_directly(SPI_CPHA cpha)
{
    int i;

    dbg_print("init spi\n\r");

   // * ===================================================== */
    dbg_print("MSB->MSB, DMA->DMA, CPHA 0\n\r");
    /* ===================================================== */
    for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
    {
        *((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
        /* clear dest buffer data. */
        *((kal_uint32 *)spi_dest_buffer + i) = 0;
    }


    //for (i = 1; i < 64; ++i)
    //{
     // dbg_print("length: %d bytes\n\r", i);
     // spi_test_directly_internal(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
  // }
      
       i=1;
       if(1==i)
       	{
     dbg_print("length: %d bytes\n\r", i);
     spi_test_directly_internal(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
       }

    dbg_print("length: 1024 bytes\n\r");
    spi_test_directly_internal(1024, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);

    dbg_print("length: 4096 bytes\n\r");
    spi_test_directly_internal(1024, 4, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);

    dbg_print("length: 64 * 1024 bytes\n\r");
    spi_test_directly_internal(1024, 64, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);

    /* ===================================================== */
    dbg_print("MSB->LSB, DMA->DMA, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 64; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_MSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }
    dbg_print("length: 1024 bytes\n\r");
    spi_test_directly_internal(1024, 1, SPI_MSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 4096 bytes\n\r");
    spi_test_directly_internal(1024, 4, SPI_MSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 64 * 1024 bytes\n\r");
    spi_test_directly_internal(1024, 64, SPI_MSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);

    /* ===================================================== */
    dbg_print("LSB->LSB, DMA->DMA, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 64; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    dbg_print("length: 1024 bytes\n\r");
    spi_test_directly_internal(1024, 1, SPI_LSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);

    dbg_print("length: 4096 bytes\n\r");
    spi_test_directly_internal(1024, 4, SPI_LSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 64 * 1024 bytes\n\r");
    spi_test_directly_internal(1024, 64, SPI_LSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);

    /* ===================================================== */
    dbg_print("LSB->MSB, DMA->DMA, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 64; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }
    dbg_print("length: 1024 bytes\n\r");
    spi_test_directly_internal(1024, 1, SPI_LSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 4096 bytes\n\r");
    spi_test_directly_internal(1024, 4, SPI_LSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 64 * 1024 bytes\n\r");
    spi_test_directly_internal(1024, 64, SPI_LSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);

    // RX FIFO
    /* ===================================================== */
    dbg_print("MSB->MSB, DMA->FIFO, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_FIFO, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("MSB->LSB, DMA->FIFO, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_MSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_FIFO, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("LSB->LSB, DMA->FIFO, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_FIFO, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("LSB->MSB, DMA->FIFO, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_FIFO, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    // TX FIFO
    /* ===================================================== */
    dbg_print("MSB->MSB, FIFO->DMA, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_FIFO, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("MSB->LSB, FIFO->DMA, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_MSB, SPI_LSB, SPI_MODE_FIFO, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("LSB->LSB, FIFO->DMA, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_LSB, SPI_MODE_FIFO, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("LSB->MSB, FIFO->DMA, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_MSB, SPI_MODE_FIFO, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }  

    // TX/RX FIFO
    /* ===================================================== */
    dbg_print("MSB->MSB, FIFO->FIFO, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_FIFO, SPI_MODE_FIFO, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("MSB->LSB, FIFO->FIFO, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_MSB, SPI_LSB, SPI_MODE_FIFO, SPI_MODE_FIFO, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("LSB->LSB, FIFO->FIFO, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_LSB, SPI_MODE_FIFO, SPI_MODE_FIFO, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("LSB->MSB, FIFO->FIFO, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_MSB, SPI_MODE_FIFO, SPI_MODE_FIFO, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
    }

    // Pause mode
    /* ===================================================== */
    dbg_print("CPHA 0, Pause mode\n\r");
    /* ===================================================== */

    dbg_print("length: 32 bytes\n\r");
    spi_test_directly_internal(32, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_TRUE, 0, cpha, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 4096 bytes\n\r");
    spi_test_directly_internal(1024, 4, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_TRUE, 1, cpha, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 32 bytes\n\r");
    spi_test_directly_internal(32, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_TRUE, -1, cpha, KAL_FALSE, KAL_FALSE);


    return KAL_TRUE;
}

kal_bool spi_test_combination1(void)
{
    kal_uint32 i;
    kal_uint32 size;
    for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
    {
        *((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
        /* clear dest buffer data. */
        *((kal_uint32 *)spi_dest_buffer + i) = 0;
    }

    spi_reset(spi_id);

    for (i=0; i<10000; i++)
    {
        dbg_print("%d\n\r", i);
        if (i&1)
            size = 0x100;
        else
            size = 0x4;


        if ((i&0x300)>>7 == 0)
		
           spi_set_get_tick_mode(spi_id, SPI_NO_GET_TICK_MODE);
        else if ((i&0x300)>>7 == 1)
           spi_set_get_tick_mode(spi_id, SPI_GET_TICK_MODE_DELAY_1);
        else if ((i&0x300)>>7 == 2)
          spi_set_get_tick_mode(spi_id, SPI_GET_TICK_MODE_DELAY_2);

        if (i&0x80)
            spi_test_enable_deassert_mode = KAL_TRUE;
        else
            spi_test_enable_deassert_mode = KAL_FALSE;
        if (((i&0x8) == 0) || ((i&0x10) == 0))
            size = 32;

		spi_test_directly_internal(size, 1, ((i&0x2)!=0), (i&0x4!=0), (i&0x8!=0), (i&0x10!=0), KAL_FALSE, 0, SPI_CPHA_0, (i&0x20!=0), (i&0x40!=0));
		
		}
    
    spi_test_enable_deassert_mode = KAL_FALSE;
    return KAL_TRUE;
}

kal_bool spi_test_combination2(kal_uint32 size)
{
    kal_uint32 i;
    SPI_CPHA cpha;
    for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
    {
        *((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
        /* clear dest buffer data. */
        *((kal_uint32 *)spi_dest_buffer + i) = 0;
    }

    spi_reset(spi_id);

    for (i=0; i<512; i++)
    {
        dbg_print("%d\n\r", i);
        if ((i&0x3) == 0)
            spi_set_ultra_high(spi_id, KAL_FALSE, 0);
        else if ((i&0x3) == 1)
            spi_set_ultra_high(spi_id, KAL_FALSE, 0xFFFF);
        else if ((i&0x3) == 2)
            spi_set_ultra_high(spi_id, KAL_TRUE, 0);
        else if ((i&0x3) == 3)
            spi_set_ultra_high(spi_id, KAL_TRUE, 0xFFFF);

        if (((i&0x1C)>>2) == 0)
        {
            spi_slow_down_gmc(spi_id, KAL_TRUE, KAL_TRUE, 0x0);
        }
        else if (((i&0x1C)>>2) == 1)
        {
            spi_slow_down_gmc(spi_id, KAL_TRUE, KAL_TRUE, 0xFFFF);
        }
        else if (((i&0x1C)>>2) == 2)
        {
            spi_slow_down_gmc(spi_id, KAL_TRUE, KAL_FALSE, 0x0);
        }
        else if (((i&0x1C)>>2) == 1)
        {
            spi_slow_down_gmc(spi_id, KAL_TRUE, KAL_FALSE, 0xFFFF);
        }
        else if (((i&0x1C)>>2) == 1)
        {
            spi_slow_down_gmc(spi_id, KAL_FALSE, KAL_TRUE, 0x0);
        }
        else if (((i&0x1C)>>2) == 1)
        {
            spi_slow_down_gmc(spi_id, KAL_FALSE, KAL_TRUE, 0xFFFF);
        }
        else if (((i&0x1C)>>2) == 1)
        {
            spi_slow_down_gmc(spi_id, KAL_FALSE, KAL_FALSE, 0x0);
        }
        else if (((i&0x1C)>>2) == 1)
        {
            spi_slow_down_gmc(spi_id, KAL_FALSE, KAL_FALSE, 0xFFFF);
        }

        if (i&0x20)
            spi_test_intr_en_finish = 0;
        else
            spi_test_intr_en_finish = 1;

        if (i&0x40)
            spi_test_intr_en_pause = 0;
        else
            spi_test_intr_en_pause = 1;

        if (i&0x80)
            cpha = 0;
        else
            cpha = 1;

        spi_test_directly_internal(size, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
        spi_test_directly_internal(size, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_TRUE, 0, cpha, KAL_FALSE, KAL_FALSE);
        spi_test_directly_internal(size, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_TRUE, 1, cpha, KAL_FALSE, KAL_FALSE);
        spi_test_directly_internal(size, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_TRUE, -1, cpha, KAL_FALSE, KAL_FALSE);
    }

    return KAL_TRUE;
}





kal_bool spi_reset_after_activate_resume(
                           kal_uint32 const length,
                           kal_uint32 const loop,
                           SPI_MLSB const tx_msb,
                           SPI_MLSB const rx_msb,
                           SPI_MODE const tx_dma,
                           SPI_MODE const rx_dma,
                           kal_bool const enable_pause_mode,
                           kal_int32 const times,
                           SPI_CPHA const fmt,
                           kal_bool const tx_endian_reverse,
                           kal_bool const rx_endian_reverse)
{
    spi_attr_t attr;

    //if (times == 0)
    //    spi_reset(spi_id);

    spi_clear_fifo(spi_id, SPI_TX);
    spi_clear_fifo(spi_id, SPI_RX);
    spi_test_init_data(tx_dma);

    /* bigger value means looser clock time. */
    attr.setup_time = 5;
    attr.hold_time = 5;
    attr.clk_low = 5;
    attr.clk_high = 5;
    attr.idle_time = 5;

    attr.enable_pause_int = KAL_FALSE;
    attr.enable_finish_int = KAL_FALSE;

    if (-1 == times)
    {
        attr.enable_pause_mode = KAL_FALSE;
    }
    else
    {
        attr.enable_pause_mode = enable_pause_mode;
    }

    attr.enable_deassert_mode = spi_test_enable_deassert_mode;
    attr.tx_mlsb = tx_msb;
    attr.rx_mlsb = rx_msb;
    attr.tx_mode = tx_dma;
    attr.rx_mode = rx_dma;
    attr.clk_polarity = SPI_CPOL_0;
    attr.clk_fmt = fmt;

    spi_config(spi_id, &attr);

    spi_set_endian_reverse(spi_id, SPI_TX, tx_endian_reverse);
    spi_set_endian_reverse(spi_id, SPI_RX, rx_endian_reverse);

    spi_set_desired_size(spi_id, length, loop);

    if (SPI_MODE_DMA == tx_dma)
    {
        ASSERT(length <= 64 * 1024);
        spi_set_rwaddr(spi_id, SPI_TX, spi_src_buffer);
    }
    else
    {
        ASSERT(length <= 32);
    }

    if (SPI_MODE_DMA == rx_dma)
    {
        ASSERT(length <= 64 * 1024);
        spi_set_rwaddr(spi_id, SPI_RX, spi_dest_buffer);
    }
    else
    {
        ASSERT(length <= 32);
    }
    if (spi_test_intr_en_finish)
    {
        spi_set_interrupt(spi_id, SPI_INT_FINISH, SPI_ENABLE);
    }
    else
    {
        spi_set_interrupt(spi_id, SPI_INT_FINISH, SPI_DISABLE);
    }
    if (spi_test_intr_en_pause)
    {
        spi_set_interrupt(spi_id, SPI_INT_PAUSE, SPI_ENABLE);
    }
    else
    {
        spi_set_interrupt(spi_id, SPI_INT_PAUSE, SPI_DISABLE);
    }
    
    spi_test_intr_flag = 0;
    
    if ((KAL_TRUE == enable_pause_mode) && (times != 0))
    {
        spi_resume(spi_id);
        /* Wait SPI controller finished. */
    }
    else
    {
        spi_activate(spi_id); 
		spi_reset(spi_id);//reset  after when activate
	return  KAL_TRUE;
		
    }

    if (attr.enable_pause_mode)
    {
        if (spi_test_intr_en_pause)
        {
            while (spi_test_intr_flag == 0) ;
            spi_test_intr_flag = 0;
        }
        else
        {
            while (KAL_TRUE == spi_is_busy()) ;
        }
    }
    else
    {
        if (spi_test_intr_en_finish)
        {
            while (spi_test_intr_flag == 0) ;
            spi_test_intr_flag = 0;
        }
        else
        {
            while (KAL_TRUE == spi_is_busy()) ;
        }
    }

    {
        int i;
        int const multiple = length / sizeof(kal_uint32);
        int const modulo = length % sizeof(kal_uint32);

        for (i = 0; i < loop; ++i)
        {
            kal_uint32 test_pattern_4_byte;
            kal_uint32 test_pattern_123_byte;

            if (SPI_MODE_DMA == rx_dma)
            {
                if (tx_msb == rx_msb)
                {
                    if (tx_endian_reverse == rx_endian_reverse)
                        test_pattern_4_byte = SPI_TEST_PATTERN;
                    else
                        test_pattern_4_byte = SPI_TEST_PATTERN_INVERSE;
                    test_pattern_123_byte = 0x345678;
                }
                else
                {
                    if (tx_endian_reverse == rx_endian_reverse)
                        test_pattern_4_byte = 0x482C6A1E;
                    else
                        test_pattern_4_byte = 0x1E6A2C48;
                    test_pattern_123_byte = 0x2C6A1E;
                }
            }
            else
            {
                if (tx_msb == rx_msb)
                {
                    test_pattern_4_byte = SPI_TEST_PATTERN;
                    test_pattern_123_byte = 0x345678;
                }
                else
                {
                    test_pattern_4_byte = 0x482C6A1E;
                    test_pattern_123_byte = 0x2C6A1E;
                }
            }

            {
                int j;
                for (j = 0; j < multiple; ++j)
                {
                    kal_uint8 *base_addr;
                    kal_uint32 value;

                    if (SPI_MODE_DMA == rx_dma)
                    {
                        base_addr = (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        value = *((kal_uint32 *)base_addr + j);
                    }
                    else
                    {
                        value = SPI_RX_FIFO_REG;
                    }

                    if (value != test_pattern_4_byte)
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }
                }
            }

            {
                kal_uint8 single_data;
                kal_uint32 fifo_data;

                if (SPI_MODE_FIFO == rx_dma)
                {
                    fifo_data = SPI_RX_FIFO_REG;
                }

                switch (modulo)
                {
                case 3:
                    if (SPI_MODE_DMA == rx_dma)
                    {
                        kal_uint8 * const base_addr =
                            (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        single_data = *((kal_uint8 *)((kal_uint32 *)base_addr + multiple) + 2);
                    }
                    else
                    {
                        single_data = ((fifo_data & 0xFF0000) >> 16);
                    }
                    if (single_data != ((test_pattern_123_byte & 0xFF0000) >> 16))
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }

                case 2:
                    if (SPI_MODE_DMA == rx_dma)
                    {
                        kal_uint8 * const base_addr =
                            (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        single_data = *((kal_uint8 *)((kal_uint32 *)base_addr + multiple) + 1);
                    }
                    else
                    {
                        single_data = ((fifo_data & 0xFF00) >> 8);
                    }
                    if (single_data != ((test_pattern_123_byte & 0xFF00) >> 8))
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }

                case 1:
                    if (SPI_MODE_DMA == rx_dma)
                    {
                        kal_uint8 * const base_addr =
                            (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        single_data = *((kal_uint8 *)((kal_uint32 *)base_addr + multiple) + 0);
                    }
                    else
                    {
                        single_data = (fifo_data & 0xFF);
                    }
                    if (single_data != (test_pattern_123_byte & 0xFF))
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }
                    break;

                case 0:
                    break;

                default:
                    ASSERT(0);
                    break;
                }
                return KAL_TRUE;
            }
        }
    }
}



kal_bool spi_clock_test(
                           kal_uint32 const length,
                           kal_uint32 const loop,
                           SPI_MLSB const tx_msb,
                           SPI_MLSB const rx_msb,
                           SPI_MODE const tx_dma,
                           SPI_MODE const rx_dma,
                           kal_bool const enable_pause_mode,
                           kal_int32 const times,
                           SPI_CPHA const fmt,
                           kal_bool const tx_endian_reverse,
                           kal_bool const rx_endian_reverse)
{
    spi_attr_t attr;

    //if (times == 0)
    //    spi_reset(spi_id);

    spi_clear_fifo(spi_id, SPI_TX);
    spi_clear_fifo(spi_id, SPI_RX);
    spi_test_init_data(tx_dma);

    /* bigger value means looser clock time. */
    attr.setup_time = 0;
    attr.hold_time = 0;
    attr.clk_low = 1;
    attr.clk_high = 0;
    attr.idle_time = 0;

    attr.enable_pause_int = KAL_FALSE;
    attr.enable_finish_int = KAL_FALSE;

    if (-1 == times)
    {
        attr.enable_pause_mode = KAL_FALSE;
    }
    else
    {
        attr.enable_pause_mode = enable_pause_mode;
    }

    attr.enable_deassert_mode = spi_test_enable_deassert_mode;
    attr.tx_mlsb = tx_msb;
    attr.rx_mlsb = rx_msb;
    attr.tx_mode = tx_dma;
    attr.rx_mode = rx_dma;
    attr.clk_polarity = SPI_CPOL_0;
    attr.clk_fmt = fmt;

    spi_config(spi_id, &attr);

    spi_set_endian_reverse(spi_id, SPI_TX, tx_endian_reverse);
    spi_set_endian_reverse(spi_id, SPI_RX, rx_endian_reverse);

    spi_set_desired_size(spi_id, length, loop);

    if (SPI_MODE_DMA == tx_dma)
    {
        ASSERT(length <= 64 * 1024);
        spi_set_rwaddr(spi_id, SPI_TX, spi_src_buffer);
    }
    else
    {
        ASSERT(length <= 32);
    }

    if (SPI_MODE_DMA == rx_dma)
    {
        ASSERT(length <= 64 * 1024);
        spi_set_rwaddr(spi_id, SPI_RX, spi_dest_buffer);
    }
    else
    {
        ASSERT(length <= 32);
    }
    if (spi_test_intr_en_finish)
    {
        spi_set_interrupt(spi_id, SPI_INT_FINISH, SPI_ENABLE);
    }
    else
    {
        spi_set_interrupt(spi_id, SPI_INT_FINISH, SPI_DISABLE);
    }
    if (spi_test_intr_en_pause)
    {
        spi_set_interrupt(spi_id, SPI_INT_PAUSE, SPI_ENABLE);
    }
    else
    {
        spi_set_interrupt(spi_id, SPI_INT_PAUSE, SPI_DISABLE);
    }
    
    spi_test_intr_flag = 0;
    
    if ((KAL_TRUE == enable_pause_mode) && (times != 0))
    {
        spi_resume(spi_id);
        /* Wait SPI controller finished. */
    }
    else
    {
        spi_activate(spi_id);
	return  KAL_TRUE;
		
    }

    if (attr.enable_pause_mode)
    {
        if (spi_test_intr_en_pause)
        {
            while (spi_test_intr_flag == 0) ;
            spi_test_intr_flag = 0;
        }
        else
        {
            while (KAL_TRUE == spi_is_busy()) ;
        }
    }
    else
    {
        if (spi_test_intr_en_finish)
        {
            while (spi_test_intr_flag == 0) ;
            spi_test_intr_flag = 0;
        }
        else
        {
            while (KAL_TRUE == spi_is_busy()) ;
        }
    }

    {
        int i;
        int const multiple = length / sizeof(kal_uint32);
        int const modulo = length % sizeof(kal_uint32);

        for (i = 0; i < loop; ++i)
        {
            kal_uint32 test_pattern_4_byte;
            kal_uint32 test_pattern_123_byte;

            if (SPI_MODE_DMA == rx_dma)
            {
                if (tx_msb == rx_msb)
                {
                    if (tx_endian_reverse == rx_endian_reverse)
                        test_pattern_4_byte = SPI_TEST_PATTERN;
                    else
                        test_pattern_4_byte = SPI_TEST_PATTERN_INVERSE;
                    test_pattern_123_byte = 0x345678;
                }
                else
                {
                    if (tx_endian_reverse == rx_endian_reverse)
                        test_pattern_4_byte = 0x482C6A1E;
                    else
                        test_pattern_4_byte = 0x1E6A2C48;
                    test_pattern_123_byte = 0x2C6A1E;
                }
            }
            else
            {
                if (tx_msb == rx_msb)
                {
                    test_pattern_4_byte = SPI_TEST_PATTERN;
                    test_pattern_123_byte = 0x345678;
                }
                else
                {
                    test_pattern_4_byte = 0x482C6A1E;
                    test_pattern_123_byte = 0x2C6A1E;
                }
            }

            {
                int j;
                for (j = 0; j < multiple; ++j)
                {
                    kal_uint8 *base_addr;
                    kal_uint32 value;

                    if (SPI_MODE_DMA == rx_dma)
                    {
                        base_addr = (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        value = *((kal_uint32 *)base_addr + j);
                    }
                    else
                    {
                        value = SPI_RX_FIFO_REG;
                    }

                    if (value != test_pattern_4_byte)
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }
                }
            }

            {
                kal_uint8 single_data;
                kal_uint32 fifo_data;

                if (SPI_MODE_FIFO == rx_dma)
                {
                    fifo_data = SPI_RX_FIFO_REG;
                }

                switch (modulo)
                {
                case 3:
                    if (SPI_MODE_DMA == rx_dma)
                    {
                        kal_uint8 * const base_addr =
                            (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        single_data = *((kal_uint8 *)((kal_uint32 *)base_addr + multiple) + 2);
                    }
                    else
                    {
                        single_data = ((fifo_data & 0xFF0000) >> 16);
                    }
                    if (single_data != ((test_pattern_123_byte & 0xFF0000) >> 16))
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }

                case 2:
                    if (SPI_MODE_DMA == rx_dma)
                    {
                        kal_uint8 * const base_addr =
                            (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        single_data = *((kal_uint8 *)((kal_uint32 *)base_addr + multiple) + 1);
                    }
                    else
                    {
                        single_data = ((fifo_data & 0xFF00) >> 8);
                    }
                    if (single_data != ((test_pattern_123_byte & 0xFF00) >> 8))
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }

                case 1:
                    if (SPI_MODE_DMA == rx_dma)
                    {
                        kal_uint8 * const base_addr =
                            (kal_uint8 *)spi_dest_buffer + loop * length * i;
                        single_data = *((kal_uint8 *)((kal_uint32 *)base_addr + multiple) + 0);
                    }
                    else
                    {
                        single_data = (fifo_data & 0xFF);
                    }
                    if (single_data != (test_pattern_123_byte & 0xFF))
                    {
                        ASSERT(0);
                        return KAL_FALSE;
                    }
                    break;

                case 0:
                    break;

                default:
                    ASSERT(0);
                    break;
                }
                return KAL_TRUE;
            }
        }
    }
}


void spi_cb(void)
{
    spi_test_intr_flag = 1;
	 dbg_print(" Interrupt mode: SPI Transaction  finished \n\r");
}

static kal_uint32 spi_test_port = 0;  // modify this port  to PAD0

/**************************************************************************/
/**************************************************************************/
void spi_msb_msb_dma_dma_test1()
{
  
  int i;
  
	  dbg_print("init spi\n\r");
  
	 // * ===================================================== */
	  dbg_print("MSB->MSB, DMA->DMA, CPHA 0\n\r");
	  /* ===================================================== */
	  for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
	  {
		  *((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
		  /* clear dest buffer data. */
		  *((kal_uint32 *)spi_dest_buffer + i) = 0;
	  }
  
  
	  //for (i = 1; i < 64; ++i)
	  //{
	   // dbg_print("length: %d bytes\n\r", i);
	   // spi_test_directly_internal(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, cpha, KAL_FALSE, KAL_FALSE);
	// }
		
		 i=1;
		 if(1==i)
		  {
	   dbg_print("length: %d bytes\n\r", i);
	   spi_test_directly_internal(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
		 }
  
	  dbg_print("length: 1024 bytes\n\r");
	  spi_test_directly_internal(1024, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
  
	  dbg_print("length: 4096 bytes\n\r");
	  spi_test_directly_internal(1024, 4, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
  
	  dbg_print("length: 64 * 1024 bytes\n\r");
	  spi_test_directly_internal(1024, 64, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
  
}
void spi_msb_lsb_dma_dma_test2()
{
  

   int i;
   /* ===================================================== */
	  dbg_print("MSB->LSB, DMA->DMA, CPHA 0\n\r");
	  /* ===================================================== */
   
	  for (i = 1; i < 64; ++i)
	  {
		  dbg_print("length: %d bytes\n\r", i);
   
		  spi_test_directly_internal(i, 1, SPI_MSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_1, KAL_FALSE, KAL_FALSE);
	  }
	  dbg_print("length: 1024 bytes\n\r");
	  spi_test_directly_internal(1024, 1, SPI_MSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_1, KAL_FALSE, KAL_FALSE);
	  dbg_print("length: 4096 bytes\n\r");
	  spi_test_directly_internal(1024, 4, SPI_MSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_1, KAL_FALSE, KAL_FALSE);
	  dbg_print("length: 64 * 1024 bytes\n\r");
	  spi_test_directly_internal(1024, 64, SPI_MSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_1, KAL_FALSE, KAL_FALSE);
   
}
void spi_delay_tick1_test3()
{
    spi_reset(spi_id);

    dbg_print("Get tick mode delay 1\n\r");
    spi_set_get_tick_mode(spi_id, SPI_GET_TICK_MODE_DELAY_1);
	

    spi_reset(spi_id);

    spi_test_directly(SPI_CPHA_1);
	   // spi_reset(spi_id);

	
   // spi_test_directly(SPI_CPHA_1);

}


void spi_delay_tick2_test4()
{   
    spi_reset(spi_id);
    dbg_print("Get tick mode delay 2\n\r");
    spi_set_get_tick_mode(spi_id, SPI_GET_TICK_MODE_DELAY_2);

    spi_reset(spi_id);

    spi_test_directly(SPI_CPHA_0);

   // spi_reset(spi_id);

   // spi_test_directly(SPI_CPHA_1);
}


void spi_combination_tick1_tick2_test5()
{
dbg_print("Combination test 1\n\r");
       spi_test_combination1();

}	

void spi_clock_test6()
{
 int i;

 dbg_print("init spi\n\r");

 /* ===================================================== */
 dbg_print("MSB->MSB, DMA->DMA, CPHA 0\n\r");
 /* ===================================================== */
 for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
 {
	 *((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
	 /* clear dest buffer data. */
	 *((kal_uint32 *)spi_dest_buffer + i) = 0;
 }
		 
	 i=64;	// user can modify	it	 
if(i==64)  //  default : 64
 {
	dbg_print("length: %d bytes\n\r", i);

 spi_clock_test(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
}


}

void  spi_lsb_lsb_dma_dma_test7()
{

int i;


/* ===================================================== */
    dbg_print("LSB->LSB, DMA->DMA, CPHA 0\n\r");
    /* ===================================================== */

	for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
	{
		*((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
		/* clear dest buffer data. */
		*((kal_uint32 *)spi_dest_buffer + i) = 0;
	}



    for (i = 1; i < 64; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
    }

    dbg_print("length: 1024 bytes\n\r");
    spi_test_directly_internal(1024, 1, SPI_LSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);

    dbg_print("length: 4096 bytes\n\r");
    spi_test_directly_internal(1024, 4, SPI_LSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 64 * 1024 bytes\n\r");
    spi_test_directly_internal(1024, 64, SPI_LSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);

}

void  spi_lsb_msb_dma_dma_test8()

{
  int i;
/* ===================================================== */
    dbg_print("LSB->MSB, DMA->DMA, CPHA 0\n\r");
    /* ===================================================== */

	for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
	{
		*((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
		/* clear dest buffer data. */
		*((kal_uint32 *)spi_dest_buffer + i) = 0;
	}



    for (i = 1; i < 64; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
    }
    dbg_print("length: 1024 bytes\n\r");
    spi_test_directly_internal(1024, 1, SPI_LSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 4096 bytes\n\r");
    spi_test_directly_internal(1024, 4, SPI_LSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 64 * 1024 bytes\n\r");
    spi_test_directly_internal(1024, 64, SPI_LSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);

}

void  spi_tx_dma_rx_fifo_test9()
{
  int i;
/* ===================================================== */
dbg_print("MSB->MSB, DMA->FIFO, CPHA 0\n\r");
/* ===================================================== */
for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
{
	*((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
	/* clear dest buffer data. */
	*((kal_uint32 *)spi_dest_buffer + i) = 0;
}



for (i = 1; i < 32; ++i)
{
	dbg_print("length: %d bytes\n\r", i);

	spi_test_directly_internal(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_FIFO, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
}

/* ===================================================== */
dbg_print("MSB->LSB, DMA->FIFO, CPHA 0\n\r");
/* ===================================================== */

for (i = 1; i < 32; ++i)
{
	dbg_print("length: %d bytes\n\r", i);

	spi_test_directly_internal(i, 1, SPI_MSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_FIFO, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
}

/* ===================================================== */
dbg_print("LSB->LSB, DMA->FIFO, CPHA 0\n\r");
/* ===================================================== */

for (i = 1; i < 32; ++i)
{
	dbg_print("length: %d bytes\n\r", i);

	spi_test_directly_internal(i, 1, SPI_LSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_FIFO, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
}

/* ===================================================== */
dbg_print("LSB->MSB, DMA->FIFO, CPHA 0\n\r");
/* ===================================================== */

for (i = 1; i < 32; ++i)
{
	dbg_print("length: %d bytes\n\r", i);

	spi_test_directly_internal(i, 1, SPI_LSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_FIFO, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
}

}
		
void  spi_tx_fifo_rx_dma_test10()
		{
 int i;

	/* ===================================================== */
    dbg_print("MSB->MSB, FIFO->DMA, CPHA 0\n\r");
    /* ===================================================== */
	for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
	{
		*((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
		/* clear dest buffer data. */
		*((kal_uint32 *)spi_dest_buffer + i) = 0;
	}


	
    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_FIFO, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("MSB->LSB, FIFO->DMA, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_MSB, SPI_LSB, SPI_MODE_FIFO, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("LSB->LSB, FIFO->DMA, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_LSB, SPI_MODE_FIFO, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
    }

    /* ===================================================== */
    dbg_print("LSB->MSB, FIFO->DMA, CPHA 0\n\r");
    /* ===================================================== */

    for (i = 1; i < 32; ++i)
    {
        dbg_print("length: %d bytes\n\r", i);

        spi_test_directly_internal(i, 1, SPI_LSB, SPI_MSB, SPI_MODE_FIFO, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
    }  

		}

void  spi_tx_fifo_rx_fifo_test11()
{
 int i;

// TX/RX FIFO
/* ===================================================== */
dbg_print("MSB->MSB, FIFO->FIFO, CPHA 0\n\r");
/* ===================================================== */
for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
{
	*((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
	/* clear dest buffer data. */
	*((kal_uint32 *)spi_dest_buffer + i) = 0;
}




for (i = 1; i < 32; ++i)
{
	dbg_print("length: %d bytes\n\r", i);

	spi_test_directly_internal(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_FIFO, SPI_MODE_FIFO, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
}

/* ===================================================== */
dbg_print("MSB->LSB, FIFO->FIFO, CPHA 0\n\r");
/* ===================================================== */

for (i = 1; i < 32; ++i)
{
	dbg_print("length: %d bytes\n\r", i);

	spi_test_directly_internal(i, 1, SPI_MSB, SPI_LSB, SPI_MODE_FIFO, SPI_MODE_FIFO, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
}

/* ===================================================== */
dbg_print("LSB->LSB, FIFO->FIFO, CPHA 0\n\r");
/* ===================================================== */

for (i = 1; i < 32; ++i)
{
	dbg_print("length: %d bytes\n\r", i);

	spi_test_directly_internal(i, 1, SPI_LSB, SPI_LSB, SPI_MODE_FIFO, SPI_MODE_FIFO, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
}

/* ===================================================== */
dbg_print("LSB->MSB, FIFO->FIFO, CPHA 0\n\r");
/* ===================================================== */

for (i = 1; i < 32; ++i)
{
	dbg_print("length: %d bytes\n\r", i);

	spi_test_directly_internal(i, 1, SPI_LSB, SPI_MSB, SPI_MODE_FIFO, SPI_MODE_FIFO, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
}
}

void spi_pause_mode_test12()
{

int i;
// Pause mode

for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
{
	*((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
	/* clear dest buffer data. */
	*((kal_uint32 *)spi_dest_buffer + i) = 0;
}

/* ===================================================== */
    dbg_print("CPHA 0, Pause mode\n\r");
    /* ===================================================== */

    dbg_print("length: 4096 bytes\n\r");
    spi_test_directly_internal(1024, 4, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_TRUE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 4096 bytes\n\r");
    spi_test_directly_internal(1024, 4, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_TRUE, 1, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);
    dbg_print("length: 4096bytes\n\r");
    spi_test_directly_internal(1024, 4, SPI_MSB, SPI_MSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_TRUE, -1, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);

}



void  spi_restart_after_reset_test13()
{

int i;

 dbg_print("init spi\n\r");

 /* ===================================================== */
 dbg_print("MSB->MSB, DMA->DMA, CPHA 0\n\r");
 /* ===================================================== */
 for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
 {
	 *((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
	 /* clear dest buffer data. */
	 *((kal_uint32 *)spi_dest_buffer + i) = 0;
 }
		 
	 i=32;	// user can modify	it	 

dbg_print("length: %d bytes\n\r", i);

 spi_reset_after_activate_resume(i, 1, SPI_MSB, SPI_MSB, SPI_MODE_FIFO, SPI_MODE_FIFO, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);


for (i = 0; i < TOTAL_TEST_AREA_LENGTH / 4; ++i)
{
	*((kal_uint32 *)spi_src_buffer + i) = SPI_TEST_PATTERN;
	/* clear dest buffer data. */
	*((kal_uint32 *)spi_dest_buffer + i) = 0;
}


i=4096;
dbg_print("length: %d bytes\n\r", i);

spi_test_directly_internal(1024, 4, SPI_LSB, SPI_LSB, SPI_MODE_DMA, SPI_MODE_DMA, KAL_FALSE, 0, SPI_CPHA_0, KAL_FALSE, KAL_FALSE);

}

void  spi_test(task_entry_struct *task_entry_ptr)
{

	  spi_test_intr_en_finish = 0;
    spi_test_intr_en_pause = 0;
    spi_init();

    spi_open(&spi_id, NULL, 0);
    
    spi_select_port(spi_test_port);

    
    spi_set_cb(spi_id, SPI_INT_PAUSE, spi_cb, NULL);
    spi_set_cb(spi_id, SPI_INT_FINISH, spi_cb, NULL);

		
/*******************************************************************/

 while(1)
    {
        kal_uint16 input;
         //kal_uint16 LSR;
        dbg_print("\r\n========================\r\n");
     	dbg_print("1  spi msb msb dma dma test...\r\n");
        dbg_print("2  spi msb lsb dma dma test...\r\n");
        dbg_print("3  delay tick1 test...\r\n");
        dbg_print("4  delay tick2 test...\r\n");
        dbg_print("5  combination test...\r\n");
		dbg_print("6  spi source clock test...\r\n");
		dbg_print("7  spi LSB LSB DMA DMA test...\r\n");
		dbg_print("8  spi LSB MSB DMA DMA test...\r\n");
		dbg_print("9  spi TX  DMA rx FIFO test...\r\n");
		dbg_print("a  spi TX FIFO RX DMA  test...\r\n");
		dbg_print("b  spi TX FIFO RX fifo  test...\r\n");
		dbg_print("c  spi pause mode   test...\r\n");
        dbg_print("d  restarts after reset during SPI transfer period  test...\r\n");
        dbg_print("============================\r\n");
        dbg_print("input:");
  
     	spi_reset(spi_id);
        spi_test_input(&input,0); //use uart1 to communicate 
        dbg_print("test num is %c\r\n",input);
        switch(input)
        {
      case '1': spi_msb_msb_dma_dma_test1();break;
      case '2': spi_msb_lsb_dma_dma_test2();break;
      case '3': spi_delay_tick1_test3();break;
      case '4': spi_delay_tick2_test4();break;
      case '5': spi_combination_tick1_tick2_test5();break;
      case '6': spi_clock_test6();break;
      case'7':  spi_lsb_lsb_dma_dma_test7();break;
	  case'8':  spi_lsb_msb_dma_dma_test8();break;
	  case'9':  spi_tx_dma_rx_fifo_test9();break;
	  case'a':  spi_tx_fifo_rx_dma_test10();break;
	  case'b':  spi_tx_fifo_rx_fifo_test11();break;
	  case'c':  spi_pause_mode_test12();break;
	  case'd':  spi_restart_after_reset_test13();break;
      default: break;
        }
 	}
	 ;//
}

#endif

