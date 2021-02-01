################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
digitalclock.lss \

FLASH_IMAGE += \
digitalclock.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: digitalclock.elf secondary-outputs

# Tool invocations
digitalclock.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,digitalclock.map -mmcu=atmega32 -o "digitalclock.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

digitalclock.lss: digitalclock.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S digitalclock.elf  >"digitalclock.lss"
	@echo 'Finished building: $@'
	@echo ' '

digitalclock.hex: digitalclock.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex digitalclock.elf  "digitalclock.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: digitalclock.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 digitalclock.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: digitalclock.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -u -Uflash:w:digitalclock.hex:a -Ulfuse:w:0xee:m -Uhfuse:w:0xc9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) digitalclock.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
