/**
  * @file    stm32f4_tmr.c
  * @brief   STM32F4 Timer
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef STM32F4_TMR_H
#define STM32F4_TMR_H


#include "stm32f4xx.h"


#if !defined(STM32F446xx) && !defined(STM32F407xx)
# warning    the code below may to work correct, but was not checked
#endif


typedef enum    stm32f4_tmr_chnl_s
{
	STM32F4_TMR_CHNL_1,
	STM32F4_TMR_CHNL_2,
	STM32F4_TMR_CHNL_3,
	STM32F4_TMR_CHNL_4,
} stm32f4_tmr_chnl_t;

// CR1
typedef enum    stm32f4_tmr_ckdiv_s
{
	STM32F4_TMR_CKDIV_1                     = 0x0,
	STM32F4_TMR_CKDIV_2                     = 0x1,
	STM32F4_TMR_CKDIV_4                     = 0x2,
} stm32f4_tmr_ckdiv_t;

typedef enum    stm32f4_tmr_cnt_preload_s
{
	STM32F4_TMR_CNT_PRELOAD_DISABLE         = 0x0,
	STM32F4_TMR_CNT_PRELOAD_ENABLE          = 0x1,
} stm32f4_tmr_cnt_preload_t;

typedef enum    stm32f4_tmr_cnt_mode_s
{
	STM32F4_TMR_CNT_MODE_UP_NONSTOP         = 0x0,
	STM32F4_TMR_CNT_MODE_UP_ONESHOT         = 0x1,
	STM32F4_TMR_CNT_MODE_DN_NONSTOP         = 0x2,
	STM32F4_TMR_CNT_MODE_DN_ONESHOT         = 0x3,
	STM32F4_TMR_CNT_MODE_UPDN_MODE1_NONSTOP = 0x4,
	STM32F4_TMR_CNT_MODE_UPDN_MODE1_ONESHOT = 0x5,
	STM32F4_TMR_CNT_MODE_UPDN_MODE2_NONSTOP = 0x8,
	STM32F4_TMR_CNT_MODE_UPDN_MODE2_ONESHOT = 0x9,
	STM32F4_TMR_CNT_MODE_UPDN_MODE3_NONSTOP = 0xC,
	STM32F4_TMR_CNT_MODE_UPDN_MODE3_ONESHOT = 0xD,
} stm32f4_tmr_cnt_mode_t;


typedef enum    stm32f4_tmr_cnt_upd_evt_s
{
	STM32F4_TMR_CNT_UPD_EVT_SRC_ANY         = 0x0,
	STM32F4_TMR_CNT_UPD_EVT_SRC_CNT         = 0x2,
	STM32F4_TMR_CNT_UPD_EVT_DISABLE         = 0x3,
} stm32f4_tmr_cnt_upd_evt_t;

// CR2
typedef enum    stm32f4_tmr_mstr_out_s
{
	STM32F4_TMR_MSTR_OUT_DEFAULT            = 0x0,
	STM32F4_TMR_MSTR_OUT_UG                 = 0x0,
	STM32F4_TMR_MSTR_OUT_CNT_EN             = 0x1,
	STM32F4_TMR_MSTR_OUT_UPDT_EVNT          = 0x2,
	STM32F4_TMR_MSTR_OUT_CC1IF              = 0x3,
	STM32F4_TMR_MSTR_OUT_OC1REF             = 0x4,
	STM32F4_TMR_MSTR_OUT_OC2REF             = 0x5,
	STM32F4_TMR_MSTR_OUT_OC3REF             = 0x6,
	STM32F4_TMR_MSTR_OUT_OC4REF             = 0x7,
} stm32f4_tmr_mstr_out_t;

typedef enum    stm32f4_tmr_chnl_dma_evt_s
{
	STM32F4_TMR_CHNL_DMA_EVT_DEFAULT        = 0x0,
	STM32F4_TMR_CHNL_DMA_EVT_CCx            = 0x0,
	STM32F4_TMR_CHNL_DMA_EVT_UPD            = 0x1,
} stm32f4_tmr_chnl_dma_evt_t;

typedef enum    stm32f4_tmr_chnl_upd_evt_s
{
	STM32F4_TMR_CHNL_UPD_EVT_COMG_ONLY      = 0x0,
	STM32F4_TMR_CHNL_UPD_EVT_COMG_OR_TRGI   = 0x1,
} stm32f4_tmr_chnl_upd_evt_t;

typedef enum    stm32f4_tmr_chnl_preload_s
{
	STM32F4_TMR_CHNL_PRELOAD_DISABLE        = 0x0,
	STM32F4_TMR_CHNL_PRELOAD_ENABLE         = 0x1,
} stm32f4_tmr_chnl_preload_t;

typedef enum    stm32f4_tmr_smcr_etrp_s
{
	STM32F4_TMR_SMCR_ETRP_POSEDGE_DIV1      = 0x0,
	STM32F4_TMR_SMCR_ETRP_POSEDGE_DIV2      = 0x1,
	STM32F4_TMR_SMCR_ETRP_POSEDGE_DIV4      = 0x2,
	STM32F4_TMR_SMCR_ETRP_POSEDGE_DIV8      = 0x3,
	STM32F4_TMR_SMCR_ETRP_NEGEDGE_DIV1      = 0x8,
	STM32F4_TMR_SMCR_ETRP_NEGEDGE_DIV2      = 0x9,
	STM32F4_TMR_SMCR_ETRP_NEGEDGE_DIV4      = 0xA,
	STM32F4_TMR_SMCR_ETRP_NEGEDGE_DIV8      = 0xB,
	STM32F4_TMR_SMCR_ETRP_ANYEDGE_DIV1      = 0x4,
	STM32F4_TMR_SMCR_ETRP_ANYEDGE_DIV2      = 0x5,
	STM32F4_TMR_SMCR_ETRP_ANYEDGE_DIV4      = 0x6,
	STM32F4_TMR_SMCR_ETRP_ANYEDGE_DIV8      = 0x7,
} stm32f4_tmr_smcr_etrp_t;

typedef enum    stm32f4_tmr_smcr_etrf_s
{
	STM32F4_TMR_SMCR_ETRF_DIV1_N1           = 0x0,
	STM32F4_TMR_SMCR_ETRF_DIV1_N2           = 0x1,
	STM32F4_TMR_SMCR_ETRF_DIV1_N4           = 0x2,
	STM32F4_TMR_SMCR_ETRF_DIV1_N8           = 0x3,
	STM32F4_TMR_SMCR_ETRF_DIV2_N6           = 0x4,
	STM32F4_TMR_SMCR_ETRF_DIV2_N8           = 0x5,
	STM32F4_TMR_SMCR_ETRF_DIV4_N6           = 0x6,
	STM32F4_TMR_SMCR_ETRF_DIV4_N8           = 0x7,
	STM32F4_TMR_SMCR_ETRF_DIV8_N6           = 0x8,
	STM32F4_TMR_SMCR_ETRF_DIV8_N8           = 0x9,
	STM32F4_TMR_SMCR_ETRF_DIV16_N5          = 0xA,
	STM32F4_TMR_SMCR_ETRF_DIV16_N6          = 0xB,
	STM32F4_TMR_SMCR_ETRF_DIV16_N8          = 0xC,
	STM32F4_TMR_SMCR_ETRF_DIV32_N5          = 0xD,
	STM32F4_TMR_SMCR_ETRF_DIV32_N6          = 0xE,
	STM32F4_TMR_SMCR_ETRF_DIV32_N8          = 0xF,
} stm32f4_tmr_smcr_etrf_t;

typedef enum    stm32f4_tmr_smcr_msm_s
{
	STM32F4_TMR_SMCR_MSM_DISABLE            = 0x0,
	STM32F4_TMR_SMCR_MSM_ENABLE             = 0x1,
} stm32f4_tmr_smcr_msm_t;

typedef enum    stm32f4_tmr_smcr_trg_sel_s
{
	STM32F4_TMR_SMCR_TRG_SEL_DEFAULT        = 0x0,
	STM32F4_TMR_SMCR_TRG_SEL_ITR0           = 0x0,
	STM32F4_TMR_SMCR_TRG_SEL_ITR1           = 0x1,
	STM32F4_TMR_SMCR_TRG_SEL_ITR2           = 0x2,
	STM32F4_TMR_SMCR_TRG_SEL_ITR3           = 0x3,
	STM32F4_TMR_SMCR_TRG_SEL_TI1F_ED        = 0x4,
	STM32F4_TMR_SMCR_TRG_SEL_TI1FP1         = 0x5,
	STM32F4_TMR_SMCR_TRG_SEL_TI1FP2         = 0x6,
	STM32F4_TMR_SMCR_TRG_SEL_ETRF           = 0x7,
} stm32f4_tmr_smcr_trg_sel_t;

typedef enum    stm32f4_tmr_smcr_slave_mode_s
{
	STM32F4_TMR_SMCR_SLV_MODE_DISABLED      = 0x0,
	STM32F4_TMR_SMCR_SLV_MODE_ENCODER1      = 0x1,
	STM32F4_TMR_SMCR_SLV_MODE_ENCODER2      = 0x2,
	STM32F4_TMR_SMCR_SLV_MODE_ENCODER3      = 0x3,
	STM32F4_TMR_SMCR_SLV_MODE_RESET         = 0x4,
	STM32F4_TMR_SMCR_SLV_MODE_GATED         = 0x5,
	STM32F4_TMR_SMCR_SLV_MODE_TRIGGER       = 0x6,
	STM32F4_TMR_SMCR_SLV_MODE_EXTCLK1       = 0x7,
} stm32f4_tmr_smcr_slave_mode_t;

typedef enum    stm32f4_tmr_chnl_mode_s
{
	STM32F4_TMR_CHNL_MODE_COMPARE           = 0x0,
	STM32F4_TMR_CHNL_MODE_CAPTURE_TI1       = 0x1,
	STM32F4_TMR_CHNL_MODE_CAPTURE_TI2       = 0x2,
	STM32F4_TMR_CHNL_MODE_CAPTURE_TRC       = 0x3
} stm32f4_tmr_chnl_mode_t;

typedef enum    stm32f4_tmr_cmp_clr_s
{
	STM32F4_TMR_CMP_CLR_DISABLE             = 0x0,
	STM32F4_TMR_CMP_CLR_ENABLE              = 0x1
} stm32f4_tmr_cmp_clr_t;

typedef enum    stm32f4_tmr_cmp_mode_s
{
	STM32F4_TMR_CMP_MODE_FROZEN             = 0x0,
	STM32F4_TMR_CMP_MODE_SET_ON_MATCH       = 0x1,
	STM32F4_TMR_CMP_MODE_CLR_ON_MATCH       = 0x2,
	STM32F4_TMR_CMP_MODE_TGGL_ON_MATCH      = 0x3,
	STM32F4_TMR_CMP_MODE_FORCE_MATCH_FALSE  = 0x4,
	STM32F4_TMR_CMP_MODE_FORCE_MATCH_TRUE   = 0x5,
	STM32F4_TMR_CMP_MODE_PWM_POSITIVE       = 0x6,
	STM32F4_TMR_CMP_MODE_PWM_NEGATIVE       = 0x7
} stm32f4_tmr_cmp_mode_t;

typedef enum    stm32f4_tmr_cmp_preload_s
{
	STM32F4_TMR_CMP_PRELOAD_DISABLE         = 0x0,
	STM32F4_TMR_CMP_PRELOAD_ENABLE          = 0x1
} stm32f4_tmr_cmp_preload_t;

typedef enum    stm32f4_tmr_cmp_fast_s
{
	STM32F4_TMR_CMP_FAST_DISABLE            = 0x0,
	STM32F4_TMR_CMP_FAST_ENABLE             = 0x1
} stm32f4_tmr_cmp_fast_t;

// OUT
typedef enum    stm32f4_tmr_out_s
{
	STM32F4_TMR_OUT_DISABLE                 = 0x0,
	STM32F4_TMR_OUT_DIRECT                  = 0x1,
	STM32F4_TMR_OUT_INVERT                  = 0x3,
} stm32f4_tmr_out_t;

//
typedef enum    stm32f4_tmr_int_s
{
	STM32F4_TMR_INT_PE = USART_CR1_PEIE,
	STM32F4_TMR_INT_TXE = USART_CR1_TXEIE,
	STM32F4_TMR_INT_TC = USART_CR1_TCIE,
	STM32F4_TMR_INT_RXNE = USART_CR1_RXNEIE,
	STM32F4_TMR_INT_IDLE = USART_CR1_IDLEIE,
} stm32f4_tmr_int_t;


static
void stm32f4_tmr_disable(               TIM_TypeDef *                   tmr )
{
	tmr->CR1 &= ~TIM_CR1_CEN;
}

static
void stm32f4_tmr_enable(                TIM_TypeDef *                   tmr )
{
	tmr->CR1 |= TIM_CR1_CEN;
}

static
void stm32f4_tmr_reload(                TIM_TypeDef *                   tmr )
{
	tmr->EGR |= TIM_EGR_UG;
}
/*
static
void stm32f4_tmr_cfg(                   TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_ckdiv_t             ckdiv )
{
	tmr->CR1 = (tmr->CR1 & ~TIM_CR1_CKD) | (ckdiv << 8);
}
*/
/*
static
void stm32f4_tmr_cfg_chnl_dma_evt(      TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_dma_evt_t      dma_evt )
{
	tmr->CR2 = (tmr->CR2 & ~TIM_CR2_CCDS) | (dma_evt << 3);
}

static
void stm32f4_tmr_cfg_chnl_update(       TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_upd_evt_t      upd_evt )
{
	tmr->CR2 = (tmr->CR2 & ~TIM_CR2_CCUS) | (upd_evt << 2);
}

static
void stm32f4_tmr_cfg_chnl_preload(      TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_preload_t      preload )
{
	tmr->CR2 = (tmr->CR2 & ~TIM_CR2_CCPC) | (preload << 0);
}
*/
static
void stm32f4_tmr_cfg(                   TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_ckdiv_t             ckdiv,
                                const   stm32f4_tmr_chnl_dma_evt_t      dma_evt,
                                const   stm32f4_tmr_chnl_upd_evt_t      upd_evt,
                                const   stm32f4_tmr_chnl_preload_t      preload )
{
	uint32_t    cr1_mask    =   TIM_CR1_CKD;
	uint32_t    cr2_mask    =   TIM_CR2_CCDS | TIM_CR2_CCUS | TIM_CR2_CCPC;

	tmr->CR1 = (tmr->CR1 & ~cr1_mask) | (ckdiv << 8);
	tmr->CR2 = (tmr->CR2 & ~cr2_mask) | (dma_evt << 3) | (upd_evt << 2) | (preload << 0);
}

static
void stm32f4_tmr_cnt_cfg(               TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_cnt_preload_t       arpe,
                                const   stm32f4_tmr_cnt_mode_t          mode,
                                const   stm32f4_tmr_cnt_upd_evt_t       upd_evt )
{
	uint32_t    cr1_mask    =   TIM_CR1_ARPE | TIM_CR1_CMS | TIM_CR1_DIR | TIM_CR1_OPM | TIM_CR1_URS | TIM_CR1_UDIS;
	uint32_t    cr1         =   (arpe << 7) | (mode << 3) | (upd_evt << 1);

	tmr->CR1 = (tmr->CR1 & ~cr1_mask) | cr1;
}


static
void stm32f4_tmr_cfg_master(            TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_mstr_out_t          mms )
{
	tmr->CR2 = (tmr->CR2 & ~TIM_CR2_MMS) | (mms << 4);
}

static
void stm32f4_tmr_cfg_slave(             TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_smcr_etrp_t         etrp,
                                const   stm32f4_tmr_smcr_etrf_t         etrf,
                                const   stm32f4_tmr_smcr_msm_t          msm,
                                const   stm32f4_tmr_smcr_trg_sel_t      ts,
                                const   stm32f4_tmr_smcr_slave_mode_t   sms )
{
	uint32_t    etrp_mask   =   TIM_SMCR_ETP | TIM_SMCR_ECE | TIM_SMCR_ETPS;
	uint32_t    smcr_mask   =   (etrp_mask | TIM_SMCR_ETF | TIM_SMCR_MSM | TIM_SMCR_TS | TIM_SMCR_SMS | 0xFFFF0008);

	tmr->SMCR = (tmr->SMCR & ~smcr_mask) | (etrp << 12) | (etrf << 8) | (msm << 7) | (ts << 4) | (sms << 0);
}

static
void stm32f4_tmr_chnl_cfg_mode(         TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_t              chnl,
                                const   stm32f4_tmr_chnl_mode_t         ccxs )
{
	switch( chnl )
        {
                case STM32F4_TMR_CHNL_1:        tmr->CCMR1 = (tmr->CCMR1 & ~TIM_CCMR1_CC1S) | (ccxs << 0);      break;
                case STM32F4_TMR_CHNL_2:        tmr->CCMR1 = (tmr->CCMR1 & ~TIM_CCMR1_CC2S) | (ccxs << 8);      break;
                case STM32F4_TMR_CHNL_3:        tmr->CCMR2 = (tmr->CCMR2 & ~TIM_CCMR2_CC3S) | (ccxs << 0);      break;
                case STM32F4_TMR_CHNL_4:        tmr->CCMR2 = (tmr->CCMR2 & ~TIM_CCMR2_CC4S) | (ccxs << 8);      break;
                default:
                        break;
	}
}

static
void stm32f4_tmr_prescaler_set(         TIM_TypeDef *                   tmr,
                                const   size_t                          prescale )
{
	tmr->PSC        =   prescale;
}

static
uint16_t stm32f4_tmr_prescaler_get(     TIM_TypeDef *                   tmr )
{
	return( tmr->PSC );
}

/******************************************************************************/
/* TIMER - COUNTER                                                            */
/******************************************************************************/

static
void stm32f4_tmr_period_set(            TIM_TypeDef *                   tmr,
                                const   uint32_t                        period )
{
	tmr->ARR        =   period;
}

static
uint32_t stm32f4_tmr_period_get(        TIM_TypeDef *                   tmr )
{
	return tmr->ARR;
}

static
void stm32f4_tmr_cnt_set(               TIM_TypeDef *                   tmr,
                                const   uint32_t                        counter )
{
	tmr->CNT        =   counter;
}

static
uint16_t stm32f4_tmr_cnt_get(           TIM_TypeDef *                   tmr )
{
	return( tmr->CNT );
}

/******************************************************************************/
/* TIMER - CHANNEL - COMPARE                                                  */
/******************************************************************************/
/*
static
void stm32f4_tmr_cmp_cfg_fast(          TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_t              chnl,
                                const   stm32f4_tmr_cmp_fast_t          ocxfe )
{
	switch( chnl )
        {
                case STM32F4_TMR_CHNL_1:        tmr->CCMR1 = (tmr->CCMR1 & ~TIM_CCMR1_OC1FE) | (ocxfe <<  2);   break;
                case STM32F4_TMR_CHNL_2:        tmr->CCMR1 = (tmr->CCMR1 & ~TIM_CCMR1_OC2FE) | (ocxfe << 10);   break;
                case STM32F4_TMR_CHNL_3:        tmr->CCMR2 = (tmr->CCMR2 & ~TIM_CCMR2_OC3FE) | (ocxfe <<  2);   break;
                case STM32F4_TMR_CHNL_4:        tmr->CCMR2 = (tmr->CCMR2 & ~TIM_CCMR2_OC4FE) | (ocxfe << 10);   break;
                default:
                        break;
	}
}

static
void stm32f4_tmr_cmp_cfg_preload(       TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_t              chnl,
                                const   stm32f4_tmr_cmp_preload_t       ocxpe )
{
        switch( chnl )
        {
                case STM32F4_TMR_CHNL_1:        tmr->CCMR1 = (tmr->CCMR1 & ~TIM_CCMR1_OC1PE) | (ocxpe <<  3);   break;
                case STM32F4_TMR_CHNL_2:        tmr->CCMR1 = (tmr->CCMR1 & ~TIM_CCMR1_OC2PE) | (ocxpe << 11);   break;
                case STM32F4_TMR_CHNL_3:        tmr->CCMR2 = (tmr->CCMR2 & ~TIM_CCMR2_OC3PE) | (ocxpe <<  3);   break;
                case STM32F4_TMR_CHNL_4:        tmr->CCMR2 = (tmr->CCMR2 & ~TIM_CCMR2_OC4PE) | (ocxpe << 11);   break;
                default:
                        break;
	}
}

static
void stm32f4_tmr_cmp_cfg_mode(          TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_t              chnl,
                                const   stm32f4_tmr_cmp_mode_t          ocxm )
{
        switch( chnl )
        {
                case STM32F4_TMR_CHNL_1:        tmr->CCMR1 = (tmr->CCMR1 & ~TIM_CCMR1_OC1M) | (ocxm <<  4);     break;
                case STM32F4_TMR_CHNL_2:        tmr->CCMR1 = (tmr->CCMR1 & ~TIM_CCMR1_OC2M) | (ocxm << 12);     break;
                case STM32F4_TMR_CHNL_3:        tmr->CCMR2 = (tmr->CCMR2 & ~TIM_CCMR2_OC3M) | (ocxm <<  4);     break;
                case STM32F4_TMR_CHNL_4:        tmr->CCMR2 = (tmr->CCMR2 & ~TIM_CCMR2_OC4M) | (ocxm << 12);     break;
                default:
                        break;
	}
}

static
void stm32f4_tmr_cmp_cfg_clr(           TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_t              chnl,
                                const   stm32f4_tmr_cmp_clr_t           ocxce )
{
	switch( chnl )
        {
                case STM32F4_TMR_CHNL_1:        tmr->CCMR1 = (tmr->CCMR1 & ~TIM_CCMR1_OC1CE) | (ocxce <<  7);   break;
                case STM32F4_TMR_CHNL_2:        tmr->CCMR1 = (tmr->CCMR1 & ~TIM_CCMR1_OC2CE) | (ocxce << 15);   break;
                case STM32F4_TMR_CHNL_3:        tmr->CCMR2 = (tmr->CCMR2 & ~TIM_CCMR2_OC3CE) | (ocxce <<  7);   break;
                case STM32F4_TMR_CHNL_4:        tmr->CCMR2 = (tmr->CCMR2 & ~TIM_CCMR2_OC4CE) | (ocxce << 15);   break;
                default:
                        break;
	}
}
*/





static
void stm32f4_tmr_cmp_cfg(               TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_t              chnl,
                                const   stm32f4_tmr_cmp_fast_t          ocxfe,
                                const   stm32f4_tmr_cmp_preload_t       ocxpe,
                                const   stm32f4_tmr_cmp_mode_t          ocxm,
                                const   stm32f4_tmr_cmp_clr_t           ocxce )
{
        uint32_t        ccmr1_ch1_mask  =   TIM_CCMR1_OC1FE | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1M | TIM_CCMR1_OC1CE;
        uint32_t        ccmr1_ch2_mask  =   TIM_CCMR1_OC2FE | TIM_CCMR1_OC2PE | TIM_CCMR1_OC2M | TIM_CCMR1_OC2CE;
        uint32_t        ccmr2_ch3_mask  =   TIM_CCMR2_OC3FE | TIM_CCMR2_OC3PE | TIM_CCMR2_OC3M | TIM_CCMR2_OC3CE;
        uint32_t        ccmr2_ch4_mask  =   TIM_CCMR2_OC4FE | TIM_CCMR2_OC4PE | TIM_CCMR2_OC4M | TIM_CCMR2_OC4CE;
	uint32_t        ccmr1_ch1       =   (ocxfe <<  2) | (ocxpe <<  3) | (ocxm <<  4) | (ocxce <<  7);
	uint32_t        ccmr1_ch2       =   (ocxfe << 10) | (ocxpe << 11) | (ocxm << 12) | (ocxce << 15);
	uint32_t        ccmr2_ch3       =   (ocxfe <<  2) | (ocxpe <<  3) | (ocxm <<  4) | (ocxce <<  7);
	uint32_t        ccmr2_ch4       =   (ocxfe << 10) | (ocxpe << 11) | (ocxm << 12) | (ocxce << 15);


	switch( chnl )
        {
                case STM32F4_TMR_CHNL_1: tmr->CCMR1 = (tmr->CCMR1 & ~ccmr1_ch1_mask) | ccmr1_ch1; break;
                case STM32F4_TMR_CHNL_2: tmr->CCMR1 = (tmr->CCMR1 & ~ccmr1_ch2_mask) | ccmr1_ch2; break;
                case STM32F4_TMR_CHNL_3: tmr->CCMR2 = (tmr->CCMR2 & ~ccmr2_ch3_mask) | ccmr2_ch3; break;
                case STM32F4_TMR_CHNL_4: tmr->CCMR2 = (tmr->CCMR2 & ~ccmr2_ch4_mask) | ccmr2_ch4; break;
                default:                                                                          break;
	}
}







static
void stm32f4_tmr_cmp_set(               TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_t              chnl,
                                const   uint16_t                        cmp )
{
	switch( chnl )
        {
                case STM32F4_TMR_CHNL_1:        tmr->CCR1 = cmp;        break;
                case STM32F4_TMR_CHNL_2:        tmr->CCR2 = cmp;        break;
                case STM32F4_TMR_CHNL_3:        tmr->CCR3 = cmp;        break;
                case STM32F4_TMR_CHNL_4:        tmr->CCR4 = cmp;        break;
                default:
                        break;
	}
}

/******************************************************************************/
/* TIMER - CHANNEL - OUTPUT                                                   */
/******************************************************************************/

static
void stm32f4_tmr_out_p_cfg(             TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_t              chnl,
                                const   stm32f4_tmr_out_t               out )
{
        switch( chnl )
        {
                case STM32F4_TMR_CHNL_1: tmr->CCER = (tmr->CCER & ~(0x00000003u)) | (out <<  0); break;
                case STM32F4_TMR_CHNL_2: tmr->CCER = (tmr->CCER & ~(0x00000030u)) | (out <<  4); break;
                case STM32F4_TMR_CHNL_3: tmr->CCER = (tmr->CCER & ~(0x00000300u)) | (out <<  8); break;
                case STM32F4_TMR_CHNL_4: tmr->CCER = (tmr->CCER & ~(0x00003000u)) | (out << 12); break;
                default:
                        break;
	}
}

static
void stm32f4_tmr_out_n_cfg(             TIM_TypeDef *                   tmr,
                                const   stm32f4_tmr_chnl_t              chnl,
                                const   stm32f4_tmr_out_t               out )
{
	switch( chnl )
        {
                case STM32F4_TMR_CHNL_1: tmr->CCER = (tmr->CCER & ~(0x0000000Cu)) | (out <<  2); break;
                case STM32F4_TMR_CHNL_2: tmr->CCER = (tmr->CCER & ~(0x000000C0u)) | (out <<  6); break;
                case STM32F4_TMR_CHNL_3: tmr->CCER = (tmr->CCER & ~(0x00000C00u)) | (out << 10); break;
                case STM32F4_TMR_CHNL_4: tmr->CCER = (tmr->CCER & ~(0x0000C000u)) | (out << 14); break;
                default:
                        break;
	}
}

#endif  // STM32F4_TMR_H
