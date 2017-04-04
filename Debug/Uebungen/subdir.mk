################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Uebungen/intToBin.c \
../Uebungen/menu.c \
../Uebungen/reverse.c 

OBJS += \
./Uebungen/intToBin.o \
./Uebungen/menu.o \
./Uebungen/reverse.o 

C_DEPS += \
./Uebungen/intToBin.d \
./Uebungen/menu.d \
./Uebungen/reverse.d 


# Each subdirectory must supply rules for building sources it contributes
Uebungen/%.o: ../Uebungen/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -I"C:\Projects\mc\src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


