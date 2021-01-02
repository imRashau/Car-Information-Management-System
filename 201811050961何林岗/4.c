#include <stdio.h>
#include <string.h>
#include <assert.h>
int main(int n,int m)
{
    int i = 0;
    int j = 0;
	int c;
	char a[100][100];
	scanf("%d%d",n,m);
    for(i=1; i<=m; i++)
    {
        for(j=1; j<n; j++)
        {
            scanf("%c", a[j][i]);
        }
    }
	scanf("%d",c);
	for(i=0;i<c;i++)
	{
		for(i=1; i<=m; i++)
		{
			for(j=1; j<n; j++)
			{
				if(a[j][i]=='X')
				{
					a[j-1][i]='X';
					a[j+1][i]='X';
					a[j][i-1]='X';
					a[j][i+1]='X';
				}
				if(a[j][i]='P')
				{
					while(a[j+1][i]='O')
					a[j+1][i]='O';
					while(a[j+1][i]='P')
					a[j+1][i]='P';
				}
			}
		}
	}

	for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            printf("%c",a[j][i]);
		}
	}
}
