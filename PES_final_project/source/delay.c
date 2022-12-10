/*
 * @delay.c
 * @brief
 *
 * This file has the function for approximate delay.
 *
 * @date 09-Dec-2022
 * @author Anuhya
 */


#include <MKL25Z4.H>

void Delay (uint32_t dly) {
  volatile uint32_t t;

	for (t=dly*10000; t>0; t--)
		;
}
