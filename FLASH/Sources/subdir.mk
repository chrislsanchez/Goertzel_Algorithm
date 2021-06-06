################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Events.c" \
"../Sources/Misc.c" \
"../Sources/goertzel.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/Events.c \
../Sources/Misc.c \
../Sources/goertzel.c \
../Sources/main.c \

OBJS += \
./Sources/Events_c.obj \
./Sources/Misc_c.obj \
./Sources/goertzel_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/Events_c.obj" \
"./Sources/Misc_c.obj" \
"./Sources/goertzel_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/Events_c.d \
./Sources/Misc_c.d \
./Sources/goertzel_c.d \
./Sources/main_c.d \

OBJS_OS_FORMAT += \
./Sources/Events_c.obj \
./Sources/Misc_c.obj \
./Sources/goertzel_c.obj \
./Sources/main_c.obj \

C_DEPS_QUOTED += \
"./Sources/Events_c.d" \
"./Sources/Misc_c.d" \
"./Sources/goertzel_c.d" \
"./Sources/main_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/Events.args" -o "Sources/Events_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Misc_c.obj: ../Sources/Misc.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/Misc.args" -o "Sources/Misc_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/goertzel_c.obj: ../Sources/goertzel.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/goertzel.args" -o "Sources/goertzel_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ColdFire Compiler'
	"$(CF_ToolsDirEnv)/mwccmcf" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


