// 数的合并1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include<iostream>
using namespace std;
int fun(int a, int b)
{
	return( b % 10 * 100 + b / 10 + a / 10 * 10 + a % 10 * 1000);
	

}
int main()
{
    
    int a, b, c;
    cout << "输入a、b:" << endl;
    cin >> a >> b;
   c = fun(a, b);
    cout << " c=" << c<< endl;
    return 0;
}
