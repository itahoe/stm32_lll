/**
  * @file    stm32f4_gpio.c
  * @brief   STM32F4 GPIO
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef  STM32F4_GPIO_H
#define  STM32F4_GPIO_H


#include <stdbool.h>
#include <stdint.h>
#include "stm32f4xx.h"


#if !defined(STM32F446xx) && !defined(STM32F407xx)
# warning    the code below may to work correct, but was not checked
#endif


typedef enum    stm32f4_gpio_pin_s
{
	STM32F4_GPIO_PIN_00                     =   0x0,
	STM32F4_GPIO_PIN_01                     =   0x1,
	STM32F4_GPIO_PIN_02                     =   0x2,
	STM32F4_GPIO_PIN_03                     =   0x3,
	STM32F4_GPIO_PIN_04                     =   0x4,
	STM32F4_GPIO_PIN_05                     =   0x5,
	STM32F4_GPIO_PIN_06                     =   0x6,
	STM32F4_GPIO_PIN_07                     =   0x7,
	STM32F4_GPIO_PIN_08                     =   0x8,
	STM32F4_GPIO_PIN_09                     =   0x9,
	STM32F4_GPIO_PIN_10                     =   0xA,
	STM32F4_GPIO_PIN_11                     =   0xB,
	STM32F4_GPIO_PIN_12                     =   0xC,
	STM32F4_GPIO_PIN_13                     =   0xD,
	STM32F4_GPIO_PIN_14                     =   0xE,
	STM32F4_GPIO_PIN_15                     =   0xF,
} stm32f4_gpio_pin_t;

typedef enum    stm32f4_gpio_cfg_s
{
	STM32F4_GPIO_CFG_INP_ANALOG             =   0x3000,
	STM32F4_GPIO_CFG_ALT_OD_SPEED_HIGH      =   0x2130,
	STM32F4_GPIO_CFG_ALT_OD_SPEED_FAST      =   0x2120,
	STM32F4_GPIO_CFG_ALT_OD_SPEED_MEDIUM    =   0x2110,
	STM32F4_GPIO_CFG_ALT_OD_SPEED_LOW       =   0x2100,
	STM32F4_GPIO_CFG_ALT_PP_SPEED_HIGH      =   0x2030,
	STM32F4_GPIO_CFG_ALT_PP_SPEED_FAST      =   0x2020,
	STM32F4_GPIO_CFG_ALT_PP_SPEED_MEDIUM    =   0x2010,
	STM32F4_GPIO_CFG_ALT_PP_SPEED_LOW       =   0x2000,
	STM32F4_GPIO_CFG_ALT_PULLDN             =   0x2002,
	STM32F4_GPIO_CFG_ALT_PULLUP             =   0x2001,
	STM32F4_GPIO_CFG_ALT_FLOAT              =   0x2000,
	STM32F4_GPIO_CFG_OUT_OD_SPEED_HIGH      =   0x1130,
	STM32F4_GPIO_CFG_OUT_OD_SPEED_FAST      =   0x1120,
	STM32F4_GPIO_CFG_OUT_OD_SPEED_MEDIUM    =   0x1110,
	STM32F4_GPIO_CFG_OUT_OD_SPEED_LOW       =   0x1100,
	STM32F4_GPIO_CFG_OUT_PP_SPEED_HIGH      =   0x1030,
	STM32F4_GPIO_CFG_OUT_PP_SPEED_FAST      =   0x1020,
	STM32F4_GPIO_CFG_OUT_PP_SPEED_MEDIUM    =   0x1010,
	STM32F4_GPIO_CFG_OUT_PP_SPEED_LOW       =   0x1000,
	STM32F4_GPIO_CFG_INP_PULLDN             =   0x0002,
	STM32F4_GPIO_CFG_INP_PULLUP             =   0x0001,
	STM32F4_GPIO_CFG_INP_FLOAT              =   0x0000,
} stm32f4_gpio_cfg_t;

typedef enum    stm32f4_gpio_af_s
{
	STM32F4_GPIO_AF_DONTCARE                =   0x0,
	STM32F4_GPIO_AF0_RTC_50Hz               =   0x0,
	STM32F4_GPIO_AF0_MCO                    =   0x0,
	STM32F4_GPIO_AF0_TAMPER                 =   0x0,
	STM32F4_GPIO_AF0_SWJ                    =   0x0,
	STM32F4_GPIO_AF0_TRACE                  =   0x0,
	STM32F4_GPIO_AF1_TIM1                   =   0x1,
	STM32F4_GPIO_AF1_TIM2                   =   0x1,
	STM32F4_GPIO_AF2_TIM3                   =   0x2,
	STM32F4_GPIO_AF2_TIM4                   =   0x2,
	STM32F4_GPIO_AF2_TIM5                   =   0x2,
	STM32F4_GPIO_AF3_TIM8                   =   0x3,
	STM32F4_GPIO_AF3_TIM9                   =   0x3,
	STM32F4_GPIO_AF3_TIM10                  =   0x3,
	STM32F4_GPIO_AF3_TIM11                  =   0x3,
	STM32F4_GPIO_AF3_CEC                    =   0x3,
	STM32F4_GPIO_AF4_I2C1                   =   0x4,
	STM32F4_GPIO_AF4_I2C2                   =   0x4,
	STM32F4_GPIO_AF4_I2C3                   =   0x4,
	STM32F4_GPIO_AF4_FMPI2C1                =   0x4,
	STM32F4_GPIO_AF4_CEC                    =   0x4,
	STM32F4_GPIO_AF5_SPI1                   =   0x5,
	STM32F4_GPIO_AF5_SPI2                   =   0x5,
	STM32F4_GPIO_AF5_SPI3                   =   0x5,
	STM32F4_GPIO_AF5_SPI4                   =   0x5,
	STM32F4_GPIO_AF6_SPI2                   =   0x6,
	STM32F4_GPIO_AF6_SPI3                   =   0x6,
	STM32F4_GPIO_AF6_SPI4                   =   0x6,
	STM32F4_GPIO_AF6_SAI1                   =   0x6,
	STM32F4_GPIO_AF7_USART1                 =   0x7,
	STM32F4_GPIO_AF7_USART2                 =   0x7,
	STM32F4_GPIO_AF7_USART3                 =   0x7,
	STM32F4_GPIO_AF7_UART5                  =   0x7,
	STM32F4_GPIO_AF7_SPI2                   =   0x7,
	STM32F4_GPIO_AF7_SPI3                   =   0x7,
	STM32F4_GPIO_AF7_SPDIFRX                =   0x7,
	STM32F4_GPIO_AF8_UART4                  =   0x8,
	STM32F4_GPIO_AF8_UART5                  =   0x8,
	STM32F4_GPIO_AF8_USART6                 =   0x8,
	STM32F4_GPIO_AF8_SPDIFRX                =   0x8,
	STM32F4_GPIO_AF8_SAI2                   =   0x8,
	STM32F4_GPIO_AF9_CAN1                   =   0x9,
	STM32F4_GPIO_AF9_CAN2                   =   0x9,
	STM32F4_GPIO_AF9_TIM12                  =   0x9,
	STM32F4_GPIO_AF9_TIM13                  =   0x9,
	STM32F4_GPIO_AF9_TIM14                  =   0x9,
	STM32F4_GPIO_AF9_QSPI                   =   0x9,
	STM32F4_GPIO_AF10_OTG_FS                =   0xA,
	STM32F4_GPIO_AF10_OTG_HS                =   0xA,
	STM32F4_GPIO_AF10_SAI2                  =   0xA,
	STM32F4_GPIO_AF10_QSPI                  =   0xA,
	STM32F4_GPIO_AF11_ETH                   =   0xB,
	STM32F4_GPIO_AF12_FMC                   =   0xC,
	STM32F4_GPIO_AF12_OTG_HS_FS             =   0xC,
	STM32F4_GPIO_AF12_SDIO                  =   0xC,
	STM32F4_GPIO_AF13_DCMI                  =   0xD,
	STM32F4_GPIO_AF15_EVENTOUT              =   0xF,
} stm32f4_gpio_af_t;

static
void stm32f4_gpio_pin_cfg(              GPIO_TypeDef *                  gpio,
                                const   stm32f4_gpio_pin_t              pin,
                                const   stm32f4_gpio_cfg_t              cfg,
                                const   stm32f4_gpio_af_t               af )
{
        const   uint32_t    mode        =   (cfg >> 12) & 0x3;
        const   uint32_t    type        =   (cfg >>  8) & 0x1;
        const   uint32_t    speed       =   (cfg >>  4) & 0x3;
        const   uint32_t    pull        =   (cfg >>  0) & 0x3;
        const   uint32_t    mode_af     =   0x2;


        gpio->MODER     =   (gpio->MODER    & ~(0x3 << pin * 2)) | (mode << pin * 2);
        gpio->OTYPER    =   (gpio->OTYPER   & ~(0x1 << pin * 1)) | (type << pin * 1);
        gpio->OSPEEDR   =   (gpio->OSPEEDR  & ~(0x3 << pin * 2)) | (speed << pin * 2);
        gpio->PUPDR     =   (gpio->PUPDR    & ~(0x3 << pin * 2)) | (pull << pin * 2);

        if( mode == mode_af )
        {
                if( pin < 8 )
                {
                        gpio->AFR[0]    =   (gpio->AFR[0] & ~(0xF << (pin * 4) * 1)) | (af << pin * 4);
                }
                else
                {
                        gpio->AFR[1]    =   (gpio->AFR[1] & ~(0xF << (pin - 8) * 4)) | (af << (pin - 8) * 4);
                }
        }
}

/*
static
void stm32f4_gpio_af_cfg(               GPIO_TypeDef *                  gpio,
                                const   stm32f4_gpio_pin_t              pin,
                                const   stm32f4_gpio_af_t               af )
{
        if( pin < 8 )
        {
                gpio->AFR[0]    =   (gpio->AFR[0] & ~(0xF << (pin * 4) * 1)) | (af << pin * 4);
        }
        else
        {
                gpio->AFR[1]    =   (gpio->AFR[1] & ~(0xF << (pin - 8) * 4)) | (af << (pin - 8) * 4);
        }
}
*/

static
bool stm32f4_gpio_pin_get(              GPIO_TypeDef *                  gpio,
                                const   stm32f4_gpio_pin_t              pin )
{
        return( gpio->IDR & (1 << pin) );
}

static
bool stm32f4_gpio_out_get(              GPIO_TypeDef *                  gpio,
                                const   stm32f4_gpio_pin_t              pin )
{
        return( gpio->ODR & (1 << pin) );
}

static
void stm32f4_gpio_pin_set(              GPIO_TypeDef *                  gpio,
                                const   stm32f4_gpio_pin_t              pin,
                                const   bool                            set )
{
        gpio->BSRR      =   set ? (1 << pin) : (1 << (pin + 16));
}

#endif  // STM32F4_GPIO_H
