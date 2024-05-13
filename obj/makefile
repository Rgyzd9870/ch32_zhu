################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ui/screens/subdir.mk
-include ui/images/subdir.mk
-include ui/fonts/subdir.mk
-include ui/components/subdir.mk
-include ui/subdir.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include LVGL/src/widgets/subdir.mk
-include LVGL/src/misc/subdir.mk
-include LVGL/src/hal/subdir.mk
-include LVGL/src/font/subdir.mk
-include LVGL/src/extra/widgets/win/subdir.mk
-include LVGL/src/extra/widgets/tileview/subdir.mk
-include LVGL/src/extra/widgets/tabview/subdir.mk
-include LVGL/src/extra/widgets/spinner/subdir.mk
-include LVGL/src/extra/widgets/spinbox/subdir.mk
-include LVGL/src/extra/widgets/span/subdir.mk
-include LVGL/src/extra/widgets/msgbox/subdir.mk
-include LVGL/src/extra/widgets/meter/subdir.mk
-include LVGL/src/extra/widgets/menu/subdir.mk
-include LVGL/src/extra/widgets/list/subdir.mk
-include LVGL/src/extra/widgets/led/subdir.mk
-include LVGL/src/extra/widgets/keyboard/subdir.mk
-include LVGL/src/extra/widgets/imgbtn/subdir.mk
-include LVGL/src/extra/widgets/colorwheel/subdir.mk
-include LVGL/src/extra/widgets/chart/subdir.mk
-include LVGL/src/extra/widgets/calendar/subdir.mk
-include LVGL/src/extra/widgets/animimg/subdir.mk
-include LVGL/src/extra/themes/mono/subdir.mk
-include LVGL/src/extra/themes/default/subdir.mk
-include LVGL/src/extra/themes/basic/subdir.mk
-include LVGL/src/extra/others/snapshot/subdir.mk
-include LVGL/src/extra/others/msg/subdir.mk
-include LVGL/src/extra/others/monkey/subdir.mk
-include LVGL/src/extra/others/imgfont/subdir.mk
-include LVGL/src/extra/others/ime/subdir.mk
-include LVGL/src/extra/others/gridnav/subdir.mk
-include LVGL/src/extra/others/fragment/subdir.mk
-include LVGL/src/extra/libs/sjpg/subdir.mk
-include LVGL/src/extra/libs/rlottie/subdir.mk
-include LVGL/src/extra/libs/qrcode/subdir.mk
-include LVGL/src/extra/libs/png/subdir.mk
-include LVGL/src/extra/libs/gif/subdir.mk
-include LVGL/src/extra/libs/fsdrv/subdir.mk
-include LVGL/src/extra/libs/freetype/subdir.mk
-include LVGL/src/extra/libs/ffmpeg/subdir.mk
-include LVGL/src/extra/libs/bmp/subdir.mk
-include LVGL/src/extra/layouts/grid/subdir.mk
-include LVGL/src/extra/layouts/flex/subdir.mk
-include LVGL/src/extra/subdir.mk
-include LVGL/src/draw/sw/subdir.mk
-include LVGL/src/draw/sdl/subdir.mk
-include LVGL/src/draw/subdir.mk
-include LVGL/src/core/subdir.mk
-include LVGL/examples/porting/subdir.mk
-include LVGL/demos/stress/subdir.mk
-include Hardware/Timer6/subdir.mk
-include Hardware/LCD/subdir.mk
-include Hardware/KEY/subdir.mk
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
LVGL.hex \

SECONDARY_LIST += \
LVGL.lst \

SECONDARY_SIZE += \
LVGL.siz \


# 所有目标
all: LVGL.elf secondary-outputs

# 工具调用
LVGL.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "E:\新桌面\学习资料\沁恒\myself\LVGL\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"LVGL.map" --specs=nano.specs --specs=nosys.specs -o "LVGL.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
LVGL.hex: LVGL.elf
	@	riscv-none-embed-objcopy -O ihex "LVGL.elf"  "LVGL.hex"
	@	@
LVGL.lst: LVGL.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "LVGL.elf" > "LVGL.lst"
	@	@
LVGL.siz: LVGL.elf
	@	riscv-none-embed-size --format=berkeley "LVGL.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) LVGL.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
