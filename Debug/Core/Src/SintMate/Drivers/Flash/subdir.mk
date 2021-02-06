################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/SintMate/Drivers/Flash/SpiFlash.c \
../Core/Src/SintMate/Drivers/Flash/flash_manager.c 

OBJS += \
./Core/Src/SintMate/Drivers/Flash/SpiFlash.o \
./Core/Src/SintMate/Drivers/Flash/flash_manager.o 

C_DEPS += \
./Core/Src/SintMate/Drivers/Flash/SpiFlash.d \
./Core/Src/SintMate/Drivers/Flash/flash_manager.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SintMate/Drivers/Flash/SpiFlash.o: ../Core/Src/SintMate/Drivers/Flash/SpiFlash.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Core/Inc/SintMate -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/SintMate/Drivers/Flash/SpiFlash.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/SintMate/Drivers/Flash/flash_manager.o: ../Core/Src/SintMate/Drivers/Flash/flash_manager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Core/Inc/SintMate -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/SintMate/Drivers/Flash/flash_manager.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

