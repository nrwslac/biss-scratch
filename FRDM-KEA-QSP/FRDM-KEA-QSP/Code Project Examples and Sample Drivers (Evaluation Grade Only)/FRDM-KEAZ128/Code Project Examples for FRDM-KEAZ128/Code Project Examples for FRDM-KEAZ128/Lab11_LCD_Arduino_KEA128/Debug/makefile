################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#Progress monitor hint: 22
first : all
-include ../makefile.init

# This file contains definitions of environment variables used in the makefiles and .args files if exist.
-include makefile.local

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include Project_Settings/Linker_Files/subdir.mk
-include MSF/platform/kea/subdir.mk
-include MSF/common/subdir.mk
-include MSF/board/frdm_kea/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Lab11_LCD_Arduino_KEA128.elf \

EXECUTABLES_QUOTED += \
"Lab11_LCD_Arduino_KEA128.elf" \

EXECUTABLES_OS_FORMAT += \
Lab11_LCD_Arduino_KEA128.elf \

SECONDARY_FLASH += \
Lab11_LCD_Arduino_KEA128.bin \

SECONDARY_FLASH_QUOTED += \
"Lab11_LCD_Arduino_KEA128.bin" \

SECONDARY_FLASH_OS_FORMAT += \
Lab11_LCD_Arduino_KEA128.bin \


# All Target
all: warning-messages explicit-dependencies Lab11_LCD_Arduino_KEA128.elf secondary-outputs

# Tool invocations
Lab11_LCD_Arduino_KEA128.elf: $(OBJS) C:/Users/B48683/Desktop/Lab11_LCD_Arduino_KEA128/Project_Settings/Linker_Files/SKEAZ_flash.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Executing target #23 $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "Lab11_LCD_Arduino_KEA128.elf" "@Lab11_LCD_Arduino_KEA128.args"  $(USER_OBJS_QUOTED) $(LIBS_QUOTED)
	@echo 'Finished building target: $@'
	@echo ' '

Lab11_LCD_Arduino_KEA128.bin: $(EXECUTABLES)
	@echo 'Executing target #24 $@'
	@echo 'Invoking: Standard S32DS Create Flash Image'
	arm-none-eabi-objcopy -O binary $(EXECUTABLES)  "Lab11_LCD_Arduino_KEA128.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*/*/*/*.o ./*/*/*.o ./*/*.o  $(SECONDARY_FLASH_QUOTED) $(EXECUTABLES_QUOTED) ./*/*/*/*.d ./*/*/*.d ./*/*.d  C:\Users\B48683\Desktop\Lab11_LCD_Arduino_KEA128\Debug\Lab11_LCD_Arduino_KEA128.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH)

.PHONY: all clean dependents explicit-dependencies warning-messages
.SECONDARY:

-include ../makefile.targets

explicit-dependencies: 

warning-messages: 

