file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp inc/*.h)
add_library(algorithm STATIC ${srcs})
target_include_directories(algorithm PUBLIC inc)