#include "r_cg_macrodriver.h"
#include "r_cg_serial.h"
#include "r_cg_userdefine.h"
#include <includes.h>
#include <string.h>
#include "accel.h"
#include "lcd.h"

extern OS_SEM Accel_Sem;  //Accelerometer Semaphore
extern OS_Q  LEDs_Q;     //LED Task Message Queue
extern stats  Stat_list[MAX_NUM]; 



void InitializeAccelerometer(void) {
	unsigned char i2cbuf[2];/* Buffer for I2C transactions */

	LCDStringPosLine("Init Accel", 0, 1);

	// initialize accelerometer
	// Set the 'measure' bit to turn on accelerometer
  	i2cbuf[0] = ACCEL_REG_PWRCTL;
  	i2cbuf[1] = ACCEL_CTL_MEASURE;
  	R_IICA0_Master_Send(ACCEL_WADDR, i2cbuf, 2, 32);

  	while (IICBSY0)
		;			/* Busy-wait until I2C TX is done */

	LCDStringPosLine("Done", 0, 2);
}

void App_TaskAccel (void * p_arg)
{
	OS_ERR err;
        CPU_TS timestamp;
        CPU_TS_TMR ovf_init,ovf_fin,wait_t;
        
	unsigned char i2cbuf[6]; /* Buffer for I2C transactions */
  	signed int datax = 0;   /* x axis acceleration */
  	signed int datay = 0;   /* y axis acceleration */
  	signed int dataz = 0;   /* z axis acceleration */
        static Accel_Data data;
	p_arg = p_arg;

	// clear initialization message from LCD
	LCDClearLine(1);
	LCDClearLine(2);

	while (1) {
  		/*** ACCELEROMETER HANDLING ***/

		/* Inform accelerometer of starting address at which to read next */
		i2cbuf[0] = ACCEL_REG_DATASTART;
		R_IICA0_Master_Send(ACCEL_WADDR, i2cbuf, 1, 32);
		//while (IICBSY0);
                  ovf_init = OS_TS_GET();
                  OSSemPend(&Accel_Sem,0,OS_OPT_PEND_BLOCKING,&timestamp,&err);
                  ovf_fin = OS_TS_GET();
                  wait_t = ovf_fin-ovf_init;
                  Stat_list[ACCELTX].min = MIN(Stat_list[ACCELTX].min,wait_t);
                  Stat_list[ACCELTX].max = MAX(Stat_list[ACCELTX].max,wait_t);
                  Stat_list[ACCELTX].samples++;
                  Stat_list[ACCELTX].total =   Stat_list[ACCELTX].total + wait_t;
                  Stat_list[ACCELTX].mean =    Stat_list[ACCELTX].total/Stat_list[ACCELTX].samples;

                  LCDErrorDisp(err);
                /* Semaphore pending until I2C TX is done */

		/* Read axis data (three at 2 bytes each) from the accelerometer */
		R_IICA0_Master_Receive(ACCEL_RADDR, i2cbuf, 6, 32);
		//while (IICBSY0);    /* Busy-wait until I2C RX is done */
                  ovf_init = OS_TS_GET();
                  OSSemPend(&Accel_Sem,0,OS_OPT_PEND_BLOCKING,&timestamp,&err);
                  ovf_fin = OS_TS_GET();
                  wait_t = ovf_fin-ovf_init;
                  Stat_list[ACCELRX].min = MIN(Stat_list[ACCELRX].min,wait_t);
                  Stat_list[ACCELRX].max = MAX(Stat_list[ACCELRX].max,wait_t);
                  Stat_list[ACCELRX].samples++;
                  Stat_list[ACCELRX].total =   Stat_list[ACCELRX].total + wait_t;
                  Stat_list[ACCELRX].mean =    Stat_list[ACCELRX].total/Stat_list[ACCELTX].samples;

                  LCDErrorDisp(err);
                

		/* Convert the returned x and y data bytes into signed data */
		datax = ((signed int)i2cbuf[1] << 8) | i2cbuf[0];
		datay = ((signed int)i2cbuf[3] << 8) | i2cbuf[2];
		dataz = ((signed int)i2cbuf[5] << 8) | i2cbuf[4];
                data.xx = datax;
                data.yy = datay;
                data.zz = dataz;
                OSQPost(&LEDs_Q,&data,sizeof(data),OS_OPT_POST_FIFO,&err);
                LCDErrorDisp(err);
		/*** LCD HANDLING ***/
                LCDClearLine(1);
                LCDClearLine(2);
                LCDClearLine(3);
		LCDPrintf(1, 0, "X:%5d", datax);
		LCDPrintf(2, 0, "Y:%5d", datay);
		LCDPrintf(3, 0, "Z:%5d", dataz);

	   	OSTimeDlyHMSM(0u, 0u, 0u, 250u, OS_OPT_TIME_HMSM_STRICT, &err);
                LCDErrorDisp(err);
	}
}
