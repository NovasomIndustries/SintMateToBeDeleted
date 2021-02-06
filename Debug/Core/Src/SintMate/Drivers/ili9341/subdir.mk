################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/SintMate/Drivers/ili9341/fonts.c \
../Core/Src/SintMate/Drivers/ili9341/ili9341.c \
../Core/Src/SintMate/Drivers/ili9341/ili9341_background.c \
../Core/Src/SintMate/Drivers/ili9341/ili9341_calibrate_touch.c \
../Core/Src/SintMate/Drivers/ili9341/ili9341_touch.c 

OBJS += \
./Core/Src/SintMate/Drivers/ili9341/fonts.o \
./Core/Src/SintMate/Drivers/ili9341/ili9341.o \
./Core/Src/SintMate/Drivers/ili9341/ili9341_background.o \
./Core/Src/SintMate/Drivers/ili9341/ili9341_calibrate_touch.o \
./Core/Src/SintMate/Drivers/ili9341/ili9341_touch.o 

C_DEPS += \
./Core/Src/SintMate/Drivers/ili9341/fonts.d \
./Core/Src/SintMate/Drivers/ili9341/ili9341.d \
./Core/Src/SintMate/Drivers/ili9341/ili9341_background.d \
./Core/Src/SintMate/Drivers/ili9341/ili9341_calibrate_touch.d \
./Core/Src/SintMate/Drivers/ili9341/ili9341_touch.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/SintMate/Drivers/ili9341/fonts.o: ../Core/Src/SintMate/Drivers/ili9341/fonts.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Core/Inc/SintMate -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/SintMate/Drivers/ili9341/fonts.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/SintMate/Drivers/ili9341/ili9341.o: ../Core/Src/SintMate/Drivers/ili9341/ili9341.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Core/Inc/SintMate -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/SintMate/Drivers/ili9341/ili9341.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/SintMate/Drivers/ili9341/ili9341_background.o: ../Core/Src/SintMate/Drivers/ili9341/ili9341_background.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Core/Inc/SintMate -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/SintMate/Drivers/ili9341/ili9341_background.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/SintMate/Drivers/ili9341/ili9341_calibrate_touch.o: ../Core/Src/SintMate/Drivers/ili9341/ili9341_calibrate_touch.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Core/Inc/SintMate -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/SintMate/Drivers/ili9341/ili9341_calibrate_touch.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/SintMate/Drivers/ili9341/ili9341_touch.o: ../Core/Src/SintMate/Drivers/ili9341/ili9341_touch.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DSTM32H750xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Core/Inc/SintMate -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/SintMate/Drivers/ili9341/ili9341_touch.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

