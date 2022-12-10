/*
 * @test.c
 * @brief
 *
 * This file has the functions to test if i2c has been initialised correctly and to test the accelerometer.
 * It checks the range of values returned from the accelerometer.
 *
 * @date 09-Dec-2022
 * @author Anuhya
 */


#include <math.h>
#include "fsl_debug_console.h"
#include "test.h"
#include "mma8451.h"
#include "i2c.h"
#include "systick.h"

#define MMA_ADDR 0x3A
#define REG_WHOAMI 0x0D
#define TEST_TIME 158				// Accelerometer test time for 10s
#define ROLL_LIMIT 181
#define PITCH_LIMIT 91

void test_i2c()
{
	PRINTF("I2C test:");

	if (i2c_read_byte(MMA_ADDR, REG_WHOAMI)==0x1A)
	{
		PRINTF("I2C INITIALISED SUCCESSFULLY \n\r");
	}
	else
	{
		PRINTF("I2C NOT INITIALISED \n\r");
	}
}


void range_test(void)
{
	PRINTF("ROTATE THE BOARD TO TEST ACCELEROMETER FOR 10s \n\r");

	while (time_count()<=TEST_TIME)
	{
		read_full_xyz_test();
		assert(convert_to_roll()<ROLL_LIMIT && convert_to_roll()>-ROLL_LIMIT);
		assert(convert_to_pitch()<PITCH_LIMIT && convert_to_pitch()>-PITCH_LIMIT);
	}

	PRINTF("RANGE TEST OF ACCELEROMETER SUCCESSFULL \n\r");
}
