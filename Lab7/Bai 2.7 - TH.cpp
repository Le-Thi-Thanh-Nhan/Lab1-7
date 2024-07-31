#include<iostream>
#include<string>
using namespace std;
template<class T>
void nhap(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "-----Nhap phan tu thu " << i + 1 << " : ";
		cin >> a[i];
	}
}
template<typename T>
void xuat(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
}
template<class T>
T tinhtong(T *a,int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}
int main()
{
	int a[50], n;
	cout << "-----Nhap so phan tu: "; cin >> n;
	nhap(a, n);
	cout << "\n-----Cac phan tu vua nhap: " << endl;
	xuat(a, n);
	cout << "\n-----Tong cua mang: " << tinhtong(a, n) << endl;
}
