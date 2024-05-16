################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32v30x_it.c \
../User/main.c \
../User/system_ch32v30x.c 

OBJS += \
./User/ch32v30x_it.o \
./User/main.o \
./User/system_ch32v30x.o 

C_DEPS += \
./User/ch32v30x_it.d \
./User/main.d \
./User/system_ch32v30x.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\新桌面\临时改动\esp8266\githubCH32文件\ch32_zhu\esp8266\Debug" -I"E:\新桌面\临时改动\esp8266\githubCH32文件\ch32_zhu\esp8266\Core" -I"E:\新桌面\临时改动\esp8266\githubCH32文件\ch32_zhu\esp8266\User" -I"E:\新桌面\临时改动\esp8266\githubCH32文件\ch32_zhu\esp8266\Peripheral\inc" -I"E:\新桌面\临时改动\esp8266\githubCH32文件\ch32_zhu\esp8266\Hardware" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

