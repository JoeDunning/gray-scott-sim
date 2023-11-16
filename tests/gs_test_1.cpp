#include "../include/gs.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

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

// 第一个测试：检查模型参数类型（F和K）与u和v向量的元素类型是否匹配
void test_parameter_type_matching(void) {
    // 检查 F 和 u[0][0] 的类型是否匹配
    TEST_CHECK(typeid(F) == typeid(u[0][0]));
    TEST_MSG("The type of F does not match with the type of elements in u");

    // 检查 K 和 v[0][0] 的类型是否匹配
    TEST_CHECK(typeid(k) == typeid(v[0][0]));
    TEST_MSG("The type of k does not match with the type of elements in v");
}

// 第二个测试：确保u和v大小相同
void test_vectors_size_matching(void) {
    // 检查u和v的外层向量大小是否匹配
    TEST_CHECK(u.size() == v.size());
    // 如果外层大小匹配，接下来检查每一个内层向量的大小
    for (size_t i = 0; i < u.size(); ++i) {
        TEST_CHECK(u[i].size() == v[i].size());
        // 如果任何一个内层向量大小不匹配，显示错误信息
        if(u[i].size() != v[i].size()) {
            TEST_MSG("The size of inner vectors at index %zu do not match: u[%zu].size() = %zu, v[%zu].size() = %zu", 
                      i, i, u[i].size(), i, v[i].size());
            break; // 一旦发现不匹配无需进一步检查，一个不匹配足以使测试失败
        }
        }
    /// 如果所有内层向量的大小都匹配，显示成功信息
    if (u.size() > 0 && v.size() > 0 && u[0].size() == v[0].size()) {
        TEST_MSG("The sizes of u and v match: u.size() = %zu, v.size() = %zu, u[0].size() = %zu, v[0].size() = %zu", 
                  u.size(), v.size(), u[0].size(), v[0].size());
    }
}

// 第三个测试：当u=0和v=0时，检查模拟产生的数学上的正确答案
void test_simulation_with_zero_initial_values(void) {
    // 将 u 和 v 初始化为 0
    for (auto& row : u) std::fill(row.begin(), row.end(), 0.0);
    for (auto& row : v) std::fill(row.begin(), row.end(), 0.0);

    // 运行模拟
    for (int iteration = 0; iteration < numIterations; ++iteration) {
        simulateStep();
    }

    // 检查 u 中是否有元素大于 0
    bool uHasPositive = false;
    for (const auto& row : u) {
        if (std::any_of(row.begin(), row.end(), [](double val) { return val > 0.0; })) {
            uHasPositive = true;
            break;
        }
    }

    // 检查 v 是否仍然全为 0
    bool vAllZero = std::all_of(v.begin(), v.end(), [](const std::vector<double>& row) {
        return std::all_of(row.begin(), row.end(), [](double val) { return val == 0.0; });
    });

    TEST_CHECK(uHasPositive && vAllZero);
    TEST_MSG("Simulation result is not as expected when u and v are initialized to zero.");
}

// 测试列表
TEST_LIST = {
    { "parameter_type_matching", test_parameter_type_matching },
    { "vectors_size_matching", test_vectors_size_matching },
    { "simulation_with_zero_initial_values", test_simulation_with_zero_initial_values },
    { NULL, NULL } // 测试列表结束
};

// // 测试用例---1
// void test_type_parameters() {
//     TEST_CHECK(typeid(F) == typeid(u[0][0]));
//     TEST_CHECK(typeid(k) == typeid(v[0][0]));
// }

// // 初始化函数的定义
// void test_init_function() {
//     init();
//     // 这里可以添加检查初始化后的状态的代码
// }

// // 测试用例---2
// void test_u_and_v_same_size() {
// 	TEST_CHECK(u.size() == v.size());
// 	TEST_CHECK(u[0].size() == v[0].size());
// }

// // 初始化函数的定义
// void test_init_function_2() {
//     init();
// 	// 检查 u 和 v 是否被正确初始化
//     TEST_CHECK(u.size() > 0);
//     TEST_CHECK(u[0].size() > 0);
//     TEST_CHECK(v.size() > 0);
//     TEST_CHECK(v[0].size() > 0);
//     // 这里可以添加检查初始化后的状态的代码
// }

// // 定义测试列表
// TEST_LIST = {
//     {"test_type_parameters", test_type_parameters},
//     {"test_init_function", test_init_function},
//     {"test_u_and_v_same_size", test_u_and_v_same_size},
//     {"test_init_function_2", test_init_function_2},
//     // 其他测试
//     {NULL, NULL}
// };
