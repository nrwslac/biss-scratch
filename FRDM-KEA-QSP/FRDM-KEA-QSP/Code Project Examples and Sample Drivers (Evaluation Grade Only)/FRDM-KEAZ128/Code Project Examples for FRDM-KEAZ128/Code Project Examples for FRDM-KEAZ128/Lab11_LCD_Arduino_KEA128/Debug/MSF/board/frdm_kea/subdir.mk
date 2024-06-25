################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../MSF/board/frdm_kea/arduino.c" \

C_SRCS += \
../MSF/board/frdm_kea/arduino.c \

OBJS += \
./MSF/board/frdm_kea/arduino.o \

C_DEPS += \
./MSF/board/frdm_kea/arduino.d \

OBJS_QUOTED += \
"./MSF/board/frdm_kea/arduino.o" \

OBJS_OS_FORMAT += \
./MSF/board/frdm_kea/arduino.o \

C_DEPS_QUOTED += \
"./MSF/board/frdm_kea/arduino.d" \


# Each subdirectory must supply rules for building sources it contributes
MSF/board/frdm_kea/arduino.o: ../MSF/board/frdm_kea/arduino.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/board/frdm_kea/arduino.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/board/frdm_kea/arduino.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


