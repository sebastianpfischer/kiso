/********************************************************************************
* Copyright (c) 2010-2019 Robert Bosch GmbH
*
* This program and the accompanying materials are made available under the
* terms of the Eclipse Public License 2.0 which is available at
* http://www.eclipse.org/legal/epl-2.0.
*
* SPDX-License-Identifier: EPL-2.0
*
* Contributors:
*    Robert Bosch GmbH - initial contribution
*
********************************************************************************/

#ifndef TEST_UNIT_INCLUDE_KISO_PIPEANDFILTER_TH_HH_
#define TEST_UNIT_INCLUDE_KISO_PIPEANDFILTER_TH_HH_

#include "gtest.h"

/* header definition ******************************************************** */
#include "Kiso_Retcode.h"

/* wrap the real interface header */
#include "Kiso_PipeAndFilter.h"

/**
 * mock-ups for the provided interfaces
 * Deprecated functions will be removed as part of PFM-659
 * Deprecated since vXXX (\todo: replace XXX with next version)
 */
FAKE_VALUE_FUNC(Retcode_T, PipeAndFilter_CreatePipe, PipeAndFilter_Pipe_T *)
FAKE_VALUE_FUNC(Retcode_T, PipeAndFilter_CreateFilter, PipeAndFilter_FilterFunction_T, PipeAndFilter_Pipe_T *, PipeAndFilter_Pipe_T *, PipeAndFilter_Filter_T *)
FAKE_VALUE_FUNC(Retcode_T, PipeAndFilter_FillPipe, PipeAndFilter_Pipe_T, uint8_t *, uint32_t)
FAKE_VALUE_FUNC(Retcode_T, PipeAndFilter_FillPipeFromISR, PipeAndFilter_Pipe_T, uint8_t *, uint32_t)

#endif /* TEST_UNIT_INCLUDE_KISO_PIPEANDFILTER_TH_HH_ */


