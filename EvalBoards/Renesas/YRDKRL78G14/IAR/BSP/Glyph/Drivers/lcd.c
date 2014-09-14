//#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <includes.h>
#include "glyph_api.h"
#include "ST7579_LCD.h"
#include "lcd.h"
#include "ior5f104pj.h"
#include "r_cg_userdefine.h"


/*-------------------------------------------------------------------------*
 * Globals
 *-------------------------------------------------------------------------*/
static  T_glyphHandle  G_lcd;
extern stats  Stat_list[MAX_NUM];


OS_MUTEX LCD_Mutex = NULL;

CPU_TS_TMR ovf_init,ovf_fin,wait_t;

uint8_t G_CharWidth = 5u;
uint8_t G_CharHeight = 7u;


void LCD_ObjCreate()
{
  OS_ERR err;
  OSMutexCreate(&LCD_Mutex,"LCD Mutex",&err);
  LEDErrorDisp(err);
  
}

void LCDInit (void)
{
    T_glyphError  err;

    err = GlyphOpen(&G_lcd, 0);
    if (err == GLYPH_ERROR_NONE) {
        GlyphNormalScreen(G_lcd);
        GlyphClearScreen(G_lcd);
		LCDFont(FONT_LARGE);
    }
}

void LEDErrorDisp(OS_ERR err)
{
  if(err != OS_ERR_NONE)
  { 
    __disable_interrupt();
    LED_5_R = LED_ON;
    while(1)
    { };
  }
}
void LCDErrorDisp(OS_ERR err)
{
switch(err)
{
case OS_ERR_PEND_ABORT:
   {
   LCDPrintf(7,0,"SEM ABORT");
   break;
   }
case OS_ERR_OBJ_TYPE:
  {
    LCDPrintf(7,0,"OBJ NC");
    break;
  }
case OS_ERR_OBJ_DEL:
  {
  LCDPrintf(7,0,"SEM/MUTEX DEL");
  break;
  }
case OS_ERR_OBJ_PTR_NULL:
  {
   LCDPrintf(7,0,"MUTEX NULL");
   break;
  }
case OS_ERR_MUTEX_OWNER:
  {
    LCDPrintf(7,0,"MUTEX OWN");
    break;
  }
case OS_ERR_OPT_INVALID :
  {
    LCDPrintf(7,0,"INV OPT");
    break;
  }
case OS_ERR_SCHED_LOCKED :
  {
    LCDPrintf(7,0,"SCHED LOCK");
    break;
  }
case OS_ERR_TIME_INVALID_HOURS :
  {
    LCDPrintf(7,0,"INV HRS");
    break;
  }
case OS_ERR_TIME_INVALID_MINUTES :
  {
    LCDPrintf(7,0,"INV MIN");
    break;
  }
case OS_ERR_TIME_INVALID_SECONDS :
  {
    LCDPrintf(7,0,"INV SEC");
    break;
  }
case OS_ERR_TIME_INVALID_MILLISECONDS :
  {
    LCDPrintf(7,0,"INV MSEC");
    break;
  }
case OS_ERR_TIME_ZERO_DLY :
  {
    LCDPrintf(7,0,"ZERO DLY");
    break;
  }
case OS_ERR_MSG_POOL_EMPTY:
  {
    LCDPrintf(7,0,"MSG POOL EMP");
    break;
  }
case OS_ERR_NONE:
  {
  //LCDPrintf(7,0,"skumar15");
  break;
  }
default:
  {
   LCDPrintf(7,0,"OS ERR");
   break;
  }       
}
}

void LCDClearScreen (void)
{
  OS_ERR err;
  CPU_TS ts;
  ovf_init = OS_TS_GET();  
  OSMutexPend(&LCD_Mutex,0,OS_OPT_PEND_BLOCKING,&ts,&err);
  ovf_fin = OS_TS_GET();   
  wait_t = ovf_fin-ovf_init; 
  Stat_list[LCDCLRSCR].min = MIN(Stat_list[LCDCLRSCR].min,wait_t);
  Stat_list[LCDCLRSCR].max = MAX(Stat_list[LCDCLRSCR].max,wait_t);
  Stat_list[LCDCLRSCR].samples++;
  Stat_list[LCDCLRSCR].total =   Stat_list[LCDCLRSCR].total + (wait_t);
  Stat_list[LCDCLRSCR].mean =    Stat_list[LCDCLRSCR].total/Stat_list[LCDCLRSCR].samples;
  LEDErrorDisp(err);
    GlyphClearScreen(G_lcd);
   OSMutexPost(&LCD_Mutex,OS_OPT_POST_NONE,&err);
   LEDErrorDisp(err);
}


void LCDFont (LCDFONT font)
{ OS_ERR err;
  CPU_TS ts;
  ovf_init = OS_TS_GET();  
  OSMutexPend(&LCD_Mutex,0,OS_OPT_PEND_BLOCKING,&ts,&err);
  ovf_fin = OS_TS_GET();   
  wait_t = ovf_fin-ovf_init; 
  Stat_list[LCDFNT].min = MIN(Stat_list[LCDFNT].min,wait_t);
  Stat_list[LCDFNT].max = MAX(Stat_list[LCDFNT].max,wait_t);
  Stat_list[LCDFNT].samples++;
  Stat_list[LCDFNT].total =   Stat_list[LCDFNT].total + (wait_t);
  Stat_list[LCDFNT].mean =    Stat_list[LCDFNT].total/Stat_list[LCDFNT].samples;
  LEDErrorDisp(err);    
    switch (font) {
    case FONT_LOGOS:
                
		GlyphSetFont(G_lcd, GLYPH_FONT_LOGOS);
		G_CharWidth = 16u;
		G_CharHeight = 16u;
       	break;

    case FONT_LARGE:
       	GlyphSetFont(G_lcd, GLYPH_FONT_8_BY_8);
		G_CharWidth = 8u;
		G_CharHeight = 8u;
       	break;

    case FONT_SMALL:
       	GlyphSetFont(G_lcd, GLYPH_FONT_5_BY_7);
		G_CharWidth = 5u;
		G_CharHeight = 7u;
       	break;
    }
  OSMutexPost(&LCD_Mutex,OS_OPT_POST_NONE,&err);
  LEDErrorDisp(err);
}

void LCDClearLine (uint8_t aLine)
{ OS_ERR err;
  CPU_TS ts;
  ovf_init = OS_TS_GET();  
  OSMutexPend(&LCD_Mutex,0,OS_OPT_PEND_BLOCKING,&ts,&err);
  ovf_fin = OS_TS_GET();   
  wait_t = ovf_fin-ovf_init; 
  Stat_list[LCDCLRLIN].min = MIN(Stat_list[LCDCLRLIN].min,wait_t);
  Stat_list[LCDCLRLIN].max = MAX(Stat_list[LCDCLRLIN].max,wait_t);
  Stat_list[LCDCLRLIN].samples++;
  Stat_list[LCDCLRLIN].total =   Stat_list[LCDCLRLIN].total + (wait_t);
  Stat_list[LCDCLRLIN].mean =    Stat_list[LCDCLRLIN].total/Stat_list[LCDCLRLIN].samples;
  LEDErrorDisp(err); 
    uint8_t y = aLine * G_CharHeight;
    GlyphEraseBlock(G_lcd, 0u, y, 95u, y + 7u);

   OSMutexPost(&LCD_Mutex,OS_OPT_POST_NONE,&err);
   LEDErrorDisp(err);
}

void LCDString (const char *aStr, uint8_t aX, uint8_t aY)
{ OS_ERR err;
  CPU_TS ts;
  ovf_init = OS_TS_GET();  
  OSMutexPend(&LCD_Mutex,0,OS_OPT_PEND_BLOCKING,&ts,&err);
  ovf_fin = OS_TS_GET();   
  wait_t = ovf_fin-ovf_init; 
  Stat_list[LCDSTR].min = MIN(Stat_list[LCDSTR].min,wait_t);
  Stat_list[LCDSTR].max = MAX(Stat_list[LCDSTR].max,wait_t);
  Stat_list[LCDSTR].samples++;
  Stat_list[LCDSTR].total =   Stat_list[LCDSTR].total + (wait_t);
  Stat_list[LCDSTR].mean =    Stat_list[LCDSTR].total/Stat_list[LCDSTR].samples;
  LEDErrorDisp(err); 
  
    GlyphSetXY (G_lcd, aX, aY);
    GlyphString(G_lcd, (uint8_t *)aStr, strlen(aStr));

   OSMutexPost(&LCD_Mutex,OS_OPT_POST_NONE,&err);
   LEDErrorDisp(err);    

}

void LCDStringPosLine (const char *aStr, uint8_t aPos, uint8_t aLine)
{
    uint8_t  x = aPos  * G_CharWidth;
	uint8_t  y = aLine * G_CharHeight;

    LCDString(aStr, x, y);
}

void LCDChar(char aChar, uint8_t aX, uint8_t aY)
{ OS_ERR err;
  CPU_TS ts;
  
  ovf_init = OS_TS_GET();  
  OSMutexPend(&LCD_Mutex,0,OS_OPT_PEND_BLOCKING,&ts,&err);
  ovf_fin = OS_TS_GET();   
  wait_t = ovf_fin-ovf_init; 
  Stat_list[LCDCHR].min = MIN(Stat_list[LCDCHR].min,wait_t);
  Stat_list[LCDCHR].max = MAX(Stat_list[LCDCHR].max,wait_t);
  Stat_list[LCDCHR].samples++;
  Stat_list[LCDCHR].total =   Stat_list[LCDCHR].total + (wait_t);
  Stat_list[LCDCHR].mean =    Stat_list[LCDCHR].total/Stat_list[LCDCHR].samples;
  LEDErrorDisp(err); 
  
  
    GlyphSetXY (G_lcd, aX, aY);
    GlyphChar(G_lcd, aChar);
   
   OSMutexPost(&LCD_Mutex,OS_OPT_POST_NONE,&err);
   LEDErrorDisp(err);
   
}

void LCDCharPosLine(char aChar, uint8_t aPos, uint8_t aLine)
{
    uint8_t  x;
    uint8_t  y;

    x = aPos  * G_CharWidth;
    y = aLine * G_CharHeight;

	LCDChar(aChar, x, y);
}

void  LCDPrintf(uint8_t aLine, uint8_t aPos, char *aFormat, ...)
{
    uint8_t  x, y;
    char buffer[100];
    va_list marker;

	x = aPos * G_CharWidth;
	y = aLine * G_CharHeight;

    // Convert to a string for output
    va_start(marker, aFormat);
    vsprintf(buffer, aFormat, marker);
    va_end(marker);

    LCDString(buffer, x, y);
}

void  LCDInvert()
{ OS_ERR err;
  CPU_TS ts;
  ovf_init = OS_TS_GET();  
  OSMutexPend(&LCD_Mutex,0,OS_OPT_PEND_BLOCKING,&ts,&err);
  ovf_fin = OS_TS_GET();   
  wait_t = ovf_fin-ovf_init; 
  Stat_list[LCDINV].min = MIN(Stat_list[LCDINV].min,wait_t);
  Stat_list[LCDINV].max = MAX(Stat_list[LCDINV].max,wait_t);
  Stat_list[LCDINV].samples++;
  Stat_list[LCDINV].total =   Stat_list[LCDINV].total + (wait_t);
  Stat_list[LCDINV].mean =    Stat_list[LCDINV].total/Stat_list[LCDINV].samples;
  LEDErrorDisp(err); 
  
	GlyphInvertScreen(G_lcd);
        
   OSMutexPost(&LCD_Mutex,OS_OPT_POST_NONE,&err);
   LEDErrorDisp(err);
}
