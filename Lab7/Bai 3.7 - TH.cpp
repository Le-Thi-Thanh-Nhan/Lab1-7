
#include<iostream>
#include<string>
using namespace std;
template<class T>
class PS
{
	T ts, ms;
public:
	PS(T ts=0, T ms=0)
	{
		this->ts = ts;
		this->ms = ms;
	}
	//nhap ps
	void nhap()
	{
		cout << "Nhap tu so:"; cin >> ts;
		cout << "Nhap mau so: "; cin >> ms;
	}
	//in ra phan so
	void xuat()
	{
		cout << ts << "/" << ms<<"\t";
	}
	//gia tri cua phan so
	T value()
	{
		return ts / ms;
	}


};
//nhap mang
template<class T>
void nhapmang(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Phan tu mang thu " << i + 1 << " : " << endl;
		a[i].nhap();
	}
}
//xuat mang
template<class T>
void xuatmang(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].xuat();
	}
}
//tim ps nho nhat
template<class T>
T MIN(T *a, int n)
{
	T min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (min.value() > a[i].value())
			min = a[i];
	}
	return min;
}
int main()
{
	int n;
	cout << "-----Nhap so phan tu mang: "; cin >> n;
	PS<float> a[50];
	nhapmang(a, n);
	cout << "\n-----Mang vua nhap: " << endl;
	xuatmang(a, n);
	cout << "\n-----Phan so nho nhat: ";
	MIN(a, n).xuat();
}

