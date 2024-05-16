################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/core_riscv.c 

OBJS += \
./Core/core_riscv.o 

C_DEPS += \
./Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/%.o: ../Core/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\������\��ʱ�Ķ�\esp8266\githubCH32�ļ�\ch32_zhu\esp8266\Debug" -I"E:\������\��ʱ�Ķ�\esp8266\githubCH32�ļ�\ch32_zhu\esp8266\Core" -I"E:\������\��ʱ�Ķ�\esp8266\githubCH32�ļ�\ch32_zhu\esp8266\User" -I"E:\������\��ʱ�Ķ�\esp8266\githubCH32�ļ�\ch32_zhu\esp8266\Peripheral\inc" -I"E:\������\��ʱ�Ķ�\esp8266\githubCH32�ļ�\ch32_zhu\esp8266\Hardware" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

