#include<iostream>
#include<string>
using namespace std;
template<typename T>
T MAX(T a, T b, T c)
{
	T max = a;
	if (b > a)
		max = b;
	if (c > max)
		max = c;
	return max;
}
int main()
{
	int a = 1, b = 2, c = 3;
	cout << "-----So nguyen lon nhat: " << MAX(a, b, c) << endl;
	float x = 1.2, y = 2.3, z = 3.4;
	cout << "-----So thuc lon nhat: " << MAX(x, y, z) << endl;
	string m = "a", n = "y", p = "F";
	cout << "-----Ky tu lon nhat: " << MAX(m, n, p) << endl;
}
