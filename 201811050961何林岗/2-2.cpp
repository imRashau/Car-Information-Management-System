#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num;//猴子的编号
    struct node *next;//下一个猴子
}node;

typedef struct node *linklist;

int main()
{
    linklist p,q,head;
    int king,i,m,n;
	printf("请输入猴子个数 m 和报数 n ：");
    scanf("%d%d",&m,&n);
    head=p=q=(linklist)malloc(sizeof(node));
    head->num=1;
    for(i=1;i<m;i++)
    {
        p=(linklist)malloc(sizeof(node));   //给新节点分配空间
        p->num=i+1; //给结点数据域传值
        q->next=p;
        q=p;        //利用节点q将新节点连接起来
    }
    q->next=head;
    p=head;
    for(i=1;i<m;i++)
    {
		p=p->next;
        q=p->next;      //两行代码在一次循环中将第三只猴子赋给p，再对p进行剔除即可
        printf("第%d轮淘汰第%d只猴子！\n",i,q->num);
        p->next=q->next;    //将淘汰掉的猴子跳过
        p=q->next;      //淘汰掉的猴子的下一只作为新p
        free(q);
    }
    king=p->num;
    free(p);
    printf("猴王是第%d只！\n",king);
    return 0;
}
