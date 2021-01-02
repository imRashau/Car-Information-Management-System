#include <stdio.h>
#include<iostream>
#include <stdlib.h> 
#include<Windows.h>
#include<mysql.h>
#include<iomanip>
#pragma comment(lib, "libmysql.lib")
using namespace std;
class sys {
public:
	void init();//初始换
	void function();//功能选择
	void secede();//退出
	void Input();//输入
	void display();//显示
	void search();//按编号查找
	void search1();//按型号查找
	void delete1();//删除
	void modify();//修改
private:
	MYSQL mysql, * sock; //声明mysql的句柄 
	const char* host = "localhost"; //本机连接
	const char* user = "root"; //mysql用户名 
	char passwd[100] = {}; //用户密码 
	const char* db = "car"; //汽车信息数据库
	unsigned int port = 3306; //mysql服务器端口设置在3306
	const char* unix_socket = NULL; //unix_socket
	unsigned long client_flag = 0; //参数一般为0 
	MYSQL_RES* result; //保存结果集
	MYSQL_ROW row; //代表的是结果集中的一行 
	unsigned int	num_fields;//结果集某行的列数
	char query_sql[800] = {};//存放sql语句
	int number;//编号
	char model[50] = {};//型号
	char colour[50] = {};//颜色
	char manufacturer[50] = {};//生产商家
	int  date;//生产日期
	int price;//价格
	int stock;//库存
};
void sys::init() //初始化系统
{
	mysql_init(&mysql); //连接之前必须使用这个函数来初始化 
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	cout << "与mysql的链接，请输入mysql密码" << endl;
	cin.get(passwd, 100);
	if ((sock = mysql_real_connect(&mysql, host, user, passwd, db, port, unix_socket, client_flag)) == NULL) //连接MySQL 
	{
		cout << "与mysql建立连接失败" << endl;
		cout << mysql_error(&mysql) << endl;//输出错误信息
		exit(1);//退出程序
	}
	else
	{
		cout << "与Mysql服务器连接成功" << endl;
	}
}
void sys::secede()//退出系统
{
	cout << "退出系统" << endl;
	exit(0);

}

void sys::Input()
{
	cout << "请输入要输入的信息的个数";
	int x;
	cin >> x;
	while (x--)
	{
		cout << "请输入汽车的编号、型号、颜色、生产厂家、出厂日期、价格、库存" << endl;
		cin >> number >> model >> colour >> manufacturer >> date >> price >> stock;
		sprintf_s(query_sql,
			"insert into carinformation(number, model ,colour , manufacturer , date , price , stock ) values(%d,'%s','%s','%s',%d,%d,%d)"
			, number, model, colour, manufacturer, date, price, stock);
		if (mysql_query(&mysql, query_sql) != 0) //mysql_query函数运行SQL语句,成功返回0
		{
			cout << "sql语句出现错误" << endl;
			cout << mysql_error(&mysql) << endl;//sql语句错误信息
			cout << "输入失败" << endl;
		}
		else
		{

			cout << "输入成功" << endl;

		}
	}
}

		
void sys::display()
{
	//显示
	sprintf_s(query_sql, "select * from carinformation");
	if (mysql_query(&mysql, query_sql) != 0) //mysql_query函数运行SQL语句,成功返回0
	{
		cout << "sql语句出现错误" << endl;
		cout << mysql_error(&mysql) << endl;//sql语句错误信息
	}
	else
	{

		result = mysql_store_result(&mysql);
		if (result == NULL) //保存查询的结果 
		{
			if (mysql_field_count(&mysql) != 0)
			{
				cout << "没有返回结果" << endl;
			}
		}
		else
		{
			cout << "编号    型号     颜色 生产厂家 出厂日期  价格   库存" << endl;
			while ((row = mysql_fetch_row(result)) != NULL) //读取结果集中的数据
			{
				num_fields = mysql_num_fields(result);
				for (unsigned i = 0; i < num_fields; i++)
				{
					printf(" %s\t", row[i]);
				}//打印当前行的数据 
				printf("\n");
			}
		}

	}
	mysql_free_result(result); //释放结果集 
}
void sys::search()
{
	//按编号查找
	cout << "请输入要查询的车的编号" << endl;
	cin >> number;
	sprintf_s(query_sql, "SELECT * FROM carinformation where number=%d", number);
		if (mysql_query(&mysql, query_sql) != 0) //mysql_query函数运行SQL语句,成功返回0
		{
			cout << "sql语句出现错误" << endl;
			cout << mysql_error(&mysql) << endl;//sql语句错误信息
		}
		else
		{

			result = mysql_store_result(&mysql);
			if (result == NULL) //保存查询的结果 
			{
				if (mysql_field_count(&mysql) == 0)
				{
					cout << "没有返回结果" << endl;
				}

			}
			else
			{
				cout << "编号    型号     颜色 生产厂家 出厂日期   价格  库存" << endl;
				while ((row = mysql_fetch_row(result)) != NULL) //读取结果集中的数据
				{
					num_fields = mysql_num_fields(result);
					for (unsigned i = 0; i < num_fields; i++)
					{
						printf(" %s\t", row[i]);
					}//打印当前行的数据 
					printf("\n");
				}
			}

		}
	mysql_free_result(result); //释放结果集 
}
void sys::search1()
{
	//按型号查找
	cout << "请输入要查询的车的型号" << endl;
	cin >> model;
	sprintf_s(query_sql, "SELECT * FROM carinformation where model='%s'", model);
	if (mysql_query(&mysql, query_sql) != 0) //mysql_query函数运行SQL语句,成功返回0
	{
		cout << "sql语句出现错误" << endl;
		cout << mysql_error(&mysql) << endl;//sql语句错误信息
	}
	else
	{

		result = mysql_store_result(&mysql);
		if (result == NULL) //保存查询的结果 
		{
			if (mysql_field_count(&mysql) == 0)
			{
				cout << "没有返回结果" << endl;
			}

		}
		else
		{
			cout << "编号    型号     颜色 生产厂家 出厂日期   价格  库存" << endl;
			while ((row = mysql_fetch_row(result)) != NULL) //读取结果集中的数据
			{
				num_fields = mysql_num_fields(result);
				for (unsigned i = 0; i < num_fields; i++)
				{
					printf(" %s\t", row[i]);
				}//打印当前行的数据 
				printf("\n");
			}
		}

	}
	mysql_free_result(result); //释放结果集 
}
void sys::delete1()
{
	cout << "请输入要删除的汽车编号" << endl;
	cin >> number;
	sprintf_s(query_sql,
		"DELETE FROM carinformation WHERE Number=%d", number);
	if (mysql_query(&mysql, query_sql) != 0) //mysql_query函数运行SQL语句,成功返回0
	{
		cout << "sql语句出现错误" << endl;
		cout << mysql_error(&mysql) << endl;//sql语句错误信息
		cout << "删除失败" << endl;
	}
	else
	{

		cout << "删除成功" << endl;

	}

}
void sys::modify()
{
	cout << "请输入要修改的信息的编号" << endl;
	cin >> number;
	cout << "请分别输入要修改的型号、颜色、生产厂家、出厂日期、价格、库存" << endl;
	cin >> model >> colour >> manufacturer >> date >> price >> stock; 
	sprintf_s(query_sql,
		"update carinformation set Model='%s',Colour='%s',Manufacturer='%s',date=%d, price=%d,stock=%d where Number=%d"
		, model, colour, manufacturer, date, price, stock, number);
	if (mysql_query(&mysql, query_sql) != 0) //mysql_query函数运行SQL语句,成功返回0
	{
		cout << "sql语句出现错误" << endl;
		cout << mysql_error(&mysql) << endl;//sql语句错误信息
		cout << "修改信息失败" << endl;
	}
	else
	{

		cout << "修改信息成功" << endl;

	}


}

void sys::function()
{
	cout << "进入汽车管理系统" << endl << endl;
	cout << "1.输入信息" << endl;
	cout << "2.显示信息" << endl;
	cout << "3.按编号查找信息" << endl;
	cout << "4.按型号查找信息" << endl;
	cout << "5.删除信息" << endl;
	cout << "6.修改信息" << endl;
	cout << "7.退出" << endl;
}
int main()
{
	int function_ch;
	char if_ch;
	sys carsys;
	carsys.init();
	carsys.function();
	
	while (1)
	{
		cout << endl;
		cout << "请输入你要进行的操作" << endl;
		cin >> function_ch;
		while (function_ch > 7 || function_ch < 1)
		{
			cout << "输入错误，请重新输入" << endl;
			cin >> function_ch;
		}
		switch (function_ch)
		{
		case 1:carsys.Input(); break;
		case 2:carsys.display(); break;
		case 3:carsys.search(); break;
		case 4:carsys.search1(); break;
		case 5:carsys.delete1(); break;
		case 6:carsys.modify(); break;
		case 7:carsys.secede();

		}
		cout << endl << "如果你想继续,请输入E,否则退出系统" << endl;
		cin >> if_ch;
		if (if_ch != 'E')
			break;
	}
	cout << "成功退出系统" << endl;
	exit(0);
}