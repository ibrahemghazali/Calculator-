cmake_minimum_required(VERSION 4.2)
project(calculator_project C)
set(CMAKE_SYSTEM_NAME GENERIC) #to set the compiler to be cross not native compilation ( it won't run on this machine)
set(CMAKE_C_COMPILER avr-gcc CACHE STRING "C compiler" FORCE) #force the compiler to be gcc 
set(CMAKE_CXX_COMPILER avr-g++ CACHE STRING "CPP compiler" FORCE) #force the compiler to be g++ ( if cpp build)
set(CMAKE_OBJCOPY avr-objcopy CACHE STRING "avr-objcopy" FORCE )



file(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.c)
list(FILTER SRCS EXCLUDE REGEX "^build/")
message("${SRCS}")
string(REGEX REPLACE "^build/[^;]+;?" "" SRCS "${SRCS}")
message("${SRCS}")

add_executable(${PROJECT_NAME}.elf ${SRCS})
target_compile_options(${PROJECT_NAME}.elf PUBLIC 
    -mmcu=atmega32 -DF_CPU=8000000UL -Os -ffunction-sections -fdata-sections
)
target_link_options(${PROJECT_NAME}.elf PUBLIC 
    -Wl,--gc-sections
)


add_custom_target(FLASH 
    DEPENDS ${PROJECT_NAME}.elf
    COMMAND ${CMAKE_OBJCOPY} -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
)


add_custom_target(burn 
    DEPENDS FLASH
    COMMAND avrdude -c usbasp -p m32 -b 19200 -U lfuse:w:0x84:m -U hfuse:w:0x99:m -U flash:w:${PROJECT_NAME}.hex:i
)