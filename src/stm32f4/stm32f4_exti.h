/**
  * @file    stm32f4_exti.c
  * @brief   STM32F4 EXTI
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef  STM32F4_EXTI_H
#define  STM32F4_EXTI_H


#include <stdbool.h>
#include <stdint.h>
#include "stm32f4xx.h"


#if !defined(STM32F446xx) && !defined(STM32F407xx)
# warning    the code below may to work correct, but was not checked
#endif


typedef enum    stm32f4_exti_line_s
{
	STM32F4_EXTI_LINE_00 = 0x00,
	STM32F4_EXTI_LINE_01 = 0x01,
	STM32F4_EXTI_LINE_02 = 0x02,
	STM32F4_EXTI_LINE_03 = 0x03,
	STM32F4_EXTI_LINE_04 = 0x04,
	STM32F4_EXTI_LINE_05 = 0x05,
	STM32F4_EXTI_LINE_06 = 0x06,
	STM32F4_EXTI_LINE_07 = 0x07,
	STM32F4_EXTI_LINE_08 = 0x08,
	STM32F4_EXTI_LINE_09 = 0x09,
	STM32F4_EXTI_LINE_10 = 0x0A,
	STM32F4_EXTI_LINE_11 = 0x0B,
	STM32F4_EXTI_LINE_12 = 0x0C,
	STM32F4_EXTI_LINE_13 = 0x0D,
	STM32F4_EXTI_LINE_14 = 0x0E,
	STM32F4_EXTI_LINE_15 = 0x0F,
	STM32F4_EXTI_LINE_PVD = 0x10,
	STM32F4_EXTI_LINE_RTC_ALRM = 0x11,
	STM32F4_EXTI_LINE_OTG_FS = 0x12,
	STM32F4_EXTI_LINE_19 = 0x13,
	STM32F4_EXTI_LINE_OTG_HS = 0x14,
	STM32F4_EXTI_LINE_RTC_TMPR = 0x15,
	STM32F4_EXTI_LINE_RTC_WKUP = 0x16,
} stm32f4_exti_line_t;

typedef enum    stm32f4_exti_mode_s
{
	STM32F4_EXTI_MODE_DISABLE = 0x0,
	STM32F4_EXTI_MODE_POSEDGE = 0x1,
	STM32F4_EXTI_MODE_NEGEDGE = 0x2,
	STM32F4_EXTI_MODE_ANYEDGE = 0x3,
} stm32f4_exti_mode_t;

typedef enum    stm32f4_exti_src_s
{
	STM32F4_EXTI_SRC_GPIOA = 0x0,
	STM32F4_EXTI_SRC_GPIOB = 0x1,
	STM32F4_EXTI_SRC_GPIOC = 0x2,
	STM32F4_EXTI_SRC_GPIOD = 0x3,
	STM32F4_EXTI_SRC_GPIOE = 0x4,
	STM32F4_EXTI_SRC_GPIOF = 0x5,
	STM32F4_EXTI_SRC_GPIOG = 0x6,
	STM32F4_EXTI_SRC_GPIOH = 0x7,
} stm32f4_exti_src_t;

static
void stm32f4_exti_cfg_int(              stm32f4_exti_line_t             line,
                                        bool                            b )
{
    uint32_t        mask        =   (uint32_t)1 << line;
    uint32_t        val         =   b ? 1 : 0;

    EXTI->IMR           =   (EXTI->IMR & ~mask) | (val << line);
}

static
void stm32f4_exti_cfg_evt(              stm32f4_exti_line_t             line,
                                        bool                            b )
{
    uint32_t        mask        =   (uint32_t)1 << line;
    uint32_t        val         =   b ? 1 : 0;

    EXTI->EMR           =   (EXTI->EMR & ~mask) | (val << line);
}

static
void stm32f4_exti_line_cfg(             stm32f4_exti_line_t             line,
                                        stm32f4_exti_mode_t             mode,
                                        stm32f4_exti_src_t              src )
{
    uint32_t        r           =   (uint32_t) 1 & (mode >> 0);
    uint32_t        f           =   (uint32_t) 1 & (mode >> 1);
    uint32_t        idx         =   (line >> 2) & 0x3;
    uint32_t        pos         =   (line & 0x3) * 4;
    uint32_t        msk         =   (uint32_t)0xF << pos;

    EXTI->RTSR          =   ( EXTI->RTSR & ~((uint32_t) 1 << line) ) | ( r << line );
    EXTI->FTSR          =   ( EXTI->FTSR & ~((uint32_t) 1 << line) ) | ( f << line );
    SYSCFG->EXTICR[idx] =   ( SYSCFG->EXTICR[ idx ] & ~msk ) | ( src << pos );
}

static
bool stm32f4_exti_line_get(             stm32f4_exti_line_t             line )
{
	return( EXTI->PR & ((uint32_t) 1 << line) ? true : false );
}

static
void stm32f4_exti_line_ack(             stm32f4_exti_line_t             line )
{
    EXTI->PR            =   ( (uint32_t) 1 << line );
}

#endif  // STM32F4_EXTI_H
