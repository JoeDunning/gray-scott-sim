# project-root/tests/CMakeLists.txt

# 设置测试源文件
set(TEST_SOURCES
    gs_test_1.cpp
)

# 创建测试目标
add_executable(gs_test ${TEST_SOURCES})

# Link the gray_scott_lib library
add_subdirectory(lib)

# 链接测试框架
target_link_libraries(gs_test PRIVATE acutest)

# 设置测试
add_test(NAME gs_test COMMAND gs_test)

# 包含项目的 include 目录
target_include_directories(gs_test PRIVATE "${CMAKE_SOURCE_DIR}/include")
