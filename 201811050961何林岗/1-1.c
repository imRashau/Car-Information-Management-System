#include <stdio.h>
int int_fun(int a,int b);
int main()
{
	int a,b,c;
	printf("请输入2个整数:");
	scanf("%d%d",&a,&b);
	c=int_fun(a,b);
	printf("合并整数为:%d\n",c);
	return c;
}
int int_fun(int a,int b)
{
	int c,c1,c10,c100,c1000;
	c1=b/10;
	c10=a%10;
	c100=b%10;
	c1000=a/10;
	c=c1000*1000+c100*100+c10*10+c1;
	return c;
}
