################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Drivers


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../ByggernG46.c \
../Drivers/adc.c \
../Drivers/FontBB.c \
../Drivers/intro.c \
../Drivers/menu.c \
../Drivers/Oled.c \
../Drivers/SPI_driver.c \
../Drivers/SRAM.c \
../Drivers/uart.c \
../Drivers/USBMFC.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
ByggernG46.o \
Drivers/adc.o \
Drivers/FontBB.o \
Drivers/intro.o \
Drivers/menu.o \
Drivers/Oled.o \
Drivers/SPI_driver.o \
Drivers/SRAM.o \
Drivers/uart.o \
Drivers/USBMFC.o

OBJS_AS_ARGS +=  \
ByggernG46.o \
Drivers/adc.o \
Drivers/FontBB.o \
Drivers/intro.o \
Drivers/menu.o \
Drivers/Oled.o \
Drivers/SPI_driver.o \
Drivers/SRAM.o \
Drivers/uart.o \
Drivers/USBMFC.o

C_DEPS +=  \
ByggernG46.d \
Drivers/adc.d \
Drivers/FontBB.d \
Drivers/intro.d \
Drivers/menu.d \
Drivers/Oled.d \
Drivers/SPI_driver.d \
Drivers/SRAM.d \
Drivers/uart.d \
Drivers/USBMFC.d

C_DEPS_AS_ARGS +=  \
ByggernG46.d \
Drivers/adc.d \
Drivers/FontBB.d \
Drivers/intro.d \
Drivers/menu.d \
Drivers/Oled.d \
Drivers/SPI_driver.d \
Drivers/SRAM.d \
Drivers/uart.d \
Drivers/USBMFC.d

OUTPUT_FILE_PATH +=ByggernG46.elf

OUTPUT_FILE_PATH_AS_ARGS +=ByggernG46.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler





















./%.o: .././%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega162 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Drivers/%.o: ../Drivers/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega162 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="ByggernG46.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega162  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "ByggernG46.elf" "ByggernG46.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "ByggernG46.elf" "ByggernG46.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "ByggernG46.elf" > "ByggernG46.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "ByggernG46.elf" "ByggernG46.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-size.exe" "ByggernG46.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "ByggernG46.elf" "ByggernG46.a" "ByggernG46.hex" "ByggernG46.lss" "ByggernG46.eep" "ByggernG46.map" "ByggernG46.srec" "ByggernG46.usersignatures"
	