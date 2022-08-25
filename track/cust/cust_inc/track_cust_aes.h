//本文出处: https://github.com/jxjgssylsg/AES

//tracker_aes.h

#ifndef __TRACKER_AES_H__
#define __TRACKER_AES_H__
#include "track_cust.h"

#define BLOCK_SIZE 16

//Operation Modes
//The Electronic Code Book (ECB), Cipher Block Chaining (CBC) and Cipher Feedback Block (CFB) modes
//are implemented.
//In ECB mode if the same block is encrypted twice with the same key, the resulting
//ciphertext blocks are the same.
//In CBC Mode a ciphertext block is obtained by first xoring the
//plaintext block with the previous ciphertext block, and encrypting the resulting value.
//In CFB mode a ciphertext block is obtained by encrypting the previous ciphertext block
//and xoring the resulting value with the plaintext.
enum { ECB = 0, CBC = 1, CFB = 2 };

enum { DEFAULT_BLOCK_SIZE = 16 };
enum { MAX_BLOCK_SIZE = 32, MAX_ROUNDS = 14, MAX_KC = 8, MAX_BC = 8 };



//送样：厂商标识：test_202009 密钥：93204ee5ab065d32 初始向量：和之前一致（0102030405060708）
//IMEI                RFID
//868120246598012  0853326980
//868120246598053  0853288388
//868120246598038  0853344996
#ifdef PROJ_ZJYD_ZZX
#define FACTORY_FLAG	"huahong_411"
#define AES_KEY_GZYD	"f09efc847596c278"
#define AES_IV_GZYD		"0102030405060708"


#define FACTORY_FLAG_TEST	"huahong"
#define AES_KEY_GZYD_TEST	"gzxjy201909sdrhh"
#define AES_IV_GZYD_TEST	"0102030405060708"
#else
#define FACTORY_FLAG	"jimi_411"
#define AES_KEY_GZYD	"1b5cf49853d3ef8b"
#define AES_IV_GZYD		"0102030405060708"

#define FACTORY_FLAG_TEST	"jimi"
#define AES_KEY_GZYD_TEST	"gzxjy201805sdrgz"
#define AES_IV_GZYD_TEST	"0102030405060708"

#endif






char* gzydGetFactory_Flag(void);
char* gzydGetAes_Key(void);
char* gzydGetAes_IV(void);



#define PROTOCOL_VERSION	"206"



void decryt(VMINT8* final_encode,VMINT8 *p_Outcontent,VMINT outSize);

#endif // __TRACKER_AES_H__
