/**
  ******************************************************************************
  * @file    FPU/FPU_Fractal/CM7/Inc/main.h
  * @author  MCD Application Team
  * @brief   Header for main.c module for Cortex-M7.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h747i_eval.h"
#include "stm32h747i_eval_io.h"
#include "stm32h747i_eval_lcd.h"
#include "stm32h747i_eval_ts.h"

#include "stm32_lcd.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>

/* Set this define to 1 to OverClocking the system clock to 480MHz*/
#define USE_VOS0_480MHZ_OVERCLOCK 0

/* 
   !!!Attention!!! 

   Overclocking the system clock to 480MHz is only available with LDO PWR configuration
    by default The STM32H747I-EVAL comes with DIRECT_SMPS configuration
    in order Overclock the system clock to 480MHz to the eval board must modified 
    to change the PWR path to LDO instead of DIRECT_SMPS

   to do so please change the following solder bridges :
   - LDO config : 
        Mount   : SB13, SB23, SB18
        Removed : SB14, SB16, SB20, SB10, SB17, SB53 and L1

   - Direct SMPS config : 
        Mount   : SB14, SB20, SB10, SB53 and L1 
        Removed : SB13, SB17, SB23, SB16, SB18

   Note that the Board HW configuration must match with the FW config 
   if not will face a deadlock (can't connect the board any more)
   the FW PWR configuration correspond in the main.c to the following :
   Function SystemClock_Config :
     - case of LDO config : HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
     - case of Direct SMPS config : HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

   BOARD_HW_CONFIG_IS_LDO and BOARD_HW_CONFIG_IS_DIRECT_SMPS defines are used to confirm the 
   board HW setting :
     - Set BOARD_HW_CONFIG_IS_LDO to 1 and BOARD_HW_CONFIG_IS_DIRECT_SMPS to 0 to confirm that
       the board is configured in LDO

     - Set BOARD_HW_CONFIG_IS_LDO to 0 and BOARD_HW_CONFIG_IS_DIRECT_SMPS to 1 to confirm that
       the board is configured in direct SMPS

   if a dead lock is faced due to a mismatch between the HW board setting and the FW setting (LDO,SMPS)
   user can recover the board by the following :
     - Power off the board
     - Change the SW1 switch position on the STM32H747I-EVAL to position 1 (Sys mem)
     - This will change the boot pin to 1 instead of 0 and thus the device boot address will
        be changed to boot address 1 making the bootloader starting instead of the FW in the flash
       (FW that is setting a wrong LDO/SMPS config versus the HW board config)

     - Power on the board and connect using STM32CubeProgrammer
     - Erase the user FLash
     - Power off the board and set the SW1 switch position back to position 0 (for boot address 0)
     - The board is now recovered and can proceed normally.     
          
*/
#define BOARD_HW_CONFIG_IS_LDO         0  /* Set to 1 : to confirm that board HW config is LDO, 0 if not */
#define BOARD_HW_CONFIG_IS_DIRECT_SMPS 1  /* Set to 1 : to confirm that board HW config is Direct SMPS, 0 if not */

#define ITERATION       ((uint32_t)256)
#define FRACTAL_ZOOM    ((uint16_t)200)
#define  REAL_CONSTANT  (0.285f)
#define  IMG_CONSTANT  (0.01f)

#define ARGB8888_BYTES_PER_PIXEL 4

#define LCD_FRAME_BUFFER  ((uint32_t)0xD0000000)

#define FRACTAL_FRAME_BUFFER  ((uint32_t)0xD0200000)

#define LCD_X_SIZE ((uint32_t) 800)
#define LCD_Y_SIZE ((uint32_t) 480)

#if (__FPU_USED == 1)
#define SCORE_FPU_MODE                "FPU On"
#else
#define SCORE_FPU_MODE                "FPU Off"
#endif  /* __FPU_USED */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
