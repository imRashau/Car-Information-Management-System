#include<iostream>
#include<ostream>
using namespace std;
int main()
{
    char a[100][100];
    int n,m,i,j,c,t;
    cout <<"输n*m的矩形"<< endl;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout << "输入经历的周期" << endl;
    cin>>c;
    for (int t = 1; t <= c; t++)
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 'X')
                {
                    if (a[i + 1][j] != 'P' && a[i + 1][j] != 'X')
                        a[i + 1][j] = 'A';
                    if (a[i - 1][j] != 'P' && a[i + 1][j] != 'X')
                        a[i - 1][j] = 'A';
                    if (a[i][j + 1] != 'A' && a[i + 1][j] != 'X')
                        a[i][j + 1] = 'A';
                    if (a[i][j - 1] != 'P' && a[i + 1][j] != 'X')
                        a[i][j - 1] = 'A';
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 'A')
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
        }
        cout << endl;
    }
    return 0;
}
