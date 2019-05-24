include_directories(".")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE SOURCE_FILES ./*)
add_executable(unit_tests ${SOURCE_FILES})

target_link_libraries(unit_tests ${CONAN_LIBS})
