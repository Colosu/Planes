################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Fuentes.cpp \
../Map.cpp \
../Planes.cpp \
../Sprite.cpp \
../Texturas.cpp \
../Ventana.cpp \
../Vista.cpp \
../main.cpp 

OBJS += \
./Fuentes.o \
./Map.o \
./Planes.o \
./Sprite.o \
./Texturas.o \
./Ventana.o \
./Vista.o \
./main.o 

CPP_DEPS += \
./Fuentes.d \
./Map.d \
./Planes.d \
./Sprite.d \
./Texturas.d \
./Ventana.d \
./Vista.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


