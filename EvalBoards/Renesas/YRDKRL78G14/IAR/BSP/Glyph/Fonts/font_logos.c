/*-------------------------------------------------------------------------*
 * File:  font_bitmap.c
 *-------------------------------------------------------------------------*
 * Description:
 *      Overrides the glyph library bitmap font for custom use
 *-------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
 * Copyright (C) 2011 Future Designs, Inc.
 *--------------------------------------------------------------------------
 *
 *    *===============================================================*
 *    |  Future Designs, Inc. can port uEZ(tm) to your own hardware!  |
 *    |             We can get you up and running fast!               |
 *    |      See http://www.teamfdi.com/uez for more details.         |
 *    *===============================================================*
 *
 *-------------------------------------------------------------------------*/
#include "glyph_cfg.h"


const uint8_t Renesas_Logo[] = {
    80, 16, // width=80, height=16
	0x08, 0x0c, 0x04, 0x06, 0x02, 0x02, 0x82, 0x82, 0xC6, 0xFE, 0xFE, 0xFE, 0x7C, 0x38, 0x00, 0x00,
	0xE0, 0xF0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,
	0xF0, 0xF0, 0x60, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0xF0, 0xF0, 0x00, 0x00,
	0xE0, 0xF0, 0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00,
	0x60, 0xF0, 0xF0, 0x90, 0x90, 0x90, 0x10, 0x10, 0x10, 0x00,
	0x00, 0x00, 0x00, 0xC0, 0xE0, 0x30, 0x70, 0xF0, 0xC0, 0x00, 0x00, 0x00,
	0x60, 0xF0, 0xF0, 0x90, 0x90, 0x90, 0x10, 0x10, 0x10, 0x00,
	
	0x0F, 0x0F,	0x0F, 0x0F, 0x00, 0x00, 0x01, 0x01, 0x07, 0x0F, 0x1F, 0x1C, 0x30, 0x20, 0x40, 0x40,
	0x0F, 0x0F, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x00,
	0x0F, 0x0F, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0E, 0x0F, 0x0F, 0x00, 0x00,
	0x0F, 0x0F, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x08, 0x00,
	0x08, 0x08, 0x09, 0x09, 0x09, 0x0B, 0x0B, 0x0F, 0x0F, 0x06,
	0x08, 0x0C, 0x0F, 0x03, 0x00, 0x08, 0x08, 0x09, 0x0F, 0x0F, 0x0E, 0x08,
	0x08, 0x08, 0x09, 0x09, 0x09, 0x0B, 0x0B, 0x0F, 0x0F, 0x06,
};

const uint8_t * const Logos_table[256] = {
	Renesas_Logo,
	0,
	0,
	0,
	0,
	0,
	0,
    0,
    0,
    0,
    0,
    0,
	0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};
