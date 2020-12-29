// 猴子选大王.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#define N 1000

using namespace std;

int main() {
    int n, k, m;
    int next[N];
    int last[N];
    cout << "猴子的数量"  << endl;
    cin >> n;
    cout << "从第几个开始数" << endl;
    cin >> k;
    cout << "数多少个数"<<endl;
    cin >> m;
    for (int i = 0; i < n - 1; i++) {
        next[i] = i + 1;
    }
    next[n - 1] = 0;
    last[0] = n - 1;
    for (int i = 1; i < n - 1; i++) {
        last[i] = i - 1;
    }
    while (k != next[k]) {
        int klast = last[k + m - 1];
        int knext = next[k + m - 1];
        next[klast] = knext;
        last[knext] = klast;
        k = knext;
    }
    cout << k << endl;
    return 0;
}
