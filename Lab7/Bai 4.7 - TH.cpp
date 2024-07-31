#include <iostream>
#include<string>
using namespace std;
template<class T>
class MyPair
{
	T a, b;
public:
	MyPair(T a, T b)
	{
		this->a = a;
		this->b = b;
	}
	T MAX()
	{
		if (a > b)
			return a;
		else
			return b;	
	}
	void xuat()
	{
		cout << "a: " << a << "\tb: " << b << endl;
	}
};
int main()
{
	MyPair<int> pair1(1, 2);
	pair1.xuat();
	cout << "Max: " << pair1.MAX() << endl;
	MyPair<float> pair2(2.3, 5.6);
	pair2.xuat();
	cout << "Max: " << pair2.MAX() << endl;
	MyPair<string> pair3("a", "y");
	pair3.xuat();
	cout << "Max: " << pair3.MAX() << endl;
}
