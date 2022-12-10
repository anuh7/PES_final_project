/*
 * @pwm.c
 * @brief
 *
 * This file has the initialization for LEDs in PWM mode, and timer peripherals for the LEDs. It has also
 * has the function for setting LED colours.
 *
 * @date 09-Dec-2022
 * @author Anuhya
 */

#include "pwm.h"
#include "board.h"
#include "peripherals.h"
#include "MKL25Z4.h"



#define MOD_VALUE (1020)



void PWM_init(){

	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK;			//clock gating to the ports B&D
	PORTB->PCR[BOARD_LED_RED_GPIO_PIN] &= ~(PORT_PCR_MUX_MASK);			//setting pin to FTM
	PORTB->PCR[BOARD_LED_RED_GPIO_PIN] |= PORT_PCR_MUX(3);				//Red FTM2_CH0, Mux Alt 3

	PORTB->PCR[BOARD_LED_GREEN_GPIO_PIN] &= ~(PORT_PCR_MUX_MASK);		//setting pin to FTM
	PORTB->PCR[BOARD_LED_GREEN_GPIO_PIN] |= PORT_PCR_MUX(3);			//Green TPM2_CH1, Mux Alt 3

	PORTD->PCR[BOARD_LED_BLUE_GPIO_PIN] &= ~(PORT_PCR_MUX_MASK);		//setting pin to FTM
	PORTD->PCR[BOARD_LED_BLUE_GPIO_PIN] |= PORT_PCR_MUX(4);				//Blue TPM0_CH1, Mux Alt 4
}

void TPM_init(){

	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;									//enabling clock to TPM 0&2
	SIM->SCGC6 |= SIM_SCGC6_TPM2_MASK;

	SIM->SOPT2 |= (SIM_SOPT2_TPMSRC(1) | SIM_SOPT2_PLLFLLSEL_MASK);		//setting clock source for TPM: 48Mhz

	TPM0->MOD = MOD_VALUE;													//loading the counter and MOD register
	TPM2->MOD = MOD_VALUE;

	TPM0->SC =  TPM_SC_PS(1);											//setting prescalar=2
	TPM2->SC =  TPM_SC_PS(1);

	TPM0->CONF |= TPM_CONF_DBGMODE(3);									//continue operation in debug mode
	TPM2->CONF |= TPM_CONF_DBGMODE(3);

	TPM0->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;	//setting time to edge-aligned low-true PWM
	TPM2->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;
	TPM2->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK | TPM_CnSC_ELSA_MASK;

	TPM0->CONTROLS[1].CnV = 0;											//setting initial duty cycle
	TPM2->CONTROLS[0].CnV = 0;
	TPM2->CONTROLS[1].CnV = 0;

	TPM0->SC |= TPM_SC_CMOD(1);											//selecting LPTPM as clock source
	TPM2->SC |= TPM_SC_CMOD(1);
}



void change_led(int R, int G, int B) {
	TPM2->CONTROLS[0].CnV  = (R*TPM2->MOD)/255;		//change led colour
	TPM2->CONTROLS[1].CnV  = (G*TPM2->MOD)/255;
	TPM0->CONTROLS[1].CnV  = (B*TPM0->MOD)/255;
}

