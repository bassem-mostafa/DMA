// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

/**
 *  @file
 *
 *  @brief Platform DMA Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_DMA DMA
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_DMA_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef DMA_H_
    #define DMA_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "DMA_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief DMA Operation Status
     *
     *  @enum DMA_Status_t
     */
    typedef enum DMA_Status
    {
        DMA_Status_Success = 0,     ///< Success
        DMA_Status_ArgumentInvalid, ///< Argument Invalid
        DMA_Status_NotSupported,    ///< Not Supported
        DMA_Status_Error,           ///< General Error
        DMA_Status_Busy,            ///< Busy
        DMA_Status_Timeout,         ///< Timeout
    } DMA_Status_t;

    // TODO Make use of the DMA channel type
    /**
     *  @brief DMA Channel Type
     *
     *  @enum DMA_Channel_t
     */
    typedef enum DMA_Channel
    {
        DMA_Channel_Unknown = 0, ///< Unknown
        DMA_Channel_1,           ///< Channel 1 (Minimum)
        DMA_Channel_2,           ///<
        DMA_Channel_3,           ///<
        DMA_Channel_4,           ///<
        DMA_Channel_5,           ///<
        DMA_Channel_6,           ///<
        DMA_Channel_7,           ///< Channel 7 (Maximum)
    } DMA_Channel_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize DMA peripheral
     *
     *  @note MUST BE called before using any DMA API
     *
     *  @param[in] DMAx Instance
     *
     *  @return DMA_Status_t
     */
    DMA_Status_t DMA_Initialize( DMA_t DMAx );

    /**
     *  @brief Cycle DMA peripheral
     *
     *  @param[in] DMAx Instance
     *
     *  @return DMA_Status_t
     */
    DMA_Status_t DMA_Cycle( DMA_t DMAx );

    /**
     *  @brief DeInitialize DMA peripheral
     *
     *  @param[in] DMAx Instance
     *
     *  @return DMA_Status_t
     */
    DMA_Status_t DMA_DeInitialize( DMA_t DMAx );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char DMA_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* DMA_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
