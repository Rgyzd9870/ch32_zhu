################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Debug/debug.c 

OBJS += \
./Debug/debug.o 

C_DEPS += \
./Debug/debug.d 


# Each subdirectory must supply rules for building sources it contributes
Debug/%.o: ../Debug/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\新桌面\临时改动\esp8266\ch32_zhu\Debug" -I"E:\新桌面\临时改动\esp8266\ch32_zhu\Core" -I"E:\新桌面\临时改动\esp8266\ch32_zhu\User" -I"E:\新桌面\临时改动\esp8266\ch32_zhu\Peripheral\inc" -I"E:\新桌面\临时改动\esp8266\ch32_zhu\Hardware" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

