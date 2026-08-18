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

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef DMA_INTERNAL_H_
    #define DMA_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "DMA.h"
    #include "driver/STM32L496VGT6P/DMA_STM32L496VGT6P.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef DMA_TIM
        #define DMA_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef DMA_LOG
        #define DMA_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define DMA_NAME       "DMA"
    #define DMA_LOG_PREFIX UTIL_StringConcatenateConstant( DMA_NAME, "> " )

    #ifdef DEBUG
        #define DMA_Raw( Level, Format, ... ) LOG_Raw( DMA_LOG, Level, Format, ##__VA_ARGS__ )
        #define DMA_Trace( Format, ... )      LOG_Trace( DMA_LOG, UTIL_StringConcatenateConstant( DMA_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define DMA_Debug( Format, ... )      LOG_Debug( DMA_LOG, UTIL_StringConcatenateConstant( DMA_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define DMA_Info( Format, ... )       LOG_Info( DMA_LOG, UTIL_StringConcatenateConstant( DMA_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define DMA_Warning( Format, ... )    LOG_Warning( DMA_LOG, UTIL_StringConcatenateConstant( DMA_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define DMA_Error( Format, ... )      LOG_Error( DMA_LOG, UTIL_StringConcatenateConstant( DMA_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define DMA_Fatal( Format, ... )      LOG_Fatal( DMA_LOG, UTIL_StringConcatenateConstant( DMA_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define DMA_Raw( Level, Format, ... )
        #define DMA_Trace( Format, ... )
        #define DMA_Debug( Format, ... )
        #define DMA_Info( Format, ... )
        #define DMA_Warning( Format, ... )
        #define DMA_Error( Format, ... )
        #define DMA_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef enum DMA_Type
    {
        DMA_Type_Unknown = 0,
        DMA_Type_Null,
        DMA_Type_STM32L496VGT6P,
    } DMA_Type_t;

    typedef struct DMA_Instance
    {
        DMA_Type_t Type;

        union
        {
            DMA_STM32L496VGT6P_t STM32L496VGT6Px;
        };

    } DMA_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    DMA_Status_t DMA_Port_Initialize( DMA_t DMAx );
    DMA_Status_t DMA_Port_Cycle( DMA_t DMAx );
    DMA_Status_t DMA_Port_DeInitialize( DMA_t DMAx );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* DMA_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
