#include <stdio.h>
#define MaxSize 100
void king(int m, int n)
{
    int p[MaxSize];
    int i,j,t=0;
    for (i=0;i< m;i++)//构建初始序列，记录m只猴子在p[0]~p[m-1]中
        p[i]=i+1; //首次报数的起始位置为0
    printf("大王的编号是:");
    for (i=m;i>=1;i--)//循环要执行m次，有m个猴子要出圈；共有i从m开始递减至1，i还表示在圈中猴子的数目
    {
        t=(t+n-1)%i;//从t开始数1，其后第n-1个将数到n，t加n-1用%i取余，目的是到达最后一个猴子可以折回去继续数
           //编号为p[t]的元素出列
        for (j=t+1;j<=i-1;j++)//后面的元素前移一个位置，删除了编号为p[t]的猴子
            p[j-1]=p[j];
    }
    printf("%d",p[t]);
}
int main()
{
    int m,n;
    printf("输入m,n\n");
    scanf_s("%d%d",&m,&n);
    king(m,n);
    return 0;
}
