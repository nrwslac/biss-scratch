################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../MSF/common/conio.c" \
"../MSF/common/coniob.c" \
"../MSF/common/msf_print.c" \
"../MSF/common/waveio.c" \

C_SRCS += \
../MSF/common/conio.c \
../MSF/common/coniob.c \
../MSF/common/msf_print.c \
../MSF/common/waveio.c \

OBJS += \
./MSF/common/conio.o \
./MSF/common/coniob.o \
./MSF/common/msf_print.o \
./MSF/common/waveio.o \

C_DEPS += \
./MSF/common/conio.d \
./MSF/common/coniob.d \
./MSF/common/msf_print.d \
./MSF/common/waveio.d \

OBJS_QUOTED += \
"./MSF/common/conio.o" \
"./MSF/common/coniob.o" \
"./MSF/common/msf_print.o" \
"./MSF/common/waveio.o" \

OBJS_OS_FORMAT += \
./MSF/common/conio.o \
./MSF/common/coniob.o \
./MSF/common/msf_print.o \
./MSF/common/waveio.o \

C_DEPS_QUOTED += \
"./MSF/common/conio.d" \
"./MSF/common/coniob.d" \
"./MSF/common/msf_print.d" \
"./MSF/common/waveio.d" \


# Each subdirectory must supply rules for building sources it contributes
MSF/common/conio.o: ../MSF/common/conio.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/common/conio.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/common/conio.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSF/common/coniob.o: ../MSF/common/coniob.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/common/coniob.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/common/coniob.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSF/common/msf_print.o: ../MSF/common/msf_print.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/common/msf_print.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/common/msf_print.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSF/common/waveio.o: ../MSF/common/waveio.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/common/waveio.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/common/waveio.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


