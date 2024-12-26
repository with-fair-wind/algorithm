file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp inc/*.h)
add_executable(main ${srcs})
target_include_directories(main PUBLIC inc)

target_link_libraries(main PUBLIC algorithm)