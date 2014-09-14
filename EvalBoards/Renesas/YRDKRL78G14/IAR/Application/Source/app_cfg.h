/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                             (c) Copyright 2010; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                       APPLICATION CONFIGURATION
*
*                                            Renesas RL78
*                                               on the
*                                     YRDKRL78G14 Evaluation Board
*
* Filename      : app_cfg.h
* Version       : V1.00
* Programmer(s) : NB
*********************************************************************************************************
*/

#ifndef  APP_CFG_MODULE_PRESENT
#define  APP_CFG_MODULE_PRESENT


/*
*********************************************************************************************************
*                                       ADDITIONAL uC/MODULE ENABLES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            TASK PRIORITIES
*********************************************************************************************************
*/

#define  APP_CFG_TASK_START_PRIO                          	2u
#define  APP_CFG_TASK1_PRIO                           		6u
#define  APP_CFG_TASKLEDS_PRIO                                  4u
#define  APP_CFG_TASKACCEL_PRIO                           	3u
#define  APP_CFG_STATDISP_PRIO                                  5u


/*
*********************************************************************************************************
*                                            TASK STACK SIZES
*********************************************************************************************************
*/

#define  APP_CFG_TASK_START_STK_SIZE                    	512u
#define  APP_CFG_TASK1_STK_SIZE                     		256u
#define  APP_CFG_TASKLEDS_STK_SIZE                              512u
#define  APP_CFG_STATDISP_STK_SIZE                              512u
#define  APP_CFG_TASKACCEL_STK_SIZE                    		512u

/*
*********************************************************************************************************
*                                            TASK STACK SIZES LIMIT
*********************************************************************************************************
*/

#define  APP_CFG_TASK_STK_SIZE_PCT_FULL             90u

#define  APP_CFG_TASK_START_STK_SIZE_LIMIT      (APP_CFG_TASK_START_STK_SIZE * (100u - APP_CFG_TASK_STK_SIZE_PCT_FULL))   / 100u
#define  APP_CFG_TASKACCEL_STK_SIZE_LIMIT       (APP_CFG_TASKACCEL_STK_SIZE * (100u - APP_CFG_TASK_STK_SIZE_PCT_FULL))   / 100u
#define  APP_CFG_TASKLEDS_STK_SIZE_LIMIT        (APP_CFG_TASKLEDS_STK_SIZE  * (100u - APP_CFG_TASK_STK_SIZE_PCT_FULL))
#define  APP_CFG_TASK1_STK_SIZE_LIMIT           (APP_CFG_TASK1_STK_SIZE * (100u - APP_CFG_TASK_STK_SIZE_PCT_FULL))   / 100u
#define  APP_CFG_STATDISP_STK_SIZE_LIMIT        (APP_CFG_STATDISP_STK_SIZE * (100u - APP_CFG_TASK_STK_SIZE_PCT_FULL))
/*
*********************************************************************************************************
*                                             uC/LIB CONFIGURATION
*********************************************************************************************************
*/

#define  LIB_MEM_CFG_OPTIMIZE_ASM_EN              DEF_ENABLED
#define  LIB_MEM_CFG_ARG_CHK_EXT_EN               DEF_ENABLED
#define  LIB_MEM_CFG_ALLOC_EN                    DEF_DISABLED
#define  LIB_MEM_CFG_HEAP_SIZE                          1024u // 1024u

/*
*********************************************************************************************************
*                                     TRACE / DEBUG CONFIGURATION
*********************************************************************************************************
*/

#define  TRACE_LEVEL_OFF                                   0
#define  TRACE_LEVEL_INFO                                  1
#define  TRACE_LEVEL_DBG                                   2

#include <cpu.h>
void  App_SerPrintf  (CPU_CHAR *format, ...);

#define  APP_CFG_TRACE_LEVEL                    TRACE_LEVEL_OFF
#define  APP_CFG_TRACE                          App_SerPrintf

#define  APP_TRACE_INFO(x)                     ((APP_CFG_TRACE_LEVEL >= TRACE_LEVEL_INFO)  ? (void)(APP_CFG_TRACE x) : (void)0)
#define  APP_TRACE_DBG(x)                      ((APP_CFG_TRACE_LEVEL >= TRACE_LEVEL_DBG)   ? (void)(APP_CFG_TRACE x) : (void)0)

#endif
