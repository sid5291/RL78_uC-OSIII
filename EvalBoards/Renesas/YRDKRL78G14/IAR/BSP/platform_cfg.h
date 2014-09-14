#ifndef MCU_SEL_H
#define MCU_SEL_H

#if 0 // RDK_RL78G13

#define RDK_RL78G13
#define MCU_RL78G13

// LED port direction
#define LED1_M PM5_bit.no5
#define LED2_M PM6_bit.no2
#define LED3_M PM6_bit.no3
#define LED4_M PM5_bit.no2
#define LED5_M PM5_bit.no3
#define LED6_M PM5_bit.no4

// LED port data
#define LED1 P5_bit.no5
#define LED2 P6_bit.no2
#define LED3 P6_bit.no3
#define LED4 P5_bit.no2
#define LED5 P5_bit.no3
#define LED6 P5_bit.no4

// Okaya Serial LCD
// LCD Reset
#define LCD_RESET_PORT P13
#define LCD_RESET_BIT_POS (0)

// LCD CS and RS
#define LCD_CTL_PORT P1
#define LCD_CTL_PORT_DIR PM1
#define LCD_CTL_RS_BIT_POS (5)
#define LCD_CTL_CS_BIT_POS (0)

#define LCD_CSIMK CSIMK10
#define LCD_SIO SIO10

#define LCD_SSR SSR02

#else // RDK_RL78G14

#define MCU_RL78G14
#define RDK_RL78G14

// LED port direction
#define LED_1_R_M PM1_bit.no1
#define LED_3_R_M PM6_bit.no2
#define LED_5_R_M PM6_bit.no3
#define LED_7_R_M PM6_bit.no4

#define LED_2_G_M PM1_bit.no0
#define LED_4_G_M PM4_bit.no2
#define LED_6_G_M PM4_bit.no3
#define LED_8_G_M PM4_bit.no4

#define LED_15_O_M PM4_bit.no1

// LED port data
#define LED_1_R P1_bit.no1
#define LED_3_R P6_bit.no2
#define LED_5_R P6_bit.no3
#define LED_7_R P6_bit.no4

#define LED_2_G P1_bit.no0
#define LED_4_G P4_bit.no2
#define LED_6_G P4_bit.no3
#define LED_8_G P4_bit.no4

#define LED_15_O P4_bit.no1

// Switches
#define SW_1 P7_bit.no6
#define SW_2 P7_bit.no5
#define SW_3 P7_bit.no4


// LCD Reset
#define LCD_RESET_PORT P13
#define LCD_RESET_BIT_POS (0)

// LCD CS and RS
#define LCD_CTL_PORT P14
#define LCD_CTL_PORT_DIR PM14

#define LCD_CTL_RS_BIT_POS (6)
#define LCD_CTL_CS_BIT_POS (5)

#define LCD_CSIMK CSIMK21
#define LCD_SIO SIO21

#define LCD_SSR SSR11

#endif // RDK_RL78G14

#endif // PLATFORM_CFG_H
