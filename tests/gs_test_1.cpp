#include "../include/gs.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cmath>

// Declare simulation parameters
extern const int width;
extern const int height;
extern double Du;
extern double Dv;
extern double F;
extern double k;
extern double threshold;
extern const double dt;
extern const int numIterations;
extern const int outputInterval;

// Declare grid and constants
extern std::vector<std::vector<double>> u;
extern std::vector<std::vector<double>> v;

// Declare initialization function
extern void init();

// Declare other functions
extern void writeVTKFile(int iteration);
extern void simulateStep();
extern double countElementsAboveThreshold(double threshold);

#include "acutest.h"

// 测试用例---1
void test_type_parameters() {
    TEST_CHECK(typeid(F) == typeid(u[0][0]));
    TEST_CHECK(typeid(k) == typeid(v[0][0]));
}

// 初始化函数的定义
void test_init_function() {
    init();
    // 这里可以添加检查初始化后的状态的代码
}

// 测试用例---2
void test_u_and_v_same_size() {
	TEST_CHECK(u.size() == v.size());
	TEST_CHECK(u[0].size() == v[0].size());
}

// 初始化函数的定义
void test_init_function_2() {
    init();
	// 检查 u 和 v 是否被正确初始化
    TEST_CHECK(u.size() > 0);
    TEST_CHECK(u[0].size() > 0);
    TEST_CHECK(v.size() > 0);
    TEST_CHECK(v[0].size() > 0);
    // 这里可以添加检查初始化后的状态的代码
}

// 定义测试列表
TEST_LIST = {
    {"test_type_parameters", test_type_parameters},
    {"test_init_function", test_init_function},
    {"test_u_and_v_same_size", test_u_and_v_same_size},
    {"test_init_function_2", test_init_function_2},
    // 其他测试
    {NULL, NULL}
};

// extern "C" {
//     TEST_LIST;
// }