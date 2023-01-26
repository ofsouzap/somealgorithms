cmake_minimum_required (VERSION 3.8)

project ("AlgorithmImplementations")

set (CMAKE_C_STANDARD 99)
set (CMAKE_CXX_STANDARD 11)

set( gtest_force_shared_crt ON CACHE BOOL "Always use msvcrt.dll" FORCE)

enable_testing ()

add_subdirectory ("googletest")

# Set include directories
include_directories ("sorting")

# Include sub-directories
add_subdirectory ("sorting")
add_subdirectory ("tests")
