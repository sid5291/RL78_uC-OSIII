/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2013 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_userdefine.h
* Version      : Applilet3 for RL78/G14 V2.00.00.08 [12 Apr 2013]
* Device(s)    : R5F104PJ
* Tool-Chain   : IAR Systems iccrl78
* Description  : This file includes user definition.
* Creation Date: 3/26/2014
***********************************************************************************************************************/

#ifndef _USER_DEF_H
#define _USER_DEF_H

/***********************************************************************************************************************
User definitions
***********************************************************************************************************************/

/* Start user code for function. Do not edit comment generated here */

#define RDKRL78G14 // or RDKRL78G13 for old board

#define MAX(a,b) ((a>b)? a : b)
#define MIN(a,b) ((a<b)? a : b)


#define DIR_OUT	(0)
#define DIR_IN  (1)

#define LED_ON  (0)
#define LED_OFF (1)

#define LED_1_R P1_bit.no1
#define LED_2_G P1_bit.no0
#define LED_3_R P6_bit.no2
#define LED_5_R P6_bit.no3
#define LED_7_R P6_bit.no4
#define LED_4_G P4_bit.no2
#define LED_6_G P4_bit.no3
#define LED_8_G P4_bit.no4
#define LED_9_R P6_bit.no5
#define LED_11_R P6_bit.no6
#define LED_13_R P6_bit.no7
#define LED_10_G P4_bit.no5
#define LED_12_G P15_bit.no2
#define LED_14_G P10_bit.no1

#define ms_250  250000

typedef struct{
  uint32_t min;
  uint32_t max;
  uint32_t mean;
  uint32_t samples;
  uint32_t total;
} stats;


#define LCDCLRSCR  0
#define LCDFNT     1
#define LCDCLRLIN  2
#define LCDSTR     3
#define LCDCHR     4
#define LCDINV     5
#define ACCELTX    6
#define ACCELRX    7

#define STRTTSK    2
#define TASK1      6
#define TSKLEDS    4
#define TSKACCEL   3
#define TSKSTATS   5

#define MAX_NUM    8
#define NUM_TASKS  5

/* End user code. Do not edit comment generated here */
#endif
