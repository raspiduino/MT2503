
#ifdef __MTK_TARGET__
#include "dcm.h"
#include "pll.h"
#include "us_timer.h"

extern void cp15_enter_low_pwr_state(void);
#pragma arm section zidata = "INTSRAM_ZI"
static kal_uint32 dropVoltageCount = 0;
#pragma arm section zidata

#pragma arm section code = "INTSRAM_ROCODE"

/** @argu mode : to be defined, currently no usage.
 *
 **/
#if defined(MT6260) || defined (MT6250)
kal_int32 arm_enter_standby_mode(kal_int32 mode)
{
#if defined (MT6250)
#if !defined (SLEEP_CON)
#define ARM_SLEEP_CON          ((volatile UINT16P)(ARM_CONFG_base+0x0040))
#define SLEEP_CON              ARM_SLEEP_CON
#endif

        kal_uint32 tmp;

        tmp = *PLL_CLK_CONDA;
        ASSERT(((tmp >> 10) & 0x3f) == 0x21); // assert RG_ARM_PLLCK_SEL1 as 87Mhz, and RG_ARM_PLLCK_SEL2 as 260Mhz

        *PLL_CLK_CONDC = (*PLL_CLK_CONDC & ~(0x7<<3)) | (0x2<<3);
        *PLL_CLK_CONDC;
        /** ASTONE,
         * "READ-modify-write" is good for flushing bus transaction, instead of write directly.
         * BUT, take care about side effect of read-modify-write, esp. about read-clear bit.
         **/
        *SLEEP_CON |= 1;
        __nop();
        __nop();
        __nop();
        __nop();
        __nop();
        __nop();

        /* debug code of long irq latency of TDMA issue. Should be removed after W12.26 */
        {
                extern kal_uint32 irq_dbg_time_leave_from_sleep;
                irq_dbg_time_leave_from_sleep = ust_get_current_time();
        }

        *PLL_CLK_CONDC = (*PLL_CLK_CONDC & ~(0x7<<3)) | (0x4<<3);
        *PLL_CLK_CONDC;

#elif defined (MT6260)
#if !defined (SLEEP_CON)
#define ARM_SLEEP_CON          ((volatile UINT16P)(ARM_CONFG_base+0x0040))
#define SLEEP_CON              ARM_SLEEP_CON
#endif
        {
                register kal_uint32 conda, condc, conde;
                kal_uint32 _savedmask;
                kal_uint32 LockIRQ(void);
                void RestoreIRQ(kal_uint32);

                _savedmask = LockIRQ();

                conda = *PLL_CLK_CONDA;
                condc = *PLL_CLK_CONDC;

                /* if (mode != 0) { */
                /*     conde = *PLL_CLK_CONDE; */
                /*     *PLL_CLK_CONDE = conde & (3<<14); */
                /* } */

                // switch MCU to MPLL/3 clock;
                /* *PLL_CLK_CONDA = (conda | (1<<13)); */
                /* *PLL_CLK_CONDC = (condc & ~(0x7<<3) | (0x04 << 3)); */
                *PLL_CLK_CONDC = (condc & ~(0x7<<3) | (0x01 << 3));
                *PLL_CLK_CONDC;

#if defined(MT6260) && defined(__ESD_LU_NEW_SOLUTION__)
#if !defined(__ESD_LU_NEW_SOLUTION_TEST__)
                if (*((volatile unsigned int *)(0xA0700E24)))
#endif /* defined(__ESD_LU_NEW_SOLUTION_TEST__) */
                {
                        kal_uint32 t1, t2;

#if !defined(__ESD_LU_NEW_SOLUTION_TEST__)
                        if (++dropVoltageCount > 100)
                        {
                                // 0.8V
                                *((volatile kal_uint16 *)(0xA0700230)) = 0x8541;
                                *((volatile kal_uint16 *)(0xA0700230));

                                EXT_ASSERT(0, 0, 0, 0);
                        }
#endif /* defined(__ESD_LU_NEW_SOLUTION_TEST__) */

                        // 0.975V
                        *((volatile kal_uint16 *)(0xA0700230)) = 0x85B1;
                        *((volatile kal_uint16 *)(0xA0700230));

                        t1 = ust_get_current_time();
                        do
                        {
                                t2 = ust_get_current_time();
                        } while(ust_get_duration(t1, t2) < 500);

                        // 1.3V
                        *((volatile kal_uint16 *)(0xA0700230)) = 0x8481;
                        *((volatile kal_uint16 *)(0xA0700230));

                        t1 = ust_get_current_time();
                        do
                        {
                                t2 = ust_get_current_time();
                        } while(ust_get_duration(t1, t2) < 200);
                }
#endif /* defined(__ESD_LU_NEW_SOLUTION__) */

                *SLEEP_CON |= 1;
                __nop();
                __nop();
                __nop();
                __nop();
                __nop();
                __nop();

                *PLL_CLK_CONDA = conda;
                *PLL_CLK_CONDC = condc;
                *PLL_CLK_CONDC;

                /* if (mode != 0) { */
                /*     *PLL_CLK_CONDE = conde; */
                /* } */

                /** disable EMI HW DCM,
                 * 1. to workaround EMI DCM having long DCM recovery time.
                 * 2. to workaround EMI DCM that has slow reponse MMSYS idle that make normal clock too late to reponse MMSYS request.
                 **/
                MT6260_EMI_DCM_DISABLE();

                RestoreIRQ(_savedmask);

        }

#else  //#if defined (MT6250)

        ASSERT(0);

#endif //#if defined (MT6250)

        return 0;
}

#endif //#if defined(MT6260) || defined (MT6250)


#if defined(MT6261)

#if !defined (SLEEP_CON)
#define ARM_SLEEP_CON          ((volatile UINT16P)(ARM_CONFG_base+0x0040))
#define SLEEP_CON              ARM_SLEEP_CON
#endif

kal_int32 arm_enter_standby_mode(kal_int32 mode)
{
        
        kal_uint32 _savedmask;
        kal_uint32 LockIRQ(void);
        void RestoreIRQ(kal_uint32);

        _savedmask = LockIRQ();

        *PLL_CLK_CONDB |= 0x1000; //0xA001_0104, bit 12 set to 1 for EMI1X clock = MCU
        while ((*PLL_CLK_CONDB & 0x1000) == 0x0000);

        *SLEEP_CON |= 1;
        __nop();
        __nop();
        __nop();
        __nop();
        __nop();
        __nop();

        *PLL_CLK_CONDB &= 0xEFFF; //0xA001_0104, bit 12 set to 0 for EMI1X clock = MCU
        while ((*PLL_CLK_CONDB & 0x1000) == 0x1000);

        RestoreIRQ(_savedmask);
        return 0;
}

#endif //#if defined (MT6261)

#pragma arm section code

#endif //__MTK_TARGET__
