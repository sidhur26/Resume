################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../HugeInteger.cpp \
../Lab1&2.cpp \
../TestHugeInteger.cpp 

OBJS += \
./HugeInteger.o \
./Lab1&2.o \
./TestHugeInteger.o 

CPP_DEPS += \
./HugeInteger.d \
./Lab1&2.d \
./TestHugeInteger.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1z -I"/Users/raulsidhu/Downloads/boost_1_78_0 2" -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


