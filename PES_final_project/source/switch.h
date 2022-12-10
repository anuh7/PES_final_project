/*
 * @switch.h
 * @brief
 *
 *  This file has the declarations to initialization for switch with gpio interrupt, function to enable the
 *  interrupt and function for portD interrupt handler.
 *
 * @date 09-Dec-2022
 * @author Anuhya
 */

#ifndef SWITCH_H_
#define SWITCH_H_

/**
 * @brief Enables the gpio interrupt for the switch and sets the interrupt priority.
 *
 * @return void.
 */
void init_interrupt(void);

/**
 * @brief Provides the clock to port D and enables internal pull-up resistors for the port; Calls the
 * function init_interrupt().
 *
 * @return void.
 */
void switch_init();

/**
 * @brief Interrupt handler for the port D; reads if the switch is pressed and sets a flag.
 *
 * @return void.
 */
void PORTD_IRQHandler(void);

#endif /* SWITCH_H_ */
