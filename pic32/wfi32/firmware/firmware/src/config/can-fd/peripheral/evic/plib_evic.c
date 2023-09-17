/*******************************************************************************
  EVIC PLIB Implementation

  Company:
    Microchip Technology Inc.

  File Name:
    plib_evic.c

  Summary:
    EVIC PLIB Source File

  Description:
    None

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#include "device.h"
#include "plib_evic.h"


EXT_INT_PIN_CALLBACK_OBJ extInt2CbObj;
// *****************************************************************************
// *****************************************************************************
// Section: IRQ Implementation
// *****************************************************************************
// *****************************************************************************

void EVIC_Initialize( void )
{
    INTCONSET = _INTCON_MVEC_MASK;

    /* Set up priority and subpriority of enabled interrupts */
    IPC0SET = 0x4 | 0x0;  /* CORE_TIMER:  Priority 1 / Subpriority 0 */
    IPC3SET = 0x400 | 0x0;  /* EXTERNAL_2:  Priority 1 / Subpriority 0 */
    IPC6SET = 0x4 | 0x0;  /* TIMER_5:  Priority 1 / Subpriority 0 */
    IPC7SET = 0x40000 | 0x0;  /* RTCC:  Priority 1 / Subpriority 0 */
    IPC9SET = 0x8 | 0x0;  /* SPI1_RX:  Priority 2 / Subpriority 0 */
    IPC9SET = 0x800 | 0x0;  /* SPI1_TX:  Priority 2 / Subpriority 0 */
    IPC13SET = 0xc0000 | 0x0;  /* SPI2_RX:  Priority 3 / Subpriority 0 */
    IPC13SET = 0xc000000 | 0x0;  /* SPI2_TX:  Priority 3 / Subpriority 0 */
    IPC18SET = 0x4 | 0x0;  /* DMA0:  Priority 1 / Subpriority 0 */
    IPC18SET = 0x400 | 0x0;  /* DMA1:  Priority 1 / Subpriority 0 */
    IPC18SET = 0x40000 | 0x0;  /* DMA2:  Priority 1 / Subpriority 0 */
    IPC19SET = 0x8 | 0x0;  /* TIMER_6:  Priority 2 / Subpriority 0 */

    /* Initialize External interrupt 2 callback object */
    extInt2CbObj.callback = NULL;


    /* Configure Shadow Register Set */
    PRISS = 0x76543210;

    while (PRISS != 0x76543210)
    {
        /* Wait for PRISS value to take effect */
    }
}

void EVIC_SourceEnable( INT_SOURCE source )
{
    volatile uint32_t *IECx = (volatile uint32_t *) (&IEC0 + ((0x10 * (source / 32)) / 4));
    volatile uint32_t *IECxSET = (volatile uint32_t *)(IECx + 2);

    *IECxSET = 1 << (source & 0x1f);
}

void EVIC_SourceDisable( INT_SOURCE source )
{
    volatile uint32_t *IECx = (volatile uint32_t *) (&IEC0 + ((0x10 * (source / 32)) / 4));
    volatile uint32_t *IECxCLR = (volatile uint32_t *)(IECx + 1);

    *IECxCLR = 1 << (source & 0x1f);
}

bool EVIC_SourceIsEnabled( INT_SOURCE source )
{
    volatile uint32_t *IECx = (volatile uint32_t *) (&IEC0 + ((0x10 * (source / 32)) / 4));

    return (bool)((*IECx >> (source & 0x1f)) & 0x01);
}

bool EVIC_SourceStatusGet( INT_SOURCE source )
{
    volatile uint32_t *IFSx = (volatile uint32_t *)(&IFS0 + ((0x10 * (source / 32)) / 4));

    return (bool)((*IFSx >> (source & 0x1f)) & 0x1);
}

void EVIC_SourceStatusSet( INT_SOURCE source )
{
    volatile uint32_t *IFSx = (volatile uint32_t *) (&IFS0 + ((0x10 * (source / 32)) / 4));
    volatile uint32_t *IFSxSET = (volatile uint32_t *)(IFSx + 2);

    *IFSxSET = 1 << (source & 0x1f);
}

void EVIC_SourceStatusClear( INT_SOURCE source )
{
    volatile uint32_t *IFSx = (volatile uint32_t *) (&IFS0 + ((0x10 * (source / 32)) / 4));
    volatile uint32_t *IFSxCLR = (volatile uint32_t *)(IFSx + 1);

    *IFSxCLR = 1 << (source & 0x1f);
}

void EVIC_INT_Enable( void )
{
    __builtin_enable_interrupts();
}

bool EVIC_INT_Disable( void )
{
    uint32_t processorStatus;

    /* Save the processor status and then Disable the global interrupt */
    processorStatus = ( uint32_t )__builtin_disable_interrupts();

    /* return the interrupt status */
    return (bool)(processorStatus & 0x01);
}

void EVIC_INT_Restore( bool state )
{
    if (state)
    {
        /* restore the state of CP0 Status register before the disable occurred */
        __builtin_enable_interrupts();
    }
}

void EVIC_ExternalInterruptEnable( EXTERNAL_INT_PIN extIntPin )
{
    IEC0SET = extIntPin;
}

void EVIC_ExternalInterruptDisable( EXTERNAL_INT_PIN extIntPin )
{
    IEC0CLR = extIntPin;
}

bool EVIC_ExternalInterruptCallbackRegister(
    EXTERNAL_INT_PIN extIntPin,
    const EXTERNAL_INT_PIN_CALLBACK callback,
    uintptr_t context
)
{
    bool status = true;
    switch  (extIntPin)
        {
        case EXTERNAL_INT_2:
            extInt2CbObj.callback = callback;
            extInt2CbObj.context  = context;
            break;
        default:
            status = false;
            break;
        }

    return status;
}


// *****************************************************************************
/* Function:
    void EXTERNAL_2_InterruptHandler(void)

  Summary:
    Interrupt Handler for External Interrupt pin 2.

  Remarks:
	It is an internal function called from ISR, user should not call it directly.
*/
void EXTERNAL_2_InterruptHandler(void)
{
    IFS0CLR = _IFS0_INT2IF_MASK;

    if(extInt2CbObj.callback != NULL)
    {
        extInt2CbObj.callback (EXTERNAL_INT_2, extInt2CbObj.context);
    }
}


/* End of file */