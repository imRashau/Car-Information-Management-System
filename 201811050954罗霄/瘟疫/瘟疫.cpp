﻿// 瘟疫.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<ostream>
using namespace std;
int main()
{
    char a[50][50];
    int n, m, i, j, c, t;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> c;
    for (int t = 1; t <= c; t++)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 'X')
                {
                    if (a[i + 1][j] != 'P' && a[i + 1][j] != 'X')
                        a[i + 1][j] = 'N';
                    if (a[i - 1][j] != 'P' && a[i + 1][j] != 'X')
                        a[i - 1][j] = 'N';
                    if (a[i][j + 1] != 'P' && a[i + 1][j] != 'X')
                        a[i][j + 1] = 'N';
                    if (a[i][j - 1] != 'P' && a[i + 1][j] != 'X')
                        a[i][j - 1] = 'N';
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 'N')
                {
                    a[i][j] = 'X';
                }
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j];
        }cout << endl;
    }
    return 0;
}