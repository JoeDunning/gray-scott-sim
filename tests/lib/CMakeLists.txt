# project-root/tests/lib/CMakeLists.txt

add_library(gs STATIC gs.cpp)

# 将库文件链接到测试文件
# target_link_libraries(gs_test PRIVATE gs)
    
target_include_directories(gs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
