################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ctgw_wasm.cpp 

OBJS += \
./src/ctgw_wasm.o 

CPP_DEPS += \
./src/ctgw_wasm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	clang++ -std=c++17 -stdlib=libc++ -lprotobuf -I/Users/dengxiaoqian/data/github/proxy-wasm/proxy-wasm-cpp-sdk -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


