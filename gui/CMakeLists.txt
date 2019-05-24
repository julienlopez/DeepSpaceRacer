include_directories(".")

file(GLOB_RECURSE SOURCE_FILES ./*)
add_executable(DeepSpaceRacer ${SOURCE_FILES})
