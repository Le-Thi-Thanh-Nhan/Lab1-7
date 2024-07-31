#include<string>
#include <iostream>
#include<math.h>
using namespace std;

class NhanVien
{
	string ma, ho_ten;
	float he_so_luong, ngay_cong;
public:
	void xuat()
	{
		cout << "Ma nhan vien: "<< ma<<endl;
		cout << "Ho ten: "<< ho_ten<<endl;
		cout << "He so luong: "<<he_so_luong<<endl;
		cout << "Ngay cong: " << ngay_cong << endl;
	}
	friend istream& operator>>(istream &is, NhanVien &nv)
	{
		cout << "Nhap ma nhan vien: "; is >> nv.ma;
		cout << "Nhap ho ten: "; cin.ignore();  getline(is, nv.ho_ten);
		cout << "He so luong: "; is >> nv.he_so_luong;
		cout << "Nhap ngay cong: "; is >> nv.ngay_cong;
		return is;
	}
	friend ostream& operator<<(ostream& os, NhanVien nv)
	{
		os << "Ma nhan vien: " << nv.ma 
			<< "\tHo ten: " << nv.ho_ten 
			<< "\t\tHe so luong: " << nv.he_so_luong 
			<< "\tNgay cong: " << nv.ngay_cong << endl;
		return os;
	}
	friend bool operator<(NhanVien nv1, NhanVien nv2)
	{
		return nv1.ma < nv2.ma;
	}
};
//tao amng
template<class T>
void nhap_mang(T *arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n-----Thong tin nhan vien thu " << i+1 << " : " << endl;
		cin >> arr[i];
	}
}
//xuat mang
template<class T>
void xuat_mang(T *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << arr[i];
	}
}
//tong
template<class T>
T tong_phan_tu(T* arr, int n)
{
	T sum;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

//phan tu nho nhat
template<class T>
T MIN(T* arr, int n)
{
	T min=arr[0];
	for (int i = 0; i < n; i++)
	{
		if (!(arr[i] < i))
			min = arr[i];
	}
	return min;
}

//sap xep
template<class T>
void sap_xep(T *arr,int n)
{
	cout << "\n-----Mang sau sap xep: " << endl;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
				swap(arr[i], arr[j]);
		}

}

int main()
{
	int n;
	cout << "So luong nhan vien: "; cin >> n;
	NhanVien* nv = new NhanVien[n];
	nhap_mang(nv, n);
	xuat_mang(nv, n);

	sap_xep(nv, n);

	xuat_mang(nv, n);
}
