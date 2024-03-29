#THIS FILE IS AUTO GENERATED FROM THE TEMPLATE! DO NOT CHANGE!
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.25)

# specify cross-compilers and tools
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER  arm-none-eabi-gcc)
set(CMAKE_AR arm-none-eabi-ar)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CPU cortex-m7)
set(USB on)

set(CMAKE_VERBOSE_MAKEFILE on)
set(INTERMEDIATE off)

# project settings
project(LatheCPP7H C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

#Uncomment for hardware floating point
add_compile_definitions(ARM_MATH_CM4;ARM_MATH_MATRIX_CHECK;ARM_MATH_ROUNDING)
add_compile_definitions(CFG_TUSB_MCU=306)
add_compile_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)
add_link_options(-mfloat-abi=hard -mfpu=fpv4-sp-d16)

#Uncomment for software floating point
#add_compile_options(-mfloat-abi=soft)

add_compile_options(-mcpu=${CPU} -mthumb -mthumb-interwork)
add_compile_options(-ffunction-sections -fdata-sections -fno-common -fmessage-length=0)
add_compile_options(-fno-move-loop-invariants --save-temps)

# uncomment to mitigate c++17 absolute addresses warnings
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-register")

# Enable assembler files preprocessing
add_compile_options($<$<COMPILE_LANGUAGE:ASM>:-x$<SEMICOLON>assembler-with-cpp>)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    message(STATUS "Maximum optimization for speed")
    add_compile_options(-Ofast)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "RelWithDebInfo")
    message(STATUS "Maximum optimization for speed, debug info included")
    add_compile_options(-Ofast -g)
elseif ("${CMAKE_BUILD_TYPE}" STREQUAL "MinSizeRel")
    message(STATUS "Maximum optimization for size")
    add_compile_options(-Os)
else ()
    message(STATUS "Minimal optimization, debug info included")
    add_compile_options(-Og -g)
endif ()

include_directories(Inc
	Drivers/STM32H7xx_HAL_Driver/Inc
	Drivers/STM32h7xx_HAL_Driver/Inc/Legacy
	Drivers/CMSIS/Device/ST/STM32H7xx/Include
	Drivers/CMSIS/Include
)

include_directories(../LatheCPP/include)

if (${USB})

add_definitions(-DUSB)

include_directories(
        ../USBx/hw
        ../USBx/hw/bsp/stm32h7
        ../USBx/hw/bsp/stm32h7/boards/stm32h743nucleo
        ../USBx/project
        ../USBx/src
        ../USBx/hw/bsp
)

endif ()

add_definitions()
add_definitions(-DSTM32H7 -DSTM32H743xx -DNUCLEOH743 -DLATHE_CPP -DCLION)

file(GLOB_RECURSE SOURCES
	"Startup/*.*"
	"Src/*.*"
	"Drivers/*.*"
	)

set(SOURCES1
	../LatheCPP/lathe_src/arc.cpp
	../LatheCPP/lathe_src/encoder.cpp
	../LatheCPP/lathe_src/getSP.s
	../LatheCPP/lathe_src/i2cx.cpp
	../LatheCPP/lathe_src/interrupts.cpp
	../LatheCPP/lathe_src/lathe.cpp
	../LatheCPP/lathe_src/latheX.cpp
	../LatheCPP/lathe_src/lcd.cpp
	../LatheCPP/lathe_src/lclcmd.cpp
	../LatheCPP/lathe_src/lclcmdX.cpp
	../LatheCPP/lathe_src/mainLoop.cpp
	../LatheCPP/lathe_src/pid.cpp
	../LatheCPP/lathe_src/pidAutoTune.cpp
	../LatheCPP/lathe_src/remcmd.cpp
	../LatheCPP/lathe_src/remfunc.cpp
	../LatheCPP/lathe_src/remvar.cpp
	../LatheCPP/lathe_src/serialio.cpp
	../LatheCPP/lathe_src/spix.cpp
	../LatheCPP/lathe_src/stm32Info.cpp
	../LatheCPP/lathe_src/xcontrol.cpp
	../LatheCPP/lathe_src/zcontrol.cpp
	)

if (${USB})

set(SOURCES2
        ../USBx/project/usb_descriptors.c
        ../USBx/project/trace.c
        ../USBx/src/tusb.c
        ../USBx/src/common/tusb_fifo.c
        ../USBx/src/class/cdc/cdc_device.c
        ../USBx/src/device/usbd.c
        ../USBx/src/device/usbd_control.c
        ../USBx/src/portable/synopsys/dwc2/dcd_dwc2.c
)

else ()
set(SOURCES2)
endif ()

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32H743ZITX_FLASH.ld)

add_link_options(-Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map)
add_link_options(-Wl,--no-warn-rwx-segments)
add_link_options(-mcpu=${CPU} -mthumb -mthumb-interwork)
add_link_options(-T ${LINKER_SCRIPT})

add_executable(${PROJECT_NAME}.elf ${SOURCES} ${SOURCES1} ${SOURCES2} ${LINKER_SCRIPT})

if(INTERMEDIATE)
foreach(SRC_ IN LISTS SOURCES1)
    get_filename_component(SRC_BASENAME_ ${SRC_} NAME_WE)
    set_source_files_properties(${SRC_} PROPERTIES COMPILE_OPTIONS "-Wa,-adhlns=${SRC_BASENAME_}.lst")
    get_source_file_property(SRC_PROP_ ${SRC_} COMPILE_OPTIONS)
    message(STATUS "${SRC_}: ${SRC_PROP_}")
endforeach()
endif()

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE}
Building ${BIN_FILE}")
