#pragma once
#include <cstdlib>
#ifdef __linux
#define CLEAR "clear"
#elif _WIN64
#define CLEAR "cls"
#include <conio.h>
#include <windows.h>
#endif
#include <iomanip>
#include <string.h>
#define WEEKDAYS " Su Mo Tu We Th Fr Sa"
// 定义参数
#define WHOLEYEAR "-y"
#define HELP "-h"

// 存储闰年与平年的对应月份天数
const int Year[2][13]{{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

// 用于定义strtol函数使用的基数
#define NUMBASE 10

// 用于标记年份是否为闰年

// 用于定义月份数
#define MONTHS 12

// 用于定义一周长度
#define WEEK 7

// 用于定义平年
#define YEAR 365

// 用于判断命令行参数的三种情况
#define FIR 1
#define SEC 2
#define THR 3

// 定义打印范围
#define RANGE 2

// 定义数组长度
#define LEN 13

// 用于初始化本地时间
#define BASE 1900

// 用于计算输入年份的第一天为星期几
int iFdy(int);

// 用于判断是否为闰年
int is_leap(int, bool *);

// 用于形成每月一号星期几的数组
void Fdm(int, int, int *);

// 用于显示单个月份
//  void function_F1(int*, int, bool);

// 用于显示多个月份
//  void function_Q12(int*, int*, bool);

// 用于显示帮助界面
void function_F2(void);

// 用于判断月份范围和范围的正确性
void param_two(char *, int *);

// 用于更改光标坐标
void gotoxy(int, int);

// 用于打印月份信息
void function_L2(int *, int *, bool);
