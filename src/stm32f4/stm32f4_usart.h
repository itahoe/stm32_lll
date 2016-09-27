/**
  * @file    stm32f4_usart.c
  * @brief   STM32F4 USART
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef  STM32F4_USART_H
#define  STM32F4_USART_H


#include <stdbool.h>
#include "stm32f4xx.h"


#if !defined(STM32F446xx) && !defined(STM32F407xx)
# warning    the code below may to work correct, but was not checked
#endif


typedef enum    stm32f4_usart_cfg_s
{
	STM32F4_USART_CFG_ASYNC_8_1_NONE = 0,
	STM32F4_USART_CFG_ASYNC_9_1_NONE = USART_CR1_M,
	// STM32F4_USART_CFG_SYNC_8_1_NONE	=	0,
	// STM32F4_USART_CFG_SYNC_9_1_NONE	=	0,
	// STM32F4_USART_CFG_SINGLEWIRE		=	0,
	// STM32F4_USART_CFG_LIN				=	0,
	// STM32F4_USART_CFG_IRDA				=	0,
	// STM32F4_USART_MODE_ISO7816			=	0,
} stm32f4_usart_cfg_t;

typedef enum    stm32f4_usart_mode_s
{
	STM32F4_USART_MODE_RX = USART_CR1_RE,
	STM32F4_USART_MODE_TX = USART_CR1_TE,
	STM32F4_USART_MODE_RX_TX = USART_CR1_RE | USART_CR1_TE,
} stm32f4_usart_mode_t;

typedef enum    stm32f4_usart_int_s
{
	STM32F4_USART_INT_PE = USART_CR1_PEIE,
	STM32F4_USART_INT_TXE = USART_CR1_TXEIE,
	STM32F4_USART_INT_TC = USART_CR1_TCIE,
	STM32F4_USART_INT_RXNE = USART_CR1_RXNEIE,
	STM32F4_USART_INT_IDLE = USART_CR1_IDLEIE,
} stm32f4_usart_int_t;


static
void stm32f4_usart_enable(              USART_TypeDef *                 usart )
{
	usart->CR1 |= USART_CR1_UE;
}

static
void stm32f4_usart_disable(             USART_TypeDef *                 usart )
{
	usart->CR1 &= ~USART_CR1_UE;
}

static
void stm32f4_usart_cfg(                 USART_TypeDef *                 usart,
                                const   stm32f4_usart_cfg_t             cfg )
{
	uint32_t cr1_mask = 0x0000E9FE;

	usart->CR1 = (usart->CR1 & cr1_mask) | cfg;
}

static
void stm32f4_usart_set_baud(            USART_TypeDef *                 usart,
                                const   uint32_t                        pclk,
                                const   uint32_t                        baud )
{
	uint32_t div;
	uint32_t brr_mantissa;
	uint32_t brr_fraction;


	div = (pclk * 25) / (4 * baud);
	brr_mantissa = div / 100;
	brr_fraction = ((div - brr_mantissa * 100) * 16 + 50) / 100;

	usart->BRR = (brr_mantissa << 4) | (brr_fraction & 0xF);
}

static
void stm32f4_usart_set_mode(            USART_TypeDef *                 usart,
                                const   stm32f4_usart_mode_t            mode )
{
	uint32_t cr1_mask = ~(USART_CR1_TE | USART_CR1_RE);

	usart->CR1 = (usart->CR1 & cr1_mask) | mode;
}

static
void stm32f4_usart_int_set(             USART_TypeDef *                 usart,
                                const   stm32f4_usart_int_t             interrupt,
                                const   bool                            val )
{
	uint32_t cr1_mask = ~((uint32_t)interrupt);

	usart->CR1 = (usart->CR1 & cr1_mask) | (val ? interrupt : 0);
}

#endif  // STM32F4_USART_H
