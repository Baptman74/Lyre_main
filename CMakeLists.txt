cmake_minimum_required(VERSION 3.18)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include($ENV{PICO_SDK_PATH}/tools/CMakeLists.txt)

project(main C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()


add_executable (main
	main.cpp
	)

target_link_libraries(main
	pico_stdlib
	hardware_dma
	pico_time
	hardware_clocks
	pico_runtime
	pico_standard_link
	hardware_adc
	hardware_pwm
	motor_ctrl
)

pico_enable_stdio_usb(main
	1
	)
pico_enable_stdio_uart(main
	0
	)

pico_add_extra_outputs(main)
