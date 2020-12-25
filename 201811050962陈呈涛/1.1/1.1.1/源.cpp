#include <iostream>
#include <ostream>
using namespace std;
int main()
{
    int fun(int a, int b);
    int a, b, c;
    cout << "ÊäÈëa,b:" << endl;
    cin >> a >> b;
    c = fun(a, b);
    cout << "c=" << c << endl;
    return 0;
}
int fun(int a, int b)
{
    return (a % 10 * 1000 + b % 10 * 100 + a / 10 * 10 + b / 10);
}
