################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include Hardware/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
esp8266_onenet.hex \

SECONDARY_LIST += \
esp8266_onenet.lst \

SECONDARY_SIZE += \
esp8266_onenet.siz \


# 所有目标
all: esp8266_onenet.elf secondary-outputs

# 工具调用
esp8266_onenet.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "E:\新桌面\临时改动\esp8266\githubCH32文件\ch32_zhu\esp8266\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"esp8266_onenet.map" --specs=nano.specs --specs=nosys.specs -o "esp8266_onenet.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
esp8266_onenet.hex: esp8266_onenet.elf
	@	riscv-none-embed-objcopy -O ihex "esp8266_onenet.elf"  "esp8266_onenet.hex"
	@	@
esp8266_onenet.lst: esp8266_onenet.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "esp8266_onenet.elf" > "esp8266_onenet.lst"
	@	@
esp8266_onenet.siz: esp8266_onenet.elf
	@	riscv-none-embed-size --format=berkeley "esp8266_onenet.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) esp8266_onenet.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
