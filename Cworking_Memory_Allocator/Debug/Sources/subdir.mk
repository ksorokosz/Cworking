################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/CW_Memory_Allocator_Main.c \
../Sources/CW_Memory_Allocator_Memory_Management.c 

OBJS += \
./Sources/CW_Memory_Allocator_Main.o \
./Sources/CW_Memory_Allocator_Memory_Management.o 

C_DEPS += \
./Sources/CW_Memory_Allocator_Main.d \
./Sources/CW_Memory_Allocator_Memory_Management.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -DDEBUG_MODE -I"/home/kamil/workspace/Cworking/Cworking_Memory_Allocator/Headers" -O0 -g3 -pedantic -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


