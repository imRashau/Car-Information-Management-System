#include <stdio.h>
#define MaxSize 100
void king(int m, int n)
{
    int p[MaxSize];
    int i,j,t=0;
    for (i=0;i< m;i++)//������ʼ���У���¼mֻ������p[0]~p[m-1]��
        p[i]=i+1; //�״α�������ʼλ��Ϊ0
    printf("�����ı����:");
    for (i=m;i>=1;i--)//ѭ��Ҫִ��m�Σ���m������Ҫ��Ȧ������i��m��ʼ�ݼ���1��i����ʾ��Ȧ�к��ӵ���Ŀ
    {
        t=(t+n-1)%i;//��t��ʼ��1������n-1��������n��t��n-1��%iȡ�࣬Ŀ���ǵ������һ�����ӿ����ۻ�ȥ������
           //���Ϊp[t]��Ԫ�س���
        for (j=t+1;j<=i-1;j++)//�����Ԫ��ǰ��һ��λ�ã�ɾ���˱��Ϊp[t]�ĺ���
            p[j-1]=p[j];
    }
    printf("%d",p[t]);
}
int main()
{
    int m,n;
    printf("����m,n\n");
    scanf_s("%d%d",&m,&n);
    king(m,n);
    return 0;
}
