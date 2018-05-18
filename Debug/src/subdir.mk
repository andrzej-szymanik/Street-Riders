################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Audio.cpp \
../src/Background.cpp \
../src/Car.cpp \
../src/Controller.cpp \
../src/Engine.cpp \
../src/Game.cpp \
../src/Level.cpp \
../src/Map.cpp \
../src/Points.cpp \
../src/Star.cpp \
../src/Trap.cpp \
../src/Tree.cpp \
../src/main.cpp 

OBJS += \
./src/Audio.o \
./src/Background.o \
./src/Car.o \
./src/Controller.o \
./src/Engine.o \
./src/Game.o \
./src/Level.o \
./src/Map.o \
./src/Points.o \
./src/Star.o \
./src/Trap.o \
./src/Tree.o \
./src/main.o 

CPP_DEPS += \
./src/Audio.d \
./src/Background.d \
./src/Car.d \
./src/Controller.d \
./src/Engine.d \
./src/Game.d \
./src/Level.d \
./src/Map.d \
./src/Points.d \
./src/Star.d \
./src/Trap.d \
./src/Tree.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


