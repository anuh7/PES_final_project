/*
 * @systick.c
 * @brief
 *
 * This file has declarations to initializations for Systick, functions to return the current time,
 *  reset the start time.
 *
 * @date 09-Dec-2022
 * @author Anuhya
 */


#ifndef SYSTICK_H_
#define SYSTICK_H_



/**
 * @brief Initializes SysTick timer for interrupts of 63.5ms
 *
 * @return void.
 */
void init_systick();

/**
 * @brief Exception handler for SysTick Timer. Calculates global variables required in the main code.
 * @return void.
 */
void SysTick_Handler();

/**
 * @brief Calculates the time since last reset of start time.
 * @return total_time
 */
uint32_t time_count();

/**
 * @brief Resets the start time.
 * @return void
 */
void reset_timer();




#endif /* SYSTICK_H_ */
