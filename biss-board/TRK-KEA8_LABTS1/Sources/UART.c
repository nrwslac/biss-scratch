
/*
 * UART.c
 *
 *  Created on: Dec 18, 2013
 *      Author: B46911
 */
#include "UART.h"

/**********************************************************************************************
* External objects
**********************************************************************************************/


/**********************************************************************************************
* Global variables
**********************************************************************************************/
pt2FuncU8 Uart_Callback;


/**********************************************************************************************
* Constants and macros
**********************************************************************************************/


/**********************************************************************************************
* Local types
**********************************************************************************************/


/**********************************************************************************************
* Local function prototypes
*********************************************************************************************/
void UART0_SCI0_IRQHandler ();

/**********************************************************************************************
* Local variables
**********************************************************************************************/


/**********************************************************************************************
* Local functions
**********************************************************************************************/


/**********************************************************************************************
* Global functions
**********************************************************************************************/


/***********************************************************************************************
*
* @brief    Uart_Init - Initalizes the Uart 0 to run at 9600 bauds assuming bus clock of 20Mhz
* @param    none
* @return   none
*
************************************************************************************************/  
void UART_Init()
{
	SIM_SCGC |=  SIM_SCGC_UART0_MASK;		/* Enable bus clock in UART2*/
	UART0_BDH = 0;							/* One stop bit*/
	UART0_BDL = 128;						/* Baud rate at 9600*/
	UART0_C1  = 0;							/* No parity enable,8 bit format*/
	UART0_C2 |= UART_C2_TE_MASK;			/* Enable Transmitter*/
	UART0_C2 |= UART_C2_RE_MASK;			/* Enable Receiver*/
	UART0_C2 |= UART_C2_RIE_MASK;			/* Enable Receiver interrupts*/
	

}

/***********************************************************************************************
*
* @brief    Uart_SetCallback - Set a callback function to execute when a byte is received on the Uart1
* @param    pointer to function with an UINT8 argument
* @return   none
*
************************************************************************************************/  
void Uart_SetCallback(pt2FuncU8 ptr)
{
	Uart_Callback = ptr;	
}


/***********************************************************************************************
*
* @brief    Uart_SendChar - Send a single byte on Uart1 
* @param    byte to send
* @return   none
*
************************************************************************************************/  
void Uart_SendChar(UINT8 send)
{
	while((UART0_S1&UART_S1_TDRE_MASK)==0);		/* Wait for transmit buffer to be empty*/
	(void)UART0_S1;								/* Read UART2_S1 register*/
	UART0_D=send;								/* Send data*/
}

/***********************************************************************************************
*
* @brief    Uart_GetChar - Retrieve the received char from the Uart1 buffer (should be called from Interrupt) 
* @param    none
* @return   received byte
*
************************************************************************************************/  
UINT8 Uart_GetChar()
{
	
  UINT8 recieve;
  while(( UART0_S1 & UART_S1_RDRF_MASK)==0);	/* Wait for received buffer to be full*/
  (void) UART0_S1;								/* Read UART2_S1 register*/
  recieve= UART0_D;								/* Read received data*/
  return recieve;

} 

/***********************************************************************************************
*
* @brief    UART2_SCI2_IRQHandler - Uart1 reception interrupt, calls the user defined callback function 
* @param    none
* @return   none
*
************************************************************************************************/
void UART0_SCI0_IRQHandler ()
{

	(void)UART0_S1;		/* Clear reception flag mechanism*/
	Uart_Callback(Uart_GetChar());

}
