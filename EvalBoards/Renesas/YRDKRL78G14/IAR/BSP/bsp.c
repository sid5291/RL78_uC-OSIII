/*
*********************************************************************************************************
*                                     MICIRUM BOARD SUPPORT PACKAGE
*
*                             (c) Copyright 2010-2011; Micrium, Inc.; Weston, FL
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
*                                    MICRIUM BOARD SUPPORT PACKAGE
*
*                                            Renesas RL78
*                                               on the
*                                     YRDKRL78G13 Evaluation Board
*                                    Modified for YRDKRL78G14 by AGD
*
* Filename      : bsp.c
* Version       : V1.00
* Programmer(s) : NB
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#define  BSP_MODULE
#include <includes.h>

/*
*********************************************************************************************************
*                                               CONSTANTS
*********************************************************************************************************
*/


#ifdef  OS_uCOS_II_H
#define  BSP_DLY_CONST  (BSP_CPU_CLKFREQ / OS_TICKS_PER_SEC)
#endif

#ifdef  OS_H
#define  BSP_DLY_CONST  (BSP_CPU_CLKFREQ / OS_CFG_TICK_RATE_HZ)
#endif

/*
*********************************************************************************************************
*                                      REGISTER & BIT FIELD DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            GPIO DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                       EXTERN  GLOBAL VARIABLES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                           LOCAL DEFINES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                          LOCAL DATA TYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            LOCAL TABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  TMR_TickInit  (void);
static  void  CLK_OscInit   (void);

/*
*********************************************************************************************************
*                                            OPTION BYTE
*********************************************************************************************************
*/
#if 0 // AGD: disabled so we can use the option bytes in r_main.c,
      // which is generated and maintained by applilet
#pragma constseg = OPTBYTE
__root  const  CPU_CHAR option[4] =
{
    0x00,                                                               /* 00000000 = 0x00                                          */
                                                                        /* ||||||||   Control of watchdog timer in standby mode     */
                                                                        /* ||||||||   -----------------------------------------     */
                                                                        /* |||||||0 - Watchdog timer stopped in HALT/STOP mode      */
                                                                        /* |||||||1 - Watchdog timer enabled in HALT/STOP mode      */
                                                                        /* |||||||                                                  */
                                                                        /* |||||||    Watchdog timer overflow time                  */
                                                                        /* |||||||    ----------------------------                  */
                                                                        /* ||||000 -- 2^10 / fIL (fIL = 240kHz)                     */
                                                                        /* ||||001 -- 2^11 / fIL                                    */
                                                                        /* ||||010 -- 2^12 / fIL                                    */
                                                                        /* ||||011 -- 2^13 / fIL                                    */
                                                                        /* ||||100 -- 2^15 / fIL                                    */
                                                                        /* ||||101 -- 2^17 / fIL                                    */
                                                                        /* ||||110 -- 2^18 / fIL                                    */
                                                                        /* ||||111 -- 2^20 / fIL                                    */
                                                                        /* ||||                                                     */
                                                                        /* ||||       Control of watchdog timer operation           */
                                                                        /* ||||       -----------------------------------           */
                                                                        /* |||0 ----- Operation disabled                            */
                                                                        /* |||1 ----- Operation enabled                             */
                                                                        /* |||                                                      */
                                                                        /* |||        Watchdog timer window open period             */
                                                                        /* |||        ----------------------------------            */
                                                                        /* |00 ------ 25%  window open                              */
                                                                        /* |01 ------ 50%  window open                              */
                                                                        /* |10 ------ 75%  window open                              */
                                                                        /* |11 ------ 100% window open                              */
                                                                        /* |                                                        */
                                                                        /* |          Use of interval interrupt                     */
                                                                        /* |          -------------------------                     */
                                                                        /* 0 -------- Interval interrupt is not used                */
                                                                        /* 1 -------- Interval interrupt is used                    */
    0xFB,                                                               /* 11111011 = 0xFB                                          */
                                                                        /* -----|||   LVI on power on application                   */
                                                                        /* -----|||   ---------------------------                   */
                                                                        /*      ||0 - LVI on by default                             */
                                                                        /*      ||1 - LVI off by default                            */
                                                                        /*      ||                                                  */
                                                                        /*      ||    Internal High-Speed Osc. Frequency            */
                                                                        /*      ||    ----------------------------------            */
                                                                        /*      01 -- 8MHz/20MHz                                    */
                                                                        /*      10 -- 1MHz                                          */
    0xFF,                                                               /* !!!!! ALWAYS SET TO 0xFF !!!!!                           */
    0x85,                                                                /* 10000101 = 0x85                                          */
                                                                        /* |------|   Control of on-chip debug operation            */
                                                                        /* |------|   ----------------------------------            */
                                                                        /* 0------0 - Disable on-chip debug operation               */
                                                                        /* 0------1 - Setting prohibited                            */
                                                                        /* 1------0 - Erases data of flash memory in case of        */
                                                                        /*            failures in enabling on-chip debugging and    */
                                                                        /*            authenticating on-chip debug security ID      */
                                                                        /* 1------1 - Does not erases data of flash memory in case  */
                                                                        /*            of failures in enabling on-chip debugging and */
                                                                        /*            authenticating on-chip debug security ID      */
        };
#endif // #if 0 to disable these optbyte settings
#pragma constseg = default

/*
***********************************************************************************************************
***********************************************************************************************************
**                                        GLOBAL FUNCTIONS
***********************************************************************************************************
***********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                         BSP_LowLevelInit()
*
* Description : Board Support Package Low Level Initialization.
*
* Argument(s) : none.
*
* Returns(s)  : none
*
* Caller(s)   : Startup code.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LowLevelInit (void)
{


}


/*
*********************************************************************************************************
*                                          BSP_PreInit()
*
* Description : System Pre-Initialization. Initializes all peripherals that don't require OS services (LEDs, PBs)
*               or modules than need to be initialized before the OS (External memories).
*
* Argument(s) : none.
*
* Return(s)   : none.

* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_PreInit (void)
{

}


/*
*********************************************************************************************************
*                                          BSP_PostInit()
*
* Description : Initialize all the peripherals that required OS services (OS initialized)
*
* Argument(s) : none.
*
* Return(s)   : none.

* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_PostInit (void)
{
    // AGD: already handled by applilet's initialization code
    //    CLK_OscInit();
    TMR_TickInit();
}

/*
*********************************************************************************************************
*                                            BSP_LED_Off()
*
* Description : Turns OFF any or all of the LEDs on the board.
*
* Argument(s) : led    The ID of the LED control:
*                      0    turns OFF ALL the LEDs on the board.
*                      1    turns OFF the blue  LED(D2) on the board.
*                      2    turns OFF the green LED(D3) on the board.
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_Off (CPU_INT08U led)
{
    switch (led) {
        case 0u:
            LED01 = DEF_TRUE;
            LED02 = DEF_TRUE;
            LED03 = DEF_TRUE;
            LED04 = DEF_TRUE;
            LED05 = DEF_TRUE;
            LED06 = DEF_TRUE;
            break;

        case 1u:
            LED01 = DEF_TRUE;
            break;

        case 2u:
            LED02 = DEF_TRUE;
            break;

        case 3u:
            LED03 = DEF_TRUE;
            break;

        case 4u:
            LED04 = DEF_TRUE;
            break;

        case 5u:
            LED05 = DEF_TRUE;
            break;

        case 6u:
            LED06 = DEF_TRUE;
            break;

        default:
            break;
    }
}


/*
*********************************************************************************************************
*                                             BSP_LED_On()
*
* Description : Turn ON any or all the LEDs on the board.
*
* Argument(s) : led    The LED number on the board(1-8)
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_On (CPU_INT08U led)
{
    switch (led) {
        case 0u:
            LED01 = DEF_FALSE;
            LED02 = DEF_FALSE;
            LED03 = DEF_FALSE;
            LED04 = DEF_FALSE;
            LED05 = DEF_FALSE;
            LED06 = DEF_FALSE;
            break;

        case 1u:
            LED01 = DEF_FALSE;
            break;

        case 2u:
            LED02 = DEF_FALSE;
            break;

        case 3u:
            LED03 = DEF_FALSE;
            break;

        case 4u:
            LED04 = DEF_FALSE;
            break;

        case 5u:
            LED05 = DEF_FALSE;
            break;

        case 6u:
            LED06 = DEF_FALSE;
            break;

        default:
            break;
    }
}


/*
*********************************************************************************************************
*                                             BSP_LED_Toggle()
*
* Description : Toggles any or all the LEDs on the board.
*
* Argument(s) : led    The LED number on the board(1-8)
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  BSP_LED_Toggle (CPU_INT08U led)
{
    switch (led) {
        case 0u:
            LED01 = ~LED01;
            LED02 = ~LED02;
            LED03 = ~LED03;
            LED04 = ~LED04;
            LED05 = ~LED05;
            LED06 = ~LED06;
            break;

        case 1u:
            LED01 = ~LED01;
            break;

        case 2u:
            LED02 = ~LED02;
            break;

        case 3u:
            LED03 = ~LED03;
            break;

        case 4u:
           LED04 = ~LED04;
            break;

        case 5u:
            LED05 = ~LED05;
            break;

        case 6u:
            LED06 = ~LED06;
            break;

        default:
            break;
    }
}


/*
*********************************************************************************************************
*                                         BSP_PB_GetStatus()
*
* Description : Get the status of a push button on the board.
*
* Argument(s) : pb      The ID of the push button to probe
*
*                       1    probe the push button USRPB1
*                       2    probe the push button USRPB2
*
* Return(s)   : DEF_FALSE   if the push button is pressed
*               DEF_TRUE    if the push button is not pressed
*********************************************************************************************************
*/

CPU_BOOLEAN  BSP_PB_GetStatus (CPU_INT08U pb)
{
    CPU_BOOLEAN   status;


    status   = DEF_TRUE;

    switch (pb) {
        case 1:
            break;

        case 2:
            break;

        default:
            break;
    }

    return (status);
}


#ifdef  OS_H

/*
*********************************************************************************************************
*                                      BSP_OS_SemCreate()
*
* Description : Creates a sempahore to lock/unlock
*
* Argument(s) : p_sem        Pointer to a BSP_OS_SEM structure
*
*               sem_val      Initial value of the semaphore.
*
*               p_sem_name   Pointer to the semaphore name.
*
* Return(s)   : DEF_OK        if the semaphore was created.
*               DEF_FAIL      if the sempahore could not be created.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*
*********************************************************************************************************
*/

CPU_BOOLEAN  BSP_OS_SemCreate (BSP_OS_SEM     *p_sem,
                               BSP_OS_SEM_VAL  sem_val,
                               CPU_CHAR       *p_sem_name)

{
    OS_ERR  os_err;


    OSSemCreate(p_sem,
                p_sem_name,
                sem_val,
                &os_err);

    if (os_err != OS_ERR_NONE) {
        return (DEF_FAIL);
    }

    return (DEF_OK);
}

/*
*********************************************************************************************************
*                                     BSP_OS_SemWait()
*
* Description : Wait on a semaphore to become available
*
* Argument(s) : p_sem        Pointer to the sempahore handler.
*
*               dly_ms       delay in miliseconds to wait on the semaphore
*
* Return(s)   : error code return     DEF_OK       if the semaphore was acquire
*                                     DEF_FAIL     if the sempahore could not be acquire
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

CPU_BOOLEAN  BSP_OS_SemWait (BSP_OS_SEM  *p_sem,
                             CPU_INT32U   dly_ms)
{
    OS_ERR  os_err;

    OSSemPend(p_sem,
              dly_ms,
              OS_OPT_PEND_BLOCKING,
              (CPU_TS*)0,
              &os_err);

    if (os_err != OS_ERR_NONE) {
        return (DEF_FAIL);
    }

    return (DEF_OK);
}


/*
*********************************************************************************************************
*                                        BSP_OS_SemPost()
*
* Description : Post a semaphore
*
* Argument(s) : p_sem                 Pointer to the Semaphore handler.
*
* Return(s)   : error code return     DEF_OK     if the semaphore was posted.
*                                     DEF_FAIL   if the sempahore could not be posted.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

CPU_BOOLEAN  BSP_OS_SemPost (BSP_OS_SEM  *p_sem)
{
    OS_ERR  os_err;


    OSSemPost(p_sem,
              OS_OPT_POST_1,
              &os_err);

    if (os_err != OS_ERR_NONE) {
        return (DEF_FAIL);
    }

    return (DEF_OK);
}

#endif

/*
*********************************************************************************************************
*                                        OSCILLATOR INITIALIZATION
*
* Description   : This function initializes the clock source.
*
* Argument      : None
*
* Returns       : None
*********************************************************************************************************
*/
#if 0 // AGD: disabled so we can use oscillator initialization code
      // which is generated and maintained by applilet

void  CLK_OscInit (void)
{

                                                                        /* Set clock operation mode                                 */
                                                                        /* ||-|-|||   Control of hi-speed system clock osc freq     */
                                                                        /* ||-|-||    -----------------------------------------     */
                                                                        /* ||-|-||0 -  2 MHz <= fMX <= 10 MHz                       */
                                                                        /* ||-|-||1 - 10 MHz <  fMX <= 20 MHz                       */
                                                                        /* ||-|-||                                                  */
                                                                        /* ||-|-||    XT1 oscillator oscillation mode selection     */
                                                                        /* ||-|-||    -----------------------------------------     */
                                                                        /* ||-|-00 -- Low-power consumption oscillation             */
                                                                        /* ||-|-01 -- Normal oscillation                            */
                                                                        /* ||-|-1x -- Ultra low-power consumption operation         */
                                                                        /* ||-|                                                     */
                                                                        /* ||-|       Subsystem clock pin operation mode            */
                                                                        /* ||-|       -----------------------------------------     */
                                                                        /* ||-0 ----- XT1/P123 & XT2/P124 in input port mode        */
                                                                        /* ||-1 ----- XT1/P123 & XT2/P124 in crystal resonator mode */
                                                                        /* ||                                                       */
                                                                        /* ||         High-speed system clock pin operation mode    */
                                                                        /* ||         ------------------------------------------    */
                                                                        /* 00 ------- X1 & X2 in input mode                         */
                                                                        /* 01 ------- X1 & x2 in crystal/ceramic resonator mode     */
                                                                        /* 10 ------- X1 & X2 in input mode                         */
                                                                        /* 11 ------- X1 in input mode & X2 in ext clock input mode */
                                                                        /* CAUTIONS 1. CMC can be written only once after reset     */
                                                                        /*             by an 8-bit memory manipulation instruction. */
                                                                        /*          2. After reset set CMC before X1 or XT1         */
                                                                        /*             oscillation is started as set by the clock   */
                                                                        /*             operation status control register (CSC).     */
                                                                        /*          3. Be sure to set AMPH to 1 if the X1 clock     */
                                                                        /*             oscillation frequency exceeds 10 MHz.        */
                                                                        /*          4. It is recommended to set the default value   */
                                                                        /*             (00H) to CMC after reset release, even when  */
                                                                        /*             the register is used at the default value,   */
                                                                        /*             in order to prevent malfunctioning during a  */
                                                                        /*             program loop.                                */
    CMC    = 0x13;                                                      /* 00010011 = 0x13                                          */
                                                                        /* Set osc stabilization time to reset value (optional)     */
                                                                        /* -----|||                                                 */
                                                                        /* -----|||   osc stabilization time selection              */
                                                                        /* -----|||   -----------------------------------------     */
                                                                        /* -----000 -    256/fMX                                    */
                                                                        /* -----001 -    512/fMX                                    */
                                                                        /* -----010 -   1024/fMX                                    */
                                                                        /* -----011 -   2048/fMX                                    */
                                                                        /* -----100 -   8192/fMX                                    */
                                                                        /* -----101 -  32768/fMX                                    */
                                                                        /* -----110 - 131072/fMX                                    */
                                                                        /* -----111 - 262144/fMX                                    */
    OSTS   = 0x07;                                                      /* 00000111 = 0x07                                          */

}
#endif

/*
*********************************************************************************************************
*                                        TICKER INITIALIZATION
*
* Description   : This function initializes the uC/OS-II's tick source.
*
* Argument      : None
*
* Returns       : None
*********************************************************************************************************
*/

void  TMR_TickInit (void)
{
    PER0          |=    0x01;                                           /* Power on Timer Array Unit                                */
    TPS0           =  0x0008;                                           /* CK00 = fClk, CK01 = fClk / 256                           */
    TMR00          =  0x0000;                                           /* Ch. CK00, PRS clock, slave, sw start, timer mode */
    TDR00          = (BSP_DLY_CONST / 512) - 1;                         /* Set interval timer                               */

    TOE0          &= 0x00FE;
    TO0           &= 0x00FE;
    TOM0          &= 0x00FE;
    TOL0          &= 0x00FE;

    PR01L_bit.no4  =      1;
    PR11L_bit.no4  =      1;

    TMIF00         =      0;                                            /* Clear TAU Ch 0 interrupt request flag            */
    TMMK00         =      0;                                            /* Enable TAU Ch 0 interrupt                        */
    TS0           |=   0x01;
}

/*
*********************************************************************************************************
*                                      Tmr_TickISR_Handler
*
* Description   : This function is part of the ISR for the OSTick.
*
* Argument      : None
*
* Returns       : None
*********************************************************************************************************
*/

void  Tmr_TickISR_Handler (void)
{

}