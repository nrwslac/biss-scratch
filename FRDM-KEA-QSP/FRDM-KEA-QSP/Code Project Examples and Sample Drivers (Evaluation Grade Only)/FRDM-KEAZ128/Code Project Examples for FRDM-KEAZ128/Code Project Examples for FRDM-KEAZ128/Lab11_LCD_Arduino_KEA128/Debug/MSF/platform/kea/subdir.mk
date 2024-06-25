################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../MSF/platform/kea/adc_kea.c" \
"../MSF/platform/kea/ftm_kea.c" \
"../MSF/platform/kea/mfs_spi.c" \
"../MSF/platform/kea/msf.c" \
"../MSF/platform/kea/msf_analog.c" \
"../MSF/platform/kea/spi_kea.c" \
"../MSF/platform/kea/uart_kea.c" \

C_SRCS += \
../MSF/platform/kea/adc_kea.c \
../MSF/platform/kea/ftm_kea.c \
../MSF/platform/kea/mfs_spi.c \
../MSF/platform/kea/msf.c \
../MSF/platform/kea/msf_analog.c \
../MSF/platform/kea/spi_kea.c \
../MSF/platform/kea/uart_kea.c \

OBJS += \
./MSF/platform/kea/adc_kea.o \
./MSF/platform/kea/ftm_kea.o \
./MSF/platform/kea/mfs_spi.o \
./MSF/platform/kea/msf.o \
./MSF/platform/kea/msf_analog.o \
./MSF/platform/kea/spi_kea.o \
./MSF/platform/kea/uart_kea.o \

C_DEPS += \
./MSF/platform/kea/adc_kea.d \
./MSF/platform/kea/ftm_kea.d \
./MSF/platform/kea/mfs_spi.d \
./MSF/platform/kea/msf.d \
./MSF/platform/kea/msf_analog.d \
./MSF/platform/kea/spi_kea.d \
./MSF/platform/kea/uart_kea.d \

OBJS_QUOTED += \
"./MSF/platform/kea/adc_kea.o" \
"./MSF/platform/kea/ftm_kea.o" \
"./MSF/platform/kea/mfs_spi.o" \
"./MSF/platform/kea/msf.o" \
"./MSF/platform/kea/msf_analog.o" \
"./MSF/platform/kea/spi_kea.o" \
"./MSF/platform/kea/uart_kea.o" \

OBJS_OS_FORMAT += \
./MSF/platform/kea/adc_kea.o \
./MSF/platform/kea/ftm_kea.o \
./MSF/platform/kea/mfs_spi.o \
./MSF/platform/kea/msf.o \
./MSF/platform/kea/msf_analog.o \
./MSF/platform/kea/spi_kea.o \
./MSF/platform/kea/uart_kea.o \

C_DEPS_QUOTED += \
"./MSF/platform/kea/adc_kea.d" \
"./MSF/platform/kea/ftm_kea.d" \
"./MSF/platform/kea/mfs_spi.d" \
"./MSF/platform/kea/msf.d" \
"./MSF/platform/kea/msf_analog.d" \
"./MSF/platform/kea/spi_kea.d" \
"./MSF/platform/kea/uart_kea.d" \


# Each subdirectory must supply rules for building sources it contributes
MSF/platform/kea/adc_kea.o: ../MSF/platform/kea/adc_kea.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/platform/kea/adc_kea.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/platform/kea/adc_kea.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSF/platform/kea/ftm_kea.o: ../MSF/platform/kea/ftm_kea.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/platform/kea/ftm_kea.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/platform/kea/ftm_kea.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSF/platform/kea/mfs_spi.o: ../MSF/platform/kea/mfs_spi.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/platform/kea/mfs_spi.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/platform/kea/mfs_spi.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSF/platform/kea/msf.o: ../MSF/platform/kea/msf.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/platform/kea/msf.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/platform/kea/msf.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSF/platform/kea/msf_analog.o: ../MSF/platform/kea/msf_analog.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/platform/kea/msf_analog.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/platform/kea/msf_analog.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSF/platform/kea/spi_kea.o: ../MSF/platform/kea/spi_kea.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/platform/kea/spi_kea.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/platform/kea/spi_kea.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSF/platform/kea/uart_kea.o: ../MSF/platform/kea/uart_kea.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@MSF/platform/kea/uart_kea.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "MSF/platform/kea/uart_kea.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


