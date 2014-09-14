#ifndef _LCD_H_
#define _LCD_H_

#include <includes.h>

/*-------------------------------------------------------------------------*
 * Defines
 *-------------------------------------------------------------------------*/
#define LCD_H 		(64)
#define LCD_W		(96)

typedef enum {
	FONT_LOGOS = 2u,
	FONT_LARGE = 1u,
	FONT_SMALL = 0u
} LCDFONT;

void LCDInit(void);

void LCDFont(LCDFONT font);

void LCDClearScreen(void);
void LCDClearLine(uint8_t line);

void LCDString(const char *aStr, uint8_t aX, uint8_t aY);
void LCDStringPos(const char *aStr, uint8_t aPos, uint8_t aY);
void LCDStringLine(const char *aStr, uint8_t aX, uint8_t aLine);
void LCDStringPosLine(const char *aStr, uint8_t aPos, uint8_t aLine);

void LCDChar(char aChar, uint8_t aX, uint8_t aY);
void LCDCharPosLine(char aChar, uint8_t aPos, uint8_t aLine);
void LCDPrintf(uint8_t aLine, uint8_t aPos, char *aFormat, ...);

void LCDInvert();

void LCDErrorDisp(OS_ERR);
void LEDErrorDisp(OS_ERR);
void LCD_ObjCreate();

#endif

