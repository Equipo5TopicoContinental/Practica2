################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/light_out.c" \
"../Sources/light_sensor.c" \
"../Sources/lights.c" \
"../Sources/main.c" \
"../Sources/sa_mtb.c" \
"../Sources/selector.c" \

C_SRCS += \
../Sources/light_out.c \
../Sources/light_sensor.c \
../Sources/lights.c \
../Sources/main.c \
../Sources/sa_mtb.c \
../Sources/selector.c \

OBJS += \
./Sources/light_out.o \
./Sources/light_sensor.o \
./Sources/lights.o \
./Sources/main.o \
./Sources/sa_mtb.o \
./Sources/selector.o \

C_DEPS += \
./Sources/light_out.d \
./Sources/light_sensor.d \
./Sources/lights.d \
./Sources/main.d \
./Sources/sa_mtb.d \
./Sources/selector.d \

OBJS_QUOTED += \
"./Sources/light_out.o" \
"./Sources/light_sensor.o" \
"./Sources/lights.o" \
"./Sources/main.o" \
"./Sources/sa_mtb.o" \
"./Sources/selector.o" \

C_DEPS_QUOTED += \
"./Sources/light_out.d" \
"./Sources/light_sensor.d" \
"./Sources/lights.d" \
"./Sources/main.d" \
"./Sources/sa_mtb.d" \
"./Sources/selector.d" \

OBJS_OS_FORMAT += \
./Sources/light_out.o \
./Sources/light_sensor.o \
./Sources/lights.o \
./Sources/main.o \
./Sources/sa_mtb.o \
./Sources/selector.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/light_out.o: ../Sources/light_out.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/light_out.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/light_out.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/light_sensor.o: ../Sources/light_sensor.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/light_sensor.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/light_sensor.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/lights.o: ../Sources/lights.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/lights.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/lights.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sa_mtb.o: ../Sources/sa_mtb.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sa_mtb.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sa_mtb.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/selector.o: ../Sources/selector.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/selector.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/selector.o"
	@echo 'Finished building: $<'
	@echo ' '


