/**
  * @file    stm32f4_adc.c
  * @brief   STM32F4 ADC
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef STM32F4_ADC_H
#define STM32F4_ADC_H


#include "stm32f4xx.h"


#if !defined(STM32F446xx) && !defined(STM32F407xx)
# warning    the code below may to work correct, but was not checked
#endif


typedef enum    stm32f4_adc_chnl_s
{
	STM32F4_ADC_CHNL_00                         =  0,
	STM32F4_ADC_CHNL_01                         =  1,
	STM32F4_ADC_CHNL_02                         =  2,
	STM32F4_ADC_CHNL_03                         =  3,
	STM32F4_ADC_CHNL_04                         =  4,
	STM32F4_ADC_CHNL_05                         =  5,
	STM32F4_ADC_CHNL_06                         =  6,
	STM32F4_ADC_CHNL_07                         =  7,
	STM32F4_ADC_CHNL_08                         =  8,
	STM32F4_ADC_CHNL_09                         =  9,
	STM32F4_ADC_CHNL_10                         = 10,
	STM32F4_ADC_CHNL_11                         = 11,
	STM32F4_ADC_CHNL_12                         = 12,
	STM32F4_ADC_CHNL_13                         = 13,
	STM32F4_ADC_CHNL_14                         = 14,
	STM32F4_ADC_CHNL_15                         = 15,
	STM32F4_ADC_CHNL_VREF                       = 17,
	STM32F4_ADC_CHNL_VBAT_TSENS                 = 18,
} stm32f4_adc_chnl_t;

typedef enum    stm32f4_adc_sequence_size_s
{
	STM32F4_ADC_SEQUENCE_SIZE_1                 =  0x0,
	STM32F4_ADC_SEQUENCE_SIZE_2                 =  0x1,
	STM32F4_ADC_SEQUENCE_SIZE_3                 =  0x2,
	STM32F4_ADC_SEQUENCE_SIZE_4                 =  0x3,
	STM32F4_ADC_SEQUENCE_SIZE_5                 =  0x4,
	STM32F4_ADC_SEQUENCE_SIZE_6                 =  0x5,
	STM32F4_ADC_SEQUENCE_SIZE_7                 =  0x6,
	STM32F4_ADC_SEQUENCE_SIZE_8                 =  0x7,
	STM32F4_ADC_SEQUENCE_SIZE_9                 =  0x8,
	STM32F4_ADC_SEQUENCE_SIZE_10                =  0x9,
	STM32F4_ADC_SEQUENCE_SIZE_11                =  0xA,
	STM32F4_ADC_SEQUENCE_SIZE_12                =  0xB,
	STM32F4_ADC_SEQUENCE_SIZE_13                =  0xC,
	STM32F4_ADC_SEQUENCE_SIZE_14                =  0xD,
	STM32F4_ADC_SEQUENCE_SIZE_15                =  0xE,
	STM32F4_ADC_SEQUENCE_SIZE_16                =  0xF,
} stm32f4_adc_sequence_size_t;

typedef enum    stm32f4_adc_sequence_num_s
{
	STM32F4_ADC_SEQUENCE_NUM_1                  =  0,
	STM32F4_ADC_SEQUENCE_NUM_2                  =  1,
	STM32F4_ADC_SEQUENCE_NUM_3                  =  2,
	STM32F4_ADC_SEQUENCE_NUM_4                  =  3,
	STM32F4_ADC_SEQUENCE_NUM_5                  =  4,
	STM32F4_ADC_SEQUENCE_NUM_6                  =  5,
	STM32F4_ADC_SEQUENCE_NUM_7                  =  6,
	STM32F4_ADC_SEQUENCE_NUM_8                  =  7,
	STM32F4_ADC_SEQUENCE_NUM_9                  =  8,
	STM32F4_ADC_SEQUENCE_NUM_10                 =  9,
	STM32F4_ADC_SEQUENCE_NUM_11                 = 10,
	STM32F4_ADC_SEQUENCE_NUM_12                 = 11,
	STM32F4_ADC_SEQUENCE_NUM_13                 = 12,
	STM32F4_ADC_SEQUENCE_NUM_14                 = 13,
	STM32F4_ADC_SEQUENCE_NUM_15                 = 14,
	STM32F4_ADC_SEQUENCE_NUM_16                 = 15,
} stm32f4_adc_sequence_num_t;

typedef enum    stm32f4_adc_resolution_s
{
	STM32F4_ADC_RESOLUTION_12_BIT               = 0x0,
	STM32F4_ADC_RESOLUTION_10_BIT               = 0x1,
	STM32F4_ADC_RESOLUTION_8_BIT                = 0x2,
	STM32F4_ADC_RESOLUTION_6_BIT                = 0x3,
} stm32f4_adc_resolution_t;

typedef enum    stm32f4_adc_scan_s
{
	STM32F4_ADC_SCAN_SINGLE                     = 0x0,
	STM32F4_ADC_SCAN_GROUP                      = 0x1,
} stm32f4_adc_scan_t;

typedef enum    stm32f4_adc_regular_etrg_s
{
	STM32F4_ADC_REGULAR_ETRG_DISABLE            = 0x00,

	STM32F4_ADC_REGULAR_ETRG_TIM1_CH1_POSEDGE   = 0x10,
	STM32F4_ADC_REGULAR_ETRG_TIM1_CH1_NEGEDGE   = 0x20,
	STM32F4_ADC_REGULAR_ETRG_TIM1_CH1_ANYEDGE   = 0x30,

	STM32F4_ADC_REGULAR_ETRG_TIM1_CH2_POSEDGE   = 0x11,
	STM32F4_ADC_REGULAR_ETRG_TIM1_CH2_NEGEDGE   = 0x21,
	STM32F4_ADC_REGULAR_ETRG_TIM1_CH2_ANYEDGE   = 0x31,

	STM32F4_ADC_REGULAR_ETRG_TIM1_CH3_POSEDGE   = 0x12,
	STM32F4_ADC_REGULAR_ETRG_TIM1_CH3_NEGEDGE   = 0x22,
	STM32F4_ADC_REGULAR_ETRG_TIM1_CH3_ANYEDGE   = 0x32,

	STM32F4_ADC_REGULAR_ETRG_TIM2_CH2_POSEDGE   = 0x13,
	STM32F4_ADC_REGULAR_ETRG_TIM2_CH2_NEGEDGE   = 0x23,
	STM32F4_ADC_REGULAR_ETRG_TIM2_CH2_ANYEDGE   = 0x33,

	STM32F4_ADC_REGULAR_ETRG_TIM2_CH3_POSEDGE   = 0x14,
	STM32F4_ADC_REGULAR_ETRG_TIM2_CH3_NEGEDGE   = 0x24,
	STM32F4_ADC_REGULAR_ETRG_TIM2_CH3_ANYEDGE   = 0x34,

	STM32F4_ADC_REGULAR_ETRG_TIM2_CH4_POSEDGE   = 0x15,
	STM32F4_ADC_REGULAR_ETRG_TIM2_CH4_NEGEDGE   = 0x25,
	STM32F4_ADC_REGULAR_ETRG_TIM2_CH4_ANYEDGE   = 0x35,

	STM32F4_ADC_REGULAR_ETRG_TIM2_TRGO_POSEDGE  = 0x16,
	STM32F4_ADC_REGULAR_ETRG_TIM2_TRGO_NEGEDGE  = 0x26,
	STM32F4_ADC_REGULAR_ETRG_TIM2_TRGO_ANYEDGE  = 0x36,

	STM32F4_ADC_REGULAR_ETRG_TIM3_CH1_POSEDGE   = 0x17,
	STM32F4_ADC_REGULAR_ETRG_TIM3_CH1_NEGEDGE   = 0x27,
	STM32F4_ADC_REGULAR_ETRG_TIM3_CH1_ANYEDGE   = 0x37,

	STM32F4_ADC_REGULAR_ETRG_TIM3_TRGO_POSEDGE  = 0x18,
	STM32F4_ADC_REGULAR_ETRG_TIM3_TRGO_NEGEDGE  = 0x28,
	STM32F4_ADC_REGULAR_ETRG_TIM3_TRGO_ANYEDGE  = 0x38,

	STM32F4_ADC_REGULAR_ETRG_TIM4_CH4_POSEDGE   = 0x19,
	STM32F4_ADC_REGULAR_ETRG_TIM4_CH4_NEGEDGE   = 0x29,
	STM32F4_ADC_REGULAR_ETRG_TIM4_CH4_ANYEDGE   = 0x39,

	STM32F4_ADC_REGULAR_ETRG_TIM5_CH1_POSEDGE   = 0x1A,
	STM32F4_ADC_REGULAR_ETRG_TIM5_CH1_NEGEDGE   = 0x2A,
	STM32F4_ADC_REGULAR_ETRG_TIM5_CH1_ANYEDGE   = 0x3A,

	STM32F4_ADC_REGULAR_ETRG_TIM5_CH2_POSEDGE   = 0x1B,
	STM32F4_ADC_REGULAR_ETRG_TIM5_CH2_NEGEDGE   = 0x2B,
	STM32F4_ADC_REGULAR_ETRG_TIM5_CH2_ANYEDGE   = 0x3B,

	STM32F4_ADC_REGULAR_ETRG_TIM5_CH3_POSEDGE   = 0x1C,
	STM32F4_ADC_REGULAR_ETRG_TIM5_CH3_NEGEDGE   = 0x2C,
	STM32F4_ADC_REGULAR_ETRG_TIM5_CH3_ANYEDGE   = 0x3C,

	STM32F4_ADC_REGULAR_ETRG_TIM8_CH1_POSEDGE   = 0x1D,
	STM32F4_ADC_REGULAR_ETRG_TIM8_CH1_NEGEDGE   = 0x2D,
	STM32F4_ADC_REGULAR_ETRG_TIM8_CH1_ANYEDGE   = 0x3D,

	STM32F4_ADC_REGULAR_ETRG_TIM8_TRGO_POSEDGE  = 0x1E,
	STM32F4_ADC_REGULAR_ETRG_TIM8_TRGO_NEGEDGE  = 0x2E,
	STM32F4_ADC_REGULAR_ETRG_TIM8_TRGO_ANYEDGE  = 0x3E,

	STM32F4_ADC_REGULAR_ETRG_EXTI_11_POSEDGE    = 0x1F,
	STM32F4_ADC_REGULAR_ETRG_EXTI_11_NEGEDGE    = 0x2F,
	STM32F4_ADC_REGULAR_ETRG_EXTI_11_ANYEDGE    = 0x3F,

} stm32f4_adc_regular_etrg_t;

typedef enum    stm32f4_adc_injected_etrg_s
{
	STM32F4_ADC_INJECTED_ETRG_DISABLE           = 0x0,

	STM32F4_ADC_INJECTED_ETRG_TIM1_CH4_POSEDGE  = 0x10,
	STM32F4_ADC_INJECTED_ETRG_TIM1_CH4_NEGEDGE  = 0x20,
	STM32F4_ADC_INJECTED_ETRG_TIM1_CH4_ANYEDGE  = 0x30,

	STM32F4_ADC_INJECTED_ETRG_TIM1_TRGO_POSEDGE = 0x11,
	STM32F4_ADC_INJECTED_ETRG_TIM1_TRGO_NEGEDGE = 0x21,
	STM32F4_ADC_INJECTED_ETRG_TIM1_TRGO_ANYEDGE = 0x31,

	STM32F4_ADC_INJECTED_ETRG_TIM2_CH1_POSEDGE  = 0x12,
	STM32F4_ADC_INJECTED_ETRG_TIM2_CH1_NEGEDGE  = 0x22,
	STM32F4_ADC_INJECTED_ETRG_TIM2_CH1_ANYEDGE  = 0x32,

	STM32F4_ADC_INJECTED_ETRG_TIM2_TRGO_POSEDGE = 0x13,
	STM32F4_ADC_INJECTED_ETRG_TIM2_TRGO_NEGEDGE = 0x23,
	STM32F4_ADC_INJECTED_ETRG_TIM2_TRGO_ANYEDGE = 0x33,

	STM32F4_ADC_INJECTED_ETRG_TIM3_CH2_POSEDGE  = 0x14,
	STM32F4_ADC_INJECTED_ETRG_TIM3_CH2_NEGEDGE  = 0x24,
	STM32F4_ADC_INJECTED_ETRG_TIM3_CH2_ANYEDGE  = 0x34,

	STM32F4_ADC_INJECTED_ETRG_TIM3_CH4_POSEDGE  = 0x15,
	STM32F4_ADC_INJECTED_ETRG_TIM3_CH4_NEGEDGE  = 0x25,
	STM32F4_ADC_INJECTED_ETRG_TIM3_CH4_ANYEDGE  = 0x35,

	STM32F4_ADC_INJECTED_ETRG_TIM4_CH1_POSEDGE  = 0x16,
	STM32F4_ADC_INJECTED_ETRG_TIM4_CH1_NEGEDGE  = 0x26,
	STM32F4_ADC_INJECTED_ETRG_TIM4_CH1_ANYEDGE  = 0x36,

	STM32F4_ADC_INJECTED_ETRG_TIM4_CH2_POSEDGE  = 0x17,
	STM32F4_ADC_INJECTED_ETRG_TIM4_CH2_NEGEDGE  = 0x27,
	STM32F4_ADC_INJECTED_ETRG_TIM4_CH2_ANYEDGE  = 0x37,

	STM32F4_ADC_INJECTED_ETRG_TIM4_CH3_POSEDGE  = 0x18,
	STM32F4_ADC_INJECTED_ETRG_TIM4_CH3_NEGEDGE  = 0x28,
	STM32F4_ADC_INJECTED_ETRG_TIM4_CH3_ANYEDGE  = 0x38,

	STM32F4_ADC_INJECTED_ETRG_TIM4_TRGO_POSEDGE = 0x19,
	STM32F4_ADC_INJECTED_ETRG_TIM4_TRGO_NEGEDGE = 0x29,
	STM32F4_ADC_INJECTED_ETRG_TIM4_TRGO_ANYEDGE = 0x39,

	STM32F4_ADC_INJECTED_ETRG_TIM5_CH4_POSEDGE  = 0x1A,
	STM32F4_ADC_INJECTED_ETRG_TIM5_CH4_NEGEDGE  = 0x2A,
	STM32F4_ADC_INJECTED_ETRG_TIM5_CH4_ANYEDGE  = 0x3A,

	STM32F4_ADC_INJECTED_ETRG_TIM5_TRGO_POSEDGE = 0x1B,
	STM32F4_ADC_INJECTED_ETRG_TIM5_TRGO_NEGEDGE = 0x2B,
	STM32F4_ADC_INJECTED_ETRG_TIM5_TRGO_ANYEDGE = 0x3B,

	STM32F4_ADC_INJECTED_ETRG_TIM8_CH2_POSEDGE  = 0x1C,
	STM32F4_ADC_INJECTED_ETRG_TIM8_CH2_NEGEDGE  = 0x2C,
	STM32F4_ADC_INJECTED_ETRG_TIM8_CH2_ANYEDGE  = 0x3C,

	STM32F4_ADC_INJECTED_ETRG_TIM8_CH3_POSEDGE  = 0x1D,
	STM32F4_ADC_INJECTED_ETRG_TIM8_CH3_NEGEDGE  = 0x2D,
	STM32F4_ADC_INJECTED_ETRG_TIM8_CH3_ANYEDGE  = 0x3D,

	STM32F4_ADC_INJECTED_ETRG_TIM8_CH4_POSEDGE  = 0x1E,
	STM32F4_ADC_INJECTED_ETRG_TIM8_CH4_NEGEDGE  = 0x2E,
	STM32F4_ADC_INJECTED_ETRG_TIM8_CH4_ANYEDGE  = 0x3E,

	STM32F4_ADC_INJECTED_ETRG_EXTI_15_POSEDGE   = 0x1F,
	STM32F4_ADC_INJECTED_ETRG_EXTI_15_NEGEDGE   = 0x2F,
	STM32F4_ADC_INJECTED_ETRG_EXTI_15_ANYEDGE   = 0x3F,

} stm32f4_adc_injected_etrg_t;

typedef enum    stm32f4_adc_data_align_s
{
	STM32F4_ADC_DATA_ALIGN_RIGHT                = 0x0,
	STM32F4_ADC_DATA_ALIGN_LEFT                 = 0x1,
} stm32f4_adc_data_align_t;

typedef enum    stm32f4_adc_dma_mode_s
{
	STM32F4_ADC_DMA_MODE_DISABLE                = 0x0,
	STM32F4_ADC_DMA_MODE_ONESHOT                = 0x1,
	STM32F4_ADC_DMA_MODE_NONSTOP                = 0x3,
} stm32f4_adc_dma_mode_t;

typedef enum    stm32f4_adc_conversion_s
{
	STM32F4_ADC_CONVERSION_SINGLE                   = 0x0,
	STM32F4_ADC_CONVERSION_CONTINIOUS               = 0x1,
} stm32f4_adc_conversion_t;

typedef enum    stm32f4_adc_analog_watchdog_s
{
	STM32F4_ADC_ANALOG_WATCHDOG_DISABLE         = 0x0,
	STM32F4_ADC_ANALOG_WATCHDOG_ENABLE          = 0x1,
} stm32f4_adc_analog_watchdog_t;

typedef enum    stm32f4_adc_discontinuous_s
{
	STM32F4_ADC_DISCONTINUOUS_DISABLE           = 0x0,
	STM32F4_ADC_DISCONTINUOUS_CHANNELS_1        = 0x1,
	STM32F4_ADC_DISCONTINUOUS_CHANNELS_2        = 0x3,
	STM32F4_ADC_DISCONTINUOUS_CHANNELS_3        = 0x5,
	STM32F4_ADC_DISCONTINUOUS_CHANNELS_4        = 0x7,
	STM32F4_ADC_DISCONTINUOUS_CHANNELS_5        = 0x9,
	STM32F4_ADC_DISCONTINUOUS_CHANNELS_6        = 0xb,
	STM32F4_ADC_DISCONTINUOUS_CHANNELS_7        = 0xd,
	STM32F4_ADC_DISCONTINUOUS_CHANNELS_8        = 0xf,
} stm32f4_adc_discontinuous_t;

typedef enum    stm32f4_adc_clk_s
{
	STM32F4_ADC_CLK_PCLK2_DIV_2                 = 0x0,
	STM32F4_ADC_CLK_PCLK2_DIV_4                 = 0x1,
	STM32F4_ADC_CLK_PCLK2_DIV_6                 = 0x2,
	STM32F4_ADC_CLK_PCLK2_DIV_8                 = 0x3,
} stm32f4_adc_clk_t;


static
void stm32f4_adc_clk_cfg(               stm32f4_adc_clk_t              clk )
{
    uint32_t        ccr_mask    =   ADC_CCR_ADCPRE;
    uint32_t        ccr         =   (clk << 16);

    ADC->CCR            =   (ADC->CCR & ~ccr_mask) | ccr;
}

static
void stm32f4_adc_disable(               ADC_TypeDef *                   adc )
{
    adc->CR2            &= ~ADC_CR2_ADON;
}

static
void stm32f4_adc_enable(                ADC_TypeDef *                   adc )
{
    adc->CR2            |=  ADC_CR2_ADON;
}

static
void stm32f4_adc_cfg(                   ADC_TypeDef *                   adc,
                                const   stm32f4_adc_resolution_t        res,
                                const   stm32f4_adc_data_align_t        align,
                                const   stm32f4_adc_dma_mode_t          dds_dma,
                                const   stm32f4_adc_conversion_t        conv  )
{
    uint32_t        cr1_mask    =    ADC_CR1_RES;
    uint32_t        cr1         =    (res << 24);
    uint32_t        cr2_mask    =    ADC_CR2_ALIGN | ADC_CR2_DDS | ADC_CR2_DMA | ADC_CR2_CONT;
    uint32_t        cr2         =    (align << 11) | (dds_dma << 8) | (conv << 1);

    adc->CR1            =   (adc->CR1 & ~cr1_mask) | cr1;
    adc->CR2            =   (adc->CR2 & ~cr2_mask) | cr2;
}

static
void stm32f4_adc_regular_cfg(           ADC_TypeDef *                   adc,
                                const   stm32f4_adc_analog_watchdog_t   awden,
                                const   stm32f4_adc_scan_t              scan,
				                const   stm32f4_adc_regular_etrg_t      exten_extsel )
{
    uint32_t        cr1_mask    =   ADC_CR1_AWDEN | ADC_CR1_SCAN;
    uint32_t        cr1         =   (awden << 23) | (scan << 8);
    uint32_t        cr2_mask    =   ADC_CR2_EXTEN | ADC_CR2_EXTSEL;
    uint32_t        cr2         =   (exten_extsel << 24);

    adc->CR1            =   (adc->CR1 & ~cr1_mask) | cr1;
    adc->CR2            =   (adc->CR2 & ~cr2_mask) | cr2;
}

static
void stm32f4_adc_injected_cfg(          ADC_TypeDef *                   adc,
                                const   stm32f4_adc_analog_watchdog_t   jawden )
{
    uint32_t        cr1_mask    =   ADC_CR1_JAWDEN;
    uint32_t        cr1         =   (jawden << 22);

    adc->CR1            =   (adc->CR1 & ~cr1_mask) | cr1;
}

static
void stm32f4_adc_sequence_cfg(          ADC_TypeDef *                   adc,
                                const   stm32f4_adc_sequence_num_t      sequence_num,
                                const   stm32f4_adc_chnl_t              sq )
{
    switch( sequence_num )
    {
        case STM32F4_ADC_SEQUENCE_NUM_1:    adc->SQR3 = (adc->SQR3 & ~ADC_SQR3_SQ1 ) | (sq <<  0);  break;
        case STM32F4_ADC_SEQUENCE_NUM_2:    adc->SQR3 = (adc->SQR3 & ~ADC_SQR3_SQ2 ) | (sq <<  5);  break;
        case STM32F4_ADC_SEQUENCE_NUM_3:    adc->SQR3 = (adc->SQR3 & ~ADC_SQR3_SQ3 ) | (sq << 10);  break;
        case STM32F4_ADC_SEQUENCE_NUM_4:    adc->SQR3 = (adc->SQR3 & ~ADC_SQR3_SQ4 ) | (sq << 15);  break;
        case STM32F4_ADC_SEQUENCE_NUM_5:    adc->SQR3 = (adc->SQR3 & ~ADC_SQR3_SQ5 ) | (sq << 20);  break;
        case STM32F4_ADC_SEQUENCE_NUM_6:    adc->SQR3 = (adc->SQR3 & ~ADC_SQR3_SQ6 ) | (sq << 25);  break;
        case STM32F4_ADC_SEQUENCE_NUM_7:    adc->SQR2 = (adc->SQR2 & ~ADC_SQR2_SQ7 ) | (sq <<  0);  break;
        case STM32F4_ADC_SEQUENCE_NUM_8:    adc->SQR2 = (adc->SQR2 & ~ADC_SQR2_SQ8 ) | (sq <<  5);  break;
        case STM32F4_ADC_SEQUENCE_NUM_9:    adc->SQR2 = (adc->SQR2 & ~ADC_SQR2_SQ9 ) | (sq << 10);  break;
        case STM32F4_ADC_SEQUENCE_NUM_10:   adc->SQR2 = (adc->SQR2 & ~ADC_SQR2_SQ10 ) | (sq << 15); break;
        case STM32F4_ADC_SEQUENCE_NUM_11:   adc->SQR2 = (adc->SQR2 & ~ADC_SQR2_SQ11 ) | (sq << 20); break;
        case STM32F4_ADC_SEQUENCE_NUM_12:   adc->SQR2 = (adc->SQR2 & ~ADC_SQR2_SQ12 ) | (sq << 25); break;
        case STM32F4_ADC_SEQUENCE_NUM_13:   adc->SQR1 = (adc->SQR1 & ~ADC_SQR1_SQ13 ) | (sq <<  0); break;
        case STM32F4_ADC_SEQUENCE_NUM_14:   adc->SQR1 = (adc->SQR1 & ~ADC_SQR1_SQ14 ) | (sq <<  5); break;
        case STM32F4_ADC_SEQUENCE_NUM_15:   adc->SQR1 = (adc->SQR1 & ~ADC_SQR1_SQ15 ) | (sq << 10); break;
        case STM32F4_ADC_SEQUENCE_NUM_16:   adc->SQR1 = (adc->SQR1 & ~ADC_SQR1_SQ16 ) | (sq << 15); break;
        default:
            break;
    }
}

static
void stm32f4_adc_sequence_size_set(     ADC_TypeDef *                   adc,
                                const   stm32f4_adc_sequence_size_t     size )
{
    adc->SQR1           =   (adc->SQR1 & ~ADC_SQR1_L) | (size << 20);
}

static
void stm32f4_adc_multi_cfg(             ADC_TypeDef *                   adc )
{

}

static
void stm32f4_adc_start(                 ADC_TypeDef *                   adc )
{
    adc->CR2            |=  ADC_CR2_SWSTART;
}

static
int stm32f4_adc_conv_ticks_get(         stm32f4_adc_resolution_t        res )
{
    int             ticks;

    switch( res )
    {
        case STM32F4_ADC_RESOLUTION_12_BIT:     ticks = 12;     break;
        case STM32F4_ADC_RESOLUTION_10_BIT:     ticks = 10;     break;
        case STM32F4_ADC_RESOLUTION_8_BIT:      ticks = 8;      break;
        case STM32F4_ADC_RESOLUTION_6_BIT:      ticks = 6;      break;
        default:                                ticks = -1;     break;
    }

    return( ticks );
}

static
void stm32f4_adc_smpl_time_cfg(         ADC_TypeDef *                   adc,
                                const   stm32f4_adc_chnl_t              chnl,
                                const   uint32_t                        ticks )
{
    uint32_t        smp;

    if(      ticks <=   3 ) { smp   =   0x0; }
    else if( ticks <=  15 ) { smp   =   0x1; }
    else if( ticks <=  28 ) { smp   =   0x2; }
    else if( ticks <=  56 ) { smp   =   0x3; }
    else if( ticks <=  84 ) { smp   =   0x4; }
    else if( ticks <= 112 ) { smp   =   0x5; }
    else if( ticks <= 144 ) { smp   =   0x6; }
    else                    { smp   =   0x7; }

    switch( chnl )
    {
        case STM32F4_ADC_CHNL_VBAT_TSENS:   adc->SMPR1 = (adc->SMPR1 & ~ADC_SMPR1_SMP18) | (smp << 24); break;
        case STM32F4_ADC_CHNL_VREF:         adc->SMPR1 = (adc->SMPR1 & ~ADC_SMPR1_SMP17) | (smp << 21); break;
        case STM32F4_ADC_CHNL_15:           adc->SMPR1 = (adc->SMPR1 & ~ADC_SMPR1_SMP15) | (smp << 15); break;
        case STM32F4_ADC_CHNL_14:           adc->SMPR1 = (adc->SMPR1 & ~ADC_SMPR1_SMP14) | (smp << 12); break;
        case STM32F4_ADC_CHNL_13:           adc->SMPR1 = (adc->SMPR1 & ~ADC_SMPR1_SMP13) | (smp <<  9); break;
        case STM32F4_ADC_CHNL_12:           adc->SMPR1 = (adc->SMPR1 & ~ADC_SMPR1_SMP12) | (smp <<  6); break;
        case STM32F4_ADC_CHNL_11:           adc->SMPR1 = (adc->SMPR1 & ~ADC_SMPR1_SMP11) | (smp <<  3); break;
        case STM32F4_ADC_CHNL_10:           adc->SMPR1 = (adc->SMPR1 & ~ADC_SMPR1_SMP10) | (smp <<  0); break;
        case STM32F4_ADC_CHNL_09:           adc->SMPR2 = (adc->SMPR2 & ~ADC_SMPR2_SMP9) | (smp <<  27); break;
        case STM32F4_ADC_CHNL_08:           adc->SMPR2 = (adc->SMPR2 & ~ADC_SMPR2_SMP8) | (smp <<  24); break;
        case STM32F4_ADC_CHNL_07:           adc->SMPR2 = (adc->SMPR2 & ~ADC_SMPR2_SMP7) | (smp <<  21); break;
        case STM32F4_ADC_CHNL_06:           adc->SMPR2 = (adc->SMPR2 & ~ADC_SMPR2_SMP6) | (smp <<  18); break;
        case STM32F4_ADC_CHNL_05:           adc->SMPR2 = (adc->SMPR2 & ~ADC_SMPR2_SMP5) | (smp <<  15); break;
        case STM32F4_ADC_CHNL_04:           adc->SMPR2 = (adc->SMPR2 & ~ADC_SMPR2_SMP4) | (smp <<  12); break;
        case STM32F4_ADC_CHNL_03:           adc->SMPR2 = (adc->SMPR2 & ~ADC_SMPR2_SMP3) | (smp <<   9); break;
        case STM32F4_ADC_CHNL_02:           adc->SMPR2 = (adc->SMPR2 & ~ADC_SMPR2_SMP2) | (smp <<   6); break;
        case STM32F4_ADC_CHNL_01:           adc->SMPR2 = (adc->SMPR2 & ~ADC_SMPR2_SMP1) | (smp <<   3); break;
        case STM32F4_ADC_CHNL_00:           adc->SMPR2 = (adc->SMPR2 & ~ADC_SMPR2_SMP0) | (smp <<   0); break;
        default:
            break;
    }
}

#endif  //STM32F4_ADC_H
