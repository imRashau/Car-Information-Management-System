#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int num;//���ӵı��
    struct node *next;//��һ������
}node;

typedef struct node *linklist;

int main()
{
    linklist p,q,head;
    int king,i,m,n;
	printf("��������Ӹ��� m �ͱ��� n ��");
    scanf("%d%d",&m,&n);
    head=p=q=(linklist)malloc(sizeof(node));
    head->num=1;
    for(i=1;i<m;i++)
    {
        p=(linklist)malloc(sizeof(node));   //���½ڵ����ռ�
        p->num=i+1; //�����������ֵ
        q->next=p;
        q=p;        //���ýڵ�q���½ڵ���������
    }
    q->next=head;
    p=head;
    for(i=1;i<m;i++)
    {
		p=p->next;
        q=p->next;      //���д�����һ��ѭ���н�����ֻ���Ӹ���p���ٶ�p�����޳�����
        printf("��%d����̭��%dֻ���ӣ�\n",i,q->num);
        p->next=q->next;    //����̭���ĺ�������
        p=q->next;      //��̭���ĺ��ӵ���һֻ��Ϊ��p
        free(q);
    }
    king=p->num;
    free(p);
    printf("�����ǵ�%dֻ��\n",king);
    return 0;
}
