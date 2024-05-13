################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ui/screens/ui_Screen1.c 

OBJS += \
./ui/screens/ui_Screen1.o 

C_DEPS += \
./ui/screens/ui_Screen1.d 


# Each subdirectory must supply rules for building sources it contributes
ui/screens/%.o: ../ui/screens/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Debug" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Core" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\User" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Peripheral\inc" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Hardware\KEY" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Hardware\LCD" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Hardware\Timer6" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\examples" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\src" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\examples\porting" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\demos" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\demos\stress" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\components" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\fonts" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\images" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\screens" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

