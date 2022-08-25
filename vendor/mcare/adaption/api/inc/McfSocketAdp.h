/***************************************************
* McrSocketAdp.h
* socket adapt to platfom, macro ,struct,enum ,constant
* by arlo,2010.09.19
****************************************************/
#ifndef _mcfsocketadp_h_
#define _mcfsocketadp_h_
#include "McfCommon.h"


typedef sockaddr_struct MadpSocAddr;//soc internal usage.

extern const MINT MADP_SOC_SUCCESS ;
extern const MINT MADP_SOC_ERROR ;
extern const MINT MADP_SOC_WOULDBLOCK ;
extern const MINT MADP_SOC_INVALID_SOCK ;
extern const MINT MADP_SOC_STREAM   ;
extern const MINT MADP_SOC_DGRAM;
extern const MINT MADP_SOC_SMS;
extern const MINT MADP_SOC_RAW;
extern const MINT MADP_PF_INET;
extern const MINT MADP_SOC_NBIO;
extern const MINT MADP_SOC_ASYNC;
extern const MINT MADP_SOC_READ ;
extern const MINT MADP_SOC_WRITE  ;
extern const MINT MADP_SOC_ACCEPT ;
extern const MINT MADP_SOC_CONNECT;
extern const MINT MADP_SOC_CLOSE ;


#endif

