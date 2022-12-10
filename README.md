# PES_final_project

For the final project of this course, I have developed a digital angle gauge using the built-in accelerometer. All the functionalities submitted in the report are functional:
- The MMA8451Q accelerometer is implemented over I2C. The success of initialization of accelerometer is printed on the terminal.  
- When the touch slider is pressed, the roll and pitch values are printed onto the terminal at 115200 baud rate. This implementation uses UART functionality. 
- The roll values have a range of (0,360) while the pitch values have a range of (0,180). The RED LED glows to show that the user is at the reference position. When the board is tilted across X-axis completely ie. the roll angle=360 degrees, GREEN LED glows the fullest. Similarly, when the board is tilted across Y-axis completely ie. the pitch angle=180 degrees, BLUE LED glows the fullest. The green and blue LEDs brightness change in pulse-width modulation format in response to the movement according to the board’s roll and pitch values.
- The reference angle can be set by the user pressing the pushbutton connected to portD-pin7. Before pressing the pushbutton, the user can check if the reference angle they want to set is accurate by printing the roll and pitch angle. Then holding the board stable, they can press the pushbutton. This methodology will give more precise and accurate values when measuring with respect to the set reference angle. The set reference angle will be printed onto the terminal.
- The user can recalibrate by pressing the push-button on board if in case they feel that the system output is inaccurate.

Testing process:
1.	The I2C was verified by checking for the correct device address. With i2c_read_byte function, the data written into the device register during initialization is read and verified for the same byte.
2.	The accelerometer is verified by checking if the pitch and roll angles are with the range. This test is run for 10s when the user can rotate the board to test out all angles.
3.	Manual testing is done in the video named demo_video. Using the switch, a reference is set and values can be printed by touching the touch slider. 
 Screenshots of the terminal and its settings are also included in the repo.

Hardware implementation:
 A pushbutton connected to PortD Pin-7 is implemented with internal pull-up resistors. The user can use this to set the reference angle. The hardware set-up is also shown in the video.
