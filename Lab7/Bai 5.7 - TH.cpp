#include <iostream>
#include<string>
using namespace std;
template<class T>
class Cal
{
	T a, b;
public:
	Cal(T a, T b)
	{
		this->a = a;
		this->b = b;
	}
	void print()
	{
		cout << "a: " << a << "\t\tb: " << b << endl;
	}
	T add()
	{
		return a + b;
	}
	T sub()
	{
		return a - b;
	}
	T mul()
	{
		return a * b;
	}
	T div()
	{
		return a / b;
	}
	T MAX()
	{
		return a > b ? a : b;
	}
};
int main()
{
	Cal<float> pair1(3, 4);
	pair1.print();
	cout << "Tong: " << pair1.add() << endl;
	cout << "Hieu: " << pair1.sub() << endl;
	cout << "Tich: " << pair1.mul() << endl;
	cout << "Thuong: " << pair1.div() << endl;
	cout << "Max: " << pair1.MAX() << endl;
}
