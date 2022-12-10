/*
 * @switch.c
 * @brief
 *
 * This file has the initialization for switch with gpio interrupt, function to enable the interrupt and
 * function for portD interrupt handler.
 *
 * @date 09-Dec-2022
 * @author Anuhya
 */

#include "MKL25Z4.h"
#include "switch.h"

#define SW1_POS (7)		//Switch connected to PortD-Pin7 using internal pull-up resistor.

#define MASK(x) (1UL << (x))

extern int switch_flag;

void init_interrupt(void) {

	/* Configure PORT peripheral. Select GPIO and enable pull-up
	resistors and interrupts on all edges for pin connected to switch */
	PORTD->PCR[SW1_POS] = PORT_PCR_MUX(1) | PORT_PCR_PS_MASK |
			PORT_PCR_PE_MASK | PORT_PCR_IRQC(11);

	NVIC_SetPriority(PORTD_IRQn, 128);					// Configure NVIC */
	NVIC_ClearPendingIRQ(PORTD_IRQn);
	NVIC_EnableIRQ(PORTD_IRQn);

	__enable_irq();										// Configure PRIMASK */
}

void switch_init() {

	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;			// Enable clock to port D

	PORTD->PCR[SW1_POS] = PORT_PCR_MUX(1) | PORT_PCR_PS_MASK | PORT_PCR_PE_MASK;		// Select port D on pin mux, enable pull-up resistors

	PTD->PDDR &= ~MASK(SW1_POS);				// Clear switch bits to input

	init_interrupt();							//initialize switch interrupt
}

void PORTD_IRQHandler() {

	if ((PORTD->ISFR & MASK(SW1_POS))) {		// Read switch
		switch_flag=1;							// set switch flag
	}

	PORTD->ISFR = 0xffffffff;					// clear status flags
}
