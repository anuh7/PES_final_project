/*
 * @test.h
 * @brief
 *
 * This file has the declarations to the functions to test if i2c has been initialised correctly and
 * to test the accelerometer.
 *
 * @date 09-Dec-2022
 * @author Anuhya
 */

#ifndef TEST_H_
#define TEST_H_


/**
 * @brief Test to check if I2C peripheral is initialized correctly
 *
 * @return void.
 */
void test_i2c();

/**
 * @brief Test for the accerelerometer which checks if the roll and pich values are in range.
 *
 * @return void.
 */
void range_test(void);


#endif /* TEST_H_ */
