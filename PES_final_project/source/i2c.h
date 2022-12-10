/*
 * @i2c.h
 * @brief
 *
 * This file has the declarations to initialization for I2C0 protocol and declarations for the function
 * to read and write a byte.
 *
 * @date 09-Dec-2022
 * @author Anuhya
 * @attributions: https://github.com/alexander-g-dean/ESF/blob/master/NXP/Code/Chapter_8/I2C-Demo/src/i2c.c
 */

#ifndef I2C_H_
#define I2C_H_



/**
 * @brief This function initializes the I2C0 peripheral using pins PTE24 and PTE25 with a baud rate of 400k.
 *
 * @return void
 */
void i2c_init(void);

/**
 * @brief This function sends the start sequence to initiate read or write
 *
 * @return void
 */
void i2c_start(void);

/**
 * @brief This function sets up to read a byte from a specific device register.
 *
 * @param dev	device address
 * @param address	register address
 * @return void
 */
void i2c_read_setup(uint8_t dev, uint8_t address);

/**
 * @brief This function causes a busy-wait until the byte transfer has completed
 *
 * @return void
 */
void i2c_wait(void);

/**
 * @brief This function reads a byte and sends a ack/nack as appropriate
 *
 */
uint8_t i2c_repeated_read(uint8_t isLastRead);


/**
 * @brief This function to read a byte from a specific device register.
 *
 * @param dev	device address
 * @param address	register address
 * @return void
 */
uint8_t i2c_read_byte(uint8_t dev, uint8_t address);

/**
 * @brief This function to write a byte to a specific device register.
 *
 * @param dev	device address to write byte into
 * @param address	register address
 * @param dara		data to write
 * @return void
 */
void i2c_write_byte(uint8_t dev, uint8_t address, uint8_t data);

#endif /* I2C_H_ */
