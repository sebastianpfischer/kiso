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

/**
 * @ingroup UTILS
 *
 * @defgroup RINGBUFFER Ring Buffer
 * @{
 *
 * @brief
 *      Ring Buffer Interface
 *
 * @details
 *      This module represents optimized for speed circular buffer implementation,
 *      intended to be used as transport for data between ISR and user code.
 *      Read and Write functions may handle data only partially, depending of fill-level
 *      of the buffer, so corresponding calls may need to be retried.
 *
 * @note
 *      For optimization purposes, error handling is minimized and responsibility
 *      for parameter correctness is transfered to user code. Also some code constructions
 *      may not follow expected patterns.
 *
 * @file
 **/

#ifndef KISO_RINGBUFFER_H
#define KISO_RINGBUFFER_H

#include "Kiso_Utils.h"

#if KISO_FEATURE_RINGBUFFER

#include "Kiso_Basics.h"

/**
 *  @brief
 *      Describes a circular buffer - this implementation expects a single consumer and a single producer.
 *
 *  @details
 *      Reading and writing to the buffer can be done independently.
 *      The read function only returns data unless the buffer is empty
 *      The write function only writes data when the buffer is not full.
 *
 *      Definition:
 *      - WriteIndex: the location where data is stored to
 *      - ReadIndex:  the location from where to read from
 *  
 */
typedef struct RingBuffer_S
{
    uint8_t *Base;       /**< Pointer to the base of the user-supplied buffer */
    uint32_t WriteIndex; /**< Write index. NOT to be changed by hand */
    uint32_t ReadIndex;  /**< Read index. NOT to be changed by hand */
    uint32_t Size;       /**< Maximum number of bytes in the user-supplied buffer. Must be set during initialization */
} RingBuffer_T;

/**
 *  @brief
 *      Initializes a ring-buffer to empty state with a given buffer and buffer size
 *
 *  @param [ in ] ringBuffer
 *      Pointer to the ring-buffer descriptor.
 *      MUST NOT be NULL
 *
 *  @param [ in ] bufferSpace
 *      Pointer to the circular buffer. This buffer must be created and maintained by the
 *      caller. The reason the buffer is separate from the descriptor is to allow for
 *      buffers of different sizes while using the same descriptor to manage any buffer
 *      MUST NOT be NULL
 *
 *  @param [ in ] size
 *      Size of the circular buffer. Must be known to the caller and will get stored
 *      inside the descriptor.
 *      MUST BE > 1
 *      NOTE: the actual number of bytes that can be stored is size -1
 * 
 */
void RingBuffer_Initialize(RingBuffer_T *ringBuffer, uint8_t *bufferSpace, uint32_t size);

/**
 *  @brief
 *      Copies specified number of bytes into the circular buffer
 *
 *  @note The actual number of bytes written may be different depending on the fill-level of the buffer.
 *
 *  @note
 *      It is the responsibility of the interface user to provide valid input parameters.
 *      Since this API is often used in ISR context, we minimize the internal validations.
 *
 *  @param [ in ] ringBuffer
 *      Pointer to the ring-buffer descriptor
 *
 *      MUST NOT be NULL
 *
 *  @param [ in ] data
 *      Pointer to the user data that is to be copied into the circular buffer
 *      MUST NOT be NULL
 *
 *  @param [ in ] length
 *      Number of bytes to copy
 *
 *  @return
 *      actual number of bytes written
 * 
 */
uint32_t RingBuffer_Write(RingBuffer_T *ringBuffer, uint8_t *data, uint32_t length);

/**
 *  @brief
 *      Removes the specified number of bytes from the circular buffer and stores
 *      them in the user supplied buffer.
 *
 *  @note The number of bytes may be different depending on the actual fill-level of the buffer.
 *
 *  @param [ in ] ringBuffer
 *      Pointer to the ring-buffer descriptor
 *      MUST NOT be NULL
 *
 *  @param [ out ] data
 *      Pointer to the user supplied buffer into which the data has to be copied.
 *      Must be large enough to hold the specific number of bytes
 *      MUST NOT be NULL
 *
 *  @param [ in ] length
 *      The number of bytes to copy
 *
 *  @return
 *      Actual number of bytes read
 *
 */
uint32_t RingBuffer_Read(RingBuffer_T *ringBuffer, uint8_t *data, uint32_t length);

/**
 *  @brief
 *      Resets the ring-buffer. All the saved / available data
 *      will be lost, if any at the time of trigger.
 *
 *  @note
 *      We do not guard the buffer. Application is expected to take
 *      care of this if needed.
 *
 *
 *  @param [ in ] ringBuffer
 *      Pointer to the ring-buffer descriptor
 *      MUST NOT be NULL
 *
 */
void RingBuffer_Reset(RingBuffer_T *ringBuffer);

#endif /* if KISO_FEATURE_RINGBUFFER */

#endif /* KISO_RINGBUFFER_H */
/**@} */
