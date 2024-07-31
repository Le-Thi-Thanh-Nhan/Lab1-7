#include <iostream>
#include<math.h>
#include<vector>
using namespace std;

class PS
{
	int ts, ms;
public:
	PS(int ts=0, int ms=1)
	{
		this->ts = ts;
		this->ms = ms;
	}
	~PS() {}
	void input()
	{
		cout << "\t- Nhap tu so: "; cin >> ts;
		cout << "\t- Nhap mau so: "; cin >> ms;
	}
	void output()
	{
		cout << ts << "/" << ms<<"\t";
	}
	void rut_gon_ps()
	{
		int a = ts, b = ms;
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		ts /= a;
		ms /= a;
	}
	friend bool operator<(PS &ps1, PS &ps2)
	{
		return ps1.ts * ps2.ms < ps2.ts * ps1.ms;
	}
	PS operator+(PS &ps)
	{
		PS temp;
		temp.ts = this->ts * ps.ms + ps.ts * this->ms;
		temp.ms = this->ms * ps.ms;
		return temp;
	}
};

//Max
template<class T>
T MAX(T *arr[],int n)
{
	T max = arr[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
			}
		}
	return max;
}

//Sum
template<class T>
T SUM(T *arr[], int n)
{
	T sum ;
	for (int i = 0; i < n; i++)
	{			
		sum = sum + arr[i][i];
	}
	return sum;
}
//sort
template<class T>
void SORT(T* arr[], int n)
{
	for (int i = 0; i < n-1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i][i] < arr[j][j])
				continue;
			else
				swap(arr[i][i], arr[j][j]);
		}
}


int main()
{
	int n;
	cout << "Nhap chieu rong mang: "; cin >> n;
	PS **arr = new PS*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new PS[n];
	//nhap mang
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Phan tu thu " << i << "," << j << " : " << endl;
			arr[i][j].input();
		}
	//xuat mang
	cout << "\nMang vua nhap: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j].output();
		}
		cout << endl << endl;
	}
	//Max
	cout << "\nMax: ";
	PS max=MAX(arr, n);
	max.rut_gon_ps();
	max.output();
	//Tong phan tu tren duong cheo chinh
	cout << "\nTong cac phan tu tren duong cheo chinh: "; 
	PS sum = SUM(arr, n);
	sum.rut_gon_ps();
	sum.output();
	//sap xep
	cout << "\nMang sau sap xep: " << endl;
	SORT(arr, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j].output();
		}
		cout << endl << endl;;
	}
}
