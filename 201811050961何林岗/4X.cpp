#include "stdio.h"
void main(){
	int M,N,c;
	char a[100][100];
	int i,j,x;

	printf("ÇëÊäÈë³¤ºÍ¿í\n");
	scanf("%d%d",&N,&M);
	for(i=0;i<M;i++){
		for(j=0;j<N+1;j++){
			scanf("%c",&a[i][j]);
		}
	}
	

	scanf("%d",&c);
	for(x=0;x<c;x++)
	{
		for(i=0; i<M; i++)
		{
			for(j=0; j<N+1; j++)
			{
				if(a[i][j]=='X')
				{
				      if (a[i + 1][j] == 'O')
                        a[i + 1][j] = 'N';
                    if (a[i - 1][j] == 'O')
                        a[i - 1][j] = 'N';
                    if (a[i][j + 1] == 'O')
                        a[i][j + 1] = 'N';
                    if (a[i][j - 1] == 'O')
                        a[i][j - 1] = 'N';



				}

			}
		}
	for(i=0; i<M; i++)
		{
			for(j=0; j<N; j++)
			{
		      if(a[i][j]=='N')
			  a[i][j]='X';
			}
		}
		

	}
	
	for(i=0;i<M;i++){
		for(j=0;j<N+1;j++){
			printf("%c",a[i][j]);
		}printf("\n");
	}printf("\n");
}