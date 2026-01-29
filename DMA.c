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

typedef struct DMA_Context
{
    DMA_Instance_t Instance[ DMA_Count ];
} DMA_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static DMA_Status_t DMA_Context_Initialize( void );
static DMA_Status_t DMA_Context_Cycle( void );
static DMA_Status_t DMA_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static DMA_Context_t DMA_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static DMA_Status_t DMA_Context_Initialize( void )
{
    DMA_Status_t Status = DMA_Status_Error;

    do
    {
        DMA_Trace( "%s( void )", __FUNCTION__ );

        for ( DMA_t DMA_x = DMA_Null; DMA_x < DMA_Count; ++DMA_x )
        {
            DMA_Context.Instance[ DMA_x ].DMAx = DMA_x;
        }

        Status = DMA_Status_Success;
    }
    while ( 0 );

    return Status;
}

static DMA_Status_t DMA_Context_Cycle( void )
{
    DMA_Status_t Status = DMA_Status_Error;

    do
    {
        DMA_Trace( "%s( void )", __FUNCTION__ );

        Status = DMA_Status_Success;
    }
    while ( 0 );

    return Status;
}

static DMA_Status_t DMA_Context_DeInitialize( void )
{
    DMA_Status_t Status = DMA_Status_Error;

    do
    {
        DMA_Trace( "%s( void )", __FUNCTION__ );

        Status = DMA_Status_Success;
    }
    while ( 0 );

    return Status;
}

DMA_Status_t DMA_GetInstance( DMA_t DMAx, DMA_Instance_t ** Instance )
{
    DMA_Status_t Status = DMA_Status_Error;

    do
    {
        DMA_Trace( "%s( DMAx=%d, Instance=%p )", __FUNCTION__, DMAx, Instance );

        if ( Instance == NULL )
        {
            Status = DMA_Status_ArgumentInvalid;
            break;
        }

        *Instance = &DMA_Context.Instance[ DMAx ];

        Status = DMA_Status_Success;
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

DMA_Status_t DMA_Initialize( DMA_t DMAx )
{
    DMA_Status_t Status = DMA_Status_Error;

    do
    {
        DMA_Trace( "%s( DMAx=%d )", __FUNCTION__, DMAx );

        if ( ( Status = DMA_IsValid( DMAx ) ) != DMA_Status_Success )
        {
            break;
        }

        if ( ( Status = DMA_Context_Initialize( ) ) != DMA_Status_Success )
        {
            break;
        }

        for ( DMA_t DMA_x = DMA_Null; DMA_x < DMA_Count; ++DMA_x )
        {
            if ( DMAx != DMA_All && DMAx != DMA_x )
            {
                continue;
            }

            DMA_Status_t DMA_Status = DMA_Status_Success;
            if ( ( DMA_Status = DMA_Instance_Initialize( &DMA_Context.Instance[ DMA_x ] ) ) != DMA_Status_Success )
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
    DMA_Status_t Status = DMA_Status_Error;

    do
    {
        DMA_Trace( "%s( DMAx=%d )", __FUNCTION__, DMAx );

        if ( ( Status = DMA_IsValid( DMAx ) ) != DMA_Status_Success )
        {
            break;
        }

        if ( ( Status = DMA_Context_Cycle( ) ) != DMA_Status_Success )
        {
            break;
        }

        for ( DMA_t DMA_x = DMA_Null; DMA_x < DMA_Count; ++DMA_x )
        {
            if ( DMAx != DMA_All && DMAx != DMA_x )
            {
                continue;
            }

            DMA_Status_t DMA_Status = DMA_Status_Success;
            if ( ( DMA_Status = DMA_Instance_Cycle( &DMA_Context.Instance[ DMA_x ] ) ) != DMA_Status_Success )
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
    DMA_Status_t Status = DMA_Status_Error;

    do
    {
        DMA_Trace( "%s( DMAx=%d )", __FUNCTION__, DMAx );

        if ( ( Status = DMA_IsValid( DMAx ) ) != DMA_Status_Success )
        {
            break;
        }

        for ( DMA_t DMA_x = DMA_Null; DMA_x < DMA_Count; ++DMA_x )
        {
            if ( DMAx != DMA_All && DMAx != DMA_x )
            {
                continue;
            }

            DMA_Status_t DMA_Status = DMA_Status_Success;
            if ( ( DMA_Status = DMA_Instance_DeInitialize( &DMA_Context.Instance[ DMA_x ] ) ) != DMA_Status_Success )
            {
                Status = DMA_Status;
            }
        }

        Status = DMA_Context_DeInitialize( );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char DMA_VERSION[] = "0.0.0.v20260129-1438";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
