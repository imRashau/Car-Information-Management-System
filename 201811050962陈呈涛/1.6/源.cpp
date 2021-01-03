#include<iostream> 
#include <math.h> 
using namespace std;
class vehicle//������
{
protected:
	int wheels;// ������
	int weight;// ����
public:
	vehicle(int a, int b)
	{
		wheels = a;
		weight = b;
	}
	void show()
	{
		cout << "��������" << wheels << "��" << endl;
		cout << "��������" << weight << "Kg" << endl;

	}
};
class car :private vehicle//С������
{
	int passenger_load;//������
public:
	car(int a, int b, int passenger1) :vehicle(a, b)
	{
		passenger_load = passenger1;
	}
	void show()
	{
		vehicle::show();
		cout << "��������" << passenger_load << "��" << endl;

	}
};
class truck :private vehicle//������
{
	int passenger_load;//������
	int payload;//������
public:
	truck(int a, int b, int passenger1, int payload1) :vehicle(a, b)
	{
		passenger_load = passenger1;
		payload = payload1;
	}
	void show()
	{
		vehicle::show();
		cout << "��������" << passenger_load << "��" << endl;
		cout << "��������" << payload << "Kg" << endl;

	}
};
int main()
{
	int wheels, weight, wheels_c, weight_c, passenger_load_c, wheels_t, weight_t, passenger_load_t, payload_t;
	cout << "����������ĳ��ָ��������أ�" << endl;
	cin >> wheels >> weight;
	cout << "����С����ĳ��ָ��������ء���������" << endl;
	cin >> wheels_c >> weight_c >> passenger_load_c;
	cout << "���뿨����ĳ��ָ��������ء�����������������" << endl;
	cin >> wheels_t >> weight_t >> passenger_load_t >> payload_t;
	cout << "\n" ;

	cout << "�����ࣺ" << endl;
	vehicle v(wheels, weight);
	v.show();
	cout << "\n";

	cout << "С���ࣺ" << endl;
	car c(wheels_c, weight_c, passenger_load_c);
	c.show();
	cout << "\n";

	cout << "�����ࣺ" << endl;
	truck t(wheels_t, weight_t, passenger_load_t, payload_t);
	t.show();
	cout << "\n" ;
}