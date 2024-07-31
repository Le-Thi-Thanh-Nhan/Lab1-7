#include <iostream>
#include<string>
using namespace std;


//Tim phan tu max
template<class T>
T MAX(T arr[],int n)
{
	T max=arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max  < arr[i] )
			max = arr[i];
	}
	return max;
}

//Tong cac phan tu
template<class T>
T SUM(T arr[], int n)
{
	T sum=0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

//Doi cho 2 phan tu
template<class T>
void SWAP(T a, T b)
{
	T tg;
	tg = a;
	a = b;
	b = tg;
}

//Sap xep phan tu tang dan
template<class T>
void SORT(T arr[],int n)
{
	for (int i = 0; i < n-1; i++)
	{
		if (arr[i]  > arr[i + 1] )
		{
			SWAP(arr[i], arr[i + 1]);
		}
	}
}

//Dem phan tu khac gia tri cho truoc
template<class T>
T INDEXING(T arr[],int n, T number)
{
	int idx=0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != number)
			idx++;
	}
	return idx;
}

//Tim phan tu
template<class T>
T FIND(T arr[], int n, T number)
{

	for (int i = 0; i < n; i++)
	{
		if (arr[i]  == number )
			return i;
	}
}

//Xoa phan tu mang
template<class T>
void DEL(T arr[], int n, int k)
{
	for (int i = k; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
}

//Them phan tu
template<class T>
void ADD(T arr[], int n, int k)
{
	T a;
	cout << "Nhap gia tri muon them: ";
	cin>>a;
	n++;
	for (int i = n; i > k; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[k] = a;
}

int main()
{
	static int n;
	cout << "Nhap so phan tu mang: "; cin >> n;
	float arr[50];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu mang thu " << i << " : ";
		cin >> arr[i];
	}
	
	cout << "\n-----Mang vua nhap: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	
	cout << "\n-----Phan tu lon nhat tren mang: "<< MAX(arr, n);
	cout << endl;
	
	cout << "\n-----Tong cac phan tu mang: "<< SUM(arr, n);
	cout << endl;
	
	cout << "\n-----Sap xep mang: "; SORT(arr, n);
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			//SWAP(arr[i], arr[i + 1]);
		{
			float tg;
			tg = arr[i];
			arr[i] = arr[i+1];
			arr[i + 1] = tg;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	
	cout << "\n-----Dem phan tu mang khac voi x: " << endl;
	cout << "Nhap x: ";
	float x; cin >> x;
	cout << "So luong: " << INDEXING(arr, n, x) << endl;
	
	cout << "\n-----Tim phan tu theo gia tri X: " << endl;
	cout << "Nhap X: "; 
	float X; cin >> X;
	cout << "Vi tri: " << FIND(arr, n, X) << endl;
	
	cout << "\n-----Xoa phan tu o vi tri k:" << endl;
	cout << "Nhap k: "; int k; cin >> k;
	DEL(arr, n, k);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}

	cout << "\n-----Them phan tu o vi tri k:" << endl;
	cout << "Nhap k: "; int K; cin >> K;
	ADD(arr, n, K);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}
