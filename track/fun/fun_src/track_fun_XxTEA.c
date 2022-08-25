/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/

#include "custom_nvram_editor_data_item.h"
#include "app_datetime.h"

#include "track_os_data_types.h"
#include "track_os_log.h"
#include "track_os_ell.h"

#define MX (z>>5^y<<2)+(y>>3^z<<4)^(sum^y)+(k[p&3^e]^z)
#define DELTA 0x9e3779b9
#define S_LOOPTIME 1
#define BLOCK_SIZE 16 //PAGE_SIZE,根据你所要加密的数据包长度修改此参数(单位:字节)
#if 0//原来的算法
//BXxTEA
void TEA_EncryptCore(int block_size, char*buf, char*key)
{
    char n = block_size / 4;
    int*v = (int*)buf;
    int*k = (int*)key;
    long z = v[n -1];
    long y = v[0];
    long sum = 0;
    long e;
    char p;
    char q;
    q = S_LOOPTIME + 52 / n;
    while(q-- > 0)
    {
        sum += DELTA;
        e = sum >> 2 & 3;
        for(p = 0; p < n - 1; p++)
        {
            y = v[p +1];
            z = v[p] += MX;
        }
        y = v[0];
        z = v[n -1] += MX;
    }
}
void TEA_DecrpytCore(int block_size, char* buf, char* key)
{
    char n = block_size / 4;
    long*v = (long*)buf;
    long*k = (long*)key;
    long z = v[n -1];
    long y = v[0];
    long sum = 0;
    long e;
    unsigned char p;
    unsigned char q;
    q = S_LOOPTIME + 52 / n;
    sum = q * DELTA;
    while(sum != 0)
    {
        e = sum >> 2 & 3;
        for(p = n - 1; p > 0; p--)
        {
            z = v[p -1];
            y = v[p] -= MX;
        }
        z = v[n -1];
        y = v[0] -= MX;
        sum -= DELTA;
    }
}
int TEA_Encrypt(char*key, char*data, short data_size)
{
    int i = 0;
    int block_size = ((data_size + 2) / 4 + 1) * 4;
    for(i = data_size + 1; i >= 2; i--)
    {
        data[i] = data[i-2];
    }
    data[0] = (data_size >> 8) & 0xff;
    data[1] = (data_size >> 0) & 0xff;
    TEA_EncryptCore(block_size, data, key);
    return block_size;
}
int TEA_Decrpyt(char*key, char*data, short data_size)
{
    int i;
    int real_data_size = 0;
    TEA_DecrpytCore(data_size, data, key);
    real_data_size = ((int)data[0] << 8) | (int)data[1];
    for(i = 0; i < real_data_size; i++)
    {
        data[i] = data[i +2];
    }
    return real_data_size;
}
#endif
/*7号人写的*/
//#define MX            (z>>5^y<<2)+(y>>3^z<<4)^(sum^y)+(k[p&3^e]^z)
//#define DELTA         0x9e3779b9

#define S_LOOPTIME    1

#define ENCRYPT_INT_BUFF 256 

static int sg_key_buff[4];
static int sg_data_buff[ENCRYPT_INT_BUFF];

int bytes2int(U8* bytes) 
{
	int result = bytes[0] & 0xFF;
	result |= ((bytes[1] << 8) & 0xFF00);
	result |= ((bytes[2] << 16) & 0xFF0000);
	result |= ((bytes[3] << 24) & 0xFF000000);
	return result;
}

void int2byte(int data, U8* bytes) 
{
	bytes[0] = (U8)(0xff & data);
	bytes[1] = (U8)((0xff00 & data) >> 8);
	bytes[2] = (U8)((0xff0000 & data) >> 16);
	bytes[3] = (U8)((0xff000000 & data) >> 24);
}

static void TEA_EncryptCore(int block_size,int* buf,int* key)
{
	//int i=0;
	char n = block_size /4;
	int*v =(int*)buf;
	int*k =(int*)key;
	long z = v[n -1];
	long y = v[0];
	long sum =0;
	long e;
	char p;
	char q;
	
	//SG_LOG_PRINT("before int [%d][%d][%d][%d]", key[0], key[1], key[2], key[3]);

	//for(i=0; i<n; i++)
	//{
	//	SG_LOG_PRINT("before data%d [%d]", i, buf[i]);
	//}


	q = S_LOOPTIME +52/ n;

	while(q-->0)
	{
		sum += DELTA;
		e = sum >>2&3;
		for(p =0; p < n -1; p++)
		{
			y = v[p +1];
			z = v[p]+= MX;
		}
		y = v[0];
		z = v[n -1]+= MX;
	}

	//for(i=0; i<n; i++)
	//{
	//	SG_LOG_PRINT("after data%d [%d]", i, buf[i]);
	//} 
}

static void TEA_DecrpytCore(int block_size,int* buf,int* key)
{
	char  n = block_size /4;
	long*v =(long*)buf;
	long*k =(long*)key;
	long  z = v[n -1];
	long  y = v[0];
	long  sum =0;
	long  e;
	unsigned char p;
	unsigned char q;

	q = S_LOOPTIME +52/ n;
	sum = q * DELTA;
	while(sum !=0)
	{
		e = sum >>2&3;
		for(p = n -1; p >0; p--)
		{
			z = v[p -1];
			y = v[p]-= MX;
		}
		z = v[n -1];
		y = v[0]-= MX;
		sum -= DELTA;
	}
}

int sg_xxtea_encrypt(unsigned char* data, U16 data_size)
{
	int i =0;
	int block_size =((data_size +2)/4+1)*4;
	memset(sg_data_buff, 0, ENCRYPT_INT_BUFF*4);

	if(block_size > data_size)
	{
		memset(&data[data_size], 0, block_size-data_size);
	}
	
	for(i = data_size +1; i >=2; i--)
	{
		data[i]= data[i-2];
	}
	
	data[0]=(data_size >>8)&0xff;
	data[1]=(data_size >>0)&0xff;

	for(i=0; i<block_size/4; i++)
	{
		sg_data_buff[i] = bytes2int(&data[i*4]);
	}
	
	TEA_EncryptCore(block_size, sg_data_buff, sg_key_buff);
	
	for(i=0; i<block_size/4; i++)
	{
		int2byte(sg_data_buff[i], &data[i*4]);
	}
	return block_size;
}

int sg_xxtea_decrypt(unsigned char* data, U16 data_size,U16 max_size)
{
	int i;
	int real_data_size =0;
	memset(sg_data_buff, 0, ENCRYPT_INT_BUFF*4);

	for(i=0; i<data_size/4; i++)
	{
		sg_data_buff[i] = bytes2int(&data[i*4]);
	}
	TEA_DecrpytCore(data_size, sg_data_buff, sg_key_buff); 
	for(i=0; i<data_size/4; i++)
	{
		int2byte(sg_data_buff[i], &data[i*4]);
	}

	real_data_size =((int)data[0]<<8)|(int)data[1];
	if(max_size !=0 && real_data_size > max_size)
	{
		return -1;
	}
	for(i =0; i < real_data_size; i++)
	{
		data[i]= data[i +2];
	}

	return real_data_size;
}

void sg_xxtea_set_key(unsigned char* key)
{
	int i;
	for(i=0; i<4; i++)
	{
		sg_key_buff[i] = bytes2int(&key[i*4]);
	}
}

void sg_xxtea_test()
{
	int len;
	U8 input[24] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,
				    0x0b,0x0c,0x0d,0x0e,0x0f,0x09,0x08,0x07,0x06,0x05, 0x00, 0x00, 0x00, 0x00};
	
	U8 key[16] = {0x87, 0x32, 0x87, 0xe4, 0x47, 0x3c, 0x15, 0x8e, 0x2e, 
				  0x87, 0x3d, 0xaf, 0x65, 0xbd, 0x7b, 0xa8};

	sg_xxtea_set_key(key);

	len = sg_xxtea_encrypt(input, 20);
    //SG_LOG_PRINT("xxtea encrypt [%d][%s]", len, (char*)hex2str(input, len));
	
	len = sg_xxtea_decrypt(input, len,0);
	//SG_LOG_PRINT("xxtea decrypt [%d][%s]", len, (char*)hex2str(input, len));
}



