#include<iostream>
#include <stdlib.h> 
#include<Windows.h>
#include<mysql.h>
#include<iomanip>
#pragma comment(lib, "libmysql.lib")
using namespace std;

#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"wsock32.lib")
MYSQL* mysql = new MYSQL; //mysql连接  
MYSQL_FIELD* fd;    //字段列数组  
char field[32][32];    //存字段名二维数组  
MYSQL_RES* res; //这个结构代表返回行的一个查询结果集  
MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列  
char query[150]; //查询语句  

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
    //初始化mysql  
    mysql_init(mysql);
    //返回false则连接失败，返回true则连接成功  
    if (!(mysql_real_connect(mysql, "localhost", "root", "100861", "car", 3306, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去  
    {
        printf("连接失败\n", mysql_error(mysql));
        return false;
    }
    else
    {
        printf("连接成功\n");
        return true;
    }
    return true;
}

bool QueryDatabase1()
{

    sprintf_s(query, "insert into Carinformation( Number,Model,Colour,Manufacturer,date,Price，Stock) values(%d,'%s','%s','%s'，%d，%d，%d)", body.userName, body.userPass, body.connection, body.type); //执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以  
    mysql_query(mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码  
    //返回0 查询成功，返回1查询失败  
    if (mysql_query(mysql, query))    //执行SQL语句
    {
        printf("查询失败\n", mysql_error(mysql));
        return false;
    }
    else
    {
        printf("查询成功\n");
    }
}
 