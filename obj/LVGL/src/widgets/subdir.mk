################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/widgets/lv_arc.c \
../LVGL/src/widgets/lv_bar.c \
../LVGL/src/widgets/lv_btn.c \
../LVGL/src/widgets/lv_btnmatrix.c \
../LVGL/src/widgets/lv_canvas.c \
../LVGL/src/widgets/lv_checkbox.c \
../LVGL/src/widgets/lv_dropdown.c \
../LVGL/src/widgets/lv_img.c \
../LVGL/src/widgets/lv_label.c \
../LVGL/src/widgets/lv_line.c \
../LVGL/src/widgets/lv_objx_templ.c \
../LVGL/src/widgets/lv_roller.c \
../LVGL/src/widgets/lv_slider.c \
../LVGL/src/widgets/lv_switch.c \
../LVGL/src/widgets/lv_table.c \
../LVGL/src/widgets/lv_textarea.c 

OBJS += \
./LVGL/src/widgets/lv_arc.o \
./LVGL/src/widgets/lv_bar.o \
./LVGL/src/widgets/lv_btn.o \
./LVGL/src/widgets/lv_btnmatrix.o \
./LVGL/src/widgets/lv_canvas.o \
./LVGL/src/widgets/lv_checkbox.o \
./LVGL/src/widgets/lv_dropdown.o \
./LVGL/src/widgets/lv_img.o \
./LVGL/src/widgets/lv_label.o \
./LVGL/src/widgets/lv_line.o \
./LVGL/src/widgets/lv_objx_templ.o \
./LVGL/src/widgets/lv_roller.o \
./LVGL/src/widgets/lv_slider.o \
./LVGL/src/widgets/lv_switch.o \
./LVGL/src/widgets/lv_table.o \
./LVGL/src/widgets/lv_textarea.o 

C_DEPS += \
./LVGL/src/widgets/lv_arc.d \
./LVGL/src/widgets/lv_bar.d \
./LVGL/src/widgets/lv_btn.d \
./LVGL/src/widgets/lv_btnmatrix.d \
./LVGL/src/widgets/lv_canvas.d \
./LVGL/src/widgets/lv_checkbox.d \
./LVGL/src/widgets/lv_dropdown.d \
./LVGL/src/widgets/lv_img.d \
./LVGL/src/widgets/lv_label.d \
./LVGL/src/widgets/lv_line.d \
./LVGL/src/widgets/lv_objx_templ.d \
./LVGL/src/widgets/lv_roller.d \
./LVGL/src/widgets/lv_slider.d \
./LVGL/src/widgets/lv_switch.d \
./LVGL/src/widgets/lv_table.d \
./LVGL/src/widgets/lv_textarea.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/widgets/%.o: ../LVGL/src/widgets/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Debug" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Core" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\User" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Peripheral\inc" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Hardware\KEY" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Hardware\LCD" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\Hardware\Timer6" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\examples" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\src" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\examples\porting" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\demos" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\LVGL\demos\stress" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\components" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\fonts" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\images" -I"E:\新桌面\学习资料\沁恒\myself\LVGL\ui\screens" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

