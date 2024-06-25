################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/LCD_DFR0009.c" \
"../src/Lab11_LCD_Arduino_KEA128.c" \
"../src/LiquidCrystal.c" \
"../src/ics.c" \
"../src/kbi.c" \
"../src/lcd_routines.c" \
"../src/nvic.c" \
"../src/rtc.c" \

C_SRCS += \
../src/LCD_DFR0009.c \
../src/Lab11_LCD_Arduino_KEA128.c \
../src/LiquidCrystal.c \
../src/ics.c \
../src/kbi.c \
../src/lcd_routines.c \
../src/nvic.c \
../src/rtc.c \

OBJS += \
./src/LCD_DFR0009.o \
./src/Lab11_LCD_Arduino_KEA128.o \
./src/LiquidCrystal.o \
./src/ics.o \
./src/kbi.o \
./src/lcd_routines.o \
./src/nvic.o \
./src/rtc.o \

C_DEPS += \
./src/LCD_DFR0009.d \
./src/Lab11_LCD_Arduino_KEA128.d \
./src/LiquidCrystal.d \
./src/ics.d \
./src/kbi.d \
./src/lcd_routines.d \
./src/nvic.d \
./src/rtc.d \

OBJS_QUOTED += \
"./src/LCD_DFR0009.o" \
"./src/Lab11_LCD_Arduino_KEA128.o" \
"./src/LiquidCrystal.o" \
"./src/ics.o" \
"./src/kbi.o" \
"./src/lcd_routines.o" \
"./src/nvic.o" \
"./src/rtc.o" \

OBJS_OS_FORMAT += \
./src/LCD_DFR0009.o \
./src/Lab11_LCD_Arduino_KEA128.o \
./src/LiquidCrystal.o \
./src/ics.o \
./src/kbi.o \
./src/lcd_routines.o \
./src/nvic.o \
./src/rtc.o \

C_DEPS_QUOTED += \
"./src/LCD_DFR0009.d" \
"./src/Lab11_LCD_Arduino_KEA128.d" \
"./src/LiquidCrystal.d" \
"./src/ics.d" \
"./src/kbi.d" \
"./src/lcd_routines.d" \
"./src/nvic.d" \
"./src/rtc.d" \


# Each subdirectory must supply rules for building sources it contributes
src/LCD_DFR0009.o: ../src/LCD_DFR0009.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/LCD_DFR0009.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/LCD_DFR0009.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Lab11_LCD_Arduino_KEA128.o: ../src/Lab11_LCD_Arduino_KEA128.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/Lab11_LCD_Arduino_KEA128.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/Lab11_LCD_Arduino_KEA128.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/LiquidCrystal.o: ../src/LiquidCrystal.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/LiquidCrystal.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/LiquidCrystal.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/ics.o: ../src/ics.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/ics.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/ics.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/kbi.o: ../src/kbi.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/kbi.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/kbi.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/lcd_routines.o: ../src/lcd_routines.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/lcd_routines.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/lcd_routines.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/nvic.o: ../src/nvic.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/nvic.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/nvic.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/rtc.o: ../src/rtc.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/rtc.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "src/rtc.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


