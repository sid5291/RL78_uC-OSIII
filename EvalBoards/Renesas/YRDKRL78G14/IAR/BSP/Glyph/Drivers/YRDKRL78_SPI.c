/******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized.
* This software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES
* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY,
* INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY
* DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES
* FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS
* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this
* software and to discontinue the availability of this software.
* By using this software, you agree to the additional terms and
* conditions found by accessing the following link:
* http://www.renesas.com/disclaimer
******************************************************************************/
/* Copyright (C) 2010 Renesas Electronics Corporation. All rights reserved. */
/* Code written for Renesas by Future Designs, Inc. www.teamfdi.com */

/******************************************************************************
* File Name : YRDKRL78_RLCD0.c
* Version : 1.00
* Device(s) : RLCD0 Communications
* Tool-Chain : Glyph - The Generic API for Graphics LCD API version 1.00
* H/W Platform : RL78 Group CPU
* Description : Glyph API RL78 RLCD Transmitter 0 Operation channel 3
* Routines for LCD code running on RL78 MCU, RLCD0.
* This program uses RLCD0.  The Chip Select for the flash device (LCD)
* is set to PC_2.
*       Manufacturer: Renesas
*       Communications Protocol: LCD 3-Wire
*                                Transmitt only
*                                MASTER
*       Transmitter Number: 0
*       channel: 3
*       Chip Select Port: PC.2
*       RLCD Clock Speed: 25MHz
******************************************************************************
* History :
******************************************************************************/

/******************************************************************************
Includes “YRDKRL78 RLCD Includes”
******************************************************************************/
#include "platform_cfg.h"

#include "intrinsics.h"
#include "ior5f.h"

#include "glyph_api.h"

void YRDKRL78_LCD_SendByte(uint8_t *aData, uint32_t aLength);
void YRDKRL78_LCD_ResetIO(void);
void YRDKRL78_LCD_RS_Start(void);
void YRDKRL78_LCD_RS_End(void);
void YRDKRL78_LCD_CS_Start(void);
void YRDKRL78_LCD_CS_End(void);

#define NOP	__no_operation

#define _6400_CSI10_DIVISOR			    0x6400U
#define _0400_CSI10_DIVISOR			    0x0400U
#define _0400_CSI21_DIVISOR			    0x0400U

//	Serial Clock Select Register m (SPSm)
#define _0000_SAU_CK00_FCLK_0			0x0000U	// ck00-fclk

//	Format of Serial Flag Clear Trigger Register mn (SIRmn)
#define	_0001_SAU_SIRMN_OVCTMN			0x0001U
#define	_0002_SAU_SIRMN_PECTMN			0x0002U
#define	_0004_SAU_SIRMN_FECTMN			0x0004U

//	Serial Channel Start Register m (SSm)
#define _0004_SAU_CH2_START_TRG_ON		0x0004U	// sets SEm2 to 1 and enters the communication wait status
#define _0002_SAU_CH1_START_TRG_ON		0x0002U	// sets SEm1 to 1 and enters the communication wait status

//	Serial Channel Stop Register m (STm)
#define _0004_SAU_CH2_STOP_TRG_ON		0x0004U	// operation is stopped (stop trigger is generated)
#define _0002_SAU_CH1_STOP_TRG_ON		0x0002U	// operation is stopped (stop trigger is generated)

//	Serial Mode Register mn (SMRmn)
#define	_0020_SAU_SMRMN_INITIALVALUE	0x0020U
#define _0000_SAU_CLOCK_SELECT_CK00		0x0000U	// operation clock CK0 set by PRS register
#define _0000_SAU_CK01_FCLK_0			0x0000U	// ck01-fclk
#define _0000_SAU_CLOCK_MODE_CKS		0x0000U	// divided operation clock MCK specified by CKSmn bit
#define _0000_SAU_TRIGGER_SOFTWARE		0x0000U	// only software trigger is valid
#define _0000_SAU_MODE_CSI			    0x0000U	// CSI mode
#define _0000_SAU_TRANSFER_END			0x0000U	// transfer end interrupt

//	Serial Communication Operation Setting Register mn (SCRmn)
#define _8000_SAU_TRANSMISSION			0x8000U	// transmission only
#define _0000_SAU_TIMING_1			    0x0000U	// type 1
#define _0000_SAU_MSB				    0x0000U	// MSB
#define _0007_SAU_LENGTH_8			    0x0007U	// 8-bit data length

//	Serial Output Enable Register m (SOEm)
#define _0004_SAU_CH2_OUTPUT_ENABLE		0x0004U	// stops output by serial communication operation
#define _0002_SAU_CH1_OUTPUT_ENABLE		0x0002U	// stops output by serial communication operation

//	Serial Output Register m (SOm)
#define _0004_SAU_CH2_DATA_OUTPUT_1		0x0004U	// Serial data output value is "1"
#define _0400_SAU_CH2_CLOCK_OUTPUT_1	0x0400U	// Serial clock output value is "1"
#define _0002_SAU_CH1_DATA_OUTPUT_1		0x0002U	// Serial data output value is "1"
#define _0200_SAU_CH1_CLOCK_OUTPUT_1	0x0200U	// Serial clock output value is "1"

//	Format of Serial Status Register mn (SSRmn)
#define _0040_SAU_UNDER_EXECUTE			0x0040U	/* communication is under execution */
#define _0020_SAU_VALID_STORED			0x0020U	/* valid data is stored in the SDRmn register */
#define _0004_SAU_FRAM_ERROR			0x0004U	/* a framing error occurs during UART reception */
#define _0002_SAU_PARITY_ERROR			0x0002U	/* a parity error occurs during UART reception or ACK is not detected during I2C transmission */
#define _0001_SAU_OVERRUN_ERROR			0x0001U	/* an overrun error occurs */

/******************************************************************************
* Function Name: YRDKRL78_LCD_Open
* Description : Open and setup the communications channel for the LCD.
* Argument : aHandle - the Glyph handle to setup for the LCD and Communications.
* Return Value : 0=success, not 0= error
******************************************************************************/
T_glyphError LCD_SPI_Open(T_glyphHandle aHandle)
{
  	uint32_t volatile delay;

  	// Setup CS, RS as output pins
	LCD_CTL_PORT = (1<<LCD_CTL_RS_BIT_POS) | (1<<LCD_CTL_CS_BIT_POS);
  	LCD_CTL_PORT_DIR &= (uint8_t) ~( (1<<LCD_CTL_RS_BIT_POS) | (1<<LCD_CTL_CS_BIT_POS));

  	// Reset IO
  	LCD_RESET_PORT |= (1<<LCD_RESET_BIT_POS); // Assert (#RESET-IO)
  	for (delay=0;delay<10000;delay++);
  	LCD_RESET_PORT &= (~1<<LCD_RESET_BIT_POS); // De-assert (#RESET-IO)
  	for (delay=0;delay<10000;delay++);

#ifdef RDK_RL78G13
	// SAU Init
  	SAU0EN = 1U;	/* supply SAU0 clock */
	NOP();
	NOP();
	NOP();
	NOP();
	SPS0 = _0000_SAU_CK00_FCLK_0 | _0000_SAU_CK01_FCLK_0;

  	// CSI10 Init
  	ST0 |= _0004_SAU_CH2_STOP_TRG_ON;	/* disable CSI10 */
	CSIMK10 = 1U;	/* disable INTCSI10 interrupt */
	CSIIF10 = 0U;	/* clear INTCSI10 interrupt flag */

	/* Set INTCSI10 low priority */
	CSIPR110 = 1U;
	CSIPR010 = 1U;
	SIR02 = _0004_SAU_SIRMN_FECTMN | _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;	/* clear error flag */
	SMR02 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_CLOCK_MODE_CKS | _0000_SAU_TRIGGER_SOFTWARE | _0000_SAU_MODE_CSI | _0000_SAU_TRANSFER_END;
	SCR02 = _8000_SAU_TRANSMISSION | _0000_SAU_TIMING_1 | _0000_SAU_MSB | _0007_SAU_LENGTH_8;
	SDR02 = _0400_CSI10_DIVISOR;
	SO0 |= _0400_SAU_CH2_CLOCK_OUTPUT_1;	/* CSI10 clock initial level */
	SO0 &= ~_0004_SAU_CH2_DATA_OUTPUT_1;	/* CSI10 SO initial level */
	SOE0 |= _0004_SAU_CH2_OUTPUT_ENABLE;	/* enable CSI10 output */
	/* Set SO10 pin */
	P0 |= 0x04U;
	PMC0 &= 0xFBU;
	PM0 &= 0xFBU;
	/* Set SCK10 pin */
	P0 |= 0x10U;
	PM0 &= 0xEFU;

    // CSI10 Start
    CSIIF10 = 0U;	/* clear INTCSI10 interrupt flag */
	CSIMK10 = 0U;	/* enable INTCSI10 */
	SO0 |= _0400_SAU_CH2_CLOCK_OUTPUT_1;	/* CSI10 clock initial level */
	SO0 &= ~_0004_SAU_CH2_DATA_OUTPUT_1;	/* CSI10 SO initial level */
	SOE0 |= _0004_SAU_CH2_OUTPUT_ENABLE;	/* enable CSI10 output */
	SS0 |= _0004_SAU_CH2_START_TRG_ON;	/* enable CSI10 */

#else
	// SAU Init
  	SAU1EN = 1U;	/* supply SAU1 clock */
	NOP();
	NOP();
	NOP();
	NOP();
	SPS1 = _0000_SAU_CK00_FCLK_0 | _0000_SAU_CK01_FCLK_0;

  	// CS21 Init
  	ST1 |= _0002_SAU_CH1_STOP_TRG_ON;	/* disable CSI10 */
	CSIMK21 = 1U;	/* disable INTCSI21 interrupt */
	CSIIF21 = 0U;	/* clear INTCSI21 interrupt flag */

	/* Set INTCSI21 low priority */
	CSIPR121 = 1U;
	CSIPR021 = 1U;
	SIR11 = _0004_SAU_SIRMN_FECTMN | _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;	/* clear error flag */
	SMR11 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_CLOCK_MODE_CKS | _0000_SAU_TRIGGER_SOFTWARE | _0000_SAU_MODE_CSI | _0000_SAU_TRANSFER_END;
	SCR11 = _8000_SAU_TRANSMISSION | _0000_SAU_TIMING_1 | _0000_SAU_MSB | _0007_SAU_LENGTH_8;
	SDR11 = _0400_CSI21_DIVISOR;
	SO1 |= _0200_SAU_CH1_CLOCK_OUTPUT_1;	/* CSI21 clock initial level */
	SO1 &= ~_0002_SAU_CH1_DATA_OUTPUT_1;	/* CSI21 SO initial level */
	SOE1 |= _0002_SAU_CH1_OUTPUT_ENABLE;	/* enable CSI21 output */

	/* Set SO21 pin */
	P7 |= 0x04U;
	PM7 &= 0xFBU;
	/* Set SCK21 pin */
	P7 |= 0x01U;
	PM7 &= 0xFEU;

  	// CSI21 Start
  	CSIIF21 = 0U;	/* clear INTCSI21 interrupt flag */
	CSIMK21 = 0U;	/* enable INTCSI21 */
	SO1 |= _0200_SAU_CH1_CLOCK_OUTPUT_1;	/* CSI21 clock initial level */
	SO1 &= ~_0002_SAU_CH1_DATA_OUTPUT_1;	/* CSI21 SO initial level */
	SOE1 |= _0002_SAU_CH1_OUTPUT_ENABLE;	/* enable CSI21 output */
	SS1 |= _0002_SAU_CH1_START_TRG_ON;	/* enable CSI21 */
#endif

  return GLYPH_ERROR_NONE ;
}

/******************************************************************************
* Function Name: YRDKRL78_LCD_SendCmd
* Description : Send a command define to the LCD.  The defines for all commands
* available to send to the ST7579 LCD controller are defined in the header
* for this file RL78_LCD.h.  The nCommand parameter should always be
* a define from that location.
* Argument : cCommand - 8 bits of data to be used as a command to the LCD
* Return Value : none
******************************************************************************/
void LCD_SPI_CommandSend(int8_t aCommand)
{
    uint8_t volatile delay;

		LCD_CTL_PORT &= ~(1<<LCD_CTL_RS_BIT_POS); // assert RS
  	LCD_CTL_PORT &= ~(1<<LCD_CTL_CS_BIT_POS); // assert CS

    LCD_CSIMK = 1U;     // disable CSI interrupt
    LCD_SIO = aCommand;	// started by writing data to SDR[7:0]

                        // Short Delay
    for(delay=0; delay<5; delay++);

                        // Wait for transmission end
    while(LCD_SSR & _0040_SAU_UNDER_EXECUTE);

	LCD_CTL_PORT |= (1<<LCD_CTL_RS_BIT_POS); // deassert RS
  	LCD_CTL_PORT |= (1<<LCD_CTL_CS_BIT_POS); // deassert CS
}

/******************************************************************************
* Function Name: YRDKRL78_SendData
* Description : Send 8 bits of data to the LCD RAM at the current location.
* The current location is determined and set with local functions.
* Argument : cData - 8 bits of data to be sent to the LCD
* Return Value : none
******************************************************************************/
void LCD_SPI_DataSend(int8_t aData)
{
    uint8_t delay;

  	LCD_CTL_PORT &= ~(1<<LCD_CTL_CS_BIT_POS); // assert CS

    LCD_CSIMK = 1U;	    // disable INTCSI10 interrupt
    LCD_SIO = aData;	    // started by writing data to SDR[7:0]

                        // Short Delay
    for(delay=0; delay<5; delay++);

                        // Wait for transmission end
    while(LCD_SSR & _0040_SAU_UNDER_EXECUTE);

  	LCD_CTL_PORT |= (1<<LCD_CTL_CS_BIT_POS); // deassert CS
}


