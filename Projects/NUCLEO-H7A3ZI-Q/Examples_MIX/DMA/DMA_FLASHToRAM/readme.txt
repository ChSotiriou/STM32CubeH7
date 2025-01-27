/**
  @page DMA_FLASHToRAM DMA example

  @verbatim
  ******************************************************************************
  * @file    Examples_MIX/DMA/DMA_FLASHToRAM/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the DMA example.
  ******************************************************************************
  *
  * Copyright (c) 2019 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  @endverbatim

@par Example Description

How to use a DMA to transfer a word data buffer from Flash memory to embedded
SRAM through the STM32H7xx DMA HAL and LL API. The LL API is used for 
performance improvement.

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system
clock (SYSCLK) to run at 280 MHz.

DMA1_Stream1 is configured to transfer the contents of a 32-word data
buffer stored in Flash memory to the reception buffer declared in RAM.

The start of transfer is triggered by LL API. DMA1_Stream1 memory-to-memory
transfer is enabled. Source and destination addresses incrementing is also enabled.
The transfer is started by setting the Stream enable bit for DMA1_Stream1.
At the end of the transfer a Transfer Complete interrupt is generated since it
is enabled and the callback function (customized by user) is called.

Board's LEDs can be used to monitor the transfer status:
 - LED1 is ON when the transfer is complete (into the Transfer Complete interrupt
   routine).
 - LED2 is ON when there is a transfer error
 - LED3 is ON when a Error_Handler is called

It is possible to select a different Stream for the DMA transfer
example by modifying defines values in the file main.h.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@Note If the  application is using the DTCM/ITCM memories (@0x20000000/ 0x0000000: not cacheable and only accessible
      by the Cortex M7 and the  MDMA), no need for cache maintenance when the Cortex M7 and the MDMA access these RAMs.
      If the application needs to use DMA (or other masters) based access or requires more RAM, then the user has to:
              - Use a non TCM SRAM. (example : CD AXI-SRAM @ 0x24000000)
              - Add a cache maintenance mechanism to ensure the cache coherence between CPU and other masters(DMAs,DMA2D,LTDC,MDMA).
              - The addresses and the size of cacheable buffers (shared between CPU and other masters)
                must be	properly defined to be aligned to L1-CACHE line size (32 bytes). 
 
@Note It is recommended to enable the cache and maintain its coherence.
      Depending on the use case, it is also possible to configure the cache attributes using the MPU.
      Please refer to the AN4838 “Managing memory protection unit (MPU) in STM32 MCUs”
      Please refer to the AN4839 “Level 1 cache on STM32F7 Series and STM32H7 Series

@par Keywords

System, DMA, Data Transfer, Memory to memory, Stream, Flash, RAM

@par Directory contents

  - DMA/DMA_FLASHToRAM/Src/system_stm32h7xx.c      STM32H7xx system clock configuration file
  - DMA/DMA_FLASHToRAM/Src/stm32h7xx_it.c          Interrupt handlers
  - DMA/DMA_FLASHToRAM/Src/main.c                  Main program
  - DMA/DMA_FLASHToRAM/Inc/stm32h7xx_hal_conf.h    HAL Configuration file
  - DMA/DMA_FLASHToRAM/Inc/stm32h7xx_it.h          Interrupt handlers header file
  - DMA/DMA_FLASHToRAM/Inc/main.h                  Main program header file
  - DMA/DMA_FLASHToRAM/Inc/stm32h7xx_nucleo_conf.h    HAL configuration file  

@par Hardware and Software environment

  - This example runs on STM32H7A3xxQ Devices.

  - This example has been tested with STMicroelectronics Nucleo-H7A3ZI-Q
    board and can be easily tailored to any other supported device
    and development board.

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
