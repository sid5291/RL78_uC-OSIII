#ifndef ACCEL_H
#define ACCEL_H

/* Accelerometer constants */
#define ACCEL_WADDR         0x3A
#define ACCEL_RADDR         0x3B
#define ACCEL_REG_PWRCTL    0x2D
#define ACCEL_REG_DATASTART 0x32
#define ACCEL_CTL_MEASURE   0x08

extern void InitializeAccelerometer(void);
extern void App_TaskAccel (void * p_arg);

extern T_glyphHandle  G_lcd;

typedef struct 
{
  signed int xx;
  signed int yy;
  signed int zz;
}Accel_Data;

#endif // #ifndef ACCEL_H
