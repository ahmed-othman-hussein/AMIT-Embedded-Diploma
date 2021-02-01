################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App.c \
../Dio.c \
../Dio_cfg.c \
../ExtInterrupt.c \
../Keypad.c \
../Keypad_cfg.c \
../Lcd.c \
../Lcd_cfg.c \
../Led.c \
../Led_cfg.c \
../Main.c \
../Os_Isr.c \
../Os_Isr_cfg.c \
../Uart.c 

OBJS += \
./App.o \
./Dio.o \
./Dio_cfg.o \
./ExtInterrupt.o \
./Keypad.o \
./Keypad_cfg.o \
./Lcd.o \
./Lcd_cfg.o \
./Led.o \
./Led_cfg.o \
./Main.o \
./Os_Isr.o \
./Os_Isr_cfg.o \
./Uart.o 

C_DEPS += \
./App.d \
./Dio.d \
./Dio_cfg.d \
./ExtInterrupt.d \
./Keypad.d \
./Keypad_cfg.d \
./Lcd.d \
./Lcd_cfg.d \
./Led.d \
./Led_cfg.d \
./Main.d \
./Os_Isr.d \
./Os_Isr_cfg.d \
./Uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


