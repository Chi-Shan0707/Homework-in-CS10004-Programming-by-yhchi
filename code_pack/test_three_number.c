/*
 * 三数问题单元测试文件
 * 本文件对three-number-question.c中的各个函数进行单元测试
 * 使用assert.h库进行断言测试
 */

#include <stdio.h>
#include <assert.h>
#include "three-number-question.h"

/*
 * 测试MAX函数
 * 测试内容包括：
 * 1. 正数比较
 * 2. 负数比较
 * 3. 正负数混合比较
 */
void test_MAX() {
    printf("Testing MAX function...\n");
    
    // 测试正数
    assert(MAX(5, 3) == 5);
    assert(MAX(2, 8) == 8);
    assert(MAX(4, 4) == 4);
    
    // 测试负数
    assert(MAX(-1, -5) == -1);
    assert(MAX(-3, -2) == -2);
    
    // 测试正负数混合
    assert(MAX(1, -1) == 1);
    assert(MAX(-10, 10) == 10);
    
    printf("MAX function tests passed!\n\n");
}

/*
 * 测试MIN函数
 * 测试内容包括：
 * 1. 正数比较
 * 2. 负数比较
 * 3. 正负数混合比较
 */
void test_MIN() {
    printf("Testing MIN function...\n");
    
    // 测试正数
    assert(MIN(5, 3) == 3);
    assert(MIN(2, 8) == 2);
    assert(MIN(4, 4) == 4);
    
    // 测试负数
    assert(MIN(-1, -5) == -5);
    assert(MIN(-3, -2) == -3);
    
    // 测试正负数混合
    assert(MIN(1, -1) == -1);
    assert(MIN(-10, 10) == -10);
    
    printf("MIN function tests passed!\n\n");
}

/*
 * 测试readFromString函数
 * 该函数是read函数的变体，用于从字符串中读取数字
 * 测试内容包括：
 * 1. 正数读取
 * 2. 负数读取
 */
void test_readFromString() {
    printf("Testing readFromString function...\n");
    
    const char* test_str1 = "123 456 789";
    int index1 = 0;
    assert(readFromString(test_str1, &index1) == 123);
    assert(readFromString(test_str1, &index1) == 456);
    assert(readFromString(test_str1, &index1) == 789);
    
    const char* test_str2 = "-45 67 -89";
    int index2 = 0;
    assert(readFromString(test_str2, &index2) == -45);
    assert(readFromString(test_str2, &index2) == 67);
    assert(readFromString(test_str2, &index2) == -89);
    
    printf("readFromString function tests passed!\n\n");
}

/*
 * 测试calculateStats函数
 * 该函数计算三个数的和、平均值、最大值和最小值
 * 测试内容包括：
 * 1. 普通三个不同数字
 * 2. 三个相同数字
 * 3. 包含负数的三个数字
 */
void test_calculateStats() {
    printf("Testing calculateStats function...\n");
    
    int sum, max, min;
    float average;
    
    // 测试正常情况
    calculateStats(10, 20, 30, &sum, &average, &max, &min);
    assert(sum == 60);
    assert(average == 20.0);
    assert(max == 30);
    assert(min == 10);
    
    // 测试相同数字
    calculateStats(5, 5, 5, &sum, &average, &max, &min);
    assert(sum == 15);
    assert(average == 5.0);
    assert(max == 5);
    assert(min == 5);
    
    // 测试负数
    calculateStats(-10, 0, 10, &sum, &average, &max, &min);
    assert(sum == 0);
    assert(average == 0.0);
    assert(max == 10);
    assert(min == -10);
    
    printf("calculateStats function tests passed!\n\n");
}

/*
 * 主函数
 * 依次运行所有测试函数
 */
int main() {
    test_MAX();
    test_MIN();
    test_readFromString();
    test_calculateStats();
    
    printf("All tests passed!\n");
    return 0;
}