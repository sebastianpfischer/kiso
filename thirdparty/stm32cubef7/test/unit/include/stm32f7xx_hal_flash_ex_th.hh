/*----------------------------------------------------------------------------*/
/*
 * Copyright (C) Bosch Connected Devices and Solutions GmbH.
 * All Rights Reserved. Confidential.
 *
 * Distribution only to people who need to know this information in
 * order to do their job.(Need-to-know principle).
 * Distribution to persons outside the company, only if these persons
 * signed a non-disclosure agreement.
 * Electronic transmission, e.g. via electronic mail, must be made in
 * encrypted form.
 *
 * @file
 *
 * Mock-up implementation for the stm32f7xx_hal_flash_ex module.
 */
/*----------------------------------------------------------------------------*/
 
#ifndef STM32F7XX_HAL_FLASH_EX_TH_HH
#define STM32F7XX_HAL_FLASH_EX_TH_HH

/* Include the needed headers */
#include "gtest.h"
#include "stm32f7xx_hal_flash_th.hh"

/* Include or ban the real interface header */
#include "stm32f7xx_hal_flash_ex.h"

/* Faked variables needs to be initialized by the test fixture */

/* Mock-ups for the provided interfaces */

FAKE_VALUE_FUNC(HAL_StatusTypeDef, HAL_FLASHEx_Erase, FLASH_EraseInitTypeDef*, uint32_t*);

FAKE_VALUE_FUNC(HAL_StatusTypeDef, HAL_FLASHEx_Erase_IT, FLASH_EraseInitTypeDef*);

FAKE_VALUE_FUNC(HAL_StatusTypeDef, HAL_FLASHEx_OBProgram, FLASH_OBProgramInitTypeDef*);

FAKE_VOID_FUNC(HAL_FLASHEx_OBGetConfig, FLASH_OBProgramInitTypeDef*);

FAKE_VOID_FUNC(FLASH_Erase_Sector, uint32_t, uint8_t);

# endif /* STM32F7XX_HAL_FLASH_EX_TH_HH */