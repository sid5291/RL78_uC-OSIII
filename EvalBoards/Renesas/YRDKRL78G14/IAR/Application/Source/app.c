/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                            (c) Copyright 2010-2011; Micrium, Inc.; Weston, FL
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
*                                           EXAMPLE CODE
*
*                                           Renesas RL78
*                                               on the
*                                     YRDKRL78G13 Evaluation Board
*
* Filename      : app.c
* Version       : V1.00
* Programmer(s) : FT
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include "r_cg_macrodriver.h"
#include "r_cg_serial.h"
#include <includes.h>
#include <string.h>
#include "accel.h"
#include "lcd.h"
#include "r_cg_userdefine.h"
#include "r_cg_intc.h"

/*
*********************************************************************************************************
*                                             LOCAL DEFINES
*********************************************************************************************************
*/
#define PI 3.14159265

/*
*********************************************************************************************************
*                                            LOCAL VARIABLES
*********************************************************************************************************
*/

static  OS_TCB    App_TaskStart_TCB;
static  OS_TCB    App_TaskAccel_TCB;
static  OS_TCB    App_TaskLeds_TCB;
static  OS_TCB    App_Task1_TCB;
static  OS_TCB    App_StatDisp_TCB;

OS_SEM    Accel_Sem;
OS_SEM    Disp_Sem;

OS_Q      LEDs_Q;

static  CPU_STK   App_TaskStart_Stk[APP_CFG_TASK_START_STK_SIZE];
static  CPU_STK   App_TaskAccel_Stk[APP_CFG_TASKACCEL_STK_SIZE];
static  CPU_STK   App_TaskLeds_Stk[APP_CFG_TASKLEDS_STK_SIZE];
static  CPU_STK   App_StatDisp_Stk[APP_CFG_STATDISP_STK_SIZE];
static  CPU_STK   App_Task1_Stk[APP_CFG_TASK1_STK_SIZE];

stats Stat_list[MAX_NUM];

struct proc_stats
{
  int prio;
  int max_stk;
  int usage;
} p_stats[NUM_TASKS];

extern uint32_t overflow_count;
extern volatile uint8_t button_flag_8;

/*
*********************************************************************************************************
*                                         FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  App_TaskCreate(void);
static  void  App_ObjCreate (void);
static  void  clearLEDS(void);
static  void  read_stats(void);

static  void  App_TaskStart (void  *p_arg);
static  void  App_Task1 (void  *p_arg);
static  void  App_TaskLeds (void *p_args);
static  void  App_StatDisp (void *p_args);


/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Argument(s) : none
*
* Return(s)   : none
*
* Caller(s)   : Startup Code.
*
* Note(s)     : none.
*********************************************************************************************************
*/

// AGD: was main, but applilet generates own main function. Added call from main to ucosIII_main.
int  ucosIII_main (void)
{
    OS_ERR   os_err;

    CPU_Init();                                                 /* Initialize the uC/CPU services                       */

    BSP_PreInit();

    OSInit(&os_err);                                            /* Init uC/OS-III.                                      */

    LEDErrorDisp(os_err);
      
    OSTaskCreate((OS_TCB      *)&App_TaskStart_TCB,              /* Create the start task                                */
                 (CPU_CHAR    *)"Start",
                 (OS_TASK_PTR  )App_TaskStart,
                 (void        *)0,
                 (OS_PRIO      )APP_CFG_TASK_START_PRIO,
                 (CPU_STK     *)&App_TaskStart_Stk[0],
                 (CPU_STK_SIZE )APP_CFG_TASK_START_STK_SIZE_LIMIT,
                 (CPU_STK_SIZE )APP_CFG_TASK_START_STK_SIZE,
                 (OS_MSG_QTY   )0u,
                 (OS_TICK      )0u,
                 (void        *)0,
                 (OS_OPT       )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR      *)&os_err);

    LEDErrorDisp(os_err);
    
    OSStart(&os_err);                                           /* Start multitasking (i.e. give control to uC/OS-III).*/

    LEDErrorDisp(os_err);
    
    return (0);
}


/*
*********************************************************************************************************
*                                          STARTUP TASK
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Arguments   : p_arg   is the argument passed to 'AppTaskStart()' by 'OSTaskCreate()'.
*
* Returns     : none
*
* Notes       : 1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                  used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static  void  App_TaskStart (void *p_arg)
{
    OS_ERR  err;

    (void)p_arg;											/* prevent compiler warning */

    BSP_PostInit();                                             /* Initialize BSP functions                             */

#if (OS_CFG_STAT_TASK_EN > 0u)
    OSStatTaskCPUUsageInit(&err);                               /* Determine CPU capacity                               */
#endif

    App_TaskCreate();                                           /* Create Application tasks                             */
    App_ObjCreate();                                            /* Create Application kernel objects                    */

#ifdef CPU_CFG_INT_DIS_MEAS_EN
    CPU_IntDisMeasMaxCurReset();
#endif

#if (OS_CFG_STAT_TASK_EN > 0u)
    OSStatReset(&err);
    LCDErrorDisp(err);
#endif

	LCDInit();

	InitializeAccelerometer(); 									// Accel init uses LCD/Glyph
        //Initialize Stats
        for (int i=0 ; i<MAX_NUM ; i++)
        {
          Stat_list[i].min = 0xffffffff;
          Stat_list[i].max = 0;
          Stat_list[i].mean = 0;
          Stat_list[i].samples = 0;
          Stat_list[i].total = 0;
        }

    while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
		LCDClearLine(0);

		LCDPrintf(0,0,"skumar15");

	   	OSTimeDlyHMSM(0u, 0u, 0u, 100u, OS_OPT_TIME_HMSM_STRICT, &err);
                LCDErrorDisp(err);
    }

}


/*
*********************************************************************************************************
*                                          AppTaskCreate()
*
* Description : Create application tasks.
*
* Argument(s) : none
*
* Return(s)   : none
*
* Caller(s)   : AppTaskStart()
*
* Note(s)     : none.
*********************************************************************************************************
*/

static  void  App_TaskCreate (void)
{
  OS_ERR  os_err;

		OSTaskCreate((OS_TCB 	*)&App_Task1_TCB,              /* Create task 1                               */
                 (CPU_CHAR    *)"Task1",
                 (OS_TASK_PTR  )App_Task1,
                 (void        *)0,
                 (OS_PRIO      )APP_CFG_TASK1_PRIO,
                 (CPU_STK     *)&App_Task1_Stk[0],
                 (CPU_STK_SIZE )APP_CFG_TASK1_STK_SIZE_LIMIT,
                 (CPU_STK_SIZE )APP_CFG_TASK1_STK_SIZE,
                 (OS_MSG_QTY   )0u,
                 (OS_TICK      )0u,
                 (void        *)0,
                 (OS_OPT       )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR      *)&os_err);
                 LCDErrorDisp(os_err);

		OSTaskCreate((OS_TCB     *)&App_TaskAccel_TCB,        /* Create accelerometer task                                */
                 (CPU_CHAR    *)"TaskAccel",
                 (OS_TASK_PTR  )App_TaskAccel,
                 (void        *)0,
                 (OS_PRIO      )APP_CFG_TASKACCEL_PRIO,
                 (CPU_STK     *)&App_TaskAccel_Stk[0],
                 (CPU_STK_SIZE )APP_CFG_TASKACCEL_STK_SIZE_LIMIT,
                 (CPU_STK_SIZE )APP_CFG_TASKACCEL_STK_SIZE,
                 (OS_MSG_QTY   )0u,
                 (OS_TICK      )0u,
                 (void        *)0,
                 (OS_OPT       )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR      *)&os_err);
                 LCDErrorDisp(os_err);
                 
                OSTaskCreate((OS_TCB     *)&App_TaskLeds_TCB,        /* Create accelerometer task                                */
                 (CPU_CHAR    *)"TaskLeds",
                 (OS_TASK_PTR  )App_TaskLeds,
                 (void        *)0,
                 (OS_PRIO      )APP_CFG_TASKLEDS_PRIO,
                 (CPU_STK     *)&App_TaskLeds_Stk[0],
                 (CPU_STK_SIZE )APP_CFG_TASKLEDS_STK_SIZE_LIMIT,
                 (CPU_STK_SIZE )APP_CFG_TASKLEDS_STK_SIZE,
                 (OS_MSG_QTY   )0u,
                 (OS_TICK      )0u,
                 (void        *)0,
                 (OS_OPT       )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR      *)&os_err);
                 LCDErrorDisp(os_err);
                 
                 OSTaskCreate((OS_TCB     *)&App_StatDisp_TCB,        /* Create accelerometer task                                */
                 (CPU_CHAR    *)"Statistics Display",
                 (OS_TASK_PTR  )App_StatDisp,
                 (void        *)0,
                 (OS_PRIO      )APP_CFG_STATDISP_PRIO,
                 (CPU_STK     *)&App_StatDisp_Stk[0],
                 (CPU_STK_SIZE )APP_CFG_STATDISP_STK_SIZE_LIMIT,
                 (CPU_STK_SIZE )APP_CFG_STATDISP_STK_SIZE,
                 (OS_MSG_QTY   )0u,
                 (OS_TICK      )0u,
                 (void        *)0,
                 (OS_OPT       )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR      *)&os_err);
                 LCDErrorDisp(os_err);
}


/*
*********************************************************************************************************
*                                          App_ObjCreate()
*
* Description : Create application kernel objects tasks.
*
* Argument(s) : none
*
* Return(s)   : none
*
* Caller(s)   : AppTaskStart()
*
* Note(s)     : none.
*********************************************************************************************************
*/

static  void  App_ObjCreate (void)
{ OS_ERR os_err;
  LCD_ObjCreate(); // Creates LCD Mutex
  OSSemCreate(&Accel_Sem,"Accelerometer Semaphore",1,&os_err); // Creates Accel Semaphore
  LCDErrorDisp(os_err);
  OSSemCreate(&Disp_Sem,"Display Semaphore",0,&os_err); // Creates display semaphore
  LCDErrorDisp(os_err);  
  OSQCreate(&LEDs_Q,"Task LED Msg Queue",10,&os_err); // Create Messgae queue for Accel Data
  LCDErrorDisp(os_err);
}


// Statistics Display function

static void App_StatDisp (void * p_arg)
{ 
  OS_ERR err;
  CPU_TS  ts;
  unsigned short time_us;
  uint32_t time_ovf;
  while(DEF_ON)
  {
  OSSemPend(&Disp_Sem,0,OS_OPT_PEND_BLOCKING,&ts,&err);
  LCDErrorDisp(err);
  LCDClearScreen();
  R_INTC8_Stop();
  R_INTC10_Stop();
  for (int i=0 ; i<MAX_NUM ; i++) 
        { switch(i)
          {
          case LCDCLRSCR:
              LCDPrintf(0,0,"LCD_CLR_SCR");
              break;
          case LCDFNT:
              LCDPrintf(0,0,"LCD_FONT");
              break;
          case LCDCLRLIN:
              LCDPrintf(0,0,"LCD_CLR_LINE");
              break;
          case LCDSTR:
              LCDPrintf(0,0,"LCD_STRING");
              break;
          case LCDCHR:
              LCDPrintf(0,0,"LCD_CHAR");
              break;
          case LCDINV:
              LCDPrintf(0,0,"LCD_INVERT");
              break;
          case ACCELTX:
              LCDPrintf(0,0,"SEM_I2CTX");
              break;
          case ACCELRX:
              LCDPrintf(0,0,"SEM_I2CRX");
              break;
          }
          LCDPrintf(1,0,"Min: %u",Stat_list[i].min);
          LCDPrintf(2,0,"Max: %u",Stat_list[i].max);
          LCDPrintf(3,0,"Avg: %u",Stat_list[i].mean);
          LCDPrintf(4,0,"Mean: %u",(Stat_list[i].min + Stat_list[i].max)/2 );
          LCDPrintf(7,0,"Wait...");
          LCDPrintf(6,0,"CPU:%3u ",OSStatTaskCPUUsage);
          button_flag_8 =0;
          time_us =TCR10;
          time_ovf = overflow_count;
          while(!button_flag_8) {if((((overflow_count-time_ovf)*65536)+time_us-TCR10)>ms_250) // 250ms debounce
                                              {R_INTC8_Start();LCDPrintf(7,0,"Press Sw2");} } // Switch 2 to change page
          LCDClearScreen();
          R_INTC8_Stop();
        } 
        read_stats();
 for (int i=0 ; i<NUM_TASKS ; i++)  
 {                     
   LCDClearScreen();
     switch(p_stats[i].prio)
          {
          case STRTTSK:
              LCDPrintf(0,0,"STRTTSK");
              break;
          case TASK1:
              LCDPrintf(0,0,"TASK1");
              break;
          case TSKLEDS:
              LCDPrintf(0,0,"TSKLEDS");
              break;
          case TSKACCEL:
              LCDPrintf(0,0,"TSKACCEL");
              break;
          case TSKSTATS:
              LCDPrintf(0,0,"TSKSTATS");
              break;
		   default:
			  LCDPrintf(0,0,"TSKUNKWN");
              break;			   
          }
   LCDPrintf(1,0,"USG: %u",p_stats[i].usage);
   LCDPrintf(2,0,"MAXSTK: %u",p_stats[i].max_stk);
   LCDPrintf(7,0,"Wait...");
    button_flag_8 =0;
    time_us =TCR10;
    time_ovf = overflow_count;
    while(!button_flag_8) {if((((overflow_count-time_ovf)*65536)+time_us-TCR10)>ms_250) // 250ms debounce
                                        {R_INTC8_Start();LCDPrintf(7,0,"Press Sw2");} } // Switch 2 to change page
    
    R_INTC8_Stop();
  }   
  R_INTC10_Start();
  LCDClearScreen();
  OSTimeDlyHMSM(0u, 0u, 0u, 250u, OS_OPT_TIME_HMSM_STRICT, &err);
  LCDErrorDisp(err);
}
}

// Task 1 (time)
static void App_Task1 (void * p_arg)
{
	OS_ERR err;
  	uint32_t n=0;

	p_arg = p_arg;
	while (1) {
                LCDPrintf(6,0,"Sw1 fr Stats");  
	        LCDPrintf(7, 0, "T1:%6ld", n++);
                OSTimeDlyHMSM(0u, 0u, 0u, 51u,
                     OS_OPT_TIME_HMSM_STRICT,
                      &err);
                LCDErrorDisp(err);
                OSTimeDlyHMSM(0u, 0u, 0u, 250u, OS_OPT_TIME_HMSM_STRICT, &err);
                LCDErrorDisp(err);
	}

}

//Plumbbob Task
static void App_TaskLeds(void *p_arg)
{
  Accel_Data *data;
  CPU_INT16U size = sizeof(Accel_Data);
  OS_ERR err;
  CPU_TS ts;
  double a_xy;
  int LED;
  while(DEF_ON)
  {
  data = OSQPend(&LEDs_Q,0,OS_OPT_PEND_BLOCKING,&size,&ts,&err);
  LCDErrorDisp(err);
  a_xy = atan2(data->xx,data->yy) * (180/PI);
  LED = (((int)a_xy) + 180)/30;
  clearLEDS();
  if(data->zz >= -70 && data->zz <= 70)
  {
	switch(LED)
		{ case 11:LED_3_R = LED_ON;break;
		  case 0: LED_4_G = LED_ON;break;
		  case 1: LED_5_R = LED_ON;break;
		  case 2: LED_6_G = LED_ON;break;
		  case 3: LED_7_R = LED_ON;break;
		  case 4: LED_8_G = LED_ON;break;
		  case 5: LED_9_R = LED_ON;break;
		  case 6: LED_10_G= LED_ON;break;
		  case 7: LED_11_R= LED_ON;break;
		  case 8: LED_12_G= LED_ON;break;
		  case 9: LED_13_R= LED_ON;break;
		  case 10:LED_14_G= LED_ON;break;
		}
  } 
  OSTimeDlyHMSM(0u, 0u, 0u, 250u, OS_OPT_TIME_HMSM_STRICT, &err);
  LCDErrorDisp(err);
  }
}
  
void clearLEDS()  // Clear all LEDS in the Circle
{
  LED_3_R = LED_OFF;
  LED_5_R = LED_OFF;
  LED_7_R = LED_OFF;
  LED_4_G = LED_OFF;
  LED_6_G = LED_OFF;
  LED_8_G = LED_OFF;
  LED_9_R = LED_OFF;
  LED_11_R= LED_OFF;
  LED_13_R= LED_OFF;
  LED_10_G= LED_OFF;
  LED_12_G= LED_OFF;
  LED_14_G= LED_OFF;
}

void read_stats() // Read Statistics from TCB
{
OS_TCB *p_tcb;
int i=0;
    p_tcb = OSTaskDbgListPtr;
 while ((p_tcb != (OS_TCB *)0) || i < NUM_TASKS) 
 {                     
	 p_stats[i].prio = p_tcb->Prio;
	 p_stats[i].max_stk = p_tcb->MaxStk;
	 p_stats[i].usage = p_tcb->CPUUsage;
	 i++;
	 p_tcb = p_tcb->DbgNextPtr;
 }
}