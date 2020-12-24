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
		cout << "车轮数：" << wheels << endl;
		cout << "重量：" << weight << endl;

	}
};
class car :private vehicle//小汽车类
{
	int passenger;//载人数
public:
	car(int a, int b, int passenger1) :vehicle(a, b)
	{
		passenger = passenger1;
	}
	void show()
	{
		vehicle::show();
		cout << "小车类：" << endl;
		vehicle::show();
		cout << "载人数：" << passenger << endl;

	}
};
class truck :private vehicle//卡车类
{
	int passenger;//载人数
	int payload;//载重量
public:
	truck(int a, int b, int passenger1, int payload1) :vehicle(a, b)
	{
		passenger = passenger1;
		payload = payload1;
	}
	void show()
	{
		vehicle::show();
		cout << "卡车类：" << endl;
		vehicle::show();
		cout << "载人数：" << passenger << endl;
		cout << "载重量：" << payload << endl;

	}
};
int main()
{
	int wheels, weight, wheels_c, weight_c, passenger_c, wheels_t, weight_t, passenger_t, payload_t;
	cout << "输入vehicle的wheel和weight：" << endl;
	cin >> wheels >> weight;
	cout << "输入car的wheel、weight和passenger：" << endl;
	cin >> wheels_c >> weight_c >> passenger_c;
	cout << "输入truck的wheel、weight、passenger和payload：" << endl;
	cin >> wheels_t >> weight_t >> passenger_t >> payload_t;
	cout << "\n" << endl;

	cout << "vehicle：" << endl;
	vehicle v(wheels, weight);
	v.show();
	cout << "\n" << endl;

	cout << "car：" << endl;
	car c(wheels_c, weight_c, passenger_c);
	c.show();
	cout << "\n" << endl;

	cout << "truck：" << endl;
	truck t(wheels_t, weight_t, passenger_t, payload_t);
	t.show();
	cout << "\n" << endl;
}