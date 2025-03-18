project(algorithm)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS inc/*.h)
add_library(${PROJECT_NAME} SHARED ${SRCS})

target_precompile_headers(${PROJECT_NAME} PUBLIC inc/stdafx.h)
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc> # 构建时使用源码目录
    $<INSTALL_INTERFACE:include>)

set(INCLUDE_INSTALL_DIR include)
set(LIB_INSTALL_DIR lib)
set(BIN_INSTALL_DIR bin)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-target
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
install(
    EXPORT ${PROJECT_NAME}-target
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE KT:: # 目标命名空间（如 MyLibrary::MyLibrary）
    DESTINATION lib/cmake/${PROJECT_NAME}
)

install(
    DIRECTORY inc/ # 源目录
    DESTINATION include # 目标安装目录
    FILES_MATCHING # 只安装匹配的文件
    PATTERN "*.h" # 只安装头文件
    PATTERN "*.hpp" # 也可以安装 .hpp 文件（如果有）
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}Config.cmake.in
    ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
    PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR BIN_INSTALL_DIR
)

install(
    FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake DESTINATION lib/cmake/${PROJECT_NAME}
)
