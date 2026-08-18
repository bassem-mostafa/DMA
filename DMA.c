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

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "DMA.h"
#include "DMA_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

DMA_Status_t DMA_Initialize( DMA_t DMAx )
{
    DMA_Status_t Status = DMA_Status_Success;
    DMA_Status_t DMA_Status = DMA_Status_Success;

    do
    {
        DMA_Trace( "%s( DMAx=%d )", __FUNCTION__, DMAx );

        DMA_t DMA_start = ( DMAx == DMA_All ? DMA_Null : DMAx );
        DMA_t DMA_end = ( DMAx == DMA_All ? DMA_Count : DMAx + 1 );
        for ( DMA_t DMA_x = DMA_start; DMA_x < DMA_end; ++DMA_x )
        {
            if ( ( DMA_Status = DMA_Port_Initialize( DMA_x ) ) != DMA_Status_Success )
            {
                Status = DMA_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

DMA_Status_t DMA_Cycle( DMA_t DMAx )
{
    DMA_Status_t Status = DMA_Status_Success;
    DMA_Status_t DMA_Status = DMA_Status_Success;

    do
    {
        DMA_Trace( "%s( DMAx=%d )", __FUNCTION__, DMAx );

        DMA_t DMA_start = ( DMAx == DMA_All ? DMA_Null : DMAx );
        DMA_t DMA_end = ( DMAx == DMA_All ? DMA_Count : DMAx + 1 );
        for ( DMA_t DMA_x = DMA_start; DMA_x < DMA_end; ++DMA_x )
        {
            if ( ( DMA_Status = DMA_Port_Cycle( DMA_x ) ) != DMA_Status_Success )
            {
                Status = DMA_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

DMA_Status_t DMA_DeInitialize( DMA_t DMAx )
{
    DMA_Status_t Status = DMA_Status_Success;
    DMA_Status_t DMA_Status = DMA_Status_Success;

    do
    {
        DMA_Trace( "%s( DMAx=%d )", __FUNCTION__, DMAx );

        DMA_t DMA_start = ( DMAx == DMA_All ? DMA_Null : DMAx );
        DMA_t DMA_end = ( DMAx == DMA_All ? DMA_Count : DMAx + 1 );
        for ( DMA_t DMA_x = DMA_start; DMA_x < DMA_end; ++DMA_x )
        {
            if ( ( DMA_Status = DMA_Port_DeInitialize( DMA_x ) ) != DMA_Status_Success )
            {
                Status = DMA_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char DMA_VERSION[] = "0.0.0.v20260818-0345";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
