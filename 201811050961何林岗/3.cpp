#include<stdio.h>
#include<algorithm>
using namespace std;
struct node
{
   int Ch,Mat,Eng; 
   int num,sum;   
}student[3000];
int cmp(node a,node b)
{
    if(a.sum!=b.sum) return a.sum>b.sum;
    if(a.Ch!=b.Ch) return a.Ch>b.Ch;
    if(a.num!=b.num) return a.num<b.num;
	return 0;
}
int main()
{
    int i,n;
	printf("������ѧ������:");
    scanf("%d",&n);
	printf("������ѧ�����ġ���ѧ��Ӣ��ɼ�:\n");
    for(i=0;i<n;i++)
    {
	  scanf("%d%d%d",&student[i].Ch,&student[i].Mat,&student[i].Eng);
      student[i].num=i+1;
      student[i].sum=student[i].Ch+student[i].Mat+student[i].Eng;
    }
    sort(student,student+n,cmp);
	printf("ѧ���ɼ�����:\n");
    for(i=0;i<5;i++)
    printf("%d %d\n",student[i].num,student[i].sum);
    while(1);
    return 0;
}
