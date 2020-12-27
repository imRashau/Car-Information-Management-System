#include <iostream>
 
using namespace std;
#define MAXSIZE 100 

typedef struct
{
	char data[50];
	int top;
}stack;//顺序栈类型定义

void newstack(stack *&S)//初始化顺序栈
{
	S=(stack*)malloc(sizeof(stack));
	S->top=-1;
} 
 
int push(stack*S,char e)//进栈 
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

int empty(stack*S)//判断栈空
{
	if(S->top<0)
	    return 1;
	else
	    return 0; 
} 
 
char pop(stack*S)//出栈
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

int isnum(char e)//判断是否为数字 
{
	if(e>='0'&&e<='9')
	    return 1;
	else
	    return 0;
}

int num(char e)//字符型转换为整型 
{
	int n;
	n=e-48;//ASCII码 
	return n;
} 

char nonum(int n)//整型转换为字符型 
{
	char e;
	e=n+48;//ASCII码 
	return e;
}

int correct(char s[])//判断括号是否匹配 
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
	}//最先遇到的后括号前必定是与之对应的前括号，如若匹配不成功，则flag记为0，即括号不匹配
	if(!empty(S))
	    flag=0;
	return flag;
} 

int rank(char a,char b)//判断运算符优先级，不包括括号的优先级 
{
	if((a=='*'||a=='/')&&(b=='+'||b=='-'))
	    return 1;
    else
        return 0;
}

void trans(char s1[],char s2[])//中缀表达式转换为后缀表达式，s1为中缀表达式，s2为后缀表达式
{
	int i=1,j=0;
	char e;
	stack *S;
	newstack(S);
	while(s1[i]!='#')
	{
		if(isnum(s1[i]))//是数字直接输出 
		    s2[j++]=s1[i];
		else//运算符号，括号的处理 
		{
			if(s1[i]=='(')//前括号直接入栈 
			    push(S,s1[i]);
			if(s1[i]==')')//遇到后括号输出栈顶运算符直至遇到左括号，左括号出栈但不输出 
				while((e=pop(S))!='(')
					s2[j++]=e;
			if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/')//栈空入栈，栈顶为左括号入栈，优先级高于栈顶运算符入栈，否则出栈并再次判断，实际实现时先进行是否出栈判断 
			{
				while(!(empty(S)||S->data[S->top]=='('||rank(s1[i],S->data[S->top])))
				    s2[j++]=pop(S);
			    if((empty(S)||S->data[S->top]=='('||rank(s1[i],S->data[S->top])))
			        push(S,s1[i]);
			} 
			if(!(s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/'||s1[i]=='('||s1[i]==')'))
			    printf("非法运算符！\n"); //除过四则运算和括号（+、-、*、/、（、)）外，其余判定为非法运算符
		}
		i++;
	}
	while(!empty(S))//表达式读毕将栈内运算符一一输出 
	    s2[j++]=pop(S);
	s2[j]='\0';//字符串结尾 
}

int workout(char s2[])//计算后缀表达式的值 
{
	int a,b,i=0;
	stack *S;
	newstack(S);
	while(s2[i]!='\0')
	{
		if(isnum(s2[i]))//数字入栈等待运算符操作 
		    push(S,s2[i++]);
		else
		{
			b=num(pop(S)); 
			a=num(pop(S));//字符型转为整型进行运算 
		    switch(s2[i++])
		    {
		    	case'+':    a=a+b;    push(S,nonum(a));    break;
		    	case'-':    a=a-b;    push(S,nonum(a));    break;
		    	case'*':    a=a*b;    push(S,nonum(a));    break;
		    	case'/':    a=a/b;    push(S,nonum(a));    break;//运算后转为字符型入栈 
		    	default:    printf("error!");
			}
		}
	}
	if(S->top!=0)//缺少运算符时，输出提示，但仍然带回栈顶元素的值作为运算结果输出
	{
		printf("缺少运算符！得到中间结果！\n");
	}
	a=num(pop(S));//字符型转为整形带入返回值 
	return a;	
} 

int main()
{
	int ans;
	char s1[80],s2[80];
	printf("输入表达式:"); 
	gets(s1);
	if(!(correct(s1)))
	{
		printf("括号不匹配！");
		return 0;
	} 
	else
	{
	    trans(s1,s2);
	    printf("后缀表达式:"); 
	    puts(s2); 
	    ans=workout(s2);
	    printf("ans=%d\n",ans);
	    system("pause"); 
	    return 0;
	}
}
