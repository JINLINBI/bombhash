# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (filedump)

aux_source_directory(. DIR_SRCS)
include_directories (source)
add_subdirectory(source)

# 指定生成目标
add_executable(filedump ${DIR_SRCS})

target_link_libraries(filedump utils)