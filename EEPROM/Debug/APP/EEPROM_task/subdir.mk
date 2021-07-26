################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/EEPROM_task/EEPROM_task.c 

OBJS += \
./APP/EEPROM_task/EEPROM_task.o 

C_DEPS += \
./APP/EEPROM_task/EEPROM_task.d 


# Each subdirectory must supply rules for building sources it contributes
APP/EEPROM_task/%.o: ../APP/EEPROM_task/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


