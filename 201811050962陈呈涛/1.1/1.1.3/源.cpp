#include <iostream>
#include <ostream>
using namespace std;
int main()
{
    int fun(int*a,int*b,int*c);
    int a,b,c;
    cout<<"ÊäÈëa,b:"<<endl;
    cin>>a>>b;
    fun(&a,&b,&c);
    cout<<"c ="<<c<<endl;
    return 0;
}

int fun(int*a,int*b,int*c)
{
    *c=*a%10*1000+*b%10*100+*a/10*10+*b/10;
    return 0;
}