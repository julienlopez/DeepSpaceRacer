cmake_minimum_required(VERSION 2.8)
project(DeepSpaceRacer CXX)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.14/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(REQUIRES boost/1.70.0@conan/stable BASIC_SETUP BUILD missing)
conan_cmake_run(REQUIRES Catch2/2.7.2@catchorg/stable BASIC_SETUP BUILD missing)
				
include_directories(3rd_party/range)
include_directories(3rd_party/expected)
include_directories(3rd_party/GSL/include)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	message("using visual")
	add_compile_options("/std:c++latest")
	add_definitions("-DBOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE")
else()
	message("using ${CMAKE_CXX_COMPILER_ID}")
	add_definitions("-std=c++17")
	add_definitions("-fprofile-arcs")
	add_definitions("-ftest-coverage")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage" )
endif()

add_subdirectory(lib)
add_subdirectory(unit_tests)
add_subdirectory(gui)
