// 多项式运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
int pri(char a) {//运算符优先级比较
    if (a == '*' || a == '/')
        return 5;
    else if (a == '+' || a == '-')
        return 4;

}
int cal(int a, int b, string c) {//计算    
    if (c == "+")
        return a + b;
    if (c == "-")
        return a - b;
    if (c == "*")
        return a * b;
    if (c == "/")
        return a / b;
}
string ctos(char c) {//字符型变成字符串型
    string res = "a";
    res[0] = c;
    return res;
}
bool isInt(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            num++;
    }
    if (num == s.size())
        return true;
    else
        return false;
}
int main() {
    string s;
    while (cin >> s) {
        vector<string>v;//后缀表达式
        stack<char>s1;//中间运算符
        stack<int>s2;
        int sum = 0;
        string str;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9')//数字直接输出
                str += s[i];
            else {
                if (str.size() != 0)
                    v.push_back(str);
                str.clear();
                if (i == s.size())
                    break;
                if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                    while (true) {
                        if (s1.empty() || s1.top() == '(') {
                            s1.push(s[i]);
                            break;
                        }
                        else if (pri(s[i]) > pri(s1.top())) {
                            s1.push(s[i]);
                            break;
                        }
                        else {
                            char cc = s1.top();
                            v.push_back(ctos(cc));
                            s1.pop();
                        }
                    }
                }
                else {
                    if (s[i] == '(')
                        s1.push(s[i]);
                    else {
                        while (s1.top() != '(') {
                            char temp = s1.top();
                            v.push_back(ctos(temp));
                            s1.pop();
                        }
                        s1.pop();
                    }
                }
            }
        }
        while (!s1.empty()) {
            char ccc = s1.top();
            v.push_back(ctos(ccc));
            s1.pop();
        }
        //for(int i=0;i<v.size();i++)
         //   cout<<v[i]<<" ";
        //到此 中缀表达式已经转变为后缀表达式 接下来是进行运算
        for (int i = 0; i < v.size(); i++) {
            if (isInt(v[i]))
                s2.push(stoi(v[i]));
            else if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/") {
                int b = s2.top();
                s2.pop();
                int a = s2.top();
                s2.pop();
                int c = cal(a, b, v[i]);
                s2.push(c);
                //cout<<a<<" "<<b<<" "<<c<<endl;
            }
        }
        sum = s2.top();
        cout << sum << endl;
    }
}
