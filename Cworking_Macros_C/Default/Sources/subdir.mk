################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/CW_Interface_Main.c \
../Sources/CW_Interface_PersonalData.c \
../Sources/CW_Macros_Definitions.c 

OBJS += \
./Sources/CW_Interface_Main.o \
./Sources/CW_Interface_PersonalData.o \
./Sources/CW_Macros_Definitions.o 

C_DEPS += \
./Sources/CW_Interface_Main.d \
./Sources/CW_Interface_PersonalData.d \
./Sources/CW_Macros_Definitions.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DDEBUG_MODE -I"/home/kamil/workspace/Cworking/Cworking_Macros_C/Headers" -O2 -g -pedantic -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


