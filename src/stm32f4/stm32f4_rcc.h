/**
  * @file    stm32f4_rcc.c
  * @brief   STM32F4 RCC
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef  STM32F4_RCC_H
#define  STM32F4_RCC_H


#include <stdbool.h>
#include <stdint.h>
#include "stm32f4xx.h"


#if !defined(STM32F446xx) && !defined(STM32F407xx)
# warning    the code below may to work correct, but was not checked
#endif


typedef enum    stm32f4_rcc_
{
	STM32F4_RCC_							=   0x0,
} stm32f4_rcc_t;

static
void stm32f4_rcc_(              GPIO_TypeDef *                  gpio,
                                const   stm32f4_gpio_pin_t              pin,
                                const   bool                            set )
{
        gpio->BSRR      =   set ? (1 << pin) : (1 << (pin + 16));
}

#endif  // STM32F4_RCC_H
