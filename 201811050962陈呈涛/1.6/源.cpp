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
		cout << "��������" << wheels << endl;
		cout << "������" << weight << endl;

	}
};
class car :private vehicle//С������
{
	int passenger;//������
public:
	car(int a, int b, int passenger1) :vehicle(a, b)
	{
		passenger = passenger1;
	}
	void show()
	{
		vehicle::show();
		cout << "С���ࣺ" << endl;
		vehicle::show();
		cout << "��������" << passenger << endl;

	}
};
class truck :private vehicle//������
{
	int passenger;//������
	int payload;//������
public:
	truck(int a, int b, int passenger1, int payload1) :vehicle(a, b)
	{
		passenger = passenger1;
		payload = payload1;
	}
	void show()
	{
		vehicle::show();
		cout << "�����ࣺ" << endl;
		vehicle::show();
		cout << "��������" << passenger << endl;
		cout << "��������" << payload << endl;

	}
};
int main()
{
	int wheels, weight, wheels_c, weight_c, passenger_c, wheels_t, weight_t, passenger_t, payload_t;
	cout << "����vehicle��wheel��weight��" << endl;
	cin >> wheels >> weight;
	cout << "����car��wheel��weight��passenger��" << endl;
	cin >> wheels_c >> weight_c >> passenger_c;
	cout << "����truck��wheel��weight��passenger��payload��" << endl;
	cin >> wheels_t >> weight_t >> passenger_t >> payload_t;
	cout << "\n" << endl;

	cout << "vehicle��" << endl;
	vehicle v(wheels, weight);
	v.show();
	cout << "\n" << endl;

	cout << "car��" << endl;
	car c(wheels_c, weight_c, passenger_c);
	c.show();
	cout << "\n" << endl;

	cout << "truck��" << endl;
	truck t(wheels_t, weight_t, passenger_t, payload_t);
	t.show();
	cout << "\n" << endl;
}