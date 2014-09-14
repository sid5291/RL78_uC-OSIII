/*-------------------------------------------------------------------------
 *      Declarations of extended SFR registers for RL78 microcontroller R5F104PJ.
 *
 *      This file can be used by both the RL78,
 *      Assembler, ARL78, and the C/C++ compiler, ICCRL78.
 *
 *      This header file is generated from the device file:
 *          DR5F104PJ.DVF
 *          Copyright(C) 2012 Renesas
 *          Format version V3.00, File version V2.00
 *-------------------------------------------------------------------------*/

#ifndef __IOR5F104PJ_EXT_H__
#define __IOR5F104PJ_EXT_H__

#if !defined(__ARL78__) && !defined(__ICCRL78__)
  #error "IOR5F104PJ_EXT.H file for use with RL78 Assembler or Compiler only"
#endif

#if defined(__ARL78__)
  #if __CORE__ != __RL78_2__
    #error "IOR5F104PJ_EXT.H file for use with ARL78 option --core rl78_2 only"
  #endif
#endif
#if defined(__ICCRL78__)
  #if __CORE__ != __RL78_2__
    #error "IOR5F104PJ_EXT.H file for use with ICCRL78 option --core rl78_2 only"
  #endif
#endif

#ifdef __IAR_SYSTEMS_ICC__

#pragma system_include

#pragma language=save
#pragma language=extended

/*----------------------------------------------
 * SFR bits (default names)
 *--------------------------------------------*/

#ifndef __RL78_BIT_STRUCTURE__
  #define __RL78_BIT_STRUCTURE__
  typedef struct
  {
    unsigned char no0:1;
    unsigned char no1:1;
    unsigned char no2:1;
    unsigned char no3:1;
    unsigned char no4:1;
    unsigned char no5:1;
    unsigned char no6:1;
    unsigned char no7:1;
  } __BITS8;
#endif

#ifndef __RL78_BIT_STRUCTURE2__
  #define __RL78_BIT_STRUCTURE2__
  typedef struct
  {
    unsigned short no0:1;
    unsigned short no1:1;
    unsigned short no2:1;
    unsigned short no3:1;
    unsigned short no4:1;
    unsigned short no5:1;
    unsigned short no6:1;
    unsigned short no7:1;
    unsigned short no8:1;
    unsigned short no9:1;
    unsigned short no10:1;
    unsigned short no11:1;
    unsigned short no12:1;
    unsigned short no13:1;
    unsigned short no14:1;
    unsigned short no15:1;
  } __BITS16;
#endif

/*----------------------------------------------
 *       Extended SFR declarations
 *--------------------------------------------*/

__near __no_init volatile union { unsigned char ADM2; __BITS8 ADM2_bit; } @ 0xF0010;
__near __no_bit_access __no_init volatile union { unsigned char ADUL; __BITS8 ADUL_bit; } @ 0xF0011;
__near __no_bit_access __no_init volatile union { unsigned char ADLL; __BITS8 ADLL_bit; } @ 0xF0012;
__near __no_bit_access __no_init volatile union { unsigned char ADTES; __BITS8 ADTES_bit; } @ 0xF0013;
__near __no_init volatile union { unsigned char PU0; __BITS8 PU0_bit; } @ 0xF0030;
__near __no_init volatile union { unsigned char PU1; __BITS8 PU1_bit; } @ 0xF0031;
__near __no_init volatile union { unsigned char PU3; __BITS8 PU3_bit; } @ 0xF0033;
__near __no_init volatile union { unsigned char PU4; __BITS8 PU4_bit; } @ 0xF0034;
__near __no_init volatile union { unsigned char PU5; __BITS8 PU5_bit; } @ 0xF0035;
__near __no_init volatile union { unsigned char PU6; __BITS8 PU6_bit; } @ 0xF0036;
__near __no_init volatile union { unsigned char PU7; __BITS8 PU7_bit; } @ 0xF0037;
__near __no_init volatile union { unsigned char PU8; __BITS8 PU8_bit; } @ 0xF0038;
__near __no_init volatile union { unsigned char PU10; __BITS8 PU10_bit; } @ 0xF003A;
__near __no_init volatile union { unsigned char PU11; __BITS8 PU11_bit; } @ 0xF003B;
__near __no_init volatile union { unsigned char PU12; __BITS8 PU12_bit; } @ 0xF003C;
__near __no_init volatile union { unsigned char PU14; __BITS8 PU14_bit; } @ 0xF003E;
__near __no_init volatile union { unsigned char PIM0; __BITS8 PIM0_bit; } @ 0xF0040;
__near __no_init volatile union { unsigned char PIM1; __BITS8 PIM1_bit; } @ 0xF0041;
__near __no_init volatile union { unsigned char PIM3; __BITS8 PIM3_bit; } @ 0xF0043;
__near __no_init volatile union { unsigned char PIM4; __BITS8 PIM4_bit; } @ 0xF0044;
__near __no_init volatile union { unsigned char PIM5; __BITS8 PIM5_bit; } @ 0xF0045;
__near __no_init volatile union { unsigned char PIM8; __BITS8 PIM8_bit; } @ 0xF0048;
__near __no_init volatile union { unsigned char PIM14; __BITS8 PIM14_bit; } @ 0xF004E;
__near __no_init volatile union { unsigned char POM0; __BITS8 POM0_bit; } @ 0xF0050;
__near __no_init volatile union { unsigned char POM1; __BITS8 POM1_bit; } @ 0xF0051;
__near __no_init volatile union { unsigned char POM3; __BITS8 POM3_bit; } @ 0xF0053;
__near __no_init volatile union { unsigned char POM4; __BITS8 POM4_bit; } @ 0xF0054;
__near __no_init volatile union { unsigned char POM5; __BITS8 POM5_bit; } @ 0xF0055;
__near __no_init volatile union { unsigned char POM7; __BITS8 POM7_bit; } @ 0xF0057;
__near __no_init volatile union { unsigned char POM8; __BITS8 POM8_bit; } @ 0xF0058;
__near __no_init volatile union { unsigned char POM14; __BITS8 POM14_bit; } @ 0xF005E;
__near __no_init volatile union { unsigned char PMC0; __BITS8 PMC0_bit; } @ 0xF0060;
__near __no_init volatile union { unsigned char PMC1; __BITS8 PMC1_bit; } @ 0xF0061;
__near __no_init volatile union { unsigned char PMC10; __BITS8 PMC10_bit; } @ 0xF006A;
__near __no_init volatile union { unsigned char PMC12; __BITS8 PMC12_bit; } @ 0xF006C;
__near __no_init volatile union { unsigned char PMC14; __BITS8 PMC14_bit; } @ 0xF006E;
__near __no_init volatile union { unsigned char NFEN0; __BITS8 NFEN0_bit; } @ 0xF0070;
__near __no_init volatile union { unsigned char NFEN1; __BITS8 NFEN1_bit; } @ 0xF0071;
__near __no_init volatile union { unsigned char NFEN2; __BITS8 NFEN2_bit; } @ 0xF0072;
__near __no_init volatile union { unsigned char ISC; __BITS8 ISC_bit; } @ 0xF0073;
__near __no_bit_access __no_init volatile union { unsigned char TIS0; __BITS8 TIS0_bit; } @ 0xF0074;
__near __no_bit_access __no_init volatile union { unsigned char ADPC; __BITS8 ADPC_bit; } @ 0xF0076;
__near __no_bit_access __no_init volatile union { unsigned char PIOR0; __BITS8 PIOR0_bit; } @ 0xF0077;
__near __no_bit_access __no_init volatile union { unsigned char IAWCTL; __BITS8 IAWCTL_bit; } @ 0xF0078;
__near __no_bit_access __no_init volatile union { unsigned char PIOR1; __BITS8 PIOR1_bit; } @ 0xF0079;
__near __no_init volatile union { unsigned char PER1; __BITS8 PER1_bit; } @ 0xF007A;
__near __no_init volatile union { unsigned char PMS; __BITS8 PMS_bit; } @ 0xF007B;
__near __no_init volatile union { unsigned char GDIDIS; __BITS8 GDIDIS_bit; } @ 0xF007D;
__near __no_init volatile union { unsigned char DFLCTL; __BITS8 DFLCTL_bit; } @ 0xF0090;
__near __no_bit_access __no_init volatile union { unsigned char HIOTRM; __BITS8 HIOTRM_bit; } @ 0xF00A0;
__near __no_bit_access __no_init volatile union { unsigned char HOCODIV; __BITS8 HOCODIV_bit; } @ 0xF00A8;
__near __no_bit_access __no_init volatile const union { unsigned char TEMPCAL0; __BITS8 TEMPCAL0_bit; } @ 0xF00AC;
__near __no_bit_access __no_init volatile const union { unsigned char TEMPCAL1; __BITS8 TEMPCAL1_bit; } @ 0xF00AD;
__near __no_bit_access __no_init volatile const union { unsigned char TEMPCAL2; __BITS8 TEMPCAL2_bit; } @ 0xF00AE;
__near __no_bit_access __no_init volatile const union { unsigned char TEMPCAL3; __BITS8 TEMPCAL3_bit; } @ 0xF00AF;
__near __no_init volatile union { unsigned char PER0; __BITS8 PER0_bit; } @ 0xF00F0;
__near __no_bit_access __no_init volatile union { unsigned char OSMC; __BITS8 OSMC_bit; } @ 0xF00F3;
__near __no_init volatile union { unsigned char RMC; __BITS8 RMC_bit; } @ 0xF00F4;
__near __no_init volatile union { unsigned char RPECTL; __BITS8 RPECTL_bit; } @ 0xF00F5;
__near __no_bit_access __no_init volatile const union { unsigned char BCDADJ; __BITS8 BCDADJ_bit; } @ 0xF00FE;
__near __no_bit_access __no_init volatile const union { unsigned short SSR00; __BITS16 SSR00_bit; struct { union { unsigned char SSR00L; __BITS8 SSR00L_bit; }; }; } @ 0xF0100;
__near __no_bit_access __no_init volatile const union { unsigned short SSR01; __BITS16 SSR01_bit; struct { union { unsigned char SSR01L; __BITS8 SSR01L_bit; }; }; } @ 0xF0102;
__near __no_bit_access __no_init volatile const union { unsigned short SSR02; __BITS16 SSR02_bit; struct { union { unsigned char SSR02L; __BITS8 SSR02L_bit; }; }; } @ 0xF0104;
__near __no_bit_access __no_init volatile const union { unsigned short SSR03; __BITS16 SSR03_bit; struct { union { unsigned char SSR03L; __BITS8 SSR03L_bit; }; }; } @ 0xF0106;
__near __no_bit_access __no_init volatile union { unsigned short SIR00; __BITS16 SIR00_bit; struct { union { unsigned char SIR00L; __BITS8 SIR00L_bit; }; }; } @ 0xF0108;
__near __no_bit_access __no_init volatile union { unsigned short SIR01; __BITS16 SIR01_bit; struct { union { unsigned char SIR01L; __BITS8 SIR01L_bit; }; }; } @ 0xF010A;
__near __no_bit_access __no_init volatile union { unsigned short SIR02; __BITS16 SIR02_bit; struct { union { unsigned char SIR02L; __BITS8 SIR02L_bit; }; }; } @ 0xF010C;
__near __no_bit_access __no_init volatile union { unsigned short SIR03; __BITS16 SIR03_bit; struct { union { unsigned char SIR03L; __BITS8 SIR03L_bit; }; }; } @ 0xF010E;
__near __no_bit_access __no_init volatile union { unsigned short SMR00; __BITS16 SMR00_bit; } @ 0xF0110;
__near __no_bit_access __no_init volatile union { unsigned short SMR01; __BITS16 SMR01_bit; } @ 0xF0112;
__near __no_bit_access __no_init volatile union { unsigned short SMR02; __BITS16 SMR02_bit; } @ 0xF0114;
__near __no_bit_access __no_init volatile union { unsigned short SMR03; __BITS16 SMR03_bit; } @ 0xF0116;
__near __no_bit_access __no_init volatile union { unsigned short SCR00; __BITS16 SCR00_bit; } @ 0xF0118;
__near __no_bit_access __no_init volatile union { unsigned short SCR01; __BITS16 SCR01_bit; } @ 0xF011A;
__near __no_bit_access __no_init volatile union { unsigned short SCR02; __BITS16 SCR02_bit; } @ 0xF011C;
__near __no_bit_access __no_init volatile union { unsigned short SCR03; __BITS16 SCR03_bit; } @ 0xF011E;
__near __no_init volatile const union { unsigned short SE0; struct { union { unsigned char SE0L; __BITS8 SE0L_bit; }; }; } @ 0xF0120;
__near __no_init volatile union { unsigned short SS0; struct { union { unsigned char SS0L; __BITS8 SS0L_bit; }; }; } @ 0xF0122;
__near __no_init volatile union { unsigned short ST0; struct { union { unsigned char ST0L; __BITS8 ST0L_bit; }; }; } @ 0xF0124;
__near __no_bit_access __no_init volatile union { unsigned short SPS0; __BITS16 SPS0_bit; struct { union { unsigned char SPS0L; __BITS8 SPS0L_bit; }; }; } @ 0xF0126;
__near __no_bit_access __no_init volatile union { unsigned short SO0; __BITS16 SO0_bit; } @ 0xF0128;
__near __no_init volatile union { unsigned short SOE0; struct { union { unsigned char SOE0L; __BITS8 SOE0L_bit; }; }; } @ 0xF012A;
__near __no_bit_access __no_init volatile union { unsigned short SOL0; __BITS16 SOL0_bit; struct { union { unsigned char SOL0L; __BITS8 SOL0L_bit; }; }; } @ 0xF0134;
__near __no_bit_access __no_init volatile union { unsigned short SSC0; __BITS16 SSC0_bit; struct { union { unsigned char SSC0L; __BITS8 SSC0L_bit; }; }; } @ 0xF0138;
__near __no_bit_access __no_init volatile const union { unsigned short SSR10; __BITS16 SSR10_bit; struct { union { unsigned char SSR10L; __BITS8 SSR10L_bit; }; }; } @ 0xF0140;
__near __no_bit_access __no_init volatile const union { unsigned short SSR11; __BITS16 SSR11_bit; struct { union { unsigned char SSR11L; __BITS8 SSR11L_bit; }; }; } @ 0xF0142;
__near __no_bit_access __no_init volatile const union { unsigned short SSR12; __BITS16 SSR12_bit; struct { union { unsigned char SSR12L; __BITS8 SSR12L_bit; }; }; } @ 0xF0144;
__near __no_bit_access __no_init volatile const union { unsigned short SSR13; __BITS16 SSR13_bit; struct { union { unsigned char SSR13L; __BITS8 SSR13L_bit; }; }; } @ 0xF0146;
__near __no_bit_access __no_init volatile union { unsigned short SIR10; __BITS16 SIR10_bit; struct { union { unsigned char SIR10L; __BITS8 SIR10L_bit; }; }; } @ 0xF0148;
__near __no_bit_access __no_init volatile union { unsigned short SIR11; __BITS16 SIR11_bit; struct { union { unsigned char SIR11L; __BITS8 SIR11L_bit; }; }; } @ 0xF014A;
__near __no_bit_access __no_init volatile union { unsigned short SIR12; __BITS16 SIR12_bit; struct { union { unsigned char SIR12L; __BITS8 SIR12L_bit; }; }; } @ 0xF014C;
__near __no_bit_access __no_init volatile union { unsigned short SIR13; __BITS16 SIR13_bit; struct { union { unsigned char SIR13L; __BITS8 SIR13L_bit; }; }; } @ 0xF014E;
__near __no_bit_access __no_init volatile union { unsigned short SMR10; __BITS16 SMR10_bit; } @ 0xF0150;
__near __no_bit_access __no_init volatile union { unsigned short SMR11; __BITS16 SMR11_bit; } @ 0xF0152;
__near __no_bit_access __no_init volatile union { unsigned short SMR12; __BITS16 SMR12_bit; } @ 0xF0154;
__near __no_bit_access __no_init volatile union { unsigned short SMR13; __BITS16 SMR13_bit; } @ 0xF0156;
__near __no_bit_access __no_init volatile union { unsigned short SCR10; __BITS16 SCR10_bit; } @ 0xF0158;
__near __no_bit_access __no_init volatile union { unsigned short SCR11; __BITS16 SCR11_bit; } @ 0xF015A;
__near __no_bit_access __no_init volatile union { unsigned short SCR12; __BITS16 SCR12_bit; } @ 0xF015C;
__near __no_bit_access __no_init volatile union { unsigned short SCR13; __BITS16 SCR13_bit; } @ 0xF015E;
__near __no_init volatile const union { unsigned short SE1; struct { union { unsigned char SE1L; __BITS8 SE1L_bit; }; }; } @ 0xF0160;
__near __no_init volatile union { unsigned short SS1; struct { union { unsigned char SS1L; __BITS8 SS1L_bit; }; }; } @ 0xF0162;
__near __no_init volatile union { unsigned short ST1; struct { union { unsigned char ST1L; __BITS8 ST1L_bit; }; }; } @ 0xF0164;
__near __no_bit_access __no_init volatile union { unsigned short SPS1; __BITS16 SPS1_bit; struct { union { unsigned char SPS1L; __BITS8 SPS1L_bit; }; }; } @ 0xF0166;
__near __no_bit_access __no_init volatile union { unsigned short SO1; __BITS16 SO1_bit; } @ 0xF0168;
__near __no_init volatile union { unsigned short SOE1; struct { union { unsigned char SOE1L; __BITS8 SOE1L_bit; }; }; } @ 0xF016A;
__near __no_bit_access __no_init volatile union { unsigned short SOL1; __BITS16 SOL1_bit; struct { union { unsigned char SOL1L; __BITS8 SOL1L_bit; }; }; } @ 0xF0174;
__near __no_bit_access __no_init volatile union { unsigned short SSC1; __BITS16 SSC1_bit; struct { union { unsigned char SSC1L; __BITS8 SSC1L_bit; }; }; } @ 0xF0178;
__near __no_bit_access __no_init volatile const union { unsigned short TCR00; __BITS16 TCR00_bit; } @ 0xF0180;
__near __no_bit_access __no_init volatile const union { unsigned short TCR01; __BITS16 TCR01_bit; } @ 0xF0182;
__near __no_bit_access __no_init volatile const union { unsigned short TCR02; __BITS16 TCR02_bit; } @ 0xF0184;
__near __no_bit_access __no_init volatile const union { unsigned short TCR03; __BITS16 TCR03_bit; } @ 0xF0186;
__near __no_bit_access __no_init volatile union { unsigned short TMR00; __BITS16 TMR00_bit; } @ 0xF0190;
__near __no_bit_access __no_init volatile union { unsigned short TMR01; __BITS16 TMR01_bit; } @ 0xF0192;
__near __no_bit_access __no_init volatile union { unsigned short TMR02; __BITS16 TMR02_bit; } @ 0xF0194;
__near __no_bit_access __no_init volatile union { unsigned short TMR03; __BITS16 TMR03_bit; } @ 0xF0196;
__near __no_bit_access __no_init volatile const union { unsigned short TSR00; __BITS16 TSR00_bit; struct { union { unsigned char TSR00L; __BITS8 TSR00L_bit; }; }; } @ 0xF01A0;
__near __no_bit_access __no_init volatile const union { unsigned short TSR01; __BITS16 TSR01_bit; struct { union { unsigned char TSR01L; __BITS8 TSR01L_bit; }; }; } @ 0xF01A2;
__near __no_bit_access __no_init volatile const union { unsigned short TSR02; __BITS16 TSR02_bit; struct { union { unsigned char TSR02L; __BITS8 TSR02L_bit; }; }; } @ 0xF01A4;
__near __no_bit_access __no_init volatile const union { unsigned short TSR03; __BITS16 TSR03_bit; struct { union { unsigned char TSR03L; __BITS8 TSR03L_bit; }; }; } @ 0xF01A6;
__near __no_init volatile const union { unsigned short TE0; struct { union { unsigned char TE0L; __BITS8 TE0L_bit; }; }; } @ 0xF01B0;
__near __no_init volatile union { unsigned short TS0; struct { union { unsigned char TS0L; __BITS8 TS0L_bit; }; }; } @ 0xF01B2;
__near __no_init volatile union { unsigned short TT0; struct { union { unsigned char TT0L; __BITS8 TT0L_bit; }; }; } @ 0xF01B4;
__near __no_bit_access __no_init volatile union { unsigned short TPS0; __BITS16 TPS0_bit; } @ 0xF01B6;
__near __no_bit_access __no_init volatile union { unsigned short TO0; __BITS16 TO0_bit; struct { union { unsigned char TO0L; __BITS8 TO0L_bit; }; }; } @ 0xF01B8;
__near __no_init volatile union { unsigned short TOE0; struct { union { unsigned char TOE0L; __BITS8 TOE0L_bit; }; }; } @ 0xF01BA;
__near __no_bit_access __no_init volatile union { unsigned short TOL0; __BITS16 TOL0_bit; struct { union { unsigned char TOL0L; __BITS8 TOL0L_bit; }; }; } @ 0xF01BC;
__near __no_bit_access __no_init volatile union { unsigned short TOM0; __BITS16 TOM0_bit; struct { union { unsigned char TOM0L; __BITS8 TOM0L_bit; }; }; } @ 0xF01BE;
__near __no_bit_access __no_init volatile const union { unsigned short TCR10; __BITS16 TCR10_bit; } @ 0xF01C0;
__near __no_bit_access __no_init volatile const union { unsigned short TCR11; __BITS16 TCR11_bit; } @ 0xF01C2;
__near __no_bit_access __no_init volatile const union { unsigned short TCR12; __BITS16 TCR12_bit; } @ 0xF01C4;
__near __no_bit_access __no_init volatile const union { unsigned short TCR13; __BITS16 TCR13_bit; } @ 0xF01C6;
__near __no_bit_access __no_init volatile union { unsigned short TMR10; __BITS16 TMR10_bit; } @ 0xF01D0;
__near __no_bit_access __no_init volatile union { unsigned short TMR11; __BITS16 TMR11_bit; } @ 0xF01D2;
__near __no_bit_access __no_init volatile union { unsigned short TMR12; __BITS16 TMR12_bit; } @ 0xF01D4;
__near __no_bit_access __no_init volatile union { unsigned short TMR13; __BITS16 TMR13_bit; } @ 0xF01D6;
__near __no_bit_access __no_init volatile const union { unsigned short TSR10; __BITS16 TSR10_bit; struct { union { unsigned char TSR10L; __BITS8 TSR10L_bit; }; }; } @ 0xF01E0;
__near __no_bit_access __no_init volatile const union { unsigned short TSR11; __BITS16 TSR11_bit; struct { union { unsigned char TSR11L; __BITS8 TSR11L_bit; }; }; } @ 0xF01E2;
__near __no_bit_access __no_init volatile const union { unsigned short TSR12; __BITS16 TSR12_bit; struct { union { unsigned char TSR12L; __BITS8 TSR12L_bit; }; }; } @ 0xF01E4;
__near __no_bit_access __no_init volatile const union { unsigned short TSR13; __BITS16 TSR13_bit; struct { union { unsigned char TSR13L; __BITS8 TSR13L_bit; }; }; } @ 0xF01E6;
__near __no_init volatile const union { unsigned short TE1; struct { union { unsigned char TE1L; __BITS8 TE1L_bit; }; }; } @ 0xF01F0;
__near __no_init volatile union { unsigned short TS1; struct { union { unsigned char TS1L; __BITS8 TS1L_bit; }; }; } @ 0xF01F2;
__near __no_init volatile union { unsigned short TT1; struct { union { unsigned char TT1L; __BITS8 TT1L_bit; }; }; } @ 0xF01F4;
__near __no_bit_access __no_init volatile union { unsigned short TPS1; __BITS16 TPS1_bit; } @ 0xF01F6;
__near __no_bit_access __no_init volatile union { unsigned short TO1; __BITS16 TO1_bit; struct { union { unsigned char TO1L; __BITS8 TO1L_bit; }; }; } @ 0xF01F8;
__near __no_init volatile union { unsigned short TOE1; struct { union { unsigned char TOE1L; __BITS8 TOE1L_bit; }; }; } @ 0xF01FA;
__near __no_bit_access __no_init volatile union { unsigned short TOL1; __BITS16 TOL1_bit; struct { union { unsigned char TOL1L; __BITS8 TOL1L_bit; }; }; } @ 0xF01FC;
__near __no_bit_access __no_init volatile union { unsigned short TOM1; __BITS16 TOM1_bit; struct { union { unsigned char TOM1L; __BITS8 TOM1L_bit; }; }; } @ 0xF01FE;
__near __no_init volatile union { unsigned char IICCTL00; __BITS8 IICCTL00_bit; } @ 0xF0230;
__near __no_init volatile union { unsigned char IICCTL01; __BITS8 IICCTL01_bit; } @ 0xF0231;
__near __no_bit_access __no_init volatile union { unsigned char IICWL0; __BITS8 IICWL0_bit; } @ 0xF0232;
__near __no_bit_access __no_init volatile union { unsigned char IICWH0; __BITS8 IICWH0_bit; } @ 0xF0233;
__near __no_bit_access __no_init volatile union { unsigned char SVA0; __BITS8 SVA0_bit; } @ 0xF0234;
__near __no_init volatile union { unsigned char IICCTL10; __BITS8 IICCTL10_bit; } @ 0xF0238;
__near __no_init volatile union { unsigned char IICCTL11; __BITS8 IICCTL11_bit; } @ 0xF0239;
__near __no_bit_access __no_init volatile union { unsigned char IICWL1; __BITS8 IICWL1_bit; } @ 0xF023A;
__near __no_bit_access __no_init volatile union { unsigned char IICWH1; __BITS8 IICWH1_bit; } @ 0xF023B;
__near __no_bit_access __no_init volatile union { unsigned char SVA1; __BITS8 SVA1_bit; } @ 0xF023C;
__near __no_bit_access __no_init volatile union { unsigned char TRJCR0; __BITS8 TRJCR0_bit; } @ 0xF0240;
__near __no_init volatile union { unsigned char TRJIOC0; __BITS8 TRJIOC0_bit; } @ 0xF0241;
__near __no_init volatile union { unsigned char TRJMR0; __BITS8 TRJMR0_bit; } @ 0xF0242;
__near __no_init volatile union { unsigned char TRJISR0; __BITS8 TRJISR0_bit; } @ 0xF0243;
__near __no_init volatile union { unsigned char TRGMR; __BITS8 TRGMR_bit; } @ 0xF0250;
__near __no_init volatile union { unsigned char TRGCNTC; __BITS8 TRGCNTC_bit; } @ 0xF0251;
__near __no_init volatile union { unsigned char TRGCR; __BITS8 TRGCR_bit; } @ 0xF0252;
__near __no_init volatile union { unsigned char TRGIER; __BITS8 TRGIER_bit; } @ 0xF0253;
__near __no_init volatile union { unsigned char TRGSR; __BITS8 TRGSR_bit; } @ 0xF0254;
__near __no_init volatile union { unsigned char TRGIOR; __BITS8 TRGIOR_bit; } @ 0xF0255;
__near __no_bit_access __no_init volatile union { unsigned short TRG; __BITS16 TRG_bit; } @ 0xF0256;
__near __no_bit_access __no_init volatile union { unsigned short TRGGRA; __BITS16 TRGGRA_bit; } @ 0xF0258;
__near __no_bit_access __no_init volatile union { unsigned short TRGGRB; __BITS16 TRGGRB_bit; } @ 0xF025A;
__near __no_bit_access __no_init volatile union { unsigned short TRGGRCM; __BITS16 TRGGRCM_bit; } @ 0xF025C;
__near __no_bit_access __no_init volatile union { unsigned short TRGGRDM; __BITS16 TRGGRDM_bit; } @ 0xF025E;
__near __no_init volatile union { unsigned char TRDELC; __BITS8 TRDELC_bit; } @ 0xF0260;
__near __no_bit_access __no_init volatile union { unsigned char TRDSTR; __BITS8 TRDSTR_bit; } @ 0xF0263;
__near __no_init volatile union { unsigned char TRDMR; __BITS8 TRDMR_bit; } @ 0xF0264;
__near __no_init volatile union { unsigned char TRDPMR; __BITS8 TRDPMR_bit; } @ 0xF0265;
__near __no_init volatile union { unsigned char TRDFCR; __BITS8 TRDFCR_bit; } @ 0xF0266;
__near __no_init volatile union { unsigned char TRDOER1; __BITS8 TRDOER1_bit; } @ 0xF0267;
__near __no_init volatile union { unsigned char TRDOER2; __BITS8 TRDOER2_bit; } @ 0xF0268;
__near __no_init volatile union { unsigned char TRDOCR; __BITS8 TRDOCR_bit; } @ 0xF0269;
__near __no_init volatile union { unsigned char TRDDF0; __BITS8 TRDDF0_bit; } @ 0xF026A;
__near __no_init volatile union { unsigned char TRDDF1; __BITS8 TRDDF1_bit; } @ 0xF026B;
__near __no_init volatile union { unsigned char TRDCR0; __BITS8 TRDCR0_bit; } @ 0xF0270;
__near __no_init volatile union { unsigned char TRDIORA0; __BITS8 TRDIORA0_bit; } @ 0xF0271;
__near __no_init volatile union { unsigned char TRDIORC0; __BITS8 TRDIORC0_bit; } @ 0xF0272;
__near __no_init volatile union { unsigned char TRDSR0; __BITS8 TRDSR0_bit; } @ 0xF0273;
__near __no_init volatile union { unsigned char TRDIER0; __BITS8 TRDIER0_bit; } @ 0xF0274;
__near __no_init volatile union { unsigned char TRDPOCR0; __BITS8 TRDPOCR0_bit; } @ 0xF0275;
__near __no_bit_access __no_init volatile union { unsigned short TRD0; __BITS16 TRD0_bit; } @ 0xF0276;
__near __no_bit_access __no_init volatile union { unsigned short TRDGRA0; __BITS16 TRDGRA0_bit; } @ 0xF0278;
__near __no_bit_access __no_init volatile union { unsigned short TRDGRB0; __BITS16 TRDGRB0_bit; } @ 0xF027A;
__near __no_bit_access __no_init volatile union { unsigned short TRDGRC0M; __BITS16 TRDGRC0M_bit; } @ 0xF027C;
__near __no_bit_access __no_init volatile union { unsigned short TRDGRD0M; __BITS16 TRDGRD0M_bit; } @ 0xF027E;
__near __no_init volatile union { unsigned char TRDCR1; __BITS8 TRDCR1_bit; } @ 0xF0280;
__near __no_init volatile union { unsigned char TRDIORA1; __BITS8 TRDIORA1_bit; } @ 0xF0281;
__near __no_init volatile union { unsigned char TRDIORC1; __BITS8 TRDIORC1_bit; } @ 0xF0282;
__near __no_init volatile union { unsigned char TRDSR1; __BITS8 TRDSR1_bit; } @ 0xF0283;
__near __no_init volatile union { unsigned char TRDIER1; __BITS8 TRDIER1_bit; } @ 0xF0284;
__near __no_init volatile union { unsigned char TRDPOCR1; __BITS8 TRDPOCR1_bit; } @ 0xF0285;
__near __no_bit_access __no_init volatile union { unsigned short TRD1; __BITS16 TRD1_bit; } @ 0xF0286;
__near __no_bit_access __no_init volatile union { unsigned short TRDGRA1; __BITS16 TRDGRA1_bit; } @ 0xF0288;
__near __no_bit_access __no_init volatile union { unsigned short TRDGRB1; __BITS16 TRDGRB1_bit; } @ 0xF028A;
__near __no_bit_access __no_init volatile union { unsigned short TRDGRC1M; __BITS16 TRDGRC1M_bit; } @ 0xF028C;
__near __no_bit_access __no_init volatile union { unsigned short TRDGRD1M; __BITS16 TRDGRD1M_bit; } @ 0xF028E;
__near __no_bit_access __no_init volatile union { unsigned char DTCBAR; __BITS8 DTCBAR_bit; } @ 0xF02E0;
__near __no_init volatile union { unsigned char DTCEN0; __BITS8 DTCEN0_bit; } @ 0xF02E8;
__near __no_init volatile union { unsigned char DTCEN1; __BITS8 DTCEN1_bit; } @ 0xF02E9;
__near __no_init volatile union { unsigned char DTCEN2; __BITS8 DTCEN2_bit; } @ 0xF02EA;
__near __no_init volatile union { unsigned char DTCEN3; __BITS8 DTCEN3_bit; } @ 0xF02EB;
__near __no_init volatile union { unsigned char DTCEN4; __BITS8 DTCEN4_bit; } @ 0xF02EC;
__near __no_init volatile union { unsigned char CRC0CTL; __BITS8 CRC0CTL_bit; } @ 0xF02F0;
__near __no_bit_access __no_init volatile union { unsigned short PGCRCL; __BITS16 PGCRCL_bit; } @ 0xF02F2;
__near __no_bit_access __no_init volatile union { unsigned short CRCD; __BITS16 CRCD_bit; } @ 0xF02FA;
__near __no_init volatile union { unsigned char ELSELR00; __BITS8 ELSELR00_bit; } @ 0xF0300;
__near __no_init volatile union { unsigned char ELSELR01; __BITS8 ELSELR01_bit; } @ 0xF0301;
__near __no_init volatile union { unsigned char ELSELR02; __BITS8 ELSELR02_bit; } @ 0xF0302;
__near __no_init volatile union { unsigned char ELSELR03; __BITS8 ELSELR03_bit; } @ 0xF0303;
__near __no_init volatile union { unsigned char ELSELR04; __BITS8 ELSELR04_bit; } @ 0xF0304;
__near __no_init volatile union { unsigned char ELSELR05; __BITS8 ELSELR05_bit; } @ 0xF0305;
__near __no_init volatile union { unsigned char ELSELR06; __BITS8 ELSELR06_bit; } @ 0xF0306;
__near __no_init volatile union { unsigned char ELSELR07; __BITS8 ELSELR07_bit; } @ 0xF0307;
__near __no_init volatile union { unsigned char ELSELR08; __BITS8 ELSELR08_bit; } @ 0xF0308;
__near __no_init volatile union { unsigned char ELSELR09; __BITS8 ELSELR09_bit; } @ 0xF0309;
__near __no_init volatile union { unsigned char ELSELR10; __BITS8 ELSELR10_bit; } @ 0xF030A;
__near __no_init volatile union { unsigned char ELSELR11; __BITS8 ELSELR11_bit; } @ 0xF030B;
__near __no_init volatile union { unsigned char ELSELR12; __BITS8 ELSELR12_bit; } @ 0xF030C;
__near __no_init volatile union { unsigned char ELSELR13; __BITS8 ELSELR13_bit; } @ 0xF030D;
__near __no_init volatile union { unsigned char ELSELR14; __BITS8 ELSELR14_bit; } @ 0xF030E;
__near __no_init volatile union { unsigned char ELSELR15; __BITS8 ELSELR15_bit; } @ 0xF030F;
__near __no_init volatile union { unsigned char ELSELR16; __BITS8 ELSELR16_bit; } @ 0xF0310;
__near __no_init volatile union { unsigned char ELSELR17; __BITS8 ELSELR17_bit; } @ 0xF0311;
__near __no_init volatile union { unsigned char ELSELR18; __BITS8 ELSELR18_bit; } @ 0xF0312;
__near __no_init volatile union { unsigned char ELSELR19; __BITS8 ELSELR19_bit; } @ 0xF0313;
__near __no_init volatile union { unsigned char ELSELR20; __BITS8 ELSELR20_bit; } @ 0xF0314;
__near __no_init volatile union { unsigned char ELSELR21; __BITS8 ELSELR21_bit; } @ 0xF0315;
__near __no_init volatile union { unsigned char ELSELR22; __BITS8 ELSELR22_bit; } @ 0xF0316;
__near __no_init volatile union { unsigned char ELSELR23; __BITS8 ELSELR23_bit; } @ 0xF0317;
__near __no_init volatile union { unsigned char ELSELR24; __BITS8 ELSELR24_bit; } @ 0xF0318;
__near __no_init volatile union { unsigned char ELSELR25; __BITS8 ELSELR25_bit; } @ 0xF0319;
__near __no_init volatile union { unsigned char COMPMDR; __BITS8 COMPMDR_bit; } @ 0xF0340;
__near __no_init volatile union { unsigned char COMPFIR; __BITS8 COMPFIR_bit; } @ 0xF0341;
__near __no_init volatile union { unsigned char COMPOCR; __BITS8 COMPOCR_bit; } @ 0xF0342;
__near __no_bit_access __no_init volatile union { unsigned short TRJ0; __BITS16 TRJ0_bit; } @ 0xF0500;

/*----------------------------------------------
 *       Extended SFR bit declarations
 *--------------------------------------------*/

#define ADTYP             ADM2_bit.no0
#define AWC               ADM2_bit.no2
#define ADRCK             ADM2_bit.no3

#define SSIE00            ISC_bit.no7

#define TRJ0EN            PER1_bit.no0
#define DTCEN             PER1_bit.no3
#define TRD0EN            PER1_bit.no4
#define CMPEN             PER1_bit.no5
#define TRGEN             PER1_bit.no6
#define DACEN             PER1_bit.no7

#define DFLEN             DFLCTL_bit.no0

#define TAU0EN            PER0_bit.no0
#define TAU1EN            PER0_bit.no1
#define SAU0EN            PER0_bit.no2
#define SAU1EN            PER0_bit.no3
#define IICA0EN           PER0_bit.no4
#define ADCEN             PER0_bit.no5
#define IICA1EN           PER0_bit.no6
#define RTCEN             PER0_bit.no7

#define WDVOL             RMC_bit.no7

#define RPEF              RPECTL_bit.no0
#define RPERDIS           RPECTL_bit.no7

#define SPT0              IICCTL00_bit.no0
#define STT0              IICCTL00_bit.no1
#define ACKE0             IICCTL00_bit.no2
#define WTIM0             IICCTL00_bit.no3
#define SPIE0             IICCTL00_bit.no4
#define WREL0             IICCTL00_bit.no5
#define LREL0             IICCTL00_bit.no6
#define IICE0             IICCTL00_bit.no7

#define PRS0              IICCTL01_bit.no0
#define DFC0              IICCTL01_bit.no2
#define SMC0              IICCTL01_bit.no3
#define DAD0              IICCTL01_bit.no4
#define CLD0              IICCTL01_bit.no5
#define WUP0              IICCTL01_bit.no7

#define SPT1              IICCTL10_bit.no0
#define STT1              IICCTL10_bit.no1
#define ACKE1             IICCTL10_bit.no2
#define WTIM1             IICCTL10_bit.no3
#define SPIE1             IICCTL10_bit.no4
#define WREL1             IICCTL10_bit.no5
#define LREL1             IICCTL10_bit.no6
#define IICE1             IICCTL10_bit.no7

#define PRS1              IICCTL11_bit.no0
#define DFC1              IICCTL11_bit.no2
#define SMC1              IICCTL11_bit.no3
#define DAD1              IICCTL11_bit.no4
#define CLD1              IICCTL11_bit.no5
#define WUP1              IICCTL11_bit.no7

#define TRGPWM            TRGMR_bit.no0
#define TRGMDF            TRGMR_bit.no1
#define TRGDFA            TRGMR_bit.no2
#define TRGDFB            TRGMR_bit.no3
#define TRGDFCK0          TRGMR_bit.no4
#define TRGDFCK1          TRGMR_bit.no5
#define TRGELCICE         TRGMR_bit.no6
#define TRGSTART          TRGMR_bit.no7

#define TRGTCK0           TRGCR_bit.no0
#define TRGTCK1           TRGCR_bit.no1
#define TRGTCK2           TRGCR_bit.no2
#define TRGCKEG0          TRGCR_bit.no3
#define TRGCKEG1          TRGCR_bit.no4
#define TRGCCLR0          TRGCR_bit.no5
#define TRGCCLR1          TRGCR_bit.no6

#define TRGIMIEA          TRGIER_bit.no0
#define TRGIMIEB          TRGIER_bit.no1
#define TRGUDIE           TRGIER_bit.no2
#define TRGOVIE           TRGIER_bit.no3

#define TRGIMFA           TRGSR_bit.no0
#define TRGIMFB           TRGSR_bit.no1
#define TRGUDF            TRGSR_bit.no2
#define TRGOVF            TRGSR_bit.no3
#define TRGDIRF           TRGSR_bit.no4

#define TRGIOA0           TRGIOR_bit.no0
#define TRGIOA1           TRGIOR_bit.no1
#define TRGIOA2           TRGIOR_bit.no2
#define TRGBUFA           TRGIOR_bit.no3
#define TRGIOB0           TRGIOR_bit.no4
#define TRGIOB1           TRGIOR_bit.no5
#define TRGIOB2           TRGIOR_bit.no6
#define TRGBUFB           TRGIOR_bit.no7

#define TRDSYNC           TRDMR_bit.no0
#define TRDBFC0           TRDMR_bit.no4
#define TRDBFD0           TRDMR_bit.no5
#define TRDBFC1           TRDMR_bit.no6
#define TRDBFD1           TRDMR_bit.no7

#define TRDPWMB0          TRDPMR_bit.no0
#define TRDPWMC0          TRDPMR_bit.no1
#define TRDPWMD0          TRDPMR_bit.no2
#define TRDPWMB1          TRDPMR_bit.no4
#define TRDPWMC1          TRDPMR_bit.no5
#define TRDPWMD1          TRDPMR_bit.no6

#define TRDSHUTS          TRDOER2_bit.no0
#define TRDPTO            TRDOER2_bit.no7

#define CRC0EN            CRC0CTL_bit.no7

#define C0ENB             COMPMDR_bit.no0
#define C0MON             COMPMDR_bit.no3
#define C1ENB             COMPMDR_bit.no4
#define C1MON             COMPMDR_bit.no7

#define C0IE              COMPOCR_bit.no0
#define C0OE              COMPOCR_bit.no1
#define C0OP              COMPOCR_bit.no2
#define C1IE              COMPOCR_bit.no4
#define C1OE              COMPOCR_bit.no5
#define C1OP              COMPOCR_bit.no6
#define SPDMD             COMPOCR_bit.no7

#pragma language=restore

#endif /* __IAR_SYSTEMS_ICC__ */

#ifdef __IAR_SYSTEMS_ASM__

/*----------------------------------------------
 *       Extended SFR declarations
 *--------------------------------------------*/

ADM2       DEFINE  0xF0010
ADUL       DEFINE  0xF0011
ADLL       DEFINE  0xF0012
ADTES      DEFINE  0xF0013
PU0        DEFINE  0xF0030
PU1        DEFINE  0xF0031
PU3        DEFINE  0xF0033
PU4        DEFINE  0xF0034
PU5        DEFINE  0xF0035
PU6        DEFINE  0xF0036
PU7        DEFINE  0xF0037
PU8        DEFINE  0xF0038
PU10       DEFINE  0xF003A
PU11       DEFINE  0xF003B
PU12       DEFINE  0xF003C
PU14       DEFINE  0xF003E
PIM0       DEFINE  0xF0040
PIM1       DEFINE  0xF0041
PIM3       DEFINE  0xF0043
PIM4       DEFINE  0xF0044
PIM5       DEFINE  0xF0045
PIM8       DEFINE  0xF0048
PIM14      DEFINE  0xF004E
POM0       DEFINE  0xF0050
POM1       DEFINE  0xF0051
POM3       DEFINE  0xF0053
POM4       DEFINE  0xF0054
POM5       DEFINE  0xF0055
POM7       DEFINE  0xF0057
POM8       DEFINE  0xF0058
POM14      DEFINE  0xF005E
PMC0       DEFINE  0xF0060
PMC1       DEFINE  0xF0061
PMC10      DEFINE  0xF006A
PMC12      DEFINE  0xF006C
PMC14      DEFINE  0xF006E
NFEN0      DEFINE  0xF0070
NFEN1      DEFINE  0xF0071
NFEN2      DEFINE  0xF0072
ISC        DEFINE  0xF0073
TIS0       DEFINE  0xF0074
ADPC       DEFINE  0xF0076
PIOR0      DEFINE  0xF0077
IAWCTL     DEFINE  0xF0078
PIOR1      DEFINE  0xF0079
PER1       DEFINE  0xF007A
PMS        DEFINE  0xF007B
GDIDIS     DEFINE  0xF007D
DFLCTL     DEFINE  0xF0090
HIOTRM     DEFINE  0xF00A0
HOCODIV    DEFINE  0xF00A8
TEMPCAL0   DEFINE  0xF00AC
TEMPCAL1   DEFINE  0xF00AD
TEMPCAL2   DEFINE  0xF00AE
TEMPCAL3   DEFINE  0xF00AF
PER0       DEFINE  0xF00F0
OSMC       DEFINE  0xF00F3
RMC        DEFINE  0xF00F4
RPECTL     DEFINE  0xF00F5
BCDADJ     DEFINE  0xF00FE
SSR00      DEFINE  0xF0100
SSR00L     DEFINE  0xF0100
SSR01      DEFINE  0xF0102
SSR01L     DEFINE  0xF0102
SSR02      DEFINE  0xF0104
SSR02L     DEFINE  0xF0104
SSR03      DEFINE  0xF0106
SSR03L     DEFINE  0xF0106
SIR00      DEFINE  0xF0108
SIR00L     DEFINE  0xF0108
SIR01      DEFINE  0xF010A
SIR01L     DEFINE  0xF010A
SIR02      DEFINE  0xF010C
SIR02L     DEFINE  0xF010C
SIR03      DEFINE  0xF010E
SIR03L     DEFINE  0xF010E
SMR00      DEFINE  0xF0110
SMR01      DEFINE  0xF0112
SMR02      DEFINE  0xF0114
SMR03      DEFINE  0xF0116
SCR00      DEFINE  0xF0118
SCR01      DEFINE  0xF011A
SCR02      DEFINE  0xF011C
SCR03      DEFINE  0xF011E
SE0        DEFINE  0xF0120
SE0L       DEFINE  0xF0120
SS0        DEFINE  0xF0122
SS0L       DEFINE  0xF0122
ST0        DEFINE  0xF0124
ST0L       DEFINE  0xF0124
SPS0       DEFINE  0xF0126
SPS0L      DEFINE  0xF0126
SO0        DEFINE  0xF0128
SOE0       DEFINE  0xF012A
SOE0L      DEFINE  0xF012A
SOL0       DEFINE  0xF0134
SOL0L      DEFINE  0xF0134
SSC0       DEFINE  0xF0138
SSC0L      DEFINE  0xF0138
SSR10      DEFINE  0xF0140
SSR10L     DEFINE  0xF0140
SSR11      DEFINE  0xF0142
SSR11L     DEFINE  0xF0142
SSR12      DEFINE  0xF0144
SSR12L     DEFINE  0xF0144
SSR13      DEFINE  0xF0146
SSR13L     DEFINE  0xF0146
SIR10      DEFINE  0xF0148
SIR10L     DEFINE  0xF0148
SIR11      DEFINE  0xF014A
SIR11L     DEFINE  0xF014A
SIR12      DEFINE  0xF014C
SIR12L     DEFINE  0xF014C
SIR13      DEFINE  0xF014E
SIR13L     DEFINE  0xF014E
SMR10      DEFINE  0xF0150
SMR11      DEFINE  0xF0152
SMR12      DEFINE  0xF0154
SMR13      DEFINE  0xF0156
SCR10      DEFINE  0xF0158
SCR11      DEFINE  0xF015A
SCR12      DEFINE  0xF015C
SCR13      DEFINE  0xF015E
SE1        DEFINE  0xF0160
SE1L       DEFINE  0xF0160
SS1        DEFINE  0xF0162
SS1L       DEFINE  0xF0162
ST1        DEFINE  0xF0164
ST1L       DEFINE  0xF0164
SPS1       DEFINE  0xF0166
SPS1L      DEFINE  0xF0166
SO1        DEFINE  0xF0168
SOE1       DEFINE  0xF016A
SOE1L      DEFINE  0xF016A
SOL1       DEFINE  0xF0174
SOL1L      DEFINE  0xF0174
SSC1       DEFINE  0xF0178
SSC1L      DEFINE  0xF0178
TCR00      DEFINE  0xF0180
TCR01      DEFINE  0xF0182
TCR02      DEFINE  0xF0184
TCR03      DEFINE  0xF0186
TMR00      DEFINE  0xF0190
TMR01      DEFINE  0xF0192
TMR02      DEFINE  0xF0194
TMR03      DEFINE  0xF0196
TSR00      DEFINE  0xF01A0
TSR00L     DEFINE  0xF01A0
TSR01      DEFINE  0xF01A2
TSR01L     DEFINE  0xF01A2
TSR02      DEFINE  0xF01A4
TSR02L     DEFINE  0xF01A4
TSR03      DEFINE  0xF01A6
TSR03L     DEFINE  0xF01A6
TE0        DEFINE  0xF01B0
TE0L       DEFINE  0xF01B0
TS0        DEFINE  0xF01B2
TS0L       DEFINE  0xF01B2
TT0        DEFINE  0xF01B4
TT0L       DEFINE  0xF01B4
TPS0       DEFINE  0xF01B6
TO0        DEFINE  0xF01B8
TO0L       DEFINE  0xF01B8
TOE0       DEFINE  0xF01BA
TOE0L      DEFINE  0xF01BA
TOL0       DEFINE  0xF01BC
TOL0L      DEFINE  0xF01BC
TOM0       DEFINE  0xF01BE
TOM0L      DEFINE  0xF01BE
TCR10      DEFINE  0xF01C0
TCR11      DEFINE  0xF01C2
TCR12      DEFINE  0xF01C4
TCR13      DEFINE  0xF01C6
TMR10      DEFINE  0xF01D0
TMR11      DEFINE  0xF01D2
TMR12      DEFINE  0xF01D4
TMR13      DEFINE  0xF01D6
TSR10      DEFINE  0xF01E0
TSR10L     DEFINE  0xF01E0
TSR11      DEFINE  0xF01E2
TSR11L     DEFINE  0xF01E2
TSR12      DEFINE  0xF01E4
TSR12L     DEFINE  0xF01E4
TSR13      DEFINE  0xF01E6
TSR13L     DEFINE  0xF01E6
TE1        DEFINE  0xF01F0
TE1L       DEFINE  0xF01F0
TS1        DEFINE  0xF01F2
TS1L       DEFINE  0xF01F2
TT1        DEFINE  0xF01F4
TT1L       DEFINE  0xF01F4
TPS1       DEFINE  0xF01F6
TO1        DEFINE  0xF01F8
TO1L       DEFINE  0xF01F8
TOE1       DEFINE  0xF01FA
TOE1L      DEFINE  0xF01FA
TOL1       DEFINE  0xF01FC
TOL1L      DEFINE  0xF01FC
TOM1       DEFINE  0xF01FE
TOM1L      DEFINE  0xF01FE
IICCTL00   DEFINE  0xF0230
IICCTL01   DEFINE  0xF0231
IICWL0     DEFINE  0xF0232
IICWH0     DEFINE  0xF0233
SVA0       DEFINE  0xF0234
IICCTL10   DEFINE  0xF0238
IICCTL11   DEFINE  0xF0239
IICWL1     DEFINE  0xF023A
IICWH1     DEFINE  0xF023B
SVA1       DEFINE  0xF023C
TRJCR0     DEFINE  0xF0240
TRJIOC0    DEFINE  0xF0241
TRJMR0     DEFINE  0xF0242
TRJISR0    DEFINE  0xF0243
TRGMR      DEFINE  0xF0250
TRGCNTC    DEFINE  0xF0251
TRGCR      DEFINE  0xF0252
TRGIER     DEFINE  0xF0253
TRGSR      DEFINE  0xF0254
TRGIOR     DEFINE  0xF0255
TRG        DEFINE  0xF0256
TRGGRA     DEFINE  0xF0258
TRGGRB     DEFINE  0xF025A
TRGGRCM    DEFINE  0xF025C
TRGGRDM    DEFINE  0xF025E
TRDELC     DEFINE  0xF0260
TRDSTR     DEFINE  0xF0263
TRDMR      DEFINE  0xF0264
TRDPMR     DEFINE  0xF0265
TRDFCR     DEFINE  0xF0266
TRDOER1    DEFINE  0xF0267
TRDOER2    DEFINE  0xF0268
TRDOCR     DEFINE  0xF0269
TRDDF0     DEFINE  0xF026A
TRDDF1     DEFINE  0xF026B
TRDCR0     DEFINE  0xF0270
TRDIORA0   DEFINE  0xF0271
TRDIORC0   DEFINE  0xF0272
TRDSR0     DEFINE  0xF0273
TRDIER0    DEFINE  0xF0274
TRDPOCR0   DEFINE  0xF0275
TRD0       DEFINE  0xF0276
TRDGRA0    DEFINE  0xF0278
TRDGRB0    DEFINE  0xF027A
TRDGRC0M   DEFINE  0xF027C
TRDGRD0M   DEFINE  0xF027E
TRDCR1     DEFINE  0xF0280
TRDIORA1   DEFINE  0xF0281
TRDIORC1   DEFINE  0xF0282
TRDSR1     DEFINE  0xF0283
TRDIER1    DEFINE  0xF0284
TRDPOCR1   DEFINE  0xF0285
TRD1       DEFINE  0xF0286
TRDGRA1    DEFINE  0xF0288
TRDGRB1    DEFINE  0xF028A
TRDGRC1M   DEFINE  0xF028C
TRDGRD1M   DEFINE  0xF028E
DTCBAR     DEFINE  0xF02E0
DTCEN0     DEFINE  0xF02E8
DTCEN1     DEFINE  0xF02E9
DTCEN2     DEFINE  0xF02EA
DTCEN3     DEFINE  0xF02EB
DTCEN4     DEFINE  0xF02EC
CRC0CTL    DEFINE  0xF02F0
PGCRCL     DEFINE  0xF02F2
CRCD       DEFINE  0xF02FA
ELSELR00   DEFINE  0xF0300
ELSELR01   DEFINE  0xF0301
ELSELR02   DEFINE  0xF0302
ELSELR03   DEFINE  0xF0303
ELSELR04   DEFINE  0xF0304
ELSELR05   DEFINE  0xF0305
ELSELR06   DEFINE  0xF0306
ELSELR07   DEFINE  0xF0307
ELSELR08   DEFINE  0xF0308
ELSELR09   DEFINE  0xF0309
ELSELR10   DEFINE  0xF030A
ELSELR11   DEFINE  0xF030B
ELSELR12   DEFINE  0xF030C
ELSELR13   DEFINE  0xF030D
ELSELR14   DEFINE  0xF030E
ELSELR15   DEFINE  0xF030F
ELSELR16   DEFINE  0xF0310
ELSELR17   DEFINE  0xF0311
ELSELR18   DEFINE  0xF0312
ELSELR19   DEFINE  0xF0313
ELSELR20   DEFINE  0xF0314
ELSELR21   DEFINE  0xF0315
ELSELR22   DEFINE  0xF0316
ELSELR23   DEFINE  0xF0317
ELSELR24   DEFINE  0xF0318
ELSELR25   DEFINE  0xF0319
COMPMDR    DEFINE  0xF0340
COMPFIR    DEFINE  0xF0341
COMPOCR    DEFINE  0xF0342
TRJ0       DEFINE  0xF0500

#endif /* __IAR_SYSTEMS_ASM__ */

#endif /* __IOR5F104PJ_EXT_H__ */
