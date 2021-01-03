#include<iostream> 
#include <math.h> 
using namespace std;
class vehicle//汽车类
{
protected:
	int wheels;// 车轮数
	int weight;// 重量
public:
	vehicle(int a, int b)
	{
		wheels = a;
		weight = b;
	}
	void show()
	{
		cout << "车轮数：" << wheels << "个" << endl;
		cout << "车重量：" << weight << "Kg" << endl;

	}
};
class car :private vehicle//小汽车类
{
	int passenger_load;//载人数
public:
	car(int a, int b, int passenger1) :vehicle(a, b)
	{
		passenger_load = passenger1;
	}
	void show()
	{
		vehicle::show();
		cout << "载人数：" << passenger_load << "人" << endl;

	}
};
class truck :private vehicle//卡车类
{
	int passenger_load;//载人数
	int payload;//载重量
public:
	truck(int a, int b, int passenger1, int payload1) :vehicle(a, b)
	{
		passenger_load = passenger1;
		payload = payload1;
	}
	void show()
	{
		vehicle::show();
		cout << "载人数：" << passenger_load << "人" << endl;
		cout << "载重量：" << payload << "Kg" << endl;

	}
};
int main()
{
	int wheels, weight, wheels_c, weight_c, passenger_load_c, wheels_t, weight_t, passenger_load_t, payload_t;
	cout << "输入汽车类的车轮个数、车重：" << endl;
	cin >> wheels >> weight;
	cout << "输入小车类的车轮个数、车重、载人数：" << endl;
	cin >> wheels_c >> weight_c >> passenger_load_c;
	cout << "输入卡车类的车轮个数、车重、载人数、载重量：" << endl;
	cin >> wheels_t >> weight_t >> passenger_load_t >> payload_t;
	cout << "\n" ;

	cout << "汽车类：" << endl;
	vehicle v(wheels, weight);
	v.show();
	cout << "\n";

	cout << "小车类：" << endl;
	car c(wheels_c, weight_c, passenger_load_c);
	c.show();
	cout << "\n";

	cout << "卡车类：" << endl;
	truck t(wheels_t, weight_t, passenger_load_t, payload_t);
	t.show();
	cout << "\n" ;
}