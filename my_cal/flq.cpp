#include "flqh.h"
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
bool IS_Leap = false;
int main(int argc, char **argv)
{
  system(CLEAR);
  int iMonths[LEN];
  struct tm *tp;
  time_t tTime;
  time(&tTime);
  tp = localtime(&tTime);
#ifdef __linux
  const char name[] = "./flq";
  const char name_other[] = "flq";
#elif _WIN64
  const char name[] = "flq";
  const char name_other[] = "flq.exe";
#endif
  switch (argc)
  {
  case FIR:
    if (!strcmp(name, argv[0])) // 显示本年本月日历
    {
      Fdm(iFdy(tp->tm_year + BASE), tp->tm_year + BASE,
          iMonths);                          // 获得一个每个元素为指定年份每一个月一号的星期数的数组
      is_leap(tp->tm_year + BASE, &IS_Leap); // 判断该年是否为闰年
      int range1[2] = {tp->tm_mon + 1, tp->tm_mon + 1};
      function_L2(iMonths, range1, IS_Leap); // 显示指定年份指定月份日历
    }
    break;
  case SEC:
    if (!strcmp(argv[1], HELP)) // 显示帮助页面
      function_F2();
    else if (!strcmp(argv[1], WHOLEYEAR)) // 显示本年整年日历
    {
      int iMonthRange[RANGE];
      iMonthRange[0] = 1;
      iMonthRange[1] = MONTHS;
      Fdm(iFdy(tp->tm_year + BASE), tp->tm_year + BASE, iMonths);
      is_leap(tp->tm_year + BASE, &IS_Leap);
      function_L2(iMonths, iMonthRange, IS_Leap);
    }
    else if (strlen(argv[1]) == 1) // 显示本年指定某个月份日历
    {
      char *end;
      long lMonth = strtol(argv[1], &end, NUMBASE);
      if (end == argv[1])
      {
        cout << "参数错误" << endl;
        cout << "请使用-h参数查看使用方法" << endl;
        exit(0);
      }
      else
      {
        Fdm(iFdy(tp->tm_year + BASE), tp->tm_year + BASE, iMonths);
        is_leap(tp->tm_year + BASE, &IS_Leap);
        int iRANGE[2] = {lMonth, lMonth};
        function_L2(iMonths, iRANGE, IS_Leap);
      }
    }
    else if (strlen(argv[1]) == 2 || strlen(argv[1]) == 3 ||
             strlen(argv[1]) == 4 ||
             strlen(argv[1]) == 5) // 指定某范围内本年的日历
    {
      int iMonthRange[RANGE];
      param_two(argv[1], iMonthRange);
      Fdm(iFdy(tp->tm_year + BASE), tp->tm_year + BASE, iMonths);
      is_leap(tp->tm_year + BASE, &IS_Leap);
      function_L2(iMonths, iMonthRange, IS_Leap);
    }
    else
    {
      cout << "参数范围错误" << endl;
      exit(0);
    }
    break;
  case THR: // 指定年份指定月份输出日历
    char *end;
    long lYear = strtol(argv[1], &end, NUMBASE);
    if (end == argv[1])
    {
      cout << "参数错误" << endl;
      cout << "请使用-h参数查看使用方法" << endl;
      exit(0);
    }
    if (lYear <= 0)
    {
      cout << "年份错误" << endl;
      exit(0);
    }
    else
    {
      if (!strcmp(argv[2], WHOLEYEAR))
      {
        int iMonthRange[RANGE];
        iMonthRange[0] = 1;
        iMonthRange[1] = MONTHS;
        Fdm(iFdy(lYear), lYear, iMonths);
        is_leap(lYear, &IS_Leap);
        function_L2(iMonths, iMonthRange, IS_Leap);
      }
      else if (strlen(argv[2]) == 1)
      {
        int a = argv[2][0] - '0';
        if (a >= 1 && a <= MONTHS)
        {
          Fdm(iFdy(lYear), lYear, iMonths);
          is_leap(lYear, &IS_Leap);
          int iRange[2] = {a, a};
          function_L2(iMonths, iRange, IS_Leap);
        }
        else
        {
          cout << "参数错误" << endl;
          exit(0);
        }
      }
      else if (strlen(argv[2]) == 2 || strlen(argv[2]) == 3 ||
               strlen(argv[2]) == 4 || strlen(argv[2]) == 5)
      {
        int iMonthRange[RANGE];
        param_two(argv[2], iMonthRange);
        Fdm(iFdy(lYear), lYear, iMonths);
        is_leap(lYear, &IS_Leap);
        function_L2(iMonths, iMonthRange, IS_Leap);
      }
    }
    break;

    /*default:
            cout << "参数个数错误 请使用-h参数查看帮助界面" << endl;*/
  }
  return 0;
}
