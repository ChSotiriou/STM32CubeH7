/**
  ******************************************************************************
  * @file    Demonstration/Oscilloscope_SignalsGenerator/Inc/main.h
  * @author  MCD Application Team
  * @brief   Header for sig_gen.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SIG_GEN_H
#define __SIG_GEN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "stm32h735g_discovery.h"
#include "display.h"
#include "graphics.h"
#include "touchscreen.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#define DEMO_OK    0
#define DEMO_ERROR 1

/* ################## TIM Tools Definetions ######################## */   
#define TIM_DAC                            TIM6
#define TIM_DAC_CLK_ENABLE()               __HAL_RCC_TIM6_CLK_ENABLE()
#define TIM_DAC_IRQn                       TIM6_IRQn
#define TIM_DAC_IRQHandler                 TIM6_IRQHandler
#define TIM_DAC_FORCE_RESET()    __HAL_RCC_TIM6_FORCE_RESET()
#define TIM_DAC_RELEASE_RESET()  __HAL_RCC_TIM6_RELEASE_RESET()

/* ################## DAC Tools Definetions ######################## */ 
/* User can use this section to tailor DACx instance used and associated
   resources */
/* Definition for DACx clock resources */
#define DACx                            DAC1
#define DACx_CHANNEL_GPIO_CLK_ENABLE()  __HAL_RCC_GPIOA_CLK_ENABLE()
#define DMAx_CLK_ENABLE()               __HAL_RCC_DMA1_CLK_ENABLE()

#define DACx_CLK_ENABLE()               __HAL_RCC_DAC12_CLK_ENABLE()
#define DACx_FORCE_RESET()              __HAL_RCC_DAC12_FORCE_RESET()
#define DACx_RELEASE_RESET()            __HAL_RCC_DAC12_RELEASE_RESET()

/* Definition for DACx Channel Pin */
#define DACx_CHANNEL_PIN                GPIO_PIN_5
#define DACx_CHANNEL_GPIO_PORT          GPIOA

/* Definition for DACx's Channel */

#define DACx_CHANNEL                    DAC_CHANNEL_2

/* Definition for DACx's DMA_STREAM */
#define DACx_DMA_INSTANCE               DMA1_Stream5

/* Definition for DACx's NVIC */
#define DACx_DMA_IRQn                   DMA1_Stream5_IRQn
#define DACx_DMA_IRQHandler             DMA1_Stream5_IRQHandler

#define DACx_TRIGGER                   DAC_TRIGGER_T6_TRGO
#define DAC_MAX_FREQUENCY 130000
#define DAC_MIN_FREQUENCY 5000
#define DAC_OFFSET_FREQUENCY 5000
     
#define DAC_MAX_AMPLITUDE 3300
#define DAC_MIN_AMPLITUDE 100
#define DAC_OFFSET_AMPLITUDE 100
/* ################## TS Tools Definetions ######################## */ 



#define BACKGROUND_IMAGE_WIDTH  480
#define BACKGROUND_IMAGE_HEIGHT 272
#define BACKGROUND_IMAGE_SIZE ((BACKGROUND_IMAGE_HEIGHT * BACKGROUND_IMAGE_WIDTH * ARGB888_BYTES_PER_PIXEL)/4)
#define BACKGROUND_IMAGE_XPOSITION  0
#define BACKGROUND_IMAGE_YPOSITION  0
#define BACKGROUND_IMAGE_INPUT_OFFSET  0

#define SG_UPDOWN_BUTTON_WIDTH       24
#define SG_UPDOWN_BUTTON_HEIGHT      24
#define SG_TOTAL_UPDOWN_BUTTON_NBR   2
/* Up Down frequency buttons params */
#define SG_FREQ_RECT_XPOSITION     160
#define SG_FREQ_RECT_YPOSITION     68
#define SG_FREQ_RECT_WIDHT         180
#define SG_FREQ_RECT_HEIGHT        50
#define SG_DOWN_FEQUECNY_BUTTON_XPOSITION     (SG_FREQ_RECT_XPOSITION +  2)
#define SG_DOWN_FEQUECNY_BUTTON_YPOSITION     (SG_FREQ_RECT_YPOSITION + SG_FREQ_RECT_HEIGHT/2)     
#define SG_UP_FEQUECNY_BUTTON_XPOSITION       (SG_FREQ_RECT_XPOSITION + SG_FREQ_RECT_WIDHT - SG_UPDOWN_BUTTON_WIDTH)
#define SG_UP_FEQUECNY_BUTTON_YPOSITION       (SG_FREQ_RECT_YPOSITION + SG_FREQ_RECT_HEIGHT/2)
     
/* Up Down amplitude buttons params */
#define SG_AMPL_RECT_XPOSITION     160
#define SG_AMPL_RECT_YPOSITION     140
#define SG_AMPL_RECT_WIDHT         180
#define SG_AMPL_RECT_HEIGHT        50
#define SG_DOWN_AMPLITUDE_BUTTON_XPOSITION     (SG_AMPL_RECT_XPOSITION +  2)
#define SG_DOWN_AMPLITUDE_BUTTON_YPOSITION     (SG_AMPL_RECT_YPOSITION + SG_AMPL_RECT_HEIGHT/2)     
#define SG_UP_AMPLITUDE_BUTTON_XPOSITION       (SG_AMPL_RECT_XPOSITION + SG_AMPL_RECT_WIDHT - SG_UPDOWN_BUTTON_WIDTH)
#define SG_UP_AMPLITUDE_BUTTON_YPOSITION       (SG_AMPL_RECT_YPOSITION + SG_AMPL_RECT_HEIGHT/2)


/* Exported macro ------------------------------------------------------------*/

uint32_t SG_GenerateWave(SG_WaveButtonIndex_e waveButtonIndex, uint32_t waveFrequency, uint16_t outputAmplitude);
uint32_t SG_StopWaveGeneration(void);
#endif /* __SIG_GEN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
