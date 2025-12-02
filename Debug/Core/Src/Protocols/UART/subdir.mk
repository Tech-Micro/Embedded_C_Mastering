################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Protocols/UART/Uart.c 

OBJS += \
./Core/Src/Protocols/UART/Uart.o 

C_DEPS += \
./Core/Src/Protocols/UART/Uart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Protocols/UART/%.o: ../Core/Src/Protocols/UART/%.c Core/Src/Protocols/UART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"D:/One_drive/OneDrive/Tech_Micro/Personal/Complete_Embedded_C/Mastering_In_Embedded_C/Middlewares/Third_Party/SEGGER/Config" -I"D:/One_drive/OneDrive/Tech_Micro/Personal/Complete_Embedded_C/Mastering_In_Embedded_C/Middlewares/Third_Party/SEGGER/OS" -I"D:/One_drive/OneDrive/Tech_Micro/Personal/Complete_Embedded_C/Mastering_In_Embedded_C/Middlewares/Third_Party/SEGGER/SEGGER" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Protocols-2f-UART

clean-Core-2f-Src-2f-Protocols-2f-UART:
	-$(RM) ./Core/Src/Protocols/UART/Uart.d ./Core/Src/Protocols/UART/Uart.o

.PHONY: clean-Core-2f-Src-2f-Protocols-2f-UART

