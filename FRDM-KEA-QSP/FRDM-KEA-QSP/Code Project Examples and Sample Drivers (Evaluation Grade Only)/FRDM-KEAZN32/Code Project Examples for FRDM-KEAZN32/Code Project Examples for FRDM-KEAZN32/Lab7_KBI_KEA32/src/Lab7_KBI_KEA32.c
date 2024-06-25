/******************************************************************************
*    LAB7 -Keyboard Interrupt (KBI) Module                                    *
*    FRDM+KEA32 Board														  *
*                                                                             *
*    This lab demonstrates how to use the KBI module to read button       	  *
*    pressed without polling. It uses interrupts to detect button presses on  *
*    SW2 and SW3. Each button toggles an LED when pressed.                    *
******************************************************************************/


/**********************************************************************************************
* External objects
**********************************************************************************************/
#include "derivative.h" /* include peripheral declarations */
#include "CLK.h"
#include "GPIO.h"
#include "KBI.h"
/**********************************************************************************************
* Global variables
**********************************************************************************************/


/**********************************************************************************************
* Constants and macros
**********************************************************************************************/
#define PTH0 24 								/* For RED LED */
#define PTH1 25 								/* For GREEN LED */
#define PTE7 7  								/* For BLUE LED */
#define PTA0 0  								/* For SW2 - BTN0 */
#define PTA1 1  								/* For SW3 - BTN1 */

#define LED0_TOGGLE		OUTPUT_TOGGLE(H1,PTH0)
#define LED1_TOGGLE		OUTPUT_TOGGLE(H1,PTH1)
#define LED2_TOGGLE		OUTPUT_TOGGLE(E1,PTE7)

#define LED0_OFF		OUTPUT_CLEAR(H1,PTH0);
#define LED1_OFF		OUTPUT_CLEAR(H1,PTH1);
#define LED2_OFF		OUTPUT_CLEAR(E1,PTE7);

#define LED0_ON			OUTPUT_SET(H1,PTH0);
#define LED1_ON			OUTPUT_SET(H1,PTH1);
#define LED2_ON			OUTPUT_SET(E1,PTE7);


/**********************************************************************************************
* Local types
**********************************************************************************************/


/**********************************************************************************************
* Local function prototypes
*********************************************************************************************/
void Enable_Interrupt(uint8_t vector_number);
void KBI_Interrupt(void);

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
* @brief    GPIO_Init - Initialize the LEDs as outputs, SWs as inputs.
* @param    none
* @return   none
*
************************************************************************************************/
void GPIO_Init()
{
	CONFIG_PIN_AS_GPIO(H1,PTH0,OUTPUT); 		/* Configure RED LED as an output */
	CONFIG_PIN_AS_GPIO(H1,PTH1,OUTPUT); 		/* Configure GREEN LED as an output */
	CONFIG_PIN_AS_GPIO(E1,PTE7,OUTPUT); 		/* Configure BLUE LED as an output */

	CONFIG_PIN_AS_GPIO(A1,PTA0,INPUT); 			/* Configure BTN0 as an input */
	CONFIG_PIN_AS_GPIO(A1,PTA1,INPUT); 			/* Configure BTN1 as an input */
	ENABLE_INPUT(A1,PTA0);			 			/* Enable input BTN0*/
	ENABLE_INPUT(A1,PTA1);						/* Enable input BTN1*/

	LED0_OFF;									/* Turn off RED */
	LED1_OFF;									/* Turn off GREEN */
	LED2_OFF;									/* Turn off BLUE */
}


/***********************************************************************************************
*
* @brief    main() - Program entry function
* @param    none
* @return   none
*
************************************************************************************************/
int main(void)
{
	/* Initialize Clock to 32MHz, Bus Clock to 16MHz  */
	Clk_Init();

	/* Configure button pins as inputs and LED pins as outputs */
	GPIO_Init();

	/* Initialize KBI module */
	KBI_Init();

	/* Enable KBI0 Interrupts */
	Enable_Interrupt(KBI0_IRQn);

	while(1);
	
	return 0;
}

/***********************************************************************************************
*
* @brief    Enable_Interrupt(UINT8 vector_number). Enable interrupts from desired module.
* @param    Module interrupt number from the interrupts vector table
* @return   none
*
************************************************************************************************/
void Enable_Interrupt(uint8_t vector_number)
{

	NVIC_ClearPendingIRQ(vector_number); 		/* Clear pending interrupt register */
	NVIC_EnableIRQ(vector_number); 				/* Enable required Interrupt */

}

/***********************************************************************************************
*
* @brief    KBI1_IRQHandler - KBI interrupt routine, calls User Function.
* @param    none
* @return   none
*
************************************************************************************************/
void KBI0_IRQHandler()
{

	KBI_Interrupt();

}

/***********************************************************************************************
*
* @brief    KBI_Interrupt(void). User Function called by the KBI module on each interrupt
* @param    KBI channel
* @return   none
*
************************************************************************************************/
void KBI_Interrupt(void)
{

	KBI0_SC |= KBI_SC_KBACK_MASK;								/*Clear flag*/

	if((READ_INPUT(A1,PTA0) && 0x00000001) == 0x00000000)   	/* If SW2 has been pressed */
	{
		LED0_TOGGLE;											/* Toggle RED LED */
	}

	if((READ_INPUT(A1,PTA1) && 0x00000002) == 0x00000000)	/* If SW3 has been pressed */
	{
		LED1_TOGGLE;											/* Toggle GREEN LED */
	}

}
