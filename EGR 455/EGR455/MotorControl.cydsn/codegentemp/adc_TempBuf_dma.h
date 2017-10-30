/******************************************************************************
* File Name: adc_TempBuf_dma.h  
* Version 1.70
*
*  Description:
*   Provides the function definitions for the DMA Controller.
*
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#if !defined(CY_DMA_adc_TempBuf_DMA_H__)
#define CY_DMA_adc_TempBuf_DMA_H__



#include <CYDMAC.H>
#include <CYFITTER.H>

#define adc_TempBuf__TD_TERMOUT_EN (((0 != adc_TempBuf__TERMOUT0_EN) ? TD_TERMOUT0_EN : 0) | \
    (adc_TempBuf__TERMOUT1_EN ? TD_TERMOUT1_EN : 0))

/* Zero based index of adc_TempBuf dma channel */
extern uint8 adc_TempBuf_DmaHandle;


uint8 adc_TempBuf_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) ;
void  adc_TempBuf_DmaRelease(void) ;


/* CY_DMA_adc_TempBuf_DMA_H__ */
#endif