#ifndef CX805_H
#define CX805_H

#include <stdint.h>


#ifndef __IO
#define __IO    volatile
#endif

#define AMBA_BASE_ADDR                      ((uint32_t)0x00040010)
#define RTC_BASE_ADDR                       ((uint32_t)0x00040080)
#define INT_CONTROLLER1_BASE_ADDR           ((uint32_t)0x00040100)
#define CRC_BASE_ADDR                       ((uint32_t)0x000401D0)
#define DEBUG_UART_BASE_ADDR                ((uint32_t)0x00040200)
#define IRDA_BASE_ADDR                      ((uint32_t)0x00040240)
#define GPIO_BASE_ADDR                      ((uint32_t)0x00040280)
#define I2C_BASE_ADDR                       ((uint32_t)0x00040300)
#define ESD_BASE_ADDR                       ((uint32_t)0x00040320)
#define SDS_IRDA_PULSE_SHAPER_BASE_ADDR     ((uint32_t)0x00040340)
#define DMA_CHANNEL0_BASE_ADDR              ((uint32_t)0x00040420)
#define DMA_CHANNEL1_BASE_ADDR              ((uint32_t)0x00040460)
#define DMA_CHANNEL2_BASE_ADDR              ((uint32_t)0x000404A0)
#define DMA_CHANNEL3_BASE_ADDR              ((uint32_t)0x000404E0)
#define DMA_CHANNEL4_BASE_ADDR              ((uint32_t)0x00040520)
#define DMA_CHANNEL5_BASE_ADDR              ((uint32_t)0x00040560)
#define SLEEP_TMR_BASE_ADDR                 ((uint32_t)0x00040700)
#define AUTO_BAUND_BASE_ADDR                ((uint32_t)0x00040740)
#define KEYPAD_BASE_ADDR                    ((uint32_t)0x00040800)
#define CCB_BASE_ADDR                       ((uint32_t)0x00040902)
#define PWM_BASE_ADDR                       ((uint32_t)0x00040A00)
#define SIM_BASE_ADDR                       ((uint32_t)0x00040A80)
#define PLL_BASE_ADDR                       ((uint32_t)0x00040B00)
#define SDS_SERIAL_BASE_ADDR                ((uint32_t)0x00041200)
#define TIMER1_BASE_ADDR                    ((uint32_t)0x00041300)
#define TIMER2_BASE_ADDR                    ((uint32_t)0x00041400)
#define GENDEX_BASE_ADDR                    ((uint32_t)0x00041500)
#define IR_TTRANS_BASE_ADDR                 ((uint32_t)0x00041600)
#define INT_CONTROLLER2_BASE_ADDR           ((uint32_t)0x00041720)





typedef struct
{
    __IO uint16_t CS0_CONFIG;   /*!< EBI CS0 configuration register */
    __IO uint16_t CS1_CONFIG;   /*!< EBI CS1 configuration register */
    __IO uint16_t CS2_CONFIG;   /*!< EBI CS2 configuration register */
    __IO uint16_t CS3_CONFIG;   /*!< EBI CS3 configuration register */
    __IO uint16_t CS4_CONFIG;   /*!< EBI CS4 configuration register */
    __IO uint16_t AMBA_CTRL;    /*!< AMBA Control register */
    __IO uint16_t AMBA_STAT;    /*!< AMBA Status register */
    __IO uint16_t CACHE_CTRL;   /*!< Reserved. Cache Control in CX810 */
    __IO uint16_t CS5_CONFIG;   /*!< EBI CS5 configuration register */
    __IO uint16_t CS6_CONFIG;   /*!< EBI CS6 configuration register */
    __IO uint16_t CS7_CONFIG;   /*!< EBI CS7 configuration register */
}AMBA_TypeDef;

typedef struct
{
    __IO uint16_t Secods;               /*!< Value register */
    __IO uint16_t Minutes;              /*!< Value register */
    __IO uint16_t Hours;                /*!< Value register */
    __IO uint16_t Days;                 /*!< Value register */
    __IO uint16_t Mounths;              /*!< Value register */
    __IO uint16_t Years;                /*!< Value register */
    __IO uint16_t Control;              /*!< Control register */
    __IO uint16_t Test;                 /*!< Test Mode Control register */
    __IO uint16_t RESERVE1;
    __IO uint16_t AlarmMinutes;         /*!< Alarm register */
    __IO uint16_t AlarmHours;           /*!< Alarm register */
    __IO uint16_t AlarmDays;            /*!< Alarm register */
    __IO uint16_t AlarmMounths;         /*!< Alarm register */
    __IO uint16_t AlarmYears;           /*!< Alarm register */
    __IO uint16_t InterruptControl;     /*!< External Interrupt Enable */
    __IO uint16_t StorageRegister0;     /*!< General Storage Register */
    __IO uint16_t StorageRegister1;     /*!< General Storage Register */
    __IO uint16_t StorageRegister2;     /*!< General Storage Register */
    __IO uint16_t StorageRegister3;     /*!< General Storage Register */
    __IO uint16_t StorageRegister4;     /*!< General Storage Register */
    __IO uint16_t StorageRegister5;     /*!< General Storage Register */
    __IO uint16_t StorageRegister6;     /*!< General Storage Register */
    __IO uint16_t StorageRegister7;     /*!< General Storage Register */
    __IO uint16_t StorageRegister8;     /*!< General Storage Register */
    __IO uint16_t StorageRegister9;     /*!< General Storage Register */
    __IO uint16_t StorageRegister10;    /*!< General Storage Register */
    __IO uint16_t StorageRegister11;    /*!< General Storage Register */
    __IO uint16_t StorageRegister12;    /*!< General Storage Register */
    __IO uint16_t StorageRegister13;    /*!< General Storage Register */
    __IO uint16_t StorageRegister14;    /*!< General Storage Register */
    __IO uint16_t StorageRegister15;    /*!< General Storage Register */    
}RTC_TypeDef;

typedef struct 
{
    __IO uint32_t IPR;                  /*!< Interrupt Pending Register */
    __IO uint32_t IPOL;                 /*!< Interrupt Polarity Register */
    __IO uint32_t IER;                  /*!< Interrupt Enable Register */
    __IO uint32_t ISEL;                 /*!< Interrupt Select Register */
    __IO uint32_t ICOND;                /*!< Interrupt Condition Register */
    __IO uint32_t FIQ;                  /*!< FIQ Interrupts Register */
    __IO uint32_t IRQ;                  /*!< IRQ Interrupts Register */
    __IO uint32_t TEST;                 /*!< Interrupt Test Register */
    __IO uint16_t VECT;                 /*!< Interrupt Priority Vector Register */
    __IO uint32_t INTRPTS;              /*!< Raw Interrupts Register */
    __IO uint16_t RESERVE;                
    __IO uint32_t ITYPE;                /*!< Interrupt Type Register */
}IntController1_Typedef;

typedef struct 
{
    __IO uint16_t DATA;                 /*!< Writing inputs 8- or 16-bit data to the shift register. Reading reads 16-bit result */
    __IO uint16_t RST;                  /*!< Writing resets shift register to 0xFFFF */
}CRC_Typedef;




#endif //CX805_H