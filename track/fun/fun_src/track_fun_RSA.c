#if 1
/*******************************************************************************************
 * Filename:    
 * Author :     
 * Date :       
 * Comment:     
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "custom_nvram_editor_data_item.h"
#include "app_datetime.h"
#include "kal_public_defs.h"
#include "track_os_data_types.h"
#include "track_os_log.h"
#include "track_os_ell.h"
#include "track_cust.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
#define BI_MAXLEN 130
#define DEC 10
#define HEX 16

#define  CARRYOVER  0x10000
#define  CARRYLAST   0xFFFF

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    U32 m_nLength;    //大数在0x1 00 00 00 00进制下的长度
    U16 m_ulValue[BI_MAXLEN];    //用数组记录大数在0x100000000进制下每一位的值
} CBigInt;
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 rsaType;//加密 1  解密 0
	int dataLength;//数据长度
	kal_uint8 dataBuffer[128];//数据
}rsa_data_struct;

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static char *publicKey = "10001";
static kal_uint8 keyContent[128] = {0};
	/*{	
	0xc6,0x69,0xa3,0xc2,0x79,0x06,0x18,0xae,0x82,0xdf,0xef,0x07,0x6e,0xa6,0x9f,0x9d,0xa2,0x10,
	0xe5,0x0d,0xe6,0xf0,0x11,0x3d,0xbf,0x7d,0x95,0x3b,0xb1,0x2a,0xab,0x4b,0xa7,0xc4,0xab,0xac,
	0xdd,0x1a,0x23,0xa2,0x01,0x13,0x7f,0x52,0x68,0x54,0xb4,0x28,0xee,0x52,0x41,0x66,0xe1,0x0c,
	0xd3,0xfb,0x2c,0xc9,0x79,0xf1,0x7c,0x6d,0x27,0x1d,0x2a,0x17,0xdc,0x8d,0xe4,0x77,0xd0,0xe3,
	0x1c,0xb3,0x37,0xcb,0x31,0x7b,0x5b,0xea,0xf9,0x1e,0x06,0xb8,0x4e,0x25,0x0f,0xda,0xdd,0xb1,
	0xd8,0xd7,0xac,0xfa,0x1e,0x7c,0xdd,0x51,0x80,0x30,0xa4,0x04,0x15,0x9b,0x10,0x3e,0xba,0x4a,
	0xa6,0x08,0xc7,0x49,0x37,0xcf,0xf1,0x60,0x53,0x72,0x13,0xc7,0xb5,0x36,0xfa,0x7d,0x27,0xdb,
	0x0f,0x55};
	*/


/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
/*****************************************************************
基本操作与运算
Init, 构造大数对象并初始化为零
Mov，赋值运算，可赋值为大数或普通整数，可重载为运算符“=”
Cmp，比较运算，可重载为运算符“==”、“!=”、“>=”、“<=”等
Add，加，求大数与大数或大数与普通整数的和，可重载为运算符“+”
Sub，减，求大数与大数或大数与普通整数的差，可重载为运算符“-”
Mul，乘，求大数与大数或大数与普通整数的积，可重载为运算符“*”
Div，除，求大数与大数或大数与普通整数的商，可重载为运算符“/”
Mod，模，求大数与大数或大数与普通整数的模，可重载为运算符“%”
*****************************************************************/
static CBigInt *Mov_Big_Long(CBigInt *X, U32 A);
static CBigInt *Mov_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Add_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Sub_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Mul_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Div_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Mod_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Add_Big_Long(CBigInt *X, U32 A);
static CBigInt *Sub_Big_Long(CBigInt *X, U32 A);
static CBigInt *Mul_Big_Long(CBigInt *X, U32 A);
static CBigInt *Div_Big_Long(CBigInt *X, U32 A);
static U32 Mod_Big_Long(CBigInt *N, U32 A);
static int Cmp(CBigInt *N, CBigInt *A);

/*****************************************************************
输入输出
Get，从字符串按10进制或16进制格式输入到大数
Put，将大数按10进制或16进制格式输出到字符串
*****************************************************************/
static CBigInt *Get(CBigInt *N, char *str, U32 system);
static char *Put(CBigInt *N, U32 system);

/*****************************************************************
RSA相关运算
Rab，拉宾米勒算法进行素数测试
Euc，欧几里德算法求解同余方程
RsaTrans，反复平方算法进行幂模运算
GetPrime，产生指定长度的随机大素数
*****************************************************************/
static int Rab(CBigInt *N);
static CBigInt *Euc(CBigInt *X, CBigInt *A);
static CBigInt *RsaTrans(CBigInt *X, CBigInt *A, CBigInt *B);
static CBigInt *GetPrime(CBigInt *X, int bits);

/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/*****************************************************************
大数运算库源文件：BigInt.c
作者：afanty@vip.sina.com，xxx
版本：1.2 (2003.5.13)
说明：适用于C，linux系统 1024位RSA运算
*****************************************************************/

//小素数表
const static int PrimeTable[550] =
{
    3,     5,     7,     11,   13,   17,   19,   23,   29,   31,
    37,   41,   43,   47,   53,   59,   61,   67,   71,   73,
    79,   83,   89,   97,   101,   103,   107,   109,   113,   127,
    131,   137,   139,   149,   151,   157,   163,   167,   173,   179,
    181,   191,   193,   197,   199,   211,   223,   227,   229,   233,
    239,   241,   251,   257,   263,   269,   271,   277,   281,   283,
    293,   307,   311,   313,   317,   331,   337,   347,   349,   353,
    359,   367,   373,   379,   383,   389,   397,   401,   409,   419,
    421,   431,   433,   439,   443,   449,   457,   461,   463,   467,
    479,   487,   491,   499,   503,   509,   521,   523,   541,   547,
    557,   563,   569,   571,   577,   587,   593,   599,   601,   607,
    613,   617,   619,   631,   641,   643,   647,   653,   659,   661,
    673,   677,   683,   691,   701,   709,   719,   727,   733,   739,
    743,   751,   757,   761,   769,   773,   787,   797,   809,   811,
    821,   823,   827,   829,   839,   853,   857,   859,   863,   877,
    881,   883,   887,   907,   911,   919,   929,   937,   941,   947,
    953,   967,   971,   977,   983,   991,   997,   1009, 1013, 1019,
    1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087,
    1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153,
    1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229,
    1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297,
    1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381,
    1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453,
    1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523,
    1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597,
    1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663,
    1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741,
    1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823,
    1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901,
    1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993,
    1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063,
    2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131,
    2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221,
    2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293,
    2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371,
    2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437,
    2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539,
    2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621,
    2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689,
    2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749,
    2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833,
    2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909,
    2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001,
    3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083,
    3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187,
    3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259,
    3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343,
    3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433,
    3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517,
    3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581,
    3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643, 3659,
    3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733,
    3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823,
    3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907, 3911,
    3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001
};

/****************************************************************************************
大数比较
调用方式：Cmp(N,A)
返回值：若N<A返回-1；若N=A返回0；若N>A返回1
****************************************************************************************/
static int Cmp(CBigInt *N, CBigInt *A)
{
    int i;
    if(N->m_nLength > A->m_nLength)
        return 1;
    if(N->m_nLength < A->m_nLength)
        return -1;
    for(i = N->m_nLength - 1; i >= 0; i--)
    {
        if(N->m_ulValue[i] > A->m_ulValue[i])
            return 1;
        if(N->m_ulValue[i] < A->m_ulValue[i])
            return -1;
    }
    return 0;
}

/****************************************************************************************
大数赋值
调用方式：__Mov_Big_Big(A)
返回值：N,被赋值为A
****************************************************************************************/
static CBigInt *Mov_Big_Big(CBigInt *X, CBigInt *A)
{
    memcpy(X, A, sizeof(CBigInt));
    return X;
}

static CBigInt *Mov_Big_Long(CBigInt *N, U32 A)
{
    int i;
    if(A > CARRYLAST)
    {
        N->m_nLength = 2;
        N->m_ulValue[1] = (U16)(A >> 16);
        N->m_ulValue[0] = (U16)A;
    }
    else
    {
        N->m_nLength = 1;
        N->m_ulValue[0] = (U16)A;
    }
    memset((unsigned char*)&N->m_ulValue[N->m_nLength], 0, sizeof(U16) * (BI_MAXLEN-N->m_nLength));
    return N;
}

/****************************************************************************************
大数相加
调用形式：Add_Big_Big(X,A)
返回值：X=X+A
****************************************************************************************/
static CBigInt *Add_Big_Big(CBigInt *X, CBigInt *A)
{
    U32 i;
    U16 carry = 0;
    U32 sum = 0;
    if(X->m_nLength < A->m_nLength)
    {
        X->m_nLength = A->m_nLength;
    }
    for(i = 0; i < X->m_nLength; i++)
    {
        sum = A->m_ulValue[i];
        sum = sum + X->m_ulValue[i] + carry;
        X->m_ulValue[i] = (U16)sum;
        carry = (U16)(sum >> 16);
    }
    X->m_ulValue[X->m_nLength] = carry;
    X->m_nLength += carry;
    return X;
}

static CBigInt *Add_Big_Long(CBigInt *X, U32 A)
{
    U32 sum;
    sum = X->m_ulValue[0];
    sum += A;
    X->m_ulValue[0] = (U16)sum;
    if(sum > CARRYLAST)
    {
        U32 i = 1;
        while(X->m_ulValue[i] == CARRYLAST)
        {
            X->m_ulValue[i] = 0;
            i++;
        }
        X->m_ulValue[i]++;
        if(X->m_nLength == i)
            X->m_nLength++;
    }
    return X;
}

/****************************************************************************************
大数相减
调用形式：Sub_Big_Big(X,A)
返回值：X=X-A
****************************************************************************************/
static CBigInt *Sub_Big_Big(CBigInt *X, CBigInt *A)
{
    if(Cmp(X, A) <= 0)
    {
        memset(X, 0, sizeof(CBigInt));
        return X;
    }
    else
    {
        U16 carry = 0;
        U32 num;
        U32 i;
        for(i = 0; i < X->m_nLength; i++)
        {
            if((X->m_ulValue[i] > A->m_ulValue[i]) || ((X->m_ulValue[i] == A->m_ulValue[i]) && (carry == 0)))
            {
                X->m_ulValue[i] = X->m_ulValue[i] - carry - A->m_ulValue[i];
                carry = 0;
            }
            else
            {
                num = CARRYOVER + X->m_ulValue[i];
                X->m_ulValue[i] = (U32)(num - carry - A->m_ulValue[i]);
                carry = 1;
            }
        }
        while(X->m_ulValue[X->m_nLength - 1] == 0)
            X->m_nLength--;
        return X;
    }
}

static CBigInt *Sub_Big_Long(CBigInt *X, U32 A)
{
    if(X->m_ulValue[0] >= A)
    {
        X->m_ulValue[0] -= A;
        return X;
    }
    if(X->m_nLength == 1)
    {
        memset(X, 0, sizeof(CBigInt));
        return X;
    }
    else
    {
        U32 num = CARRYOVER + X->m_ulValue[0];
        int i = 1;
        X->m_ulValue[0] = (U16)(num - A);
        while(X->m_ulValue[i] == 0)
        {
            X->m_ulValue[i] = CARRYLAST;
            i++;
        }
        X->m_ulValue[i]--;
        if(X->m_ulValue[i] == 0)
            X->m_nLength--;
        return X;
    }
}

/****************************************************************************************
大数相乘
调用形式：Mul_Big_Big(N,A)
返回值：X=N*A
	A	a 0
	N	c d
		0					d*0
		1			c*0
					d*a
		2	c*a

****************************************************************************************/
static CBigInt *Mul_Big_Big(CBigInt *X, CBigInt *A)
{
    if(A->m_nLength == 1)
    {
        return Mul_Big_Long(X, A->m_ulValue[0]);
    }
    else
    {
        U32 sum, mul = 0, carry = 0;
        U32 i, j;
        CBigInt N = {0};
        memcpy(&N, X, sizeof(CBigInt));
        memset(X, 0, sizeof(CBigInt));
        X->m_nLength = N.m_nLength + A->m_nLength - 1;
        for(i = 0; i < X->m_nLength; i++)
        {
            sum = carry;
            carry = 0;
            for(j = 0; j < A->m_nLength; j++)
            {
                if(((i - j) >= 0) && ((i - j) < N.m_nLength))
                {
                    mul = N.m_ulValue[i - j];
                    mul *= A->m_ulValue[j];
                    carry += mul >> 16;
                    mul = mul & CARRYLAST;
                    sum += mul;
                }
            }
            carry += sum >> 16;
            X->m_ulValue[i] = (U16)sum;
        }
        if(carry)
        {
            X->m_nLength++;
            X->m_ulValue[X->m_nLength - 1] = (U16)carry;
        }
        return X;
    }
}

static CBigInt *Mul_Big_Long(CBigInt *X, U32 A)
{
    U32 mul;
    U32 carry = 0;
    U32 i;
    for(i = 0; i < X->m_nLength; i++)
    {
        mul = X->m_ulValue[i];
        mul = mul * A + carry;
        X->m_ulValue[i] = (U16)mul;
        carry = (U16)(mul >> 16);
    }
    if(carry)
    {
        X->m_nLength++;
        X->m_ulValue[X->m_nLength - 1] = carry;
    }
    return X;
}

/****************************************************************************************
大数相除
调用形式：Div_Big_Big(N,A)
返回值：X=N/A
****************************************************************************************/
static CBigInt *Div_Big_Big(CBigInt *X, CBigInt *A)
{
    CBigInt Y = {0}, Z = {0}, T;
    if(A->m_nLength == 1)
    {
        return Div_Big_Long(X, A->m_ulValue[0]);
    }
    else
    {
        U32 i, len;
        U32 num, div;
        memcpy(&Y, X, sizeof(CBigInt));
        while(Cmp(&Y, A) >= 0)
        {
            div = Y.m_ulValue[Y.m_nLength - 1];
            num = A->m_ulValue[A->m_nLength - 1];
            len = Y.m_nLength - A->m_nLength;
            if((div == num) && (len == 0))
            {
                Add_Big_Long(X, 1);
                break;
            }
            if((div <= num) && len)
            {
                len--;
                div = (div << 16) + Y.m_ulValue[Y.m_nLength - 2];
            }
            div = div / (num + 1);
            Mov_Big_Long(&Z, div);
            if(len)
            {
                Z.m_nLength += len;
                for(i = Z.m_nLength - 1; i >= len; i--)
                    Z.m_ulValue[i] = Z.m_ulValue[i - len];
                for(i = 0; i < len; i++)
                    Z.m_ulValue[i] = 0;
            }
            Add_Big_Big(X, &Z);
            memcpy(&T, A, sizeof(CBigInt));
            Mul_Big_Big(&T, &Z);
            Sub_Big_Big(&Y, &T);
        }
        return X;
    }
}
static CBigInt *Div_Big_Long(CBigInt *X, U32 A)
{
    if(X->m_nLength == 1)
    {
        X->m_ulValue[0] = X->m_ulValue[0] / A;
        return X;
    }
    else
    {
        U32 div, mul;
        U32 carry = 0;
        int i;
        for(i = X->m_nLength - 1; i >= 0; i--)
        {
            div = carry;
            div = (div << 16) + X->m_ulValue[i];
            X->m_ulValue[i] = (U16)(div / A);
            mul = (div / A) * A;
            carry = (U16)(div - mul);
        }
        if(X->m_ulValue[X->m_nLength - 1] == 0)
            X->m_nLength--;
        return X;
    }
}

/****************************************************************************************
大数求模
调用形式：Mod_Big_Big(N,A)
返回值：X=N%A
****************************************************************************************/
static CBigInt *Mod_Big_Big(CBigInt *X, CBigInt *A)
{
    CBigInt Y = {0}, Z;
    U32 div, num;
    U32 carry = 0;
    U32 i, len;
    while(Cmp(X, A) >= 0)
    {
        div = X->m_ulValue[X->m_nLength - 1];
        num = A->m_ulValue[A->m_nLength - 1];
        len = X->m_nLength - A->m_nLength;
        if((div == num) && (len == 0))
        {
            Sub_Big_Big(X, A);
            break;
        }
        if((div <= num) && len)
        {
            len--;
            div = (div << 16) + X->m_ulValue[X->m_nLength - 2];
        }
        div = div / (num + 1);
        Mov_Big_Long(&Y, div);
        memcpy(&Z, A, sizeof(CBigInt));
        Mul_Big_Big(&Z, &Y);
        memcpy(&Y, &Z, sizeof(CBigInt));
        if(len)
        {
            Y.m_nLength += len;
            for(i = Y.m_nLength - 1; i >= len; i--)
                Y.m_ulValue[i] = Y.m_ulValue[i - len];
            for(i = 0; i < len; i++)
                Y.m_ulValue[i] = 0;
        }
        Sub_Big_Big(X, &Y);
    }
    return X;
}

static U32 Mod_Big_Long(CBigInt *N, U32 A)
{
    if(N->m_nLength == 1)
        return(N->m_ulValue[0] % A);
    else
    {
        U32 div;
        U32 carry = 0;
        int i;
        for(i = N->m_nLength - 1; i >= 0; i--)
        {
            div = N->m_ulValue[i];
            div += carry * CARRYOVER;
            carry = (U16)(div % A);
        }
        return carry;
    }
}

/****************************************************************************************
从字符串按10进制或16进制格式输入到大数
调用格式：Get(N,str,sys)
返回值：N被赋值为相应大数
sys暂时只能为10或16
****************************************************************************************/
static CBigInt *Get(CBigInt *N, char *s, U32 system)
{
    int i;
    int len = strlen(s), k;
    memset(N, 0, sizeof(CBigInt));
    N->m_nLength = 1;
    for(i = 0; i < len; i++)
    {
        Mul_Big_Long(N, system);
        if((s[i] >= '0') && (s[i] <= '9'))
            k = s[i] - 48;
        else if((s[i] >= 'A') && (s[i] <= 'F'))
            k = s[i] - 55;
        else if((s[i] >= 'a') && (s[i] <= 'f'))
            k = s[i] - 87;
        else k = 0;
        Add_Big_Long(N, k);
    }
    return N;
}
static CBigInt *GetHex(CBigInt *N, unsigned char *s, unsigned short len, U32 system)
{
    int i, j;
    unsigned char *p = (unsigned char*)N->m_ulValue;
    memset(N, 0, sizeof(CBigInt));
    N->m_nLength = 1;
    for(i = len - 1, j = 0; i >= 0; i--, j++)
    {
        p[j] = s[i];
    }
    i = len % 2;
    if(i > 0) N->m_nLength = len / 2 + 1;
    else N->m_nLength = len / 2;
    return N;
}
/****************************************************************************************
将大数按10进制或16进制格式输出为字符串
调用格式：Put(N,str,sys)
返回值：无，参数str被赋值为N的sys进制字符串
sys暂时只能为10或16
****************************************************************************************/
static char *Put(CBigInt *N, U32 system)
{
    char t[17] = "0123456789ABCDEF";
    int i, a;
    static char s[2048];

    if((N->m_nLength == 1) && (N->m_ulValue[0] == 0))
    {
        return NULL;
    }
    else
    {
        CBigInt X = {0};
        memcpy(&X, N, sizeof(CBigInt));
        memset(s, 0, 2048);
        for(i = 2046; X.m_ulValue[X.m_nLength - 1] > 0 && i > 0; i--)
        {
            a = Mod_Big_Long(&X, system);
            s[i] = t[a];
            Div_Big_Long(&X, system);
        }
        if(i % 2 == 0)
        {
            return &s[i + 1];
        }
        else
        {
            s[i] = '0';
            return &s[i];
        }
    }
}

static void PutHex(CBigInt *N, U8 *out, U16 *len)
{
    int i, j, size;
    if((N->m_nLength == 1) && (N->m_ulValue[0] == 0))
    {
        return;
    }
    size = N->m_nLength * sizeof(N->m_ulValue[0]);
    for(i = size - 1, j = 0; i >= 0; i--, j++)
    {
        out[j] = ((U8*)N->m_ulValue)[i];
    }
    *len = size;
}

/****************************************************************************************
求不定方程ax-by=1的最小整数解
调用方式：Euc(N,A)
返回值：X,满足：NX mod A=1
****************************************************************************************/
static CBigInt *Euc(CBigInt *X, CBigInt *A)
{
    CBigInt M = {0}, E = {0}, N = {0}, Y = {0}, I = {0}, J = {0};
    int x, y;
    memcpy(&E, X, sizeof(CBigInt));
    memcpy(&M, A, sizeof(CBigInt));
    Mov_Big_Long(X, 0);
    Mov_Big_Long(&Y, 1);
    x = y = 1;
    while((E.m_nLength != 1) || (E.m_ulValue[0] != 0))
    {
        memcpy(&I, &M, sizeof(CBigInt));
        Div_Big_Big(&I, &E);
        memcpy(&J, &M, sizeof(CBigInt));
        Mod_Big_Big(&J, &E);
        memcpy(&M, &E, sizeof(CBigInt));
        memcpy(&E, &J, sizeof(CBigInt));
        memcpy(&J, &Y, sizeof(CBigInt));
        Mul_Big_Big(&Y, &I);
        if(x == y)
        {
            if(Cmp(X, &Y) >= 0)
                Sub_Big_Big(&Y, X);
            else
            {
                Sub_Big_Big(&Y, X);
                y = 0;
            }
        }
        else
        {
            Add_Big_Big(&Y, X);
            x = 1 - x;
            y = 1 - y;
        }
        memcpy(X, &J, sizeof(CBigInt));
    }
    if(x == 0)
        Sub_Big_Big(X, A);
    return X;
}

/****************************************************************************************
求乘方的模
调用方式：RsaTrans(N,A,B)
返回值：X=N^A MOD B
****************************************************************************************/
static CBigInt *RsaTrans(CBigInt *X, CBigInt *A, CBigInt *B)
{
    CBigInt N = {0}, Y = {0}, Z;
    int i, j, k;
    U32 n;
    U32 num;
    k = A->m_nLength * 16 - 16;
    num = A->m_ulValue[A->m_nLength - 1];
    while(num)
    {
        num = num >> 1;
        k++;
    }
    memcpy(&N, X, sizeof(CBigInt));
    for(i = k - 2; i >= 0; i--)
    {
        memcpy(&Y, X, sizeof(CBigInt));
        Mul_Big_Long(&Y, X->m_ulValue[X->m_nLength - 1]);
        Mod_Big_Big(&Y, B);
        for(n = 1; n < X->m_nLength; n++)
        {
            for(j = Y.m_nLength; j > 0; j--)
                Y.m_ulValue[j] = Y.m_ulValue[j - 1];
            Y.m_ulValue[0] = 0;
            Y.m_nLength++;
            memcpy(&Z, X, sizeof(CBigInt));
            Mul_Big_Long(&Z, X->m_ulValue[X->m_nLength - n - 1]);
            Add_Big_Big(&Y, &Z);
            Mod_Big_Big(&Y, B);
        }
        memcpy(X, &Y, sizeof(CBigInt));
        if((A->m_ulValue[i >> 4] >> (i & 15)) & 1)
        {
            memcpy(&Y, &N, sizeof(CBigInt));
            Mul_Big_Long(&Y, X->m_ulValue[X->m_nLength - 1]);
            Mod_Big_Big(&Y, B);
            for(n = 1; n < X->m_nLength; n++)
            {
                for(j = Y.m_nLength; j > 0; j--)
                    Y.m_ulValue[j] = Y.m_ulValue[j - 1];
                Y.m_ulValue[0] = 0;
                Y.m_nLength++;
                memcpy(&Z, &N, sizeof(CBigInt));
                Mul_Big_Long(&Z, X->m_ulValue[X->m_nLength - n - 1]);
                Add_Big_Big(&Y, &Z);
                Mod_Big_Big(&Y, B);
            }
            memcpy(X, &Y, sizeof(CBigInt));
        }
    }
    return X;
}

/****************************************************************************************
拉宾米勒算法测试素数
调用方式：Rab(N)
返回值：若N为素数，返回1，否则返回0
****************************************************************************************/
static int Rab(CBigInt *N)
{
    CBigInt S = {0}, A = {0}, I = {0}, K = {0};
    U32 i, j, pass;
    for(i = 0; i < 550; i++)
    {
        if(Mod_Big_Long(N, PrimeTable[i]) == 0)
            return 0;
    }
    memcpy(&K, N, sizeof(CBigInt));
    K.m_ulValue[0]--;
    for(i = 0; i < 5; i++)
    {
        pass = 0;
        Mov_Big_Long(&A, rand()*rand());
        memcpy(&S, &K, sizeof(CBigInt));
        while((S.m_ulValue[0] & 1) == 0)
        {
            for(j = 0; j < S.m_nLength; j++)
            {
                S.m_ulValue[j] = S.m_ulValue[j] >> 1;
                if(S.m_ulValue[j + 1] & 1)
                    S.m_ulValue[j] = S.m_ulValue[j] | 0x8000;
            }
            if(S.m_ulValue[S.m_nLength - 1] == 0)
                S.m_nLength--;
            memcpy(&I, &A, sizeof(CBigInt));
            RsaTrans(&I, &S, N);
            if(Cmp(&I, &K) == 0)
            {
                pass = 1;
                break;
            }
        }
        if((I.m_nLength == 1) && (I.m_ulValue[0] == 1))
            pass = 1;
        if(pass == 0)
            return 0;
    }
    return 1;
}

/****************************************************************************************
产生随机素数
调用方法：GetPrime(N,bits)
返回值：N,被赋值为一个bits位（0x100000000进制长度）的素数
****************************************************************************************/
static CBigInt *GetPrime(CBigInt *N, int bits)
{
    U32 i;
    CBigInt S = {0}, A = {0}, I = {0}, K = {0};

    memset(N, 0, sizeof(CBigInt));
    N->m_nLength = bits;
begin:
    srand((int)clock());
    for(i = 0; i < N->m_nLength; i++)
    {
        N->m_ulValue[i] = rand() * 0x100 + rand();
    }
    N->m_ulValue[0] = N->m_ulValue[0] | 1;
    for(i = N->m_nLength - 1; i > 0; i--)
    {
        N->m_ulValue[i] = N->m_ulValue[i] << 1;
        if(N->m_ulValue[i - 1] & 0x8000)
            N->m_ulValue[i]++;
    }
    N->m_ulValue[0] = N->m_ulValue[0] << 1;
    N->m_ulValue[0]++;
    for(i = 0; i < 550; i++)
    {
        if(Mod_Big_Long(N, PrimeTable[i]) == 0)
            goto begin;
    }
    memcpy(&K, N, sizeof(CBigInt));
    K.m_ulValue[0]--;
    for(i = 0; i < 5; i++)
    {
        Mov_Big_Long(&A, rand()*rand());
        memcpy(&S, &K, sizeof(CBigInt));
        Div_Big_Long(&S, 2);
        memcpy(&I, &A, sizeof(CBigInt));
        RsaTrans(&I, &S, N);
        if(((I.m_nLength != 1) || (I.m_ulValue[0] != 1)) && (Cmp(&I, &K) != 0))
            goto begin;
    }
    return N;
}

/***********************************************************************/
/***********************************************************************/
extern void printf_hex(unsigned char *data, unsigned int len);

static void entropy_poll(unsigned char *output, unsigned int len)
{
    if(len > 0)
    {
        int i;
        OTA_srand( kal_get_systicks() );
        for (i = 0; i < len; i++){
            output[i] = OTA_rand() % 0xff + 1;
        }
    }
}
static char *del_PKCS1Padding(char *src)
{
    int len = strlen(src);
    if(len % 2 == 1)
    {
        src++;
    }
    while(*src != 0 && *(src + 1) != 0)
    {
        if(*src == '0' && *(src + 1) == '0')
        {
            src += 2;
            break;
        }
        src += 2;
    }
    return src;
}
static int add_PKCS1Padding(unsigned char *src, unsigned int len, unsigned char *out)
{
    if(len > 128 - 11)
        return -1;
    else
    {
        /*要加密的msg*/
        memcpy(&out[128-len], src, len);
        out[0] = 0;
        out[1] = 2;
        /*至少8字节的随机数*/
        entropy_poll(&out[2], 128 - 3 - len);
        out[128-len - 1] = 0;
        return 0;
    }
}
static int PKCS1PKCS1PaddingHexRemove(unsigned char *input, unsigned short *len, unsigned char *output)
{
    if(input[0] == 0 && (input[1] == 1 || input[1] == 2))
    {
        int i;
        for(i = 2; i < *len; i++)
        {
            if(input[i] == 0)
            {
                *len -= (i + 1);
                memcpy(output, &input[i+1], *len);
                return *len;
            }
        }
    }
    return -1;
}

int RSA2048_ECB_PKCS1Padding_Encode(unsigned char *data, unsigned short len, unsigned char *out, char *publicKey, char *Modulus)
{
    unsigned char buf[128];
    CBigInt N, E;
    CBigInt mw, mi, jm;
    U16 outlen = 128;
/*
    printf("正在运算生成随机数，需要耗费点时间，应稍后...\r\n");
    CBigInt P;
    GetPrime(&P, 64/8);
    printf("随机生成p为%s\r\n\r\n", Put(&P, HEX));
*/
    Get(&N, Modulus, 16);
    Get(&E, publicKey, 16);

    add_PKCS1Padding(data, len, buf);

    if(0)
    {
        unsigned char tmp[550];
        HexToString(buf, 128, tmp);
        Get(&mw, tmp, 16);
    }
    else
    {
        GetHex(&mw, buf, 128, 16);
    }

    RsaTrans(&mw, &E, &N);

    PutHex(&mw, out, &outlen);
    return 0;
}

int RSA2048_ECB_PKCS1Padding_Encode2(unsigned char *data, unsigned short len, unsigned char *out, char *publicKey, unsigned char *ModulusHex)
{
    unsigned char buf[128];
    CBigInt N, E;
    CBigInt mw, mi, jm;
    U16 outlen = 128;
/*
    printf("正在运算生成随机数，需要耗费点时间，应稍后...\r\n");
    CBigInt P;
    GetPrime(&P, 64/8);
    printf("随机生成p为%s\r\n\r\n", Put(&P, HEX));
*/
    //Get(&N, Modulus, 16);
    GetHex(&N, ModulusHex, 128, 16);//256->294
    Get(&E, publicKey, 16);

    add_PKCS1Padding(data, len, buf);

    GetHex(&mw, buf, 128, 16);

    RsaTrans(&mw, &E, &N);

    PutHex(&mw, out, &outlen);
    LOGD(5, L_V5, "加密:%d",outlen);
    return outlen;
}

int RSA2048_ECB_PKCS1Padding_Decode(unsigned char *data, unsigned short *len, unsigned char *out, char *privateKey, char *Modulus)
{
    unsigned char buf[128], tmp[550];
    CBigInt N, D;
    CBigInt mw, jm;

    Get(&N, Modulus, 16);
    Get(&D, privateKey, 16);

    if(0)
    {
        HexToString(data, *len, tmp);
        Get(&mw, tmp, 16);
    }
    else
    {
        GetHex(&mw, data, *len, 16);
    }

    RsaTrans(&mw, &D, &N);
    PutHex(&mw, buf, len);
    PKCS1PKCS1PaddingHexRemove(buf, len, out);
    return 0;
}
int RSA2048_ECB_PKCS1Padding_Decode2(unsigned char *data, unsigned short *len, unsigned char *out, char *privateKey, unsigned char *ModulusHex)
{
    unsigned char buf[128];//, tmp[550];
    CBigInt N, D;
    CBigInt mw, jm;
	int t_len = 0;

    //Get(&N, Modulus, 16);
    GetHex(&N, ModulusHex, 128, 16);
    Get(&D, privateKey, 16);

/*    if(0)
    {
        HexToString(data, *len, tmp);
        Get(&mw, tmp, 16);
    }
    else
    {*/
        GetHex(&mw, data, *len, 16);
    //}

    RsaTrans(&mw, &D, &N);
    PutHex(&mw, buf, len);
    LOGD(5, L_V5, "%d",*len);
    t_len = PKCS1PKCS1PaddingHexRemove(buf, len, out);
    LOGD(5, L_V5, "解密:%d",t_len);
    return t_len;
}
static void RSA_data_handle_rsp(void *msg)
{
	int buffLength = 0;
	unsigned short sendLength = 0;
	kal_uint8 outBuffTemp[128];
	rsa_data_struct *par = (rsa_data_struct*)msg;
	rsa_data_struct *myMsgPtr = NULL;
	myMsgPtr = (rsa_data_struct*) construct_local_para(sizeof(rsa_data_struct), TD_RESET);
	sendLength = par->dataLength;
	if(par->rsaType == 0)
	{
		buffLength = RSA2048_ECB_PKCS1Padding_Decode2(par->dataBuffer, &sendLength, outBuffTemp, publicKey, keyContent);
	}
	else if(par->rsaType == 1)
	{
	  	buffLength = RSA2048_ECB_PKCS1Padding_Encode2(par->dataBuffer, sendLength, outBuffTemp, publicKey, keyContent);
	}
	myMsgPtr->rsaType = par->rsaType;
	myMsgPtr->dataLength = buffLength;
	memcpy(myMsgPtr->dataBuffer,outBuffTemp, buffLength);
	track_fun_msg_send(MSG_ID_DATA_RSA_TO_TRACK_IND, myMsgPtr, MOD_AGENT, MOD_MMI);
}
void RSA_data_handle_req(kal_uint8 len,kal_uint8 *data,kal_uint8 rsatype)
{
	rsa_data_struct *myMsgPtr = NULL;
	myMsgPtr = (rsa_data_struct*) construct_local_para(sizeof(rsa_data_struct), TD_RESET);
	myMsgPtr->rsaType = rsatype;
	myMsgPtr->dataLength = len;
	memcpy(myMsgPtr->dataBuffer, data, len);
	track_fun_msg_send(MSG_ID_DATA_TRACK_TO_RSA_REQ, myMsgPtr, MOD_MMI, MOD_AGENT);
}
void RSA_data_handle_result_receive(void* msg)
{
    rsa_data_struct *rsa_data = (rsa_data_struct *)msg;
	LOGD(L_APP, L_V5, "len:%d,%d",rsa_data->dataLength,rsa_data->rsaType);
	LOGH(L_APP, L_V5, rsa_data->dataBuffer, rsa_data->dataLength);
	if(rsa_data->rsaType == 1)//加密
	{
		track_cust_NO7_packet_00_encode_msg(rsa_data->dataBuffer, rsa_data->dataLength,0x02);
	}
	else
	{
		track_cust_NO7_packet_00_decode_msg(rsa_data->dataBuffer, rsa_data->dataLength);
	}
}
void track_rsa_main(ilm_struct *ilm_ptr)
{	
	//LOGD(L_APP, L_V5, "msg_id=MSG_ID_DATA_TRACK_TO_RSA_REQ");
	switch(ilm_ptr->msg_id)
	{
		case MSG_ID_DATA_TRACK_TO_RSA_REQ:
			LOGD(L_SYS, L_V5, "msg_id=MSG_ID_DATA_TRACK_TO_RSA_REQ");
			RSA_data_handle_rsp(ilm_ptr->local_para_ptr);
			break;
		default:
			break;
	}
}
void track_cust_keycontent_init()
{
	memcpy(keyContent, G_parameter.ste_param.publickey, 128);
}
#if 0
void rsa_test_cml(void)
{
    unsigned short len = 256;
    U32 tick = OTA_kal_get_systicks();
    char *publicKey = "10001";
    unsigned char ModulusHex[256] = {
        0x9E, 0xE6, 0xEF, 0x13, 0x83, 0x03, 0x27, 0x1E, 0x4E, 0x1D, 0x95, 0x72, 0x80, 0x5D, 0xEA, 0xAD, 
        0x89, 0xF6, 0xEB, 0xA0, 0xC8, 0x1B, 0xD0, 0x9B, 0x6A, 0x56, 0x36, 0x0C, 0xFC, 0x78, 0x3A, 0x87, 
        0xB5, 0x3A, 0xBB, 0xC3, 0x17, 0x70, 0x0A, 0x3A, 0xF7, 0xEF, 0x14, 0x19, 0x6B, 0x41, 0xA7, 0x82, 
        0x4E, 0xAA, 0x08, 0x19, 0x57, 0x55, 0xEC, 0x75, 0xD0, 0x68, 0x2A, 0xA0, 0x82, 0x15, 0x49, 0x24, 
        0xCF, 0x2D, 0x10, 0x2A, 0x49, 0xDA, 0xD2, 0x52, 0x7C, 0xCF, 0x23, 0xB5, 0x77, 0x4C, 0x03, 0x65, 
        0xD5, 0xD5, 0xAD, 0xB3, 0xAE, 0x07, 0xE5, 0xB4, 0xE4, 0x04, 0xF1, 0xD5, 0xDB, 0xF1, 0x99, 0xD5, 
        0x10, 0x6F, 0x6E, 0xF8, 0xEF, 0x3C, 0xD5, 0xDF, 0x89, 0x8A, 0x65, 0x8C, 0xBD, 0xDB, 0xE6, 0xD4, 
        0xAB, 0x85, 0x7D, 0x36, 0x8A, 0xE6, 0x5B, 0xF6, 0xF2, 0xFC, 0xC3, 0x7B, 0x3B, 0x0F, 0x25, 0x89, 
        0x68, 0x2D, 0xF8, 0x98, 0xFD, 0xFA, 0x11, 0x3C, 0xC5, 0xE6, 0xE3, 0x14, 0x28, 0x79, 0x9F, 0x31, 
        0xBE, 0x36, 0xEF, 0x36, 0xE2, 0xA1, 0xDD, 0x99, 0x12, 0x1B, 0x63, 0x27, 0xE6, 0xC2, 0xEB, 0x36, 
        0xEE, 0x63, 0x1F, 0x41, 0xD7, 0x4D, 0x56, 0x23, 0x45, 0x6C, 0xE4, 0xCC, 0xF8, 0xFC, 0x85, 0x4E, 
        0x19, 0x5D, 0x25, 0x41, 0x60, 0x59, 0x1E, 0x95, 0x5B, 0xC8, 0xAA, 0x75, 0x0E, 0x7B, 0x1B, 0x7C, 
        0x54, 0x5F, 0xAA, 0xA3, 0xC9, 0xD6, 0x2C, 0xE9, 0x5D, 0x0E, 0x85, 0x24, 0x82, 0xAC, 0x90, 0x4F, 
        0x3B, 0x51, 0xA3, 0x74, 0xBC, 0xE3, 0x12, 0x58, 0x51, 0xCC, 0x22, 0x8E, 0x0D, 0x18, 0xEF, 0xB2, 
        0xFF, 0x9F, 0xC0, 0xF5, 0xF5, 0xD5, 0x69, 0x30, 0x0C, 0xC4, 0x01, 0x58, 0xCB, 0x89, 0x7A, 0x58, 
        0x29, 0xAC, 0x6E, 0xF1, 0x43, 0x6B, 0x61, 0xBB, 0xBB, 0xE4, 0x3E, 0x10, 0x11, 0x6B, 0x43, 0x31
    };
    unsigned char data[256] = {
        0x7E, 0x61, 0x03, 0x47, 0x62, 0xB8, 0xA3, 0x12, 0x0D, 0x57, 0xFC, 0xE0, 0x3A, 0xE9, 0x3A, 0x9F, 
        0x43, 0x6B, 0xFA, 0xE4, 0x6C, 0xA2, 0xED, 0x0E, 0xE7, 0x17, 0xEB, 0x7D, 0xBA, 0xF9, 0xB5, 0xBF, 
        0xEA, 0xE6, 0x47, 0xF7, 0xF5, 0x72, 0xA5, 0x22, 0x0C, 0xED, 0xAF, 0xF9, 0x71, 0x91, 0x03, 0x34, 
        0x18, 0x5F, 0xED, 0xB6, 0x2A, 0xF4, 0x12, 0xBC, 0x78, 0x45, 0x71, 0x4C, 0x8F, 0x9F, 0x9D, 0xC0, 
        0xED, 0xF3, 0xCE, 0xC2, 0x3E, 0x2F, 0xD8, 0x57, 0xA2, 0x47, 0x1D, 0xD3, 0xB1, 0x92, 0xD4, 0x2F, 
        0xAD, 0x1E, 0x9D, 0x4E, 0xAA, 0xC1, 0xA5, 0xEB, 0xE0, 0xB8, 0x71, 0x20, 0x8C, 0x37, 0x8A, 0x1E, 
        0x76, 0xD0, 0x4B, 0xD0, 0xCD, 0x19, 0x4F, 0x40, 0xE4, 0x31, 0x6F, 0xE4, 0xB7, 0xE6, 0x3B, 0x2E, 
        0x8A, 0xE7, 0x6F, 0x59, 0x72, 0xCF, 0x5B, 0x1C, 0x6B, 0xA6, 0x16, 0xB9, 0x65, 0xEC, 0x6E, 0xFF, 
        0x50, 0x14, 0xFE, 0x26, 0x61, 0xB2, 0x1D, 0xC6, 0xF6, 0xB1, 0xCC, 0x6D, 0xC8, 0x16, 0xA7, 0x38, 
        0x1C, 0x61, 0xF1, 0x24, 0x40, 0x9D, 0xBF, 0xEB, 0x7F, 0x97, 0xDA, 0xF0, 0x60, 0x90, 0x95, 0x5A, 
        0x9D, 0x1D, 0x26, 0xD4, 0x50, 0xF3, 0x22, 0x4C, 0xE7, 0x30, 0x50, 0x27, 0x00, 0xC8, 0x23, 0xFE, 
        0x3D, 0x8A, 0x5C, 0xD4, 0x0B, 0x0B, 0x67, 0x3E, 0x5C, 0x77, 0xA7, 0x1F, 0x97, 0x01, 0xF4, 0x3F, 
        0xE6, 0x8D, 0x44, 0xF1, 0xAF, 0x75, 0x5C, 0x0C, 0x11, 0x34, 0x97, 0x58, 0x9A, 0xEE, 0xBF, 0x7A, 
        0xF0, 0x2E, 0x0D, 0xC6, 0xD7, 0x01, 0xDE, 0xE8, 0x8D, 0xC7, 0x41, 0xA7, 0xF1, 0x11, 0xD8, 0x27, 
        0xC8, 0x4D, 0xFA, 0x44, 0x5A, 0x7A, 0xD2, 0x24, 0x8A, 0x28, 0xAC, 0x52, 0x9D, 0xBD, 0x6B, 0xC5, 
        0x89, 0x2A, 0x6E, 0xEE, 0xCD, 0x05, 0xE1, 0xD3, 0x50, 0xE0, 0x6F, 0x10, 0x6B, 0x0B, 0x72, 0x64
    };
    unsigned char out[256]={0};

    LOGD(L_APP, L_V1, "Begin...");
    RSA2048_ECB_PKCS1Padding_Decode2(data, &len, out, publicKey, ModulusHex);
    tick = OTA_kal_get_systicks() - tick;
    LOGD(L_APP, L_V1, "耗时:%dms", kal_ticks_to_milli_secs(tick));
    LOGH(L_APP, L_V1, out, len);
}
#endif

#endif /* 0 */

#if 0
/*******************************************************************************************
 * Filename:    
 * Author :     
 * Date :       
 * Comment:     
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "custom_nvram_editor_data_item.h"
#include "app_datetime.h"

#include "track_os_data_types.h"
#include "track_os_log.h"
#include "track_os_ell.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
#define BI_MAXLEN 130
#define DEC 10
#define HEX 16

#define  CARRYOVER  0x10000
#define  CARRYLAST   0xFFFF
/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    U32 m_nLength;    //大数在0x1 00 00 00 00进制下的长度
    U16 m_ulValue[BI_MAXLEN];    //用数组记录大数在0x100000000进制下每一位的值
} CBigInt;

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
/*****************************************************************
基本操作与运算
Init, 构造大数对象并初始化为零
Mov，赋值运算，可赋值为大数或普通整数，可重载为运算符“=”
Cmp，比较运算，可重载为运算符“==”、“!=”、“>=”、“<=”等
Add，加，求大数与大数或大数与普通整数的和，可重载为运算符“+”
Sub，减，求大数与大数或大数与普通整数的差，可重载为运算符“-”
Mul，乘，求大数与大数或大数与普通整数的积，可重载为运算符“*”
Div，除，求大数与大数或大数与普通整数的商，可重载为运算符“/”
Mod，模，求大数与大数或大数与普通整数的模，可重载为运算符“%”
*****************************************************************/
static CBigInt *Mov_Big_Long(CBigInt *X, U32 A);
static CBigInt *Mov_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Add_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Sub_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Mul_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Div_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Mod_Big_Big(CBigInt *X, CBigInt *A);
static CBigInt *Add_Big_Long(CBigInt *X, U32 A);
static CBigInt *Sub_Big_Long(CBigInt *X, U32 A);
static CBigInt *Mul_Big_Long(CBigInt *X, U32 A);
static CBigInt *Div_Big_Long(CBigInt *X, U32 A);
static U32 Mod_Big_Long(CBigInt *N, U32 A);
static int Cmp(CBigInt *N, CBigInt *A);

/*****************************************************************
输入输出
Get，从字符串按10进制或16进制格式输入到大数
Put，将大数按10进制或16进制格式输出到字符串
*****************************************************************/
static CBigInt *Get(CBigInt *N, char *str, U32 system);
static char *Put(CBigInt *N, U32 system);

/*****************************************************************
RSA相关运算
Rab，拉宾米勒算法进行素数测试
Euc，欧几里德算法求解同余方程
RsaTrans，反复平方算法进行幂模运算
GetPrime，产生指定长度的随机大素数
*****************************************************************/
static int Rab(CBigInt *N);
static CBigInt *Euc(CBigInt *X, CBigInt *A);
static CBigInt *RsaTrans(CBigInt *X, CBigInt *A, CBigInt *B);
static CBigInt *GetPrime(CBigInt *X, int bits);

/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/*****************************************************************
大数运算库源文件：BigInt.c
作者：afanty@vip.sina.com，xxx
版本：1.2 (2003.5.13)
说明：适用于C，linux系统 1024位RSA运算
*****************************************************************/

//小素数表
const static int PrimeTable[550] =
{
    3,     5,     7,     11,   13,   17,   19,   23,   29,   31,
    37,   41,   43,   47,   53,   59,   61,   67,   71,   73,
    79,   83,   89,   97,   101,   103,   107,   109,   113,   127,
    131,   137,   139,   149,   151,   157,   163,   167,   173,   179,
    181,   191,   193,   197,   199,   211,   223,   227,   229,   233,
    239,   241,   251,   257,   263,   269,   271,   277,   281,   283,
    293,   307,   311,   313,   317,   331,   337,   347,   349,   353,
    359,   367,   373,   379,   383,   389,   397,   401,   409,   419,
    421,   431,   433,   439,   443,   449,   457,   461,   463,   467,
    479,   487,   491,   499,   503,   509,   521,   523,   541,   547,
    557,   563,   569,   571,   577,   587,   593,   599,   601,   607,
    613,   617,   619,   631,   641,   643,   647,   653,   659,   661,
    673,   677,   683,   691,   701,   709,   719,   727,   733,   739,
    743,   751,   757,   761,   769,   773,   787,   797,   809,   811,
    821,   823,   827,   829,   839,   853,   857,   859,   863,   877,
    881,   883,   887,   907,   911,   919,   929,   937,   941,   947,
    953,   967,   971,   977,   983,   991,   997,   1009, 1013, 1019,
    1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069, 1087,
    1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151, 1153,
    1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223, 1229,
    1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 1297,
    1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 1381,
    1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 1453,
    1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 1523,
    1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 1597,
    1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 1663,
    1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 1741,
    1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 1823,
    1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889, 1901,
    1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987, 1993,
    1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053, 2063,
    2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129, 2131,
    2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213, 2221,
    2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287, 2293,
    2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 2371,
    2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 2437,
    2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 2539,
    2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 2621,
    2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 2689,
    2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741, 2749,
    2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 2833,
    2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 2909,
    2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 3001,
    3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 3083,
    3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 3187,
    3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 3259,
    3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 3343,
    3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 3433,
    3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 3517,
    3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571, 3581,
    3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643, 3659,
    3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727, 3733,
    3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821, 3823,
    3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907, 3911,
    3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989, 4001
};

/****************************************************************************************
大数比较
调用方式：Cmp(N,A)
返回值：若N<A返回-1；若N=A返回0；若N>A返回1
****************************************************************************************/
static int Cmp(CBigInt *N, CBigInt *A)
{
    int i;
    if(N->m_nLength > A->m_nLength)
        return 1;
    if(N->m_nLength < A->m_nLength)
        return -1;
    for(i = N->m_nLength - 1; i >= 0; i--)
    {
        if(N->m_ulValue[i] > A->m_ulValue[i])
            return 1;
        if(N->m_ulValue[i] < A->m_ulValue[i])
            return -1;
    }
    return 0;
}

/****************************************************************************************
大数赋值
调用方式：__Mov_Big_Big(A)
返回值：N,被赋值为A
****************************************************************************************/
static CBigInt *Mov_Big_Big(CBigInt *X, CBigInt *A)
{
    memcpy(X, A, sizeof(CBigInt));
    return X;
}

static CBigInt *Mov_Big_Long(CBigInt *N, U32 A)
{
    int i;
    if(A > CARRYLAST)
    {
        N->m_nLength = 2;
        N->m_ulValue[1] = (U16)(A >> 16);
        N->m_ulValue[0] = (U16)A;
    }
    else
    {
        N->m_nLength = 1;
        N->m_ulValue[0] = (U16)A;
    }
    memset((unsigned char*)&N->m_ulValue[N->m_nLength], 0, sizeof(U16) * (BI_MAXLEN-N->m_nLength));
    return N;
}

/****************************************************************************************
大数相加
调用形式：Add_Big_Big(X,A)
返回值：X=X+A
****************************************************************************************/
static CBigInt *Add_Big_Big(CBigInt *X, CBigInt *A)
{
    U32 i;
    U16 carry = 0;
    U32 sum = 0;
    if(X->m_nLength < A->m_nLength)
    {
        X->m_nLength = A->m_nLength;
    }
    for(i = 0; i < X->m_nLength; i++)
    {
        sum = A->m_ulValue[i];
        sum = sum + X->m_ulValue[i] + carry;
        X->m_ulValue[i] = (U16)sum;
        carry = (U16)(sum >> 16);
    }
    X->m_ulValue[X->m_nLength] = carry;
    X->m_nLength += carry;
    return X;
}

static CBigInt *Add_Big_Long(CBigInt *X, U32 A)
{
    U32 sum;
    sum = X->m_ulValue[0];
    sum += A;
    X->m_ulValue[0] = (U16)sum;
    if(sum > CARRYLAST)
    {
        U32 i = 1;
        while(X->m_ulValue[i] == CARRYLAST)
        {
            X->m_ulValue[i] = 0;
            i++;
        }
        X->m_ulValue[i]++;
        if(X->m_nLength == i)
            X->m_nLength++;
    }
    return X;
}

/****************************************************************************************
大数相减
调用形式：Sub_Big_Big(X,A)
返回值：X=X-A
****************************************************************************************/
static CBigInt *Sub_Big_Big(CBigInt *X, CBigInt *A)
{
    if(Cmp(X, A) <= 0)
    {
        memset(X, 0, sizeof(CBigInt));
        return X;
    }
    else
    {
        U16 carry = 0;
        U32 num;
        U32 i;
        for(i = 0; i < X->m_nLength; i++)
        {
            if((X->m_ulValue[i] > A->m_ulValue[i]) || ((X->m_ulValue[i] == A->m_ulValue[i]) && (carry == 0)))
            {
                X->m_ulValue[i] = X->m_ulValue[i] - carry - A->m_ulValue[i];
                carry = 0;
            }
            else
            {
                num = CARRYOVER + X->m_ulValue[i];
                X->m_ulValue[i] = (U32)(num - carry - A->m_ulValue[i]);
                carry = 1;
            }
        }
        while(X->m_ulValue[X->m_nLength - 1] == 0)
            X->m_nLength--;
        return X;
    }
}

static CBigInt *Sub_Big_Long(CBigInt *X, U32 A)
{
    if(X->m_ulValue[0] >= A)
    {
        X->m_ulValue[0] -= A;
        return X;
    }
    if(X->m_nLength == 1)
    {
        memset(X, 0, sizeof(CBigInt));
        return X;
    }
    else
    {
        U32 num = CARRYOVER + X->m_ulValue[0];
        int i = 1;
        X->m_ulValue[0] = (U16)(num - A);
        while(X->m_ulValue[i] == 0)
        {
            X->m_ulValue[i] = CARRYLAST;
            i++;
        }
        X->m_ulValue[i]--;
        if(X->m_ulValue[i] == 0)
            X->m_nLength--;
        return X;
    }
}

/****************************************************************************************
大数相乘
调用形式：Mul_Big_Big(N,A)
返回值：X=N*A
	A	a 0
	N	c d
		0					d*0
		1			c*0
					d*a
		2	c*a

****************************************************************************************/
static CBigInt *Mul_Big_Big(CBigInt *X, CBigInt *A)
{
    if(A->m_nLength == 1)
    {
        return Mul_Big_Long(X, A->m_ulValue[0]);
    }
    else
    {
        U32 sum, mul = 0, carry = 0;
        U32 i, j;
        CBigInt N = {0};
        memcpy(&N, X, sizeof(CBigInt));
        memset(X, 0, sizeof(CBigInt));
        X->m_nLength = N.m_nLength + A->m_nLength - 1;
        for(i = 0; i < X->m_nLength; i++)
        {
            sum = carry;
            carry = 0;
            for(j = 0; j < A->m_nLength; j++)
            {
                if(((i - j) >= 0) && ((i - j) < N.m_nLength))
                {
                    mul = N.m_ulValue[i - j];
                    mul *= A->m_ulValue[j];
                    carry += mul >> 16;
                    mul = mul & CARRYLAST;
                    sum += mul;
                }
            }
            carry += sum >> 16;
            X->m_ulValue[i] = (U16)sum;
        }
        if(carry)
        {
            X->m_nLength++;
            X->m_ulValue[X->m_nLength - 1] = (U16)carry;
        }
        return X;
    }
}

static CBigInt *Mul_Big_Long(CBigInt *X, U32 A)
{
    U32 mul;
    U32 carry = 0;
    U32 i;
    for(i = 0; i < X->m_nLength; i++)
    {
        mul = X->m_ulValue[i];
        mul = mul * A + carry;
        X->m_ulValue[i] = (U16)mul;
        carry = (U16)(mul >> 16);
    }
    if(carry)
    {
        X->m_nLength++;
        X->m_ulValue[X->m_nLength - 1] = carry;
    }
    return X;
}

/****************************************************************************************
大数相除
调用形式：Div_Big_Big(N,A)
返回值：X=N/A
****************************************************************************************/
static CBigInt *Div_Big_Big(CBigInt *X, CBigInt *A)
{
    CBigInt Y = {0}, Z = {0}, T;
    if(A->m_nLength == 1)
    {
        return Div_Big_Long(X, A->m_ulValue[0]);
    }
    else
    {
        U32 i, len;
        U32 num, div;
        memcpy(&Y, X, sizeof(CBigInt));
        while(Cmp(&Y, A) >= 0)
        {
            div = Y.m_ulValue[Y.m_nLength - 1];
            num = A->m_ulValue[A->m_nLength - 1];
            len = Y.m_nLength - A->m_nLength;
            if((div == num) && (len == 0))
            {
                Add_Big_Long(X, 1);
                break;
            }
            if((div <= num) && len)
            {
                len--;
                div = (div << 16) + Y.m_ulValue[Y.m_nLength - 2];
            }
            div = div / (num + 1);
            Mov_Big_Long(&Z, div);
            if(len)
            {
                Z.m_nLength += len;
                for(i = Z.m_nLength - 1; i >= len; i--)
                    Z.m_ulValue[i] = Z.m_ulValue[i - len];
                for(i = 0; i < len; i++)
                    Z.m_ulValue[i] = 0;
            }
            Add_Big_Big(X, &Z);
            memcpy(&T, A, sizeof(CBigInt));
            Mul_Big_Big(&T, &Z);
            Sub_Big_Big(&Y, &T);
        }
        return X;
    }
}
static CBigInt *Div_Big_Long(CBigInt *X, U32 A)
{
    if(X->m_nLength == 1)
    {
        X->m_ulValue[0] = X->m_ulValue[0] / A;
        return X;
    }
    else
    {
        U32 div, mul;
        U32 carry = 0;
        int i;
        for(i = X->m_nLength - 1; i >= 0; i--)
        {
            div = carry;
            div = (div << 16) + X->m_ulValue[i];
            X->m_ulValue[i] = (U16)(div / A);
            mul = (div / A) * A;
            carry = (U16)(div - mul);
        }
        if(X->m_ulValue[X->m_nLength - 1] == 0)
            X->m_nLength--;
        return X;
    }
}

/****************************************************************************************
大数求模
调用形式：Mod_Big_Big(N,A)
返回值：X=N%A
****************************************************************************************/
static CBigInt *Mod_Big_Big(CBigInt *X, CBigInt *A)
{
    CBigInt Y = {0}, Z;
    U32 div, num;
    U32 carry = 0;
    U32 i, len;
    while(Cmp(X, A) >= 0)
    {
        div = X->m_ulValue[X->m_nLength - 1];
        num = A->m_ulValue[A->m_nLength - 1];
        len = X->m_nLength - A->m_nLength;
        if((div == num) && (len == 0))
        {
            Sub_Big_Big(X, A);
            break;
        }
        if((div <= num) && len)
        {
            len--;
            div = (div << 16) + X->m_ulValue[X->m_nLength - 2];
        }
        div = div / (num + 1);
        Mov_Big_Long(&Y, div);
        memcpy(&Z, A, sizeof(CBigInt));
        Mul_Big_Big(&Z, &Y);
        memcpy(&Y, &Z, sizeof(CBigInt));
        if(len)
        {
            Y.m_nLength += len;
            for(i = Y.m_nLength - 1; i >= len; i--)
                Y.m_ulValue[i] = Y.m_ulValue[i - len];
            for(i = 0; i < len; i++)
                Y.m_ulValue[i] = 0;
        }
        Sub_Big_Big(X, &Y);
    }
    return X;
}

static U32 Mod_Big_Long(CBigInt *N, U32 A)
{
    if(N->m_nLength == 1)
        return(N->m_ulValue[0] % A);
    else
    {
        U32 div;
        U32 carry = 0;
        int i;
        for(i = N->m_nLength - 1; i >= 0; i--)
        {
            div = N->m_ulValue[i];
            div += carry * CARRYOVER;
            carry = (U16)(div % A);
        }
        return carry;
    }
}

/****************************************************************************************
从字符串按10进制或16进制格式输入到大数
调用格式：Get(N,str,sys)
返回值：N被赋值为相应大数
sys暂时只能为10或16
****************************************************************************************/
static CBigInt *Get(CBigInt *N, char *s, U32 system)
{
    int i;
    int len = strlen(s), k;
    memset(N, 0, sizeof(CBigInt));
    N->m_nLength = 1;
    for(i = 0; i < len; i++)
    {
        Mul_Big_Long(N, system);
        if((s[i] >= '0') && (s[i] <= '9'))
            k = s[i] - 48;
        else if((s[i] >= 'A') && (s[i] <= 'F'))
            k = s[i] - 55;
        else if((s[i] >= 'a') && (s[i] <= 'f'))
            k = s[i] - 87;
        else k = 0;
        Add_Big_Long(N, k);
    }
    return N;
}
static CBigInt *GetHex(CBigInt *N, unsigned char *s, unsigned short len, U32 system)
{
    int i, j;
    unsigned char *p = (unsigned char*)N->m_ulValue;
    memset(N, 0, sizeof(CBigInt));
    N->m_nLength = 1;
    for(i = len - 1, j = 0; i >= 0; i--, j++)
    {
        p[j] = s[i];
    }
    i = len % 2;
    if(i > 0) N->m_nLength = len / 2 + 1;
    else N->m_nLength = len / 2;
    return N;
}
/****************************************************************************************
将大数按10进制或16进制格式输出为字符串
调用格式：Put(N,str,sys)
返回值：无，参数str被赋值为N的sys进制字符串
sys暂时只能为10或16
****************************************************************************************/
static char *Put(CBigInt *N, U32 system)
{
    char t[17] = "0123456789ABCDEF";
    int i, a;
    static char s[2048];

    if((N->m_nLength == 1) && (N->m_ulValue[0] == 0))
    {
        return NULL;
    }
    else
    {
        CBigInt X = {0};
        memcpy(&X, N, sizeof(CBigInt));
        memset(s, 0, 2048);
        for(i = 2046; X.m_ulValue[X.m_nLength - 1] > 0 && i > 0; i--)
        {
            a = Mod_Big_Long(&X, system);
            s[i] = t[a];
            Div_Big_Long(&X, system);
        }
        if(i % 2 == 0)
        {
            return &s[i + 1];
        }
        else
        {
            s[i] = '0';
            return &s[i];
        }
    }
}

static void PutHex(CBigInt *N, U8 *out, U16 *len)
{
    int i, j, size;
    if((N->m_nLength == 1) && (N->m_ulValue[0] == 0))
    {
        return;
    }
    size = N->m_nLength * sizeof(N->m_ulValue[0]);
    for(i = size - 1, j = 0; i >= 0; i--, j++)
    {
        out[j] = ((U8*)N->m_ulValue)[i];
    }
    *len = size;
}

/****************************************************************************************
求不定方程ax-by=1的最小整数解
调用方式：Euc(N,A)
返回值：X,满足：NX mod A=1
****************************************************************************************/
static CBigInt *Euc(CBigInt *X, CBigInt *A)
{
    CBigInt M = {0}, E = {0}, N = {0}, Y = {0}, I = {0}, J = {0};
    int x, y;
    memcpy(&E, X, sizeof(CBigInt));
    memcpy(&M, A, sizeof(CBigInt));
    Mov_Big_Long(X, 0);
    Mov_Big_Long(&Y, 1);
    x = y = 1;
    while((E.m_nLength != 1) || (E.m_ulValue[0] != 0))
    {
        memcpy(&I, &M, sizeof(CBigInt));
        Div_Big_Big(&I, &E);
        memcpy(&J, &M, sizeof(CBigInt));
        Mod_Big_Big(&J, &E);
        memcpy(&M, &E, sizeof(CBigInt));
        memcpy(&E, &J, sizeof(CBigInt));
        memcpy(&J, &Y, sizeof(CBigInt));
        Mul_Big_Big(&Y, &I);
        if(x == y)
        {
            if(Cmp(X, &Y) >= 0)
                Sub_Big_Big(&Y, X);
            else
            {
                Sub_Big_Big(&Y, X);
                y = 0;
            }
        }
        else
        {
            Add_Big_Big(&Y, X);
            x = 1 - x;
            y = 1 - y;
        }
        memcpy(X, &J, sizeof(CBigInt));
    }
    if(x == 0)
        Sub_Big_Big(X, A);
    return X;
}

/****************************************************************************************
求乘方的模
调用方式：RsaTrans(N,A,B)
返回值：X=N^A MOD B
****************************************************************************************/
static CBigInt *RsaTrans(CBigInt *X, CBigInt *A, CBigInt *B)
{
    CBigInt N = {0}, Y = {0}, Z;
    int i, j, k;
    U32 n;
    U32 num;
    k = A->m_nLength * 16 - 16;
    num = A->m_ulValue[A->m_nLength - 1];
    while(num)
    {
        num = num >> 1;
        k++;
    }
    memcpy(&N, X, sizeof(CBigInt));
    for(i = k - 2; i >= 0; i--)
    {
        memcpy(&Y, X, sizeof(CBigInt));
        Mul_Big_Long(&Y, X->m_ulValue[X->m_nLength - 1]);
        Mod_Big_Big(&Y, B);
        for(n = 1; n < X->m_nLength; n++)
        {
            for(j = Y.m_nLength; j > 0; j--)
                Y.m_ulValue[j] = Y.m_ulValue[j - 1];
            Y.m_ulValue[0] = 0;
            Y.m_nLength++;
            memcpy(&Z, X, sizeof(CBigInt));
            Mul_Big_Long(&Z, X->m_ulValue[X->m_nLength - n - 1]);
            Add_Big_Big(&Y, &Z);
            Mod_Big_Big(&Y, B);
        }
        memcpy(X, &Y, sizeof(CBigInt));
        if((A->m_ulValue[i >> 4] >> (i & 15)) & 1)
        {
            memcpy(&Y, &N, sizeof(CBigInt));
            Mul_Big_Long(&Y, X->m_ulValue[X->m_nLength - 1]);
            Mod_Big_Big(&Y, B);
            for(n = 1; n < X->m_nLength; n++)
            {
                for(j = Y.m_nLength; j > 0; j--)
                    Y.m_ulValue[j] = Y.m_ulValue[j - 1];
                Y.m_ulValue[0] = 0;
                Y.m_nLength++;
                memcpy(&Z, &N, sizeof(CBigInt));
                Mul_Big_Long(&Z, X->m_ulValue[X->m_nLength - n - 1]);
                Add_Big_Big(&Y, &Z);
                Mod_Big_Big(&Y, B);
            }
            memcpy(X, &Y, sizeof(CBigInt));
        }
    }
    return X;
}

/****************************************************************************************
拉宾米勒算法测试素数
调用方式：Rab(N)
返回值：若N为素数，返回1，否则返回0
****************************************************************************************/
static int Rab(CBigInt *N)
{
    CBigInt S = {0}, A = {0}, I = {0}, K = {0};
    U32 i, j, pass;
    for(i = 0; i < 550; i++)
    {
        if(Mod_Big_Long(N, PrimeTable[i]) == 0)
            return 0;
    }
    memcpy(&K, N, sizeof(CBigInt));
    K.m_ulValue[0]--;
    for(i = 0; i < 5; i++)
    {
        pass = 0;
        Mov_Big_Long(&A, rand()*rand());
        memcpy(&S, &K, sizeof(CBigInt));
        while((S.m_ulValue[0] & 1) == 0)
        {
            for(j = 0; j < S.m_nLength; j++)
            {
                S.m_ulValue[j] = S.m_ulValue[j] >> 1;
                if(S.m_ulValue[j + 1] & 1)
                    S.m_ulValue[j] = S.m_ulValue[j] | 0x8000;
            }
            if(S.m_ulValue[S.m_nLength - 1] == 0)
                S.m_nLength--;
            memcpy(&I, &A, sizeof(CBigInt));
            RsaTrans(&I, &S, N);
            if(Cmp(&I, &K) == 0)
            {
                pass = 1;
                break;
            }
        }
        if((I.m_nLength == 1) && (I.m_ulValue[0] == 1))
            pass = 1;
        if(pass == 0)
            return 0;
    }
    return 1;
}

/****************************************************************************************
产生随机素数
调用方法：GetPrime(N,bits)
返回值：N,被赋值为一个bits位（0x100000000进制长度）的素数
****************************************************************************************/
static CBigInt *GetPrime(CBigInt *N, int bits)
{
    U32 i;
    CBigInt S = {0}, A = {0}, I = {0}, K = {0};

    memset(N, 0, sizeof(CBigInt));
    N->m_nLength = bits;
begin:
    srand((int)clock());
    for(i = 0; i < N->m_nLength; i++)
    {
        N->m_ulValue[i] = rand() * 0x100 + rand();
    }
    N->m_ulValue[0] = N->m_ulValue[0] | 1;
    for(i = N->m_nLength - 1; i > 0; i--)
    {
        N->m_ulValue[i] = N->m_ulValue[i] << 1;
        if(N->m_ulValue[i - 1] & 0x8000)
            N->m_ulValue[i]++;
    }
    N->m_ulValue[0] = N->m_ulValue[0] << 1;
    N->m_ulValue[0]++;
    for(i = 0; i < 550; i++)
    {
        if(Mod_Big_Long(N, PrimeTable[i]) == 0)
            goto begin;
    }
    memcpy(&K, N, sizeof(CBigInt));
    K.m_ulValue[0]--;
    for(i = 0; i < 5; i++)
    {
        Mov_Big_Long(&A, rand()*rand());
        memcpy(&S, &K, sizeof(CBigInt));
        Div_Big_Long(&S, 2);
        memcpy(&I, &A, sizeof(CBigInt));
        RsaTrans(&I, &S, N);
        if(((I.m_nLength != 1) || (I.m_ulValue[0] != 1)) && (Cmp(&I, &K) != 0))
            goto begin;
    }
    return N;
}

/***********************************************************************/
/***********************************************************************/
extern void printf_hex(unsigned char *data, unsigned int len);

static void entropy_poll(unsigned char *output, unsigned int len)
{
    if(len > 0)
    {
        int i;
        OTA_srand( kal_get_systicks() );
        for (i = 0; i < len; i++){
            output[i] = OTA_rand() % 0xff + 1;
        }
    }
}
static char *del_PKCS1Padding(char *src)
{
    int len = strlen(src);
    if(len % 2 == 1)
    {
        src++;
    }
    while(*src != 0 && *(src + 1) != 0)
    {
        if(*src == '0' && *(src + 1) == '0')
        {
            src += 2;
            break;
        }
        src += 2;
    }
    return src;
}
static int add_PKCS1Padding(unsigned char *src, unsigned int len, unsigned char *out)
{
    if(len > 256 - 11)
        return -1;
    else
    {
        /*要加密的msg*/
        memcpy(&out[256-len], src, len);
        out[0] = 0;
        out[1] = 2;
        /*至少8字节的随机数*/
        entropy_poll(&out[2], 256 - 3 - len);
        out[256-len - 1] = 0;
        return 0;
    }
}
static int PKCS1PKCS1PaddingHexRemove(unsigned char *input, unsigned short *len, unsigned char *output)
{
    if(input[0] == 0 && (input[1] == 1 || input[1] == 2))
    {
        int i;
        for(i = 2; i < *len; i++)
        {
            if(input[i] == 0)
            {
                *len -= (i + 1);
                memcpy(output, &input[i+1], *len);
                return 0;
            }
        }
    }
    return -1;
}

int RSA2048_ECB_PKCS1Padding_Encode(unsigned char *data, unsigned short len, unsigned char *out, char *publicKey, char *Modulus)
{
    unsigned char buf[256];
    CBigInt N, E;
    CBigInt mw, mi, jm;
    U16 outlen = 256;
/*
    printf("正在运算生成随机数，需要耗费点时间，应稍后...\r\n");
    CBigInt P;
    GetPrime(&P, 64/8);
    printf("随机生成p为%s\r\n\r\n", Put(&P, HEX));
*/
    Get(&N, Modulus, 16);
    Get(&E, publicKey, 16);

    add_PKCS1Padding(data, len, buf);

    if(0)
    {
        unsigned char tmp[550];
        HexToString(buf, 256, tmp);
        Get(&mw, tmp, 16);
    }
    else
    {
        GetHex(&mw, buf, 256, 16);
    }

    RsaTrans(&mw, &E, &N);

    PutHex(&mw, out, &outlen);
    return 0;
}

int RSA2048_ECB_PKCS1Padding_Encode2(unsigned char *data, unsigned short len, unsigned char *out, char *publicKey, unsigned char *ModulusHex)
{
    unsigned char buf[256];
    CBigInt N, E;
    CBigInt mw, mi, jm;
    U16 outlen = 256;
/*
    printf("正在运算生成随机数，需要耗费点时间，应稍后...\r\n");
    CBigInt P;
    GetPrime(&P, 64/8);
    printf("随机生成p为%s\r\n\r\n", Put(&P, HEX));
*/
    //Get(&N, Modulus, 16);
    GetHex(&N, ModulusHex, 256, 16);//256->294
    Get(&E, publicKey, 16);

    add_PKCS1Padding(data, len, buf);

    GetHex(&mw, buf, 256, 16);

    RsaTrans(&mw, &E, &N);

    PutHex(&mw, out, &outlen);
    return 0;
}

int RSA2048_ECB_PKCS1Padding_Decode(unsigned char *data, unsigned short *len, unsigned char *out, char *privateKey, char *Modulus)
{
    unsigned char buf[256], tmp[550];
    CBigInt N, D;
    CBigInt mw, jm;

    Get(&N, Modulus, 16);
    Get(&D, privateKey, 16);

    if(0)
    {
        HexToString(data, *len, tmp);
        Get(&mw, tmp, 16);
    }
    else
    {
        GetHex(&mw, data, *len, 16);
    }

    RsaTrans(&mw, &D, &N);
    PutHex(&mw, buf, len);
    PKCS1PKCS1PaddingHexRemove(buf, len, out);
    return 0;
}
int RSA2048_ECB_PKCS1Padding_Decode2(unsigned char *data, unsigned short *len, unsigned char *out, char *privateKey, unsigned char *ModulusHex)
{
    unsigned char buf[256], tmp[550];
    CBigInt N, D;
    CBigInt mw, jm;

    //Get(&N, Modulus, 16);
    GetHex(&N, ModulusHex, 256, 16);
    Get(&D, privateKey, 16);

    if(0)
    {
        HexToString(data, *len, tmp);
        Get(&mw, tmp, 16);
    }
    else
    {
        GetHex(&mw, data, *len, 16);
    }

    RsaTrans(&mw, &D, &N);
    PutHex(&mw, buf, len);
    PKCS1PKCS1PaddingHexRemove(buf, len, out);
    return 0;
}
#if 0
void rsa_test_cml(void)
{
    unsigned short len = 256;
    U32 tick = OTA_kal_get_systicks();
    char *publicKey = "10001";
    unsigned char ModulusHex[256] = {
        0x9E, 0xE6, 0xEF, 0x13, 0x83, 0x03, 0x27, 0x1E, 0x4E, 0x1D, 0x95, 0x72, 0x80, 0x5D, 0xEA, 0xAD, 
        0x89, 0xF6, 0xEB, 0xA0, 0xC8, 0x1B, 0xD0, 0x9B, 0x6A, 0x56, 0x36, 0x0C, 0xFC, 0x78, 0x3A, 0x87, 
        0xB5, 0x3A, 0xBB, 0xC3, 0x17, 0x70, 0x0A, 0x3A, 0xF7, 0xEF, 0x14, 0x19, 0x6B, 0x41, 0xA7, 0x82, 
        0x4E, 0xAA, 0x08, 0x19, 0x57, 0x55, 0xEC, 0x75, 0xD0, 0x68, 0x2A, 0xA0, 0x82, 0x15, 0x49, 0x24, 
        0xCF, 0x2D, 0x10, 0x2A, 0x49, 0xDA, 0xD2, 0x52, 0x7C, 0xCF, 0x23, 0xB5, 0x77, 0x4C, 0x03, 0x65, 
        0xD5, 0xD5, 0xAD, 0xB3, 0xAE, 0x07, 0xE5, 0xB4, 0xE4, 0x04, 0xF1, 0xD5, 0xDB, 0xF1, 0x99, 0xD5, 
        0x10, 0x6F, 0x6E, 0xF8, 0xEF, 0x3C, 0xD5, 0xDF, 0x89, 0x8A, 0x65, 0x8C, 0xBD, 0xDB, 0xE6, 0xD4, 
        0xAB, 0x85, 0x7D, 0x36, 0x8A, 0xE6, 0x5B, 0xF6, 0xF2, 0xFC, 0xC3, 0x7B, 0x3B, 0x0F, 0x25, 0x89, 
        0x68, 0x2D, 0xF8, 0x98, 0xFD, 0xFA, 0x11, 0x3C, 0xC5, 0xE6, 0xE3, 0x14, 0x28, 0x79, 0x9F, 0x31, 
        0xBE, 0x36, 0xEF, 0x36, 0xE2, 0xA1, 0xDD, 0x99, 0x12, 0x1B, 0x63, 0x27, 0xE6, 0xC2, 0xEB, 0x36, 
        0xEE, 0x63, 0x1F, 0x41, 0xD7, 0x4D, 0x56, 0x23, 0x45, 0x6C, 0xE4, 0xCC, 0xF8, 0xFC, 0x85, 0x4E, 
        0x19, 0x5D, 0x25, 0x41, 0x60, 0x59, 0x1E, 0x95, 0x5B, 0xC8, 0xAA, 0x75, 0x0E, 0x7B, 0x1B, 0x7C, 
        0x54, 0x5F, 0xAA, 0xA3, 0xC9, 0xD6, 0x2C, 0xE9, 0x5D, 0x0E, 0x85, 0x24, 0x82, 0xAC, 0x90, 0x4F, 
        0x3B, 0x51, 0xA3, 0x74, 0xBC, 0xE3, 0x12, 0x58, 0x51, 0xCC, 0x22, 0x8E, 0x0D, 0x18, 0xEF, 0xB2, 
        0xFF, 0x9F, 0xC0, 0xF5, 0xF5, 0xD5, 0x69, 0x30, 0x0C, 0xC4, 0x01, 0x58, 0xCB, 0x89, 0x7A, 0x58, 
        0x29, 0xAC, 0x6E, 0xF1, 0x43, 0x6B, 0x61, 0xBB, 0xBB, 0xE4, 0x3E, 0x10, 0x11, 0x6B, 0x43, 0x31
    };
    unsigned char data[256] = {
        0x7E, 0x61, 0x03, 0x47, 0x62, 0xB8, 0xA3, 0x12, 0x0D, 0x57, 0xFC, 0xE0, 0x3A, 0xE9, 0x3A, 0x9F, 
        0x43, 0x6B, 0xFA, 0xE4, 0x6C, 0xA2, 0xED, 0x0E, 0xE7, 0x17, 0xEB, 0x7D, 0xBA, 0xF9, 0xB5, 0xBF, 
        0xEA, 0xE6, 0x47, 0xF7, 0xF5, 0x72, 0xA5, 0x22, 0x0C, 0xED, 0xAF, 0xF9, 0x71, 0x91, 0x03, 0x34, 
        0x18, 0x5F, 0xED, 0xB6, 0x2A, 0xF4, 0x12, 0xBC, 0x78, 0x45, 0x71, 0x4C, 0x8F, 0x9F, 0x9D, 0xC0, 
        0xED, 0xF3, 0xCE, 0xC2, 0x3E, 0x2F, 0xD8, 0x57, 0xA2, 0x47, 0x1D, 0xD3, 0xB1, 0x92, 0xD4, 0x2F, 
        0xAD, 0x1E, 0x9D, 0x4E, 0xAA, 0xC1, 0xA5, 0xEB, 0xE0, 0xB8, 0x71, 0x20, 0x8C, 0x37, 0x8A, 0x1E, 
        0x76, 0xD0, 0x4B, 0xD0, 0xCD, 0x19, 0x4F, 0x40, 0xE4, 0x31, 0x6F, 0xE4, 0xB7, 0xE6, 0x3B, 0x2E, 
        0x8A, 0xE7, 0x6F, 0x59, 0x72, 0xCF, 0x5B, 0x1C, 0x6B, 0xA6, 0x16, 0xB9, 0x65, 0xEC, 0x6E, 0xFF, 
        0x50, 0x14, 0xFE, 0x26, 0x61, 0xB2, 0x1D, 0xC6, 0xF6, 0xB1, 0xCC, 0x6D, 0xC8, 0x16, 0xA7, 0x38, 
        0x1C, 0x61, 0xF1, 0x24, 0x40, 0x9D, 0xBF, 0xEB, 0x7F, 0x97, 0xDA, 0xF0, 0x60, 0x90, 0x95, 0x5A, 
        0x9D, 0x1D, 0x26, 0xD4, 0x50, 0xF3, 0x22, 0x4C, 0xE7, 0x30, 0x50, 0x27, 0x00, 0xC8, 0x23, 0xFE, 
        0x3D, 0x8A, 0x5C, 0xD4, 0x0B, 0x0B, 0x67, 0x3E, 0x5C, 0x77, 0xA7, 0x1F, 0x97, 0x01, 0xF4, 0x3F, 
        0xE6, 0x8D, 0x44, 0xF1, 0xAF, 0x75, 0x5C, 0x0C, 0x11, 0x34, 0x97, 0x58, 0x9A, 0xEE, 0xBF, 0x7A, 
        0xF0, 0x2E, 0x0D, 0xC6, 0xD7, 0x01, 0xDE, 0xE8, 0x8D, 0xC7, 0x41, 0xA7, 0xF1, 0x11, 0xD8, 0x27, 
        0xC8, 0x4D, 0xFA, 0x44, 0x5A, 0x7A, 0xD2, 0x24, 0x8A, 0x28, 0xAC, 0x52, 0x9D, 0xBD, 0x6B, 0xC5, 
        0x89, 0x2A, 0x6E, 0xEE, 0xCD, 0x05, 0xE1, 0xD3, 0x50, 0xE0, 0x6F, 0x10, 0x6B, 0x0B, 0x72, 0x64
    };
    unsigned char out[256]={0};

    LOGD(L_APP, L_V1, "Begin...");
    RSA2048_ECB_PKCS1Padding_Decode2(data, &len, out, publicKey, ModulusHex);
    tick = OTA_kal_get_systicks() - tick;
    LOGD(L_APP, L_V1, "耗时:%dms", kal_ticks_to_milli_secs(tick));
    LOGH(L_APP, L_V1, out, len);
}
#endif

#endif /* 0 */
