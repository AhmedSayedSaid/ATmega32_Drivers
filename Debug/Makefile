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
../HeaderFiles \
../HeaderFiles/Header_HAL/ \
../HeaderFiles/Header_MCAL/ \
../Helpers/ \
../Services/ \
../SourceFiles/Source_HAL/ \
../SourceFiles/Source_MCAL/ \
../tests \
../SourceFiles


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../main.c \
../Services/SPI_Services.c \
../Services/usart_services.c \
../SourceFiles/Source_HAL/LCD.c \
../SourceFiles/Source_MCAL/DIO.c \
../SourceFiles/Source_MCAL/DIO_CONFIG.c \
../SourceFiles/Source_MCAL/EEPROM.c \
../SourceFiles/Source_MCAL/EXT_INTERRUPT.c \
../SourceFiles/Source_MCAL/SPI.c \
../SourceFiles/Source_MCAL/Timers.c \
../SourceFiles/Source_MCAL/USART.c \
../SourceFiles/Source_MCAL/Watch_Dog.c \
../tests/DIO_Test.c \
../tests/EEPROM_Test.c \
../tests/EXT_Interrupt_test.c \
../tests/usart_test.c \
../tests/WDT_test.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
main.o \
Services/SPI_Services.o \
Services/usart_services.o \
SourceFiles/Source_HAL/LCD.o \
SourceFiles/Source_MCAL/DIO.o \
SourceFiles/Source_MCAL/DIO_CONFIG.o \
SourceFiles/Source_MCAL/EEPROM.o \
SourceFiles/Source_MCAL/EXT_INTERRUPT.o \
SourceFiles/Source_MCAL/SPI.o \
SourceFiles/Source_MCAL/Timers.o \
SourceFiles/Source_MCAL/USART.o \
SourceFiles/Source_MCAL/Watch_Dog.o \
tests/DIO_Test.o \
tests/EEPROM_Test.o \
tests/EXT_Interrupt_test.o \
tests/usart_test.o \
tests/WDT_test.o

OBJS_AS_ARGS +=  \
main.o \
Services/SPI_Services.o \
Services/usart_services.o \
SourceFiles/Source_HAL/LCD.o \
SourceFiles/Source_MCAL/DIO.o \
SourceFiles/Source_MCAL/DIO_CONFIG.o \
SourceFiles/Source_MCAL/EEPROM.o \
SourceFiles/Source_MCAL/EXT_INTERRUPT.o \
SourceFiles/Source_MCAL/SPI.o \
SourceFiles/Source_MCAL/Timers.o \
SourceFiles/Source_MCAL/USART.o \
SourceFiles/Source_MCAL/Watch_Dog.o \
tests/DIO_Test.o \
tests/EEPROM_Test.o \
tests/EXT_Interrupt_test.o \
tests/usart_test.o \
tests/WDT_test.o

C_DEPS +=  \
main.d \
Services/SPI_Services.d \
Services/usart_services.d \
SourceFiles/Source_HAL/LCD.d \
SourceFiles/Source_MCAL/DIO.d \
SourceFiles/Source_MCAL/DIO_CONFIG.d \
SourceFiles/Source_MCAL/EEPROM.d \
SourceFiles/Source_MCAL/EXT_INTERRUPT.d \
SourceFiles/Source_MCAL/SPI.d \
SourceFiles/Source_MCAL/Timers.d \
SourceFiles/Source_MCAL/USART.d \
SourceFiles/Source_MCAL/Watch_Dog.d \
tests/DIO_Test.d \
tests/EEPROM_Test.d \
tests/EXT_Interrupt_test.d \
tests/usart_test.d \
tests/WDT_test.d

C_DEPS_AS_ARGS +=  \
main.d \
Services/SPI_Services.d \
Services/usart_services.d \
SourceFiles/Source_HAL/LCD.d \
SourceFiles/Source_MCAL/DIO.d \
SourceFiles/Source_MCAL/DIO_CONFIG.d \
SourceFiles/Source_MCAL/EEPROM.d \
SourceFiles/Source_MCAL/EXT_INTERRUPT.d \
SourceFiles/Source_MCAL/SPI.d \
SourceFiles/Source_MCAL/Timers.d \
SourceFiles/Source_MCAL/USART.d \
SourceFiles/Source_MCAL/Watch_Dog.d \
tests/DIO_Test.d \
tests/EEPROM_Test.d \
tests/EXT_Interrupt_test.d \
tests/usart_test.d \
tests/WDT_test.d

OUTPUT_FILE_PATH +=XC8Application1.elf

OUTPUT_FILE_PATH_AS_ARGS +=XC8Application1.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Services/SPI_Services.o: ../Services/SPI_Services.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Services/usart_services.o: ../Services/usart_services.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

SourceFiles/Source_HAL/LCD.o: ../SourceFiles/Source_HAL/LCD.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

SourceFiles/Source_MCAL/DIO.o: ../SourceFiles/Source_MCAL/DIO.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

SourceFiles/Source_MCAL/DIO_CONFIG.o: ../SourceFiles/Source_MCAL/DIO_CONFIG.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

SourceFiles/Source_MCAL/EEPROM.o: ../SourceFiles/Source_MCAL/EEPROM.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

SourceFiles/Source_MCAL/EXT_INTERRUPT.o: ../SourceFiles/Source_MCAL/EXT_INTERRUPT.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

SourceFiles/Source_MCAL/SPI.o: ../SourceFiles/Source_MCAL/SPI.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

SourceFiles/Source_MCAL/Timers.o: ../SourceFiles/Source_MCAL/Timers.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

SourceFiles/Source_MCAL/USART.o: ../SourceFiles/Source_MCAL/USART.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

SourceFiles/Source_MCAL/Watch_Dog.o: ../SourceFiles/Source_MCAL/Watch_Dog.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

tests/DIO_Test.o: ../tests/DIO_Test.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

tests/EEPROM_Test.o: ../tests/EEPROM_Test.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

tests/EXT_Interrupt_test.o: ../tests/EXT_Interrupt_test.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

tests/usart_test.o: ../tests/usart_test.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

tests/WDT_test.o: ../tests/WDT_test.c
	@echo Building file: $<
	@echo Invoking: XC8 C Compiler : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE)  -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -c -x c -funsigned-char -funsigned-bitfields -mext=cci -D__ATmega32__ -DDEBUG  -I"../HeaderFiles/Header_MCAL" -I"../HeaderFiles/Header_HAL" -I"../Helpers" -I"../SourceFiles/Source_MCAL" -I"../SourceFiles/Source_HAL" -I".." -I"../Services"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
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
	@echo Invoking:  XC8 C Linker : 2.36
	$(QUOTE)C:\Program Files\Microchip\xc8\v2.36\bin\xc8-cc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -mcpu=ATmega32  -mdfp="C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.7.374\xc8"  -Wl,-Map="XC8Application1.map" -funsigned-char -funsigned-bitfields -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums --memorysummary,memoryfile.xml  
	@echo Finished building target: $@
	"C:\Program Files\Microchip\xc8\v2.36\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "XC8Application1.elf" "XC8Application1.hex"
	"C:\Program Files\Microchip\xc8\v2.36\bin\avr-objcopy.exe" -j .eeprom --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0 --no-change-warnings -O ihex "XC8Application1.elf" "XC8Application1.eep" || exit 0
	"C:\Program Files\Microchip\xc8\v2.36\bin\avr-objdump.exe" -h -S "XC8Application1.elf" > "XC8Application1.lss"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "XC8Application1.elf" "XC8Application1.hex" "XC8Application1.eep" "XC8Application1.map" "XC8Application1.usersignatures" "XC8Application1.a"  "XC8Application1.lss"
	