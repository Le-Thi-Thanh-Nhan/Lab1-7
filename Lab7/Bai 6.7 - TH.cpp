#include <iostream>
#include<string>
using namespace std;
template<class T>
class Array
{
	T arr[50];
	int size;
public:
	Array(T *p, int size)
	{
		this->size = size;
	}
	void input()
	{
		cout << "Nhap mang: " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "Nhap phan tu thu " << i + 1 << " : ";
			cin >> arr[i];
		}
	}
	void output()
	{
		for (int i = 0; i < size; i++)
		{			
			cout << arr[i]<<"\t";
		}
	}
	T SUM()
	{
		T sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		return sum;
	}
};
int main()
{
	int arr[50];
	int n;
	cout << "-----So phan tu mang: "; cin >> n;
	Array<int> a(arr, n);
	a.input();
	a.output();
	cout << "\n-----Tong cua mang: " << a.SUM() << endl;
}
