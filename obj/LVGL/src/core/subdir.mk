################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/core/lv_disp.c \
../LVGL/src/core/lv_event.c \
../LVGL/src/core/lv_group.c \
../LVGL/src/core/lv_indev.c \
../LVGL/src/core/lv_indev_scroll.c \
../LVGL/src/core/lv_obj.c \
../LVGL/src/core/lv_obj_class.c \
../LVGL/src/core/lv_obj_draw.c \
../LVGL/src/core/lv_obj_pos.c \
../LVGL/src/core/lv_obj_scroll.c \
../LVGL/src/core/lv_obj_style.c \
../LVGL/src/core/lv_obj_style_gen.c \
../LVGL/src/core/lv_obj_tree.c \
../LVGL/src/core/lv_refr.c \
../LVGL/src/core/lv_theme.c 

OBJS += \
./LVGL/src/core/lv_disp.o \
./LVGL/src/core/lv_event.o \
./LVGL/src/core/lv_group.o \
./LVGL/src/core/lv_indev.o \
./LVGL/src/core/lv_indev_scroll.o \
./LVGL/src/core/lv_obj.o \
./LVGL/src/core/lv_obj_class.o \
./LVGL/src/core/lv_obj_draw.o \
./LVGL/src/core/lv_obj_pos.o \
./LVGL/src/core/lv_obj_scroll.o \
./LVGL/src/core/lv_obj_style.o \
./LVGL/src/core/lv_obj_style_gen.o \
./LVGL/src/core/lv_obj_tree.o \
./LVGL/src/core/lv_refr.o \
./LVGL/src/core/lv_theme.o 

C_DEPS += \
./LVGL/src/core/lv_disp.d \
./LVGL/src/core/lv_event.d \
./LVGL/src/core/lv_group.d \
./LVGL/src/core/lv_indev.d \
./LVGL/src/core/lv_indev_scroll.d \
./LVGL/src/core/lv_obj.d \
./LVGL/src/core/lv_obj_class.d \
./LVGL/src/core/lv_obj_draw.d \
./LVGL/src/core/lv_obj_pos.d \
./LVGL/src/core/lv_obj_scroll.d \
./LVGL/src/core/lv_obj_style.d \
./LVGL/src/core/lv_obj_style_gen.d \
./LVGL/src/core/lv_obj_tree.d \
./LVGL/src/core/lv_refr.d \
./LVGL/src/core/lv_theme.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/core/%.o: ../LVGL/src/core/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Debug" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Core" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\User" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Peripheral\inc" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Hardware\KEY" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Hardware\LCD" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Hardware\Timer6" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\examples" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\src" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\examples\porting" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\demos" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\demos\stress" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\components" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\fonts" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\images" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\screens" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

