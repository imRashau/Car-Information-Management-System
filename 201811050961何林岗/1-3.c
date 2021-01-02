#include <stdio.h>
int fun(int *a,int *b,int *c);
int main()
{
	int a,b,c;
	printf("请输入2个整数:");
	scanf("%d%d",&a,&b);
	fun(&a,&b,&c);
	printf("合并整数为:%d\n",c);
	return 0;
}
int fun(int *a,int *b,int *c)
{
	*c = *a % 10 * 1000 + *b % 10 * 100 + *a / 10 * 10 + *b / 10;
    return 0;
}
