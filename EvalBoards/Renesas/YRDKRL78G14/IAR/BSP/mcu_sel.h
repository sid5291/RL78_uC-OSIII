#ifndef MCU_SEL_H
#define MCU_SEL_H


// #define MCU_RL78G13
#define MCU_RL78G14

// #define RDK_RL78G13
#define RDK_RL78G14

#ifdef MCU_G13
	#include <ior5f100LE.h>
	#include <ior5f100LE_ext.h>
#else
	#include <ior5f104PJ.h>
	#include <ior5f104PJ_ext.h>
#endif

#endif