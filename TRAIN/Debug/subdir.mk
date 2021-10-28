################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../H7SEG_FIRST_program.c \
../H7SEG_SECOND_program.c \
../MADC_program.c \
../MDIO_program.c \
../MGIE_Program.c \
../MTIMER0_projram.c \
../MUART_program.c \
../main.c 

OBJS += \
./H7SEG_FIRST_program.o \
./H7SEG_SECOND_program.o \
./MADC_program.o \
./MDIO_program.o \
./MGIE_Program.o \
./MTIMER0_projram.o \
./MUART_program.o \
./main.o 

C_DEPS += \
./H7SEG_FIRST_program.d \
./H7SEG_SECOND_program.d \
./MADC_program.d \
./MDIO_program.d \
./MGIE_Program.d \
./MTIMER0_projram.d \
./MUART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


