################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/PES_final_project.c \
../source/delay.c \
../source/i2c.c \
../source/mma8451.c \
../source/mtb.c \
../source/pwm.c \
../source/semihost_hardfault.c \
../source/switch.c \
../source/systick.c \
../source/test.c \
../source/touch_sensor.c 

C_DEPS += \
./source/PES_final_project.d \
./source/delay.d \
./source/i2c.d \
./source/mma8451.d \
./source/mtb.d \
./source/pwm.d \
./source/semihost_hardfault.d \
./source/switch.d \
./source/systick.d \
./source/test.d \
./source/touch_sensor.d 

OBJS += \
./source/PES_final_project.o \
./source/delay.o \
./source/i2c.o \
./source/mma8451.o \
./source/mtb.o \
./source/pwm.o \
./source/semihost_hardfault.o \
./source/switch.o \
./source/systick.o \
./source/test.o \
./source/touch_sensor.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\CU-B\PES\final project\final_project\PES_final_project\board" -I"D:\CU-B\PES\final project\final_project\PES_final_project\source" -I"D:\CU-B\PES\final project\final_project\PES_final_project" -I"D:\CU-B\PES\final project\final_project\PES_final_project\drivers" -I"D:\CU-B\PES\final project\final_project\PES_final_project\CMSIS" -I"D:\CU-B\PES\final project\final_project\PES_final_project\utilities" -I"D:\CU-B\PES\final project\final_project\PES_final_project\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/PES_final_project.d ./source/PES_final_project.o ./source/delay.d ./source/delay.o ./source/i2c.d ./source/i2c.o ./source/mma8451.d ./source/mma8451.o ./source/mtb.d ./source/mtb.o ./source/pwm.d ./source/pwm.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/switch.d ./source/switch.o ./source/systick.d ./source/systick.o ./source/test.d ./source/test.o ./source/touch_sensor.d ./source/touch_sensor.o

.PHONY: clean-source

