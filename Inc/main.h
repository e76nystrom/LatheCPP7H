/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PinA2_Pin GPIO_PIN_2
#define PinA2_GPIO_Port GPIOE
#define PinA16_Pin GPIO_PIN_3
#define PinA16_GPIO_Port GPIOE
#define PinA17_Pin GPIO_PIN_4
#define PinA17_GPIO_Port GPIOE
#define PinA14_Pin GPIO_PIN_5
#define PinA14_GPIO_Port GPIOE
#define DbgA11_Pin GPIO_PIN_6
#define DbgA11_GPIO_Port GPIOE
#define PinA13_Pin GPIO_PIN_13
#define PinA13_GPIO_Port GPIOC
#define DbgA8_Pin GPIO_PIN_0
#define DbgA8_GPIO_Port GPIOF
#define DbgA7_Pin GPIO_PIN_1
#define DbgA7_GPIO_Port GPIOF
#define DbgA0_Pin GPIO_PIN_2
#define DbgA0_GPIO_Port GPIOF
#define ZFlag_Pin GPIO_PIN_3
#define ZFlag_GPIO_Port GPIOF
#define XFlag_Pin GPIO_PIN_4
#define XFlag_GPIO_Port GPIOF
#define Dir3_Pin GPIO_PIN_5
#define Dir3_GPIO_Port GPIOF
#define Uart7Rx_Pin GPIO_PIN_6
#define Uart7Rx_GPIO_Port GPIOF
#define Uart7Tx_Pin GPIO_PIN_7
#define Uart7Tx_GPIO_Port GPIOF
#define DbgA1_Pin GPIO_PIN_8
#define DbgA1_GPIO_Port GPIOF
#define DbgA2_Pin GPIO_PIN_9
#define DbgA2_GPIO_Port GPIOF
#define Pin15_Pin GPIO_PIN_10
#define Pin15_GPIO_Port GPIOF
#define PinA15_Pin GPIO_PIN_0
#define PinA15_GPIO_Port GPIOC
#define PinA10_Pin GPIO_PIN_2
#define PinA10_GPIO_Port GPIOC
#define PinA9_Pin GPIO_PIN_3
#define PinA9_GPIO_Port GPIOC
#define PinA12_Pin GPIO_PIN_0
#define PinA12_GPIO_Port GPIOA
#define Step2a_Pin GPIO_PIN_3
#define Step2a_GPIO_Port GPIOA
#define PinA11_Pin GPIO_PIN_4
#define PinA11_GPIO_Port GPIOA
#define Pin17_Pin GPIO_PIN_5
#define Pin17_GPIO_Port GPIOA
#define Pin1_Pin GPIO_PIN_6
#define Pin1_GPIO_Port GPIOA
#define Led1_Pin GPIO_PIN_0
#define Led1_GPIO_Port GPIOB
#define ExtInt_Pin GPIO_PIN_1
#define ExtInt_GPIO_Port GPIOB
#define ExtInt_EXTI_IRQn EXTI1_IRQn
#define Exti2_Pin GPIO_PIN_2
#define Exti2_GPIO_Port GPIOB
#define Dbg2_Pin GPIO_PIN_11
#define Dbg2_GPIO_Port GPIOF
#define ZA_Pin GPIO_PIN_12
#define ZA_GPIO_Port GPIOF
#define ZA_EXTI_IRQn EXTI15_10_IRQn
#define ZB_Pin GPIO_PIN_13
#define ZB_GPIO_Port GPIOF
#define ZB_EXTI_IRQn EXTI15_10_IRQn
#define XA_Pin GPIO_PIN_14
#define XA_GPIO_Port GPIOF
#define XA_EXTI_IRQn EXTI15_10_IRQn
#define XB_Pin GPIO_PIN_15
#define XB_GPIO_Port GPIOF
#define XB_EXTI_IRQn EXTI15_10_IRQn
#define DbgA4_Pin GPIO_PIN_0
#define DbgA4_GPIO_Port GPIOG
#define DbgA3_Pin GPIO_PIN_1
#define DbgA3_GPIO_Port GPIOG
#define Dir4_Pin GPIO_PIN_9
#define Dir4_GPIO_Port GPIOE
#define Pin12_Pin GPIO_PIN_10
#define Pin12_GPIO_Port GPIOE
#define SPI_SEL_Pin GPIO_PIN_11
#define SPI_SEL_GPIO_Port GPIOE
#define SPI_SCK_Pin GPIO_PIN_12
#define SPI_SCK_GPIO_Port GPIOE
#define SPI_MISO_Pin GPIO_PIN_13
#define SPI_MISO_GPIO_Port GPIOE
#define SPI_MOSI_Pin GPIO_PIN_14
#define SPI_MOSI_GPIO_Port GPIOE
#define Dbg3_Pin GPIO_PIN_15
#define Dbg3_GPIO_Port GPIOE
#define Step1_Pin GPIO_PIN_10
#define Step1_GPIO_Port GPIOB
#define Dir1_Pin GPIO_PIN_12
#define Dir1_GPIO_Port GPIOB
#define Led3_Pin GPIO_PIN_14
#define Led3_GPIO_Port GPIOB
#define Pin16_Pin GPIO_PIN_15
#define Pin16_GPIO_Port GPIOB
#define Dbg1_Pin GPIO_PIN_10
#define Dbg1_GPIO_Port GPIOD
#define Pin10_Pin GPIO_PIN_11
#define Pin10_GPIO_Port GPIOD
#define I2C_SCL_Pin GPIO_PIN_12
#define I2C_SCL_GPIO_Port GPIOD
#define I2C_SDA_Pin GPIO_PIN_13
#define I2C_SDA_GPIO_Port GPIOD
#define Pin11_Pin GPIO_PIN_14
#define Pin11_GPIO_Port GPIOD
#define Pin13_Pin GPIO_PIN_15
#define Pin13_GPIO_Port GPIOD
#define PinA6_Pin GPIO_PIN_2
#define PinA6_GPIO_Port GPIOG
#define PinA4_Pin GPIO_PIN_3
#define PinA4_GPIO_Port GPIOG
#define Dbg0_Pin GPIO_PIN_4
#define Dbg0_GPIO_Port GPIOG
#define JogA1_Pin GPIO_PIN_5
#define JogA1_GPIO_Port GPIOG
#define JogA1_EXTI_IRQn EXTI9_5_IRQn
#define JogB1_Pin GPIO_PIN_6
#define JogB1_GPIO_Port GPIOG
#define JogB1_EXTI_IRQn EXTI9_5_IRQn
#define JogA2_Pin GPIO_PIN_7
#define JogA2_GPIO_Port GPIOG
#define JogA2_EXTI_IRQn EXTI9_5_IRQn
#define JogB2_Pin GPIO_PIN_8
#define JogB2_GPIO_Port GPIOG
#define JogB2_EXTI_IRQn EXTI9_5_IRQn
#define Step5_Pin GPIO_PIN_6
#define Step5_GPIO_Port GPIOC
#define Step3_Pin GPIO_PIN_7
#define Step3_GPIO_Port GPIOC
#define Pin14_Pin GPIO_PIN_8
#define Pin14_GPIO_Port GPIOC
#define Dir5_Pin GPIO_PIN_9
#define Dir5_GPIO_Port GPIOC
#define Step2b_Pin GPIO_PIN_8
#define Step2b_GPIO_Port GPIOA
#define Dbg4_Pin GPIO_PIN_9
#define Dbg4_GPIO_Port GPIOA
#define Usart3Tx_Pin GPIO_PIN_10
#define Usart3Tx_GPIO_Port GPIOC
#define Usart3Rx_Pin GPIO_PIN_11
#define Usart3Rx_GPIO_Port GPIOC
#define DbgA10_Pin GPIO_PIN_0
#define DbgA10_GPIO_Port GPIOD
#define DbgA9_Pin GPIO_PIN_1
#define DbgA9_GPIO_Port GPIOD
#define PinA8_Pin GPIO_PIN_3
#define PinA8_GPIO_Port GPIOD
#define PinA7_Pin GPIO_PIN_4
#define PinA7_GPIO_Port GPIOD
#define PinA5_Pin GPIO_PIN_5
#define PinA5_GPIO_Port GPIOD
#define PinA3_Pin GPIO_PIN_6
#define PinA3_GPIO_Port GPIOD
#define PinA1_Pin GPIO_PIN_7
#define PinA1_GPIO_Port GPIOD
#define DbgA12_Pin GPIO_PIN_9
#define DbgA12_GPIO_Port GPIOG
#define DbgA6_Pin GPIO_PIN_10
#define DbgA6_GPIO_Port GPIOG
#define DbgA13_Pin GPIO_PIN_12
#define DbgA13_GPIO_Port GPIOG
#define DbgA5_Pin GPIO_PIN_15
#define DbgA5_GPIO_Port GPIOG
#define Dir2_Pin GPIO_PIN_5
#define Dir2_GPIO_Port GPIOB
#define Dbg5_Pin GPIO_PIN_6
#define Dbg5_GPIO_Port GPIOB
#define Step4_Pin GPIO_PIN_8
#define Step4_GPIO_Port GPIOB
#define Encoder_Pin GPIO_PIN_9
#define Encoder_GPIO_Port GPIOB
#define Index_Pin GPIO_PIN_0
#define Index_GPIO_Port GPIOE
#define Index_EXTI_IRQn EXTI0_IRQn
#define Led2_Pin GPIO_PIN_1
#define Led2_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
