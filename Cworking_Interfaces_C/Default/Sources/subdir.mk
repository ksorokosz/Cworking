################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/CW_Interface_Main.c \
../Sources/CW_Interface_PersonalData.c 

OBJS += \
./Sources/CW_Interface_Main.o \
./Sources/CW_Interface_PersonalData.o 

C_DEPS += \
./Sources/CW_Interface_Main.d \
./Sources/CW_Interface_PersonalData.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/kamil/workspace/Cworking/Cworking_Interfaces_C/Headers" -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


