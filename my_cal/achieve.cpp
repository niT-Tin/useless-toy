#include <iostream>
#include <ctime>
#include "flqh.h"
#include <ctype.h>
#include <stdlib.h>
//储存本年时间
int iYEAR = 0, iMONTHS = 0, iDAY = 0;
using namespace std;
bool bIs_leap = false;
int iFdy(int iYear) //获得输入年份的一月一号为星期几
{
	struct tm *tmpt;
	time_t tNowTime;
	time(&tNowTime);
	int iFirstDay = 0;
	tmpt = localtime(&tNowTime); //获取本地时间

	for (int i = 1; i <= WEEK; i++) //用于确定本年一月一号为星期几
		if ((i + tmpt->tm_yday) % WEEK == tmpt->tm_wday)
		{
			iFirstDay = i;
			break;
		}
	iYEAR = tmpt->tm_year + BASE;
	iMONTHS = tmpt->tm_mon + 1;
	iDAY = tmpt->tm_mday;
	unsigned int uiTotal = 0;			   //用于计算输入年份到起始年份的总天数
	int iStartYear = tmpt->tm_year + BASE; //设置起始年份为本年

	if (iYear > iStartYear)
	{
		for (int i = iStartYear; i < iYear; i++)
			uiTotal += YEAR + is_leap(i, &bIs_leap);
		uiTotal = (uiTotal + iFirstDay) % WEEK;
		if (uiTotal == 0)
			uiTotal = WEEK;
	}
	else if (iYear < iStartYear)
	{
		for (int i = iYear; i < iStartYear; i++)
			uiTotal += YEAR + is_leap(i, &bIs_leap);
		for (int i = 0; i < WEEK; i++) //用于确定本年一月一号为星期几
		{

			if ((i + uiTotal) % WEEK == iFirstDay)
			{
				if (i == 0)
					uiTotal = WEEK;
				else
					uiTotal = i;
				break;
			}
		}
	}
	else
		uiTotal = iFirstDay;

	return uiTotal;
}

int is_leap(int iYear, bool *is_leap) //用于判断是否为闰年
{
	if ((iYear % 400 == 0) || (iYear % 100 != 0 && iYear % 4 == 0))
	{
		*is_leap = true;
		return 1;
	}
	else
	{
		*is_leap = false;
		return 0;
	}
}

void Fdm(int iFir, int iYear, int *arr) //获得一个数组，存储输入年份每个月份1号对应的星期几
{
	arr[0] = iYear;
	arr[1] = iFir;
	int iDay = 0;

	for (int i = 2, j = 1; i <= MONTHS; i++, j++)
	{
		iDay += Year[is_leap(iYear, &bIs_leap)][j];
		arr[i] = (iDay + iFir) % 7;
		if (arr[i] == 0)
			arr[i] = WEEK;
	}
}

void param_two(char *cpMonthRange, int *ipRange) //将命令行参数转化为实际数字和程序内置的参数，并保证参数在正确范围内
{
	int a, b, c, d;
	switch (strlen(cpMonthRange))
	{
	case 2:
		if (!isdigit(cpMonthRange[0]) || !isdigit(cpMonthRange[1]))
		{
			cout << "参数错误" << endl;
			exit(0);
		}
		a = cpMonthRange[0] - '0';
		b = cpMonthRange[1] - '0';
		c = a * 10 + b;
		if (c >= 10 && c <= MONTHS)
		{
			ipRange[0] = c;
			ipRange[1] = c;
		}
		else
		{
			cout << "参数范围错误" << endl;
			exit(0);
		}
		break;
	case 3:
		if (!isdigit(cpMonthRange[0]) || !isdigit(cpMonthRange[2]))
		{
			cout << "参数错误" << endl;
			exit(0);
		}
		a = cpMonthRange[0] - '0';
		b = cpMonthRange[2] - '0';
		if (a >= 1 && a <= MONTHS && b >= 1 && b <= MONTHS)
		{
			if (a <= b)
			{
				ipRange[0] = a;
				ipRange[1] = b;
			}
			else
			{
				cout << "范围错误" << endl;
				exit(0);
			}
		}
		break;
	case 4:
		b = cpMonthRange[1] - '0';
		if (b >= 0 && b <= 9)
		{
			cout << "参数范围错误" << endl;
			exit(0);
		}
		else
		{
			if (!isdigit(cpMonthRange[0]) || !isdigit(cpMonthRange[2]) || !isdigit(cpMonthRange[3]))
			{
				cout << "参数错误" << endl;
				exit(0);
			}
			a = cpMonthRange[0] - '0';
			b = cpMonthRange[2] - '0';
			c = cpMonthRange[3] - '0';
			d = b * 10 + c;
			if (a >= 1 && a <= 9 && d >= a && d <= MONTHS)
			{
				ipRange[0] = a;
				ipRange[1] = d;
			}
			else
			{
				cout << "参数范围错误" << endl;
				exit(0);
			}
		}
		break;
	case 5:
		if (!isdigit(cpMonthRange[0]) || !isdigit(cpMonthRange[1]) || !isdigit(cpMonthRange[3]) || !isdigit(cpMonthRange[4]))
		{
			cout << "参数错误" << endl;
			exit(0);
		}
		a = cpMonthRange[0] - '0';
		b = cpMonthRange[1] - '0';
		c = cpMonthRange[3] - '0';
		d = cpMonthRange[4] - '0';
		int n1, n2;
		n1 = a * 10 + b;
		n2 = c * 10 + d;
		if (n1 >= 10 && n1 <= MONTHS && n2 >= n1 && n2 <= MONTHS)
		{
			ipRange[0] = n1;
			ipRange[1] = n2;
		}
		else
		{
			cout << "参数范围错误" << endl;
			exit(0);
		}
		break;
	default:
		cout << "参数范围错误" << endl;
		exit(0);
	}
}

void gotoxy(int x, int y) //转跳光标
{
#if __linux
	printf("\033[%d;%dH ", y, x);
#elif _WIN64
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
#endif
}

void function_L2(int *all_months, int *month_range, bool is_leap) //用于显示月份
{
	int g = 1, c = 1, z = 1, count = 0;
	int fx = 3;
	int fy = 2;
	int x1 = 0;
	int fy2 = 3;
	int iY = 0;
	// int range[2] = { 5, 9 };
	// int all_month[13] = { 2020,3,6,7,3,5,1,3,6,2,4,7,2 };
	int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (is_leap)
		months[2]++;
	int year = all_months[0];
	for (int a = 0; a < 3; a++)
	{
		for (int i = 0; i < 3; i++)
			cout << right << setw(3) << " ";
	}
	cout << right << setw(8) << year << endl;
	gotoxy(x1 + 10, fy++);
	iY++;
	for (int k = month_range[0]; k <= month_range[1]; k++, g++)
	{
		bool flag = true, f2 = false;
		z = 1;
		c = 1;
		count = 0;
		int iBlank = 0;
		int day = all_months[k];
		if (day == 7)
		{
			iBlank = 0;
			count = 1;
		}
		else
			iBlank = day;
		if (g % 3 == 1)
		{
		}
		else
		{
			gotoxy(x1 + 10, fy - 1);
			iY++;
		}
		cout << k;
		gotoxy(x1, fy++);
		iY++;
		if (g % 3 == 1)
			cout << WEEKDAYS << endl;
		else
		{
			cout << WEEKDAYS;
			gotoxy(x1, fy);
		}
		while (c <= iBlank)
		{
			cout << right << setw(3) << " ";
			c++;
		}
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (z <= months[k])
				{
					if ((iBlank + count) % 7 == 0)
					{
						if (iBlank == 0 && count % 7 == 0 && f2)
						{
						}
						else
							gotoxy(x1, ++fy);
					}
					cout << right << setw(3) << z;
					count++;
					if (iBlank == 0 && count == 6)
					{
						if (flag)
						{
							count -= 1;
							flag = false;
						}
					}
				}
				z++;
			}
			if ((iBlank + count) % 7 == 0)
			{
				f2 = true;
				gotoxy(x1, ++fy);
			}

			iY++;
		}
		x1 += 22;
		fy = fy2 - 1;

		if (g % 3 == 0)
		{
			x1 = 0;
			fy2 += iY + 1;
			fy = fy2 - 1;
			if (g == 3)
				fx += 14;
			else
				fx += 10;
		}
		if (g > 1 && x1 == 0)
			gotoxy(x1 + 10, fy++);
		else
			gotoxy(x1, fy++);
		iY = 0;
	}
	if (g == 2 || g == 3 || g == 4)
	{
		gotoxy(0, 11);
		cout << "Today:";
		gotoxy(0, 12);
		cout << iYEAR << '/' << iMONTHS << '/' << iDAY << endl;
	}

	else if (g % 3 == 2)
	{
		gotoxy(0, fx + 2);
		cout << "Today:";
		gotoxy(0, fx + 3);
		cout << iYEAR << '/' << iMONTHS << '/' << iDAY << endl;
	}

	else if (g % 3 == 1)
	{
		gotoxy(0, fx - 8);
		cout << "Today:";
		gotoxy(0, fx - 7);
		cout << iYEAR << '/' << iMONTHS << '/' << iDAY << endl;
	}

	else
	{
		gotoxy(0, fx + 2);
		cout << "Today:";
		gotoxy(0, fx + 3);
		cout << iYEAR << '/' << iMONTHS << '/' << iDAY << endl;
	}
}