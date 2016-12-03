/**
  ******************************************************************************
  * @file    cx20542.h
  * @author  Denis Krasutski (Krasutski.deni@gmail.com)
  * @version V0.0.1
  * @date    20-November-2016
  * @brief   This file contains all data types for cx20524 PMU
  ******************************************************************************
  */
#ifndef CX20524_H
#define CX20524_H

#include <stdint.h>

#define CX20524_I2C_ADDR                    (0x48)
typedef enum
{
	CX20524_RESULT_OK = 0,
	CX20524_RESULT_ERROR,
}cx20524_status_t;


typedef enum Reg8BitList_e
{
    RESERVED1 = 0U,                         /*!<-- Reserved */
    VRF_TUNING_CONTROL = 1U,                /*!<-- Tuning and control for VRF regulator */
    OVERRIDE_CONTROL = 2U,                  /*!<-- Override pin control and register */
    PM_CONTROL = 3U,                        /*!<-- Power management control register */
    LDO_VRF = 4U,                           /*!<-- Enable control for VRF */
    LDO_VTIC = 5U,                          /*!<-- Enable control for VTIC */
    LDO_VUHF = 6U,                          /*!<-- Enable control for VUHF */
    RESERVED2 = 7U,                         /*!<-- Reserved */
    POWER_UP_STATUS = 8U,                   /*!<-- Power up status register */
    VTIC_TIMING_CONTROL = 9U,               /*!<-- Tuning and control for VTIC register */
    BANDGAP_TUNING = 10U,                   /*!<-- Bandgap tuning register */
    VUHF_TUNING_CONTROL = 11U,              /*!<-- Tuning and control for VUHF registe */
    MUX_CONTROL = 12U,                      /*!<-- Mux out control register */
    DAC_VALUE = 13U,                        /*!<-- DAC value input register for VGAT */
    RESERVED3 = 14U,                        /*!<-- Reserved */
    RESERVED4 = 15U,                        /*!<-- Reserved */
}Reg8BitList_t;


/* VRF Output Voltage Tuning  */
#define VRFOVT_TUNE_SHIFT                      (0U)
#define VRFOVT_TUNE_MASK                       (0x0F)
#define VRFOVT_TUNE_2_25V                      (0U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_30V                      (1U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_35V                      (2U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_40V                      (3U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_45V                      (4U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_50V                      (5U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_55V                      (6U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_60V                      (7U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_65V                      (8U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_70V                      (9U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_75V                      (10U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_80V                      (11U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_85V                      (12U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_90V                      (13U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_2_95V                      (14U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_TUNE_3_00V                      (15U << VRFOVT_TUNE_SHIFT)
#define VRFOVT_OVERLOAD_SHIFT                  (6U)
#define VRFOVT_OVERLOAD_MASK                   (0x40)
#define VRFOVT_OVERLOAD_EN                     (1U << VRFOVT_OVERLOAD_SHIFT)
#define VRFOVT_OVERLOAD_DIS                    (0U << VRFOVT_OVERLOAD_SHIFT)


/* Override Control Registers */
#define OCR_VUHF_SHIFT                      (0U)
#define OCR_VUHF_MASK                       (0x01)
#define OCR_VUHF_ON                         (1U << OCR_VUHF_SHIFT)
#define OCR_VUHF_OFF                        (0U << OCR_VUHF_SHIFT)

#define OCR_VUHF_CONTROL_SHIFT              (1U)
#define OCR_VUHF_CONTROL_MASK               (0x02)
#define OCR_VUHF_CONTROL_PIN                (0U << OCR_VUHF_CONTROL_SHIFT)
#define OCR_VUHF_CONTROL_REG                (1U << OCR_VUHF_CONTROL_SHIFT)

#define OCR_VTIC_SHIFT                      (2U)
#define OCR_VTIC_MASK                       (0x04)
#define OCR_VTIC_ON                         (1U << OCR_VTIC_SHIFT)
#define OCR_VTIC_OFF                        (0U << OCR_VTIC_SHIFT)

#define OCR_VTIC_CONTROL_SHIFT              (3U)
#define OCR_VTIC_CONTROL_MASK               (0x08)
#define OCR_VTIC_CONTROL_PIN                (0U << OCR_VTIC_CONTROL_MASK)
#define OCR_VTIC_CONTROL_REG                (1U << OCR_VTIC_CONTROL_MASK)

#define OCR_VRF_SHIFT                       (4U)
#define OCR_VRF_MASK                        (0x10)
#define OCR_VRF_ON                          (1U << OCR_VRF_SHIFT)
#define OCR_VRF_OFF                         (0U << OCR_VRF_SHIFT)

#define OCR_VRF_COTNROL_SHIFT               (5U)
#define OCR_VRF_COTNROL_MASK                (0x20)
#define OCR_VRF_COTNROL_PIN                 (0U << OCR_VRF_COTNROL_SHIFT)
#define OCR_VRF_CONTROL_REG                 (1U << OCR_VRF_COTNROL_SHIFT)

#define OCR_RESET_VAL_SHIFT                 (6U)
#define OCR_RESET_VAL_MASK                  (0xC0)
#define OCR_RESET_VAL_DIS                   (0U << OCR_RESET_VAL_SHIFT)
#define OCR_RESET_VAL_M4PER                 (1U << OCR_RESET_VAL_SHIFT)
#define OCR_RESET_VAL_M8PER                 (2U << OCR_RESET_VAL_SHIFT)
#define OCR_RESET_VAL_M12PER                (3U << OCR_RESET_VAL_SHIFT)

/* Power Management Control Register */
#define PMCR_PHONE_SHIFT                    (0U)
#define PMCR_PHONE_MASK                     (0x01)
#define PMCR_PHONE_ON                       (1U << PMCR_PHONE_SHIFT)
#define PMCR_PHONE_OFF                      (0U << PMCR_PHONE_SHIFT)

/*
-------------------------------------------------------------
|   %   | VCORE@1.2V | VCORE@1.7V | VCORE@2.4V | VCORE@2.8V |
| -6.3% |   1.1249   |   1.5929   |   2.2488   |   2.6236   |
| -5.4% |   1.1357   |   1.6082   |   2.2704   |   2.6488   |
| -4.5% |   1.1464   |   1.6235   |   2.2920   |   2.6740   |
| -3.6% |   1.1571   |   1.6388   |   2.3136   |   2.6992   |
| -2.7% |   1.1679   |   1.6541   |   2.3352   |   2.7244   |
| -1.8% |   1.1786   |   1.6694   |   2.3568   |   2.7496   |
| -0.9% |   1.1893   |   1.6847   |   2.3784   |   2.7748   |
|    0  |   1.2000   |   1.7000   |   2.4000   |   2.8000   |
| +0.9% |   1.2101   |   1.7153   |   2.4216   |   2.8252   |
| +1.8% |   1.2214   |   1.7306   |   2.4432   |   2.8504   |
| +2.7% |   1.2321   |   1.7459   |   2.4648   |   2.8756   |
| +3.6% |   1.2428   |   1.7612   |   2.4864   |   2.9008   |
| +4.5% |   1.2535   |   1.7765   |   2.5080   |   2.9260   |
| +5.4% |   1.2648   |   1.7918   |   2.5296   |   2.9512   |
| +6.3% |   1.2749   |   1.8071   |   2.5512   |   2.9764   |
| +7.2% |   1.2857   |   1.8224   |   2.5728   |   3.0016   |
-------------------------------------------------------------
*/
#define PMCR_VCORE_SHIFT                    (1U)
#define PMCR_VCORE_MASK                     (0x1E)
#define PMCR_VCORE_M6_3PER                  (0U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_M5_4PER                  (1U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_M4_5PER                  (2U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_M3_6PER                  (3U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_M2_7PER                  (4U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_M1_8PER                  (5U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_M0_9PER                  (6U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_0PER                     (7U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_0_9PER                   (8U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_1_8PER                   (9U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_2_7PER                   (10U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_3_6PER                   (11U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_4_5PER                   (12U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_5_4PER                   (13U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_6_3PER                   (14U << PMCR_VCORE_SHIFT)
#define PMCR_VCORE_7_2PER                   (15U << PMCR_VCORE_SHIFT)

#define PMCR_VSIM_SHIFT                     (6U)
#define PMCR_VSIM_MASK                      (0x40)
#define PMCR_VSIM_1V8                       (0U << PMCR_VSIM_SHIFT)
#define PMCR_VSIM_2V8                       (1U << PMCR_VSIM_SHIFT)

/* Low-Drop-Out VRF Control Register */
/* Real time control combination selection (EN_1, EN_2, EN_3) */
#define LDO_VRF_RTCS_CS_SHIFT               (0U)
#define LDO_VRF_RTCS_CS_MASK                (0x1F)
#define LDO_VRF_RTCS_EN_1                   (0U << LDO_VRF_RTCS_CS_SHIFT)
#define LDO_VRF_RTCS_EN_2                   (1U << LDO_VRF_RTCS_CS_SHIFT)
#define LDO_VRF_RTCS_EN_3                   (2U << LDO_VRF_RTCS_CS_SHIFT)
#define LDO_VRF_RTCS_EN_1_M_EN_2            (3U << LDO_VRF_RTCS_CS_SHIFT)
#define LDO_VRF_RTCS_EN_1_M_EN_3            (4U << LDO_VRF_RTCS_CS_SHIFT)
#define LDO_VRF_RTCS_EN_2_M_EN_3            (5U << LDO_VRF_RTCS_CS_SHIFT)
#define LDO_VRF_RTCS_EN_1_P_EN_2            (6U << LDO_VRF_RTCS_CS_SHIFT)
#define LDO_VRF_RTCS_EN_1_P_EN_3            (7U << LDO_VRF_RTCS_CS_SHIFT)
#define LDO_VRF_RTCS_EN_2_P_EN_3            (8U << LDO_VRF_RTCS_CS_SHIFT)
/* Polarity control */
#define LDO_VRF_POL_CTRL_SHIFT              (5U)
#define LDO_VRF_POL_CTRL_MASK               (0xE0)
#define LDO_VRF_POL_CTRL_EN1_EN2_EN3        (0U << LDO_VRF_POL_CTRL_SHIFT)
#define LDO_VRF_POL_CTRL_EN1_EN2_NEN3       (1U << LDO_VRF_POL_CTRL_SHIFT)
#define LDO_VRF_POL_CTRL_EN1_NEN2_EN3       (2U << LDO_VRF_POL_CTRL_SHIFT)
#define LDO_VRF_POL_CTRL_EN1_NEN2_NEN3      (3U << LDO_VRF_POL_CTRL_SHIFT)
#define LDO_VRF_POL_CTRL_NEN1_EN2_EN3       (4U << LDO_VRF_POL_CTRL_SHIFT)
#define LDO_VRF_POL_CTRL_NEN1_EN2_NEN3      (5U << LDO_VRF_POL_CTRL_SHIFT)
#define LDO_VRF_POL_CTRL_NEN1_NEN2_EN3      (6U << LDO_VRF_POL_CTRL_SHIFT)
#define LDO_VRF_POL_CTRL_NEN1_NEN2_NEN3     (7U << LDO_VRF_POL_CTRL_SHIFT)

/* Low-Drop-Out VTIC Control Register */
/* Real time control combination selection (EN_1, EN_2, EN_3) */
#define LDO_VTIC_RTCS_CS_SHIFT              (0U)
#define LDO_VTIC_RTCS_CS_MASK               (0x1F)
#define LDO_VTIC_RTCS_EN_1                  (0U << LDO_VTIC_RTCS_CS_SHIFT)
#define LDO_VTIC_RTCS_EN_2                  (1U << LDO_VTIC_RTCS_CS_SHIFT)
#define LDO_VTIC_RTCS_EN_3                  (2U << LDO_VTIC_RTCS_CS_SHIFT)
#define LDO_VTIC_RTCS_EN_1_M_EN_2           (3U << LDO_VTIC_RTCS_CS_SHIFT)
#define LDO_VTIC_RTCS_EN_1_M_EN_3           (4U << LDO_VTIC_RTCS_CS_SHIFT)
#define LDO_VTIC_RTCS_EN_2_M_EN_3           (5U << LDO_VTIC_RTCS_CS_SHIFT)
#define LDO_VTIC_RTCS_EN_1_P_EN_2           (6U << LDO_VTIC_RTCS_CS_SHIFT)
#define LDO_VTIC_RTCS_EN_1_P_EN_3           (7U << LDO_VTIC_RTCS_CS_SHIFT)
#define LDO_VTIC_RTCS_EN_2_P_EN_3           (8U << LDO_VTIC_RTCS_CS_SHIFT)
/* Polarity control */
#define LDO_VTIC_POL_CTRL_SHIFT             (5U)
#define LDO_VTIC_POL_CTRL_MASK              (0xE0)
#define LDO_VTIC_POL_CTRL_EN1_EN2_EN3       (0U << LDO_VTIC_POL_CTRL_SHIFT)
#define LDO_VTIC_POL_CTRL_EN1_EN2_NEN3      (1U << LDO_VTIC_POL_CTRL_SHIFT)
#define LDO_VTIC_POL_CTRL_EN1_NEN2_EN3      (2U << LDO_VTIC_POL_CTRL_SHIFT)
#define LDO_VTIC_POL_CTRL_EN1_NEN2_NEN3     (3U << LDO_VTIC_POL_CTRL_SHIFT)
#define LDO_VTIC_POL_CTRL_NEN1_EN2_EN3      (4U << LDO_VTIC_POL_CTRL_SHIFT)
#define LDO_VTIC_POL_CTRL_NEN1_EN2_NEN3     (5U << LDO_VTIC_POL_CTRL_SHIFT)
#define LDO_VTIC_POL_CTRL_NEN1_NEN2_EN3     (6U << LDO_VTIC_POL_CTRL_SHIFT)
#define LDO_VTIC_POL_CTRL_NEN1_NEN2_NEN3    (7U << LDO_VTIC_POL_CTRL_SHIFT)

/* Low-Drop-Out VUHF Control Register */
/* Real time control combination selection (EN_1, EN_2, EN_3) */
#define LDO_VUHF_RTCS_CS_SHIFT              (0U)
#define LDO_VUHF_RTCS_CS_MASK               (0x1F)
#define LDO_VUHF_RTCS_EN_1                  (0U << LDO_VUHF_RTCS_CS_SHIFT)
#define LDO_VUHF_RTCS_EN_2                  (1U << LDO_VUHF_RTCS_CS_SHIFT)
#define LDO_VUHF_RTCS_EN_3                  (2U << LDO_VUHF_RTCS_CS_SHIFT)
#define LDO_VUHF_RTCS_EN_1_M_EN_2           (3U << LDO_VUHF_RTCS_CS_SHIFT)
#define LDO_VUHF_RTCS_EN_1_M_EN_3           (4U << LDO_VUHF_RTCS_CS_SHIFT)
#define LDO_VUHF_RTCS_EN_2_M_EN_3           (5U << LDO_VUHF_RTCS_CS_SHIFT)
#define LDO_VUHF_RTCS_EN_1_P_EN_2           (6U << LDO_VUHF_RTCS_CS_SHIFT)
#define LDO_VUHF_RTCS_EN_1_P_EN_3           (7U << LDO_VUHF_RTCS_CS_SHIFT)
#define LDO_VUHF_RTCS_EN_2_P_EN_3           (8U << LDO_VUHF_RTCS_CS_SHIFT)
/* Polarity control */
#define LDO_VUHF_POL_CTRL_SHIFT             (5U)
#define LDO_VUHF_POL_CTRL_MASK              (0xE0)
#define LDO_VUHF_POL_CTRL_EN1_EN2_EN3       (0U << LDO_VUHF_POL_CTRL_SHIFT)
#define LDO_VUHF_POL_CTRL_EN1_EN2_NEN3      (1U << LDO_VUHF_POL_CTRL_SHIFT)
#define LDO_VUHF_POL_CTRL_EN1_NEN2_EN3      (2U << LDO_VUHF_POL_CTRL_SHIFT)
#define LDO_VUHF_POL_CTRL_EN1_NEN2_NEN3     (3U << LDO_VUHF_POL_CTRL_SHIFT)
#define LDO_VUHF_POL_CTRL_NEN1_EN2_EN3      (4U << LDO_VUHF_POL_CTRL_SHIFT)
#define LDO_VUHF_POL_CTRL_NEN1_EN2_NEN3     (5U << LDO_VUHF_POL_CTRL_SHIFT)
#define LDO_VUHF_POL_CTRL_NEN1_NEN2_EN3     (6U << LDO_VUHF_POL_CTRL_SHIFT)
#define LDO_VUHF_POL_CTRL_NEN1_NEN2_NEN3    (7U << LDO_VUHF_POL_CTRL_SHIFT)

/* Power-up Status Register */
#define PSR_PWE_KEY_L                       (1U << 0U)
#define PSR_ALARM                           (1U << 1U)
#define PSR_DTR                             (1U << 2U)
#define PSR_PWR_KEY_H                       (1U << 3U)

/* VTIC Voltage Tuning and Control */
#define VTIC_TUNE_SHIFT                     (0U)
#define VTIC_TUNE_MASK                      (0x0F)
#define VTIC_TUNE_2_25V                     (0U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_30V                     (1U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_35V                     (2U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_40V                     (3U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_45V                     (4U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_50V                     (5U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_55V                     (6U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_60V                     (7U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_65V                     (8U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_70V                     (9U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_75V                     (10U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_80V                     (11U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_85V                     (12U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_90V                     (13U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_2_95V                     (14U << VTIC_TUNE_SHIFT)
#define VTIC_TUNE_3_00V                     (15U << VTIC_TUNE_SHIFT)
/* Overload protection */
#define VTIC_OVERLOAD_SHIFT                 (6U)
#define VTIC_OVERLOAD_MASK                  (0x40)
#define VTIC_OVERLOAD_EN                    (1U << VTIC_OVERLOAD_SHIFT)
#define VTIC_OVERLOAD_DIS                   (0U << VTIC_OVERLOAD_SHIFT)


/* VUHF Voltage Tuning and Control */
#define VUHF_TUNE_SHIFT                     (0U)
#define VUHF_TUNE_MASK                      (0x0F)
#define VUHF_TUNE_2_25V                     (0U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_30V                     (1U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_35V                     (2U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_40V                     (3U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_45V                     (4U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_50V                     (5U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_55V                     (6U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_60V                     (7U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_65V                     (8U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_70V                     (9U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_75V                     (10U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_80V                     (11U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_85V                     (12U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_90V                     (13U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_2_95V                     (14U << VUHF_TUNE_SHIFT)
#define VUHF_TUNE_3_00V                     (15U << VUHF_TUNE_SHIFT)
/* Overload protection */
#define VUHF_OVERLOAD_SHIFT                 (6U)
#define VUHF_OVERLOAD_MASK                  (0x40)
#define VUHF_OVERLOAD_EN                    (1U << VUHF_OVERLOAD_SHIFT)
#define VUHF_OVERLOAD_DIS                   (0U << VUHF_OVERLOAD_SHIFT)

/* MUX Control Register */
/* Selects which analog voltage is present on MUX_OUT pin*/
#define MUXCR_SEL_SHIFT                     (0U)
#define MUXCR_SEL_MASK                      (0x07)
#define MUXCR_SEL_ALL_OFF                   (0U << MUXCR_SEL_SHIFT)
#define MUXCR_SEL_CURR_SENSE                (1U << MUXCR_SEL_SHIFT)
#define MUXCR_SEL_BAT_PK_IN                 (2U << MUXCR_SEL_SHIFT)
#define MUXCR_SEL_DAC_VOLT                  (3U << MUXCR_SEL_SHIFT)
#define MUXCR_SEL_VCHARGE                   (4U << MUXCR_SEL_SHIFT)
#define MUXCR_SEL_VBAT                      (5U << MUXCR_SEL_SHIFT)
#define MUXCR_SEL_VCORE                     (6U << MUXCR_SEL_SHIFT)
#define MUXCR_SEL_VIO                       (7U << MUXCR_SEL_SHIFT)
/* Current sense amplifier gain */
#define MUXCR_CURR_AMP_GAIN_SHIFT           (5U)
#define MUXCR_CURR_AMP_GAIN_MASK            (0x20)
#define MUXCR_CURR_AMP_GAIN_20V             (0U << MUXCR_CURR_AMP_GAIN_SHIFT)
#define MUXCR_CURR_AMP_GAIN_10V             (1U << MUXCR_CURR_AMP_GAIN_SHIFT)


#endif //CX20524_H
