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
#define IR_TRANS_BASE_ADDR                  ((uint32_t)0x00041600)
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
}AMBA__TypeDef;

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
}RTC__TypeDef;

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
}IntController1__TypeDef;

typedef struct 
{
    __IO uint16_t DATA;                 /*!< Writing inputs 8- or 16-bit data to the shift register. Reading reads 16-bit result */
    __IO uint16_t RST;                  /*!< Writing resets shift register to 0xFFFF */
}CRC__TypeDef;

typedef struct
{
    __IO uint16_t TX_CONTROL;
    __IO uint16_t TX_BR;
    __IO uint16_t TX_HOLDING;
    __IO uint16_t TX_STATUS;
    __IO uint16_t RX_CONTROL;
    __IO uint16_t RX_BR;
    __IO uint16_t RX_HOLDING;
    __IO uint16_t RX_DELAY;
    __IO uint8_t TIMEOUT;
    __IO uint8_t RESERVED;              /*!< Requested Delay */
    __IO uint16_t DELAY_COUNT;          /*!< Actual Delay Counted */
}SerialPort_TypeDef;

typedef struct 
{
    __IO uint16_t FRAME_CONTROL;
    __IO uint16_t STATUS;
    __IO uint16_t DATA;
    __IO uint16_t NUMBER_OF_LAST_RXD_MSG;
    __IO uint16_t NUMBER_OF_TX_MSG;
    __IO uint16_t XON_AND_XOFF_CHARS;
    __IO uint16_t NUMBER_OF_BOFS;
    __IO uint16_t INT_CONTROL_STATUS1;
    __IO uint16_t INT_CONTROL_STATUS2;
    __IO uint16_t TEST_PPM;
    __IO uint16_t CRC_RESULT_LS;
    __IO uint16_t CRC_RESULT_MS;
    __IO uint16_t TEST_FAULT;
    __IO uint16_t BUFF_REG;
    __IO uint16_t PPM_BIT_WIDTH;
    __IO uint16_t TEST_SHIFT_REG;
    __IO uint16_t TIMING_CONTROL;
    __IO uint16_t BYTES_RXD;
    __IO uint16_t BYTES_TXD;
    __IO uint16_t BYTES_LAST_RXD;
    __IO uint16_t CGARS_FOR_BOF_EOF;
}IRDA_TypeDef;

typedef struct 
{
    __IO uint16_t GRP10_CTL;                /*!< Groups 1 & 0 Drive and DC Controls */
    __IO uint16_t GRP32_CTL;                /*!< Groups 3 & 2 Drive and DC Controls */
    __IO uint16_t GRPA_CTL;                 /*!< Group A Oen and IE Controls */
    __IO uint16_t GRPB_CTL;                 /*!< Group B Oen and IE Controls */
    __IO uint16_t GRPC_CTL;                 /*!< Group C Oen and IE Controls */
    __IO uint16_t GRPD_CTL;                 /*!< Group D Oen and IE Controls */
    __IO uint16_t GRPA_DAT;                 /*!< Group A Data In & Data Out */
    __IO uint16_t GRPB_DAT;                 /*!< Group B Data In & Data Out */
    __IO uint16_t GRPC_DAT;                 /*!< Group C Data In & Data Out */
    __IO uint16_t GRPD_DAT;                 /*!< Group D Data In & Data Out */
    __IO uint16_t CHIP_ID1;                 /*!< Device Identification Registers */
    __IO uint16_t CHIP_ID2;                 /*!< Device Identification Registers */
    __IO uint16_t SPARE;                    /*!< Spare Register */
    __IO uint16_t GRPE_CTL;                 /*!< Group E Control Register */
    __IO uint16_t GRPE_DAT;                 /*!< Group E Data In & Data Out */
    __IO uint16_t GRPE_DRV;                 /*!< Group E Drive Controls */
    __IO uint16_t GRPE_DC;                  /*!< Group E Drive Controls */
}GPIO_TypeDef;

typedef struct
{
    __IO uint16_t DATA;
    __IO uint16_t CLOCK;
}I2C_TypeDef;

typedef struct
{
    __IO uint16_t CONTROL;                  /*!< Sets mode of detector */
    __IO uint16_t STATUS;                   /*!< Detector Status */
    __IO uint16_t ESC_CHAR;                 /*!< Character to use as Escape Sequence Detection */
    __IO uint16_t XON_CHAR;                 /*!< Character to detect as XON */
    __IO uint16_t XOF_CHAR;                 /*!< Character to detect as XOFF */
    __IO uint16_t ESC_TIMEOUT;              /*!< Number of 20ms periods to count */
    __IO uint16_t DIVIDER;                  /*!< Prescaler divider */
}ESD_TypeDef;

typedef struct
{
    __IO uint16_t CONTROL;                  
    __IO uint16_t BR;                       
    __IO uint16_t CONFIG;                   
}SDS_IRDA_PULSE_TypeDef;

typedef struct
{
    __IO uint16_t CONTROL;
    __IO uint16_t STATUS;
    __IO uint16_t SOURCE_LS;
    __IO uint16_t SOURCE_MS;
    __IO uint16_t DECTINATION_LS;
    __IO uint16_t DESTINATION_MS;
    __IO uint16_t TRESHOLD_LS;
    __IO uint16_t TRESHOLD_MS;
    __IO uint16_t END_OF_BUFFER_LS;
    __IO uint16_t END_OF_BUFFER_MS;
    __IO uint16_t CURRENT_SOURCE_LS;
    __IO uint16_t CURRENT_SOURCE_MS;
    __IO uint16_t CURRENT_DESTINATION_LS;
    __IO uint16_t CURRENT_DESTINATION_MS;    
}DMA_Channel_TypeDef;

typedef struct
{
    __IO uint16_t CONTROL;
    __IO uint16_t CLOCK_COUNT;
    __IO uint16_t COUNTER_LS;
    __IO uint16_t COUNTER_MS;
    __IO uint16_t SLEEP_COUNT_LS;
    __IO uint16_t SLEEP_COUNT_MS;
}SleepTmr_TypeDef;

typedef struct
{
    __IO uint16_t DECISION[16];
    __IO uint16_t CONTROL;
    __IO uint16_t STATUS;
    __IO uint16_t FAILURE;
    __IO uint16_t CHARS;
    __IO uint16_t BAUD_COUNTER;
    __IO uint16_t SHIFT;
    __IO uint16_t ASP_CONTROL;
    __IO uint16_t BLOCK_STATE;
}Autobaud_TypeDef;


typedef struct
{
    __IO uint16_t CONTROL;                          /*<! GPIO for keypad control */
    __IO uint16_t STROBE;                           /*<!  */
    __IO uint16_t RETURN;                           /*<!  */
}Keypad_TypeDef;


typedef struct
{
    __IO uint16_t CONTROL1;
    __IO uint16_t FORCE1;
    __IO uint16_t CONTROL2;
    __IO uint16_t FORCE2;
    __IO uint16_t REQUEST_VECTOR;
    __IO uint16_t DSP_CONFIG;
    __IO uint16_t DSP_CONTROL;
    __IO uint16_t DSP_INT;
    __IO uint16_t ASIC_MODE_CONTROL;    
}CCB_TypeDef;


typedef struct
{
    __IO uint16_t CONTROL;
    __IO uint16_t DUTY_CYCLE;
    __IO uint16_t DIVIDER;
    __IO uint16_t COUNT;
    __IO uint16_t PATTERN_LS;
    __IO uint16_t PATTERN_MS;
}PWM_TypeDef;


typedef struct
{
    __IO uint16_t CONTROL_LS;
    __IO uint16_t CONTROL_MS;
    __IO uint16_t STATUS;
    __IO uint16_t INT_CONTROL;
    __IO uint16_t OUT_BUFFER;
    __IO uint16_t IN_BUFFER;
    __IO uint16_t DMA_DELAY_COUNT;
}SIM_TypeDef;


typedef struct
{
    __IO uint16_t CONTROL;
    __IO uint16_t DIVIDERS;
    __IO uint16_t EXTERNAL_CONTROL;
}PLL_TypeDef;


typedef struct
{
    __IO uint16_t PERIOD_LS;                /*!< 16 bit */
    __IO uint16_t PERIOD_MS;                /*!< 10 bit */
    __IO uint16_t PERIOD_HOLDING_LS;        /*!< 16 bit */
    __IO uint16_t PERIOD_HOLDING_MS;        /*!< 10 bit */
    __IO uint16_t COUNT_LS;                 /*!< Count value 16 bit */
    __IO uint16_t COUNT_MS;                 /*!< Count value 10 bit */
    __IO uint16_t COMTROL                   /*!< Timer Control Register */
}Timer_TypeDef;


typedef struct
{
    __IO uint16_t CONTROL;
    __IO uint16_t STATUS;
    __IO uint16_t KEY_1;
    __IO uint16_t KEY_2;
    __IO uint16_t KEY_3;
    __IO uint16_t KEY_4;
    __IO uint16_t IN_1;
    __IO uint16_t IN_2;
    __IO uint16_t FRAME_LENGHT;
    __IO uint16_t NCRC;
    __IO uint16_t OFFSET;
    __IO uint16_t CRC_LS;
    __IO uint16_t CRC_MS;
}GENDEX_TypeDef;


typedef struct
{
    __IO uint16_t CONTROL;
    __IO uint16_t BAUD_GEN;
    __IO uint16_t CONF;
}IR_TRANS_TypeDef;



#endif //CX805_H