cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME Lab01_LCD)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)
#Thêm thư mục module vào hệ thống build
add_subdirectory(Components/LCD1602)
#Thêm thư mục module vào hệ thống build
add_subdirectory(Components/LED7)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths

)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    Components/LCD1602/Src/lcd1602.c
    Components/LED7/Src/led7.c
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
    Components/LCD1602/Inc
    Components/LED7/Inc
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
    # Add user defined libraries
    # Link thư viện LCD1602 vào chương trình chính
    LCD1602
    LED7
)
# config to export .hex and .bin
if(CMAKE_OBJCOPY)
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${CMAKE_PROJECT_NAME}> "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.hex"
        COMMENT "--> Dang khoi tao file HEX tai: ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.hex"
    )

    # Lệnh sinh file .bin (nếu sau này bạn cần dùng nạp qua bootloader)
    add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${CMAKE_PROJECT_NAME}> "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.bin"
        COMMENT "--> Dang khoi tao file BIN tai: ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.bin"
    )
else()
    message(WARNING "Khong tim thay CMAKE_OBJCOPY. Vui long kiem tra lai Toolchain compiler!")
endif()
