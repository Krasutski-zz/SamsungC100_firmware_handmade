/*
 * cx805.h
 *
 *  Created on: 06.08.2011
 *      Author: Krasutski Denis
 */
/*******************************************************************************
cx805.h - Register defs for CX805-30(using in Samsung C100)
*******************************************************************************/


/*******************************************************************************
 * CX805 consist 12kb iROM and 16kb iRAM
 *  Memory Map
 * 	|---------------------------------------|
 * 	|Address				|	Name		|
 * 	|---------------------------------------|
 * 	|0x0000004-0x0002FFF	| Internal RAM	|
 * 	|0x0003000-0x003FFFF	| iRAM expansion|
 * 	|0x0040000-0x005FFFF	| iPeripherals	|
 * 	|0x0200
 *
 */
#ifndef CX805_H_
#define CX805_H_


#define REG8  (volatile unsigned char*)
#define REG16 (volatile unsigned short*)
#define REG32 (volatile unsigned int*)
#define nop asm("nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");


/*##############################################################################
## PLL
##############################################################################*/
#define PLL_CONTROL		(*(REG16 (0x40B00)))	//Control registers
#define PLL_DRIVERS		(*(REG16 (0x40b02)))	//arm, aARM 2x, PLL_ROOT
#define PLL_EXT_CLOCK	(*(REG16 (0x40b04)))	//External clk

#define PLL_CONTROL_DIV_P_MASK			0x0300			//divisor 1/2/3/4
#define PLL_CONTROL_DIV_Q_MASK			0x0060			//divisor 1/2/4/Bypass
#define PLL_CONTROL_DIV_N_MASK			0x001F			//multiply	1-32


/*##############################################################################
## ClockEnabled
##############################################################################*/
#define CLOCK_CONTROL
#define CLOCK_CONTROL_ARM_CORE	0
#define CLOCK_CONTROL_AM		1
#define CLOCK_CONTROL_SLP		2
#define CLOCK_CONTROL_SIM		3
#define CLOCK_CONTROL_PWM		4
#define CLOCK_CONTROL_TIMERB	5
#define CLOCK_CONTROL_CRC		6
#define CLOCK_CONTROL_PTGA		7
#define CLOCK_CONTROL_PTGB		8
#define CLOCK_CONTROL_DEBPORT	9
#define CLOCK_CONTROL_SDSPORT	10
#define CLOCK_CONTROL_AUTOBAND	11
#define CLOCK_CONTROL_DMA_CTRLD	12
#define CLOCK_CONTROL_DMA_CTRL	13
#define CLOCK_CONTROL_DSP		14
#define CLOCK_CONTROL_IRDA_ES	15

/*##############################################################################
## GPIO - General Purpose I/O
##############################################################################*/
//CTL-CONTROL register, use for set input(1) or output port(0)
#define GRPA_CTL	(*(REG16(0x040284)))
#define GRPB_CTL	(*(REG16(0x040286)))
#define GRPC_CTL	(*(REG16(0x040288)))
#define GRPD_CTL	(*(REG16(0x04028a)))
#define GRPE_CTL	(*(REG16(0x04029a)))

//DAT-DATA register,
//if port is used as output, the bit[15:8] output date(1-Hi/0-Low),bits[7:0] set change(1-change state 0-no change )
//if port is used as input, bits[7:0] input level
#define GRPA_DAT	(*(REG16(0x04028c)))
#define GRPB_DAT	(*(REG16(0x04028e)))
#define GRPC_DAT	(*(REG16(0x040290)))
#define GRPD_DAT	(*(REG16(0x040292)))
#define GRPE_DAT	(*(REG16(0x04029c)))

#define GRPA_SEL	(*(REG16(0x040d04)))
#define GRPB_SEL	(*(REG16(0x040d06)))
#define GRPC_SEL	(*(REG16(0x040d08)))
#define GRPD_SEL	(*(REG16(0x040d0a)))
#define GRPE_SEL	(*(REG16(0x040d1c)))


/*##############################################################################
## KEYB
##############################################################################*/
#define KEYB_CTL	(*(REG16(0x040800)))
#define KEYB_STRB	(*(REG16(0x040802)))
#define KEYB_RET	(*(REG16(0x040804)))


/*##############################################################################
## I2C
##############################################################################*/
#define I2C_DAT       (*(REG16 (0x040300)))//bit[0] output data bit, bit[1]-input data bit
#define I2C_CLK       (*(REG16 (0x040302)))//bit[0] output clk bit, bit[1]-input clk bit

/*##############################################################################
## RTC
##############################################################################*/
#define RTC_SEC		(*(REG16 (0x040080)))
#define RTC_MIN		(*(REG16 (0x040082)))
#define RTC_H		(*(REG16 (0x040084)))
#define RTC_DAY     (*(REG16 (0x040086)))
#define RTC_MON     (*(REG16 (0x040088)))
#define RTC_Y       (*(REG16 (0x04008a)))
#define RTC_CTL     (*(REG16 (0x04008c)))
#define RTC_TST     (*(REG16 (0x04008e)))
#define ALARM_MIN   (*(REG16 (0x040092)))
#define ALARM_H     (*(REG16 (0x040094)))
#define ALARM_DAY   (*(REG16 (0x040096)))
#define ALARM_MON   (*(REG16 (0x040098)))
#define ALARM_Y     (*(REG16 (0x04009a)))
#define RTC_INTCTL	(*(REG16 (0x04009c)))

#define RTC_STR0       (*(REG16 (0x0400a0)))
#define RTC_STR1       (*(REG16 (0x0400a2)))
#define RTC_STR2       (*(REG16 (0x0400a4)))
#define RTC_STR3       (*(REG16 (0x0400a6)))
#define RTC_STR4       (*(REG16 (0x0400a8)))
#define RTC_STR5       (*(REG16 (0x0400aa)))
#define RTC_STR6       (*(REG16 (0x0400ac)))
#define RTC_STR7       (*(REG16 (0x0400ae)))
#define RTC_STR8       (*(REG16 (0x0400b0)))
#define RTC_STR9       (*(REG16 (0x0400b2)))
#define RTC_STR10      (*(REG16 (0x0400b4)))
#define RTC_STR11      (*(REG16 (0x0400b6)))
#define RTC_STR12      (*(REG16 (0x0400b8)))
#define RTC_STR13      (*(REG16 (0x0400ba)))
#define RTC_STR14      (*(REG16 (0x0400bc)))
#define RTC_STR15      (*(REG16 (0x0400be)))

/*##############################################################################
## LCD ports
##############################################################################*/
#define LCD_base	(*(REG16 (0x00C00000)))//command port
#define LCD_data	(*(REG16 (0x00C80000)))//data port

/*##############################################################################
## SDS ports
##############################################################################*/
#define SDS_TX_CTL		(*(REG16 (0x41200)))
#define SDS_TX_BRS		(*(REG16 (0x41202)))
#define SDS_TX_HOLD		(*(REG16 (0x41204)))
#define SDS_TX_STAT		(*(REG16 (0x41206)))
#define SDS_RX_CTL		(*(REG16 (0x41208)))
#define SDS_RX_BRS		(*(REG16 (0x4120a)))
#define SDS_RX_HOLD		(*(REG16 (0x4120c)))
#define SDS_RX_STAT		(*(REG16 (0x4120e)))
#define SDS_TOUT		(*(REG8  (0x41210)))
#define SDS_DELAY		(*(REG16 (0x41212)))

/*##############################################################################
## Timers
##############################################################################*/
//Timer1
#define TMR1_PRL		(*(REG16(0x041300)))
#define TMR1_PRH		(*(REG16(0x041302)))
#define TMR1_PRHL		(*(REG16(0x041304)))
#define TMR1_PRHH		(*(REG16(0x041306)))
#define TMR1_L			(*(REG16(0x041308)))
#define TMR1_H			(*(REG16(0x04130A)))
#define TMR1_CTL		(*(REG16(0x04130C)))

//Timer2
#define TMR2_PRL		(*(REG16(0x041400)))
#define TMR2_PRH		(*(REG16(0x041402)))
#define TMR2_PRHL		(*(REG16(0x041404)))
#define TMR2_PRHH		(*(REG16(0x041406)))
#define TMR2_L			(*(REG16(0x041408)))
#define TMR2_H			(*(REG16(0x04140A)))
#define TMR2_CTL		(*(REG16(0x04140C)))

/*##############################################################################
## AMBA
##############################################################################*/
#define CS0_CONFIG	(*(REG16(0x040010)))
#define CS1_CONFIG	(*(REG16(0x040012)))
#define CS2_CONFIG	(*(REG16(0x040014)))
#define CS3_CONFIG	(*(REG16(0x040016)))
#define CS4_CONFIG	(*(REG16(0x040018)))
#define CS5_CONFIG	(*(REG16(0x040020)))
#define CS6_CONFIG	(*(REG16(0x040022)))
#define CS7_CONFIG	(*(REG16(0x040024)))

#define AMBA_CTRL	(*(REG16(0x04001A)))
#define AMBA_STAT	(*(REG16(0x04001C)))
#define CACHE_CTL	(*(REG16(0x04001E)))

/*##############################################################################
## Perifical Pins
##############################################################################*/
//GpioA
#define IRDA_EN 0
//#define _RST 1
//#define AN_SW_CTL 2
#define GREEN_LED 3
#define KEYB_LED 4
#define RED_LED 5
#define BLUE_LED 6
#define LCD_LED 7


#endif /* CX805_H_ */
