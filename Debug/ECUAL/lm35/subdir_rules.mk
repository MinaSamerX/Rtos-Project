################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
ECUAL/lm35/%.obj: ../ECUAL/lm35/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/apps/codecompser/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="E:/adv embedded/3.Rtos/demo/freertos_demo" --include_path="E:/adv embedded/3.Rtos/demo/freertos_demo/MCAL" --include_path="E:/adv embedded/3.Rtos/demo/freertos_demo/MCAL/GPTM" --include_path="E:/adv embedded/3.Rtos/demo/freertos_demo/MCAL/UART" --include_path="E:/adv embedded/3.Rtos/demo/freertos_demo/FreeRTOS/Source/include" --include_path="E:/adv embedded/3.Rtos/demo/freertos_demo/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="E:/apps/codecompser/ccs/tools/compiler/ti-cgt-arm_20.2.7.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="ECUAL/lm35/$(basename $(<F)).d_raw" --obj_directory="ECUAL/lm35" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


