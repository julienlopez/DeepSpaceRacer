include_directories(".")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE SOURCE_FILES ./*)
add_library(lib ${SOURCE_FILES})

target_link_libraries(lib ${CONAN_LIBS})
