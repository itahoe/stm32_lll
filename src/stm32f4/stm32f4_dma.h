/**
  * @file    stm32f4_dma.c
  * @brief   STM32F4 DMA
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef  STM32F4_DMA_H
#define  STM32F4_DMA_H


#include <stdbool.h>
#include "stm32f4xx.h"


#if !defined(STM32F446xx) && !defined(STM32F407xx)
# warning    the code below may to work correct, but was not checked
#endif


typedef enum    stm32f4_dma_stream_s
{
	STM32F4_DMA_STREAM_0                        = 0x0,
	STM32F4_DMA_STREAM_1                        = 0x1,
	STM32F4_DMA_STREAM_2                        = 0x2,
	STM32F4_DMA_STREAM_3                        = 0x3,
	STM32F4_DMA_STREAM_4                        = 0x4,
	STM32F4_DMA_STREAM_5                        = 0x5,
	STM32F4_DMA_STREAM_6                        = 0x6,
	STM32F4_DMA_STREAM_7                        = 0x7,
} stm32f4_dma_stream_t;

typedef enum    stm32f4_dma_rqst_chnl_s
{
	STM32F4_DMA_RQST_CHNL_0                     = 0x0,
	STM32F4_DMA_RQST_CHNL_1                     = 0x1,
	STM32F4_DMA_RQST_CHNL_2                     = 0x2,
	STM32F4_DMA_RQST_CHNL_3                     = 0x3,
	STM32F4_DMA_RQST_CHNL_4                     = 0x4,
	STM32F4_DMA_RQST_CHNL_5                     = 0x5,
	STM32F4_DMA_RQST_CHNL_6                     = 0x6,
	STM32F4_DMA_RQST_CHNL_7                     = 0x7,
} stm32f4_dma_rqst_chnl_t;

typedef enum    stm32f4_dma_burst_s
{
	STM32F4_DMA_BURST_NONE                      = 0x0,
	STM32F4_DMA_BURST_4                         = 0x1,
	STM32F4_DMA_BURST_8                         = 0x2,
	STM32F4_DMA_BURST_16                        = 0x3,
} stm32f4_dma_burst_t;

typedef enum    stm32f4_dma_priority_s
{
	STM32F4_DMA_PRIORITY_LOW                    = 0x0,
	STM32F4_DMA_PRIORITY_MEDIUM                 = 0x1,
	STM32F4_DMA_PRIORITY_HIGH                   = 0x2,
	STM32F4_DMA_PRIORITY_VERYHIGH               = 0x3,
} stm32f4_dma_priority_t;

typedef enum    stm32f4_dma_xfer_size_s
{
	STM32F4_DMA_XFER_SIZE_8_BIT                 = 0x0,
	STM32F4_DMA_XFER_SIZE_16_BIT                = 0x1,
	STM32F4_DMA_XFER_SIZE_32_BIT                = 0x2,
} stm32f4_dma_xfer_size_t;

typedef enum    stm32f4_dma_increment_s
{
	STM32F4_DMA_INCREMENT_DISABLE               = 0x0,
	STM32F4_DMA_INCREMENT_ENABLE                = 0x1,
} stm32f4_dma_increment_t;

typedef enum    stm32f4_dma_circular_s
{
	STM32F4_DMA_CIRCULAR_DISABLE                = 0x0,
	STM32F4_DMA_CIRCULAR_ENABLE                 = 0x1,
} stm32f4_dma_circular_t;

typedef enum    stm32f4_dma_dir_s
{
	STM32F4_DMA_DIR_PERI2MEM                    = 0x0,
	STM32F4_DMA_DIR_MEM2PERI                    = 0x1,
	STM32F4_DMA_DIR_MEM2MEM                     = 0x2,
} stm32f4_dma_dir_t;

typedef enum    stm32f4_dma_irq_s
{
	STM32F4_DMA_IRQ_DIRECTMODE_ERR              = 0x0,
	STM32F4_DMA_IRQ_XFER_ERR                    = 0x1,
	STM32F4_DMA_IRQ_XFER_HALF                   = 0x2,
	STM32F4_DMA_IRQ_XFER_COMPLETE               = 0x3,
} stm32f4_dma_irq_t;


static
void stm32f4_dma_disable(               DMA_Stream_TypeDef *            stream )
{
    stream->CR          &= ~DMA_SxCR_EN;
}

static
void stm32f4_dma_enable(                DMA_Stream_TypeDef *            stream )
{
    stream->CR          |=  DMA_SxCR_EN;
}

static
void stm32f4_dma_cfg_mem(               DMA_Stream_TypeDef *            stream,
                                const   uint32_t                        adr0,
                                const   uint32_t                        adr1,
                                const   stm32f4_dma_burst_t             mburst,
                                const   stm32f4_dma_xfer_size_t         msize,
                                const   stm32f4_dma_increment_t         minc )
{
    uint32_t        cr_mask     =   0xFE7F9BFF;

    stream->M0AR        =   adr0;
    stream->M1AR        =   adr1;
    stream->CR          =   (stream->CR & cr_mask) | (mburst << 23) | (msize << 13) | (minc << 10);
}

static
void stm32f4_dma_cfg_peri(              DMA_Stream_TypeDef *            stream,
                                const   uint32_t                        adr,
                                const   stm32f4_dma_burst_t             pburst,
                                const   stm32f4_dma_xfer_size_t         psize,
                                const   stm32f4_dma_increment_t         pinc )
{
    uint32_t        cr_mask     =   0xFF9FE5FF;

    stream->PAR         =   adr;
    stream->CR          =   (stream->CR & cr_mask) | (pburst << 21) | (psize << 11) | (pinc << 9);
}

static
void stm32f4_dma_cfg_xfer(              DMA_Stream_TypeDef *            stream,
                                const   uint32_t                        xfer_size,
                                const   stm32f4_dma_rqst_chnl_t         chsel,
                                const   stm32f4_dma_priority_t          pl,
                                const   stm32f4_dma_circular_t          circ,
                                const   stm32f4_dma_dir_t               dir )
{
    uint32_t        cr_mask     =   DMA_SxCR_CHSEL | DMA_SxCR_PL | DMA_SxCR_CIRC | DMA_SxCR_DIR;
    uint32_t        cr          =   (chsel << 25) | (pl << 16) | (circ << 8) | (dir << 6);

    stream->NDTR        =   xfer_size;
    stream->CR          =   ( stream->CR & ~cr_mask ) | cr;
}

static
void stm32f4_dma_irq_cfg(               DMA_Stream_TypeDef *            stream,
                                const   stm32f4_dma_irq_t               irq,
                                const   bool                            val )
{
    uint32_t        cr_mask     =   1 << (irq + 1);
    uint32_t        cr          =   val ? (1 << (irq + 1)) : (0 << (irq + 1));

    stream->CR          =   (stream->CR & ~cr_mask) | cr;
}

static
void stm32f4_dma_irq_ack(               DMA_TypeDef *                   dma,
                                const   stm32f4_dma_stream_t            stream,
                                const   stm32f4_dma_irq_t               irq )
{
}

#endif  // STM32F4_DMA_H
