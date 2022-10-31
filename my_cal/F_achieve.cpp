#include <iostream>
using namespace std;
void function_F2(void)
{

    cout << " flq:" << endl
         << " Usage:" << endl
         << " 根据不同参数显示日历" << endl;
    cout << " (前无年份）-y       显示本年整年日历" << endl;
    cout << " (前有年份）-y       显示指定年份日历" << endl;
    cout << "          -h       帮助界面" << endl;
    cout << "  (无年份）后跟n-m      显示本年n-m月份" << endl;
    cout << "  (有年份）后跟n-m      显示该年n-m月份" << endl;
    cout << "  无参数。              显示本年本月份 " << endl;
    cout << "  年份+单月。           显示该年份该月份" << endl;
}