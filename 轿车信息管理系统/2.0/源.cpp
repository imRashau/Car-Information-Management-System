#include<iostream>
#include <stdlib.h> 
#include<Windows.h>
#include<mysql.h>
#include<iomanip>
#pragma comment(lib, "libmysql.lib")
using namespace std;

#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"wsock32.lib")
MYSQL* mysql = new MYSQL; //mysql����  
MYSQL_FIELD* fd;    //�ֶ�������  
char field[32][32];    //���ֶ�����ά����  
MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����  
MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���  
char query[150]; //��ѯ���  

bool ConnectDatabase();
bool QueryDatabase1();
bool QueryDatabase2();
int main()
{
    ConnectDatabase();
    QueryDatabase1();
    //QueryDatabase2();
    system("pause");
    return 0;
}


bool ConnectDatabase()
{
    //��ʼ��mysql  
    mysql_init(mysql);
    //����false������ʧ�ܣ�����true�����ӳɹ�  
    if (!(mysql_real_connect(mysql, "localhost", "root", "100861", "car", 3306, NULL, 0))) //�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ  
    {
        printf("����ʧ��\n", mysql_error(mysql));
        return false;
    }
    else
    {
        printf("���ӳɹ�\n");
        return true;
    }
    return true;
}

bool QueryDatabase1()
{

    sprintf_s(query, "insert into Carinformation( Number,Model,Colour,Manufacturer,date,Price��Stock) values(%d,'%s','%s','%s'��%d��%d��%d)", body.userName, body.userPass, body.connection, body.type); //ִ�в�ѯ��䣬�����ǲ�ѯ���У�user�Ǳ��������ü����ţ���strcpyҲ����  
    mysql_query(mysql, "set names gbk"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������  
    //����0 ��ѯ�ɹ�������1��ѯʧ��  
    if (mysql_query(mysql, query))    //ִ��SQL���
    {
        printf("��ѯʧ��\n", mysql_error(mysql));
        return false;
    }
    else
    {
        printf("��ѯ�ɹ�\n");
    }
}
 