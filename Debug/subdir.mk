################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Fahrrad.cpp \
../Fahrzeug.cpp \
../GlobaleUhr.cpp \
../Pkw.cpp \
../main.cpp 

CPP_DEPS += \
./Fahrrad.d \
./Fahrzeug.d \
./GlobaleUhr.d \
./Pkw.d \
./main.d 

OBJS += \
./Fahrrad.o \
./Fahrzeug.o \
./GlobaleUhr.o \
./Pkw.o \
./main.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++17 -I/Users/marcd/boost/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Fahrrad.d ./Fahrrad.o ./Fahrzeug.d ./Fahrzeug.o ./GlobaleUhr.d ./GlobaleUhr.o ./Pkw.d ./Pkw.o ./main.d ./main.o

.PHONY: clean--2e-

