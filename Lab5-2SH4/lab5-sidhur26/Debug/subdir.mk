################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../SLLNode.cpp \
../SLLSet.cpp \
../Test.cpp 

OBJS += \
./SLLNode.o \
./SLLSet.o \
./Test.o 

CPP_DEPS += \
./SLLNode.d \
./SLLSet.d \
./Test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1z -I"/Users/raulsidhu/Desktop/2SH4/LABS/Lab5/lab5-sidhur26/cute" -O0 -g3 -Wall -c -fmessage-length=0 -Wno-attributes -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


