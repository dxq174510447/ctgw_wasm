################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/seclang.cpp 

OBJS += \
./src/seclang.o 

CPP_DEPS += \
./src/seclang.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	clang++ -std=c++17 -stdlib=libc++ -lprotobuf -I/Users/dengxiaoqian/data/github/Cylix/cpp_redis/includes -I/Users/dengxiaoqian/data/github/proxy-wasm/proxy-wasm-cpp-sdk -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


