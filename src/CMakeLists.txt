cmake_minimum_required(VERSION 3.12)

set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.c*")

add_executable(main "${SRC}")
pico_add_extra_outputs(main)
target_link_libraries(main
  PRIVATE
    pico_cyw43_arch_none  # A cyw43 library is needed to access wireless hardware and pico-w definitions
    pico_stdlib
)
target_compile_options(main PRIVATE
  -Wall     # All warnings
  -Werror   # All warnings are treated as errors
  -O3       # Optimize level 3
)

pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

target_include_directories(main
  PRIVATE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>")

# This copies the *.uf2 file to the install directory (dist) on install
install(
    DIRECTORY
        "${CMAKE_CURRENT_BINARY_DIR}/"
    DESTINATION
        "./"
    FILES_MATCHING PATTERN
        "*.uf2"
    PATTERN "CMakeFiles" EXCLUDE
    PATTERN "elf2uf2" EXCLUDE
)
