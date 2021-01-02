#include <iostream>
 
using namespace std;
#define MAXSIZE 100 

typedef struct
{
	char data[50];
	int top;
}stack;//˳��ջ���Ͷ���

void newstack(stack *&S)//��ʼ��˳��ջ
{
	S=(stack*)malloc(sizeof(stack));
	S->top=-1;
} 
 
int push(stack*S,char e)//��ջ 
{
	if(S->top>49)
	{
		printf("in error!\n");
		return 0;
	}
	else
	{
		S->data[++S->top]=e;
		return 1;
	}
} 

int empty(stack*S)//�ж�ջ��
{
	if(S->top<0)
	    return 1;
	else
	    return 0; 
} 
 
char pop(stack*S)//��ջ
{
	char e;
	if(empty(S))
	{
		printf("out error!\n");
		return 0;
	}
	else
	{
		e=S->data[S->top--];
		return e;
	}
} 

int isnum(char e)//�ж��Ƿ�Ϊ���� 
{
	if(e>='0'&&e<='9')
	    return 1;
	else
	    return 0;
}

int num(char e)//�ַ���ת��Ϊ���� 
{
	int n;
	n=e-48;//ASCII�� 
	return n;
} 

char nonum(int n)//����ת��Ϊ�ַ��� 
{
	char e;
	e=n+48;//ASCII�� 
	return e;
}

int correct(char s[])//�ж������Ƿ�ƥ�� 
{
	stack *S;
	newstack(S);
	int flag=1,i=1;
	while(s[i]!='#'&&flag)
	{
		if(s[i]=='(')
		    push(S,s[i]);
		if(s[i]==')')
		    if(pop(S)!='(')
		        flag=0;
		i++;
	}//���������ĺ�����ǰ�ض�����֮��Ӧ��ǰ���ţ�����ƥ�䲻�ɹ�����flag��Ϊ0�������Ų�ƥ��
	if(!empty(S))
	    flag=0;
	return flag;
} 

int rank(char a,char b)//�ж���������ȼ������������ŵ����ȼ� 
{
	if((a=='*'||a=='/')&&(b=='+'||b=='-'))
	    return 1;
    else
        return 0;
}

void trans(char s1[],char s2[])//��׺���ʽת��Ϊ��׺���ʽ��s1Ϊ��׺���ʽ��s2Ϊ��׺���ʽ
{
	int i=1,j=0;
	char e;
	stack *S;
	newstack(S);
	while(s1[i]!='#')
	{
		if(isnum(s1[i]))//������ֱ����� 
		    s2[j++]=s1[i];
		else//������ţ����ŵĴ��� 
		{
			if(s1[i]=='(')//ǰ����ֱ����ջ 
			    push(S,s1[i]);
			if(s1[i]==')')//�������������ջ�������ֱ�����������ţ������ų�ջ������� 
				while((e=pop(S))!='(')
					s2[j++]=e;
			if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/')//ջ����ջ��ջ��Ϊ��������ջ�����ȼ�����ջ���������ջ�������ջ���ٴ��жϣ�ʵ��ʵ��ʱ�Ƚ����Ƿ��ջ�ж� 
			{
				while(!(empty(S)||S->data[S->top]=='('||rank(s1[i],S->data[S->top])))
				    s2[j++]=pop(S);
			    if((empty(S)||S->data[S->top]=='('||rank(s1[i],S->data[S->top])))
			        push(S,s1[i]);
			} 
			if(!(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='('||s1[i]==')'))
			    printf("�Ƿ��������\n"); //����������������ţ�+��-��*��/������)���⣬�����ж�Ϊ�Ƿ������
		}
		i++;
	}
	while(!empty(S))//���ʽ���Ͻ�ջ�������һһ��� 
	    s2[j++]=pop(S);
	s2[j]='\0';//�ַ�����β 
}

int workout(char s2[])//�����׺���ʽ��ֵ 
{
	int a,b,i=0;
	stack *S;
	newstack(S);
	while(s2[i]!='\0')
	{
		if(isnum(s2[i]))//������ջ�ȴ���������� 
		    push(S,s2[i++]);
		else
		{
			b=num(pop(S)); 
			a=num(pop(S));//�ַ���תΪ���ͽ������� 
		    switch(s2[i++])
		    {
		    	case'+':    a=a+b;    push(S,nonum(a));    break;
		    	case'-':    a=a-b;    push(S,nonum(a));    break;
		    	case'*':    a=a*b;    push(S,nonum(a));    break;
		    	case'/':    a=a/b;    push(S,nonum(a));    break;//�����תΪ�ַ�����ջ 
		    	default:    printf("error!");
			}
		}
	}
	if(S->top!=0)//ȱ�������ʱ�������ʾ������Ȼ����ջ��Ԫ�ص�ֵ��Ϊ���������
	{
		printf("ȱ����������õ��м�����\n");
	}
	a=num(pop(S));//�ַ���תΪ���δ��뷵��ֵ 
	return a;	
} 

int main()
{
	int ans;
	char s1[80],s2[80];
	printf("������ʽ:"); 
	gets(s1);
	if(!(correct(s1)))
	{
		printf("���Ų�ƥ�䣡");
		return 0;
	} 
	else
	{
	    trans(s1,s2);
	    printf("��׺���ʽ:"); 
	    puts(s2); 
	    ans=workout(s2);
	    printf("ans=%d\n",ans);
	    system("pause"); 
	    return 0;
	}
}
