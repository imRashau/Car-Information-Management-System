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
	void init();//��ʼ��
	void function();//����ѡ��
	void secede();//�˳�
	void Input();//����
	void display();//��ʾ
	void search();//����Ų���
	void search1();//���ͺŲ���
	void delete1();//ɾ��
	void modify();//�޸�
private:
	MYSQL mysql, * sock; //����mysql�ľ�� 
	const char* host = "localhost"; //��������
	const char* user = "root"; //mysql�û��� 
	char passwd[100] = {}; //�û����� 
	const char* db = "car"; //������Ϣ���ݿ�
	unsigned int port = 3306; //mysql�������˿�������3306
	const char* unix_socket = NULL; //unix_socket
	unsigned long client_flag = 0; //����һ��Ϊ0 
	MYSQL_RES* result; //��������
	MYSQL_ROW row; //������ǽ�����е�һ�� 
	unsigned int	num_fields;//�����ĳ�е�����
	char query_sql[800] = {};//���sql���
	int number;//���
	char model[50] = {};//�ͺ�
	char colour[50] = {};//��ɫ
	char manufacturer[50] = {};//�����̼�
	int  date;//��������
	int price;//�۸�
	int stock;//���
};
void sys::init() //��ʼ��ϵͳ
{
	mysql_init(&mysql); //����֮ǰ����ʹ�������������ʼ�� 
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	cout << "��mysql�����ӣ�������mysql����" << endl;
	cin.get(passwd, 100);
	if ((sock = mysql_real_connect(&mysql, host, user, passwd, db, port, unix_socket, client_flag)) == NULL) //����MySQL 
	{
		cout << "��mysql��������ʧ��" << endl;
		cout << mysql_error(&mysql) << endl;//���������Ϣ
		exit(1);//�˳�����
	}
	else
	{
		cout << "��Mysql���������ӳɹ�" << endl;
	}
}
void sys::secede()//�˳�ϵͳ
{
	cout << "�˳�ϵͳ" << endl;
	exit(0);

}

void sys::Input()
{
	cout << "������Ҫ�������Ϣ�ĸ���";
	int x;
	cin >> x;
	while (x--)
	{
		cout << "�����������ı�š��ͺš���ɫ���������ҡ��������ڡ��۸񡢿��" << endl;
		cin >> number >> model >> colour >> manufacturer >> date >> price >> stock;
		sprintf_s(query_sql,
			"insert into carinformation(number, model ,colour , manufacturer , date , price , stock ) values(%d,'%s','%s','%s',%d,%d,%d)"
			, number, model, colour, manufacturer, date, price, stock);
		if (mysql_query(&mysql, query_sql) != 0) //mysql_query��������SQL���,�ɹ�����0
		{
			cout << "sql�����ִ���" << endl;
			cout << mysql_error(&mysql) << endl;//sql��������Ϣ
			cout << "����ʧ��" << endl;
		}
		else
		{

			cout << "����ɹ�" << endl;

		}
	}
}

		
void sys::display()
{
	//��ʾ
	sprintf_s(query_sql, "select * from carinformation");
	if (mysql_query(&mysql, query_sql) != 0) //mysql_query��������SQL���,�ɹ�����0
	{
		cout << "sql�����ִ���" << endl;
		cout << mysql_error(&mysql) << endl;//sql��������Ϣ
	}
	else
	{

		result = mysql_store_result(&mysql);
		if (result == NULL) //�����ѯ�Ľ�� 
		{
			if (mysql_field_count(&mysql) != 0)
			{
				cout << "û�з��ؽ��" << endl;
			}
		}
		else
		{
			cout << "���    �ͺ�     ��ɫ �������� ��������  �۸�   ���" << endl;
			while ((row = mysql_fetch_row(result)) != NULL) //��ȡ������е�����
			{
				num_fields = mysql_num_fields(result);
				for (unsigned i = 0; i < num_fields; i++)
				{
					printf(" %s\t", row[i]);
				}//��ӡ��ǰ�е����� 
				printf("\n");
			}
		}

	}
	mysql_free_result(result); //�ͷŽ���� 
}
void sys::search()
{
	//����Ų���
	cout << "������Ҫ��ѯ�ĳ��ı��" << endl;
	cin >> number;
	sprintf_s(query_sql, "SELECT * FROM carinformation where number=%d", number);
		if (mysql_query(&mysql, query_sql) != 0) //mysql_query��������SQL���,�ɹ�����0
		{
			cout << "sql�����ִ���" << endl;
			cout << mysql_error(&mysql) << endl;//sql��������Ϣ
		}
		else
		{

			result = mysql_store_result(&mysql);
			if (result == NULL) //�����ѯ�Ľ�� 
			{
				if (mysql_field_count(&mysql) == 0)
				{
					cout << "û�з��ؽ��" << endl;
				}

			}
			else
			{
				cout << "���    �ͺ�     ��ɫ �������� ��������   �۸�  ���" << endl;
				while ((row = mysql_fetch_row(result)) != NULL) //��ȡ������е�����
				{
					num_fields = mysql_num_fields(result);
					for (unsigned i = 0; i < num_fields; i++)
					{
						printf(" %s\t", row[i]);
					}//��ӡ��ǰ�е����� 
					printf("\n");
				}
			}

		}
	mysql_free_result(result); //�ͷŽ���� 
}
void sys::search1()
{
	//���ͺŲ���
	cout << "������Ҫ��ѯ�ĳ����ͺ�" << endl;
	cin >> model;
	sprintf_s(query_sql, "SELECT * FROM carinformation where model='%s'", model);
	if (mysql_query(&mysql, query_sql) != 0) //mysql_query��������SQL���,�ɹ�����0
	{
		cout << "sql�����ִ���" << endl;
		cout << mysql_error(&mysql) << endl;//sql��������Ϣ
	}
	else
	{

		result = mysql_store_result(&mysql);
		if (result == NULL) //�����ѯ�Ľ�� 
		{
			if (mysql_field_count(&mysql) == 0)
			{
				cout << "û�з��ؽ��" << endl;
			}

		}
		else
		{
			cout << "���    �ͺ�     ��ɫ �������� ��������   �۸�  ���" << endl;
			while ((row = mysql_fetch_row(result)) != NULL) //��ȡ������е�����
			{
				num_fields = mysql_num_fields(result);
				for (unsigned i = 0; i < num_fields; i++)
				{
					printf(" %s\t", row[i]);
				}//��ӡ��ǰ�е����� 
				printf("\n");
			}
		}

	}
	mysql_free_result(result); //�ͷŽ���� 
}
void sys::delete1()
{
	cout << "������Ҫɾ�����������" << endl;
	cin >> number;
	sprintf_s(query_sql,
		"DELETE FROM carinformation WHERE Number=%d", number);
	if (mysql_query(&mysql, query_sql) != 0) //mysql_query��������SQL���,�ɹ�����0
	{
		cout << "sql�����ִ���" << endl;
		cout << mysql_error(&mysql) << endl;//sql��������Ϣ
		cout << "ɾ��ʧ��" << endl;
	}
	else
	{

		cout << "ɾ���ɹ�" << endl;

	}

}
void sys::modify()
{
	cout << "������Ҫ�޸ĵ���Ϣ�ı��" << endl;
	cin >> number;
	cout << "��ֱ�����Ҫ�޸ĵ��ͺš���ɫ���������ҡ��������ڡ��۸񡢿��" << endl;
	cin >> model >> colour >> manufacturer >> date >> price >> stock; 
	sprintf_s(query_sql,
		"update carinformation set Model='%s',Colour='%s',Manufacturer='%s',date=%d, price=%d,stock=%d where Number=%d"
		, model, colour, manufacturer, date, price, stock, number);
	if (mysql_query(&mysql, query_sql) != 0) //mysql_query��������SQL���,�ɹ�����0
	{
		cout << "sql�����ִ���" << endl;
		cout << mysql_error(&mysql) << endl;//sql��������Ϣ
		cout << "�޸���Ϣʧ��" << endl;
	}
	else
	{

		cout << "�޸���Ϣ�ɹ�" << endl;

	}


}

void sys::function()
{
	cout << "������������ϵͳ" << endl << endl;
	cout << "1.������Ϣ" << endl;
	cout << "2.��ʾ��Ϣ" << endl;
	cout << "3.����Ų�����Ϣ" << endl;
	cout << "4.���ͺŲ�����Ϣ" << endl;
	cout << "5.ɾ����Ϣ" << endl;
	cout << "6.�޸���Ϣ" << endl;
	cout << "7.�˳�" << endl;
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
		cout << "��������Ҫ���еĲ���" << endl;
		cin >> function_ch;
		while (function_ch > 7 || function_ch < 1)
		{
			cout << "�����������������" << endl;
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
		cout << endl << "����������,������E,�����˳�ϵͳ" << endl;
		cin >> if_ch;
		if (if_ch != 'E')
			break;
	}
	cout << "�ɹ��˳�ϵͳ" << endl;
	exit(0);
}