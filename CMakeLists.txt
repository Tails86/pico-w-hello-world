cmake_minimum_required(VERSION 3.12)

set(CMAKE_VERBOSE_MAKEFILE ON)

if (NOT DEFINED PICO_SDK_PATH AND NOT DEFINED ENV{PICO_SDK_PATH})
  message(FATAL_ERROR "PICO_SDK_PATH not defined; either execute:\ngit submodule update --recursive --init\nor set PICO_SDK_PATH in environment")
elseif (NOT DEFINED PICO_SDK_PATH AND DEFINED ENV{PICO_SDK_PATH})
  message(STATUS "Setting PICO_SDK_PATH from environment: $ENV{PICO_SDK_PATH}")
  set(PICO_SDK_PATH "$ENV{PICO_SDK_PATH}")
endif ()

set(PICO_BOARD pico_w)
set(PICO_PLATFORM rp2040)
set(PICO_COMPILER pico_arm_gcc)

include("${PICO_SDK_PATH}/external/pico_sdk_import.cmake")

project(pico-w-hello-world)

pico_sdk_init()

add_subdirectory(src)
