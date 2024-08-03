#include <iostream>
#include <string>

using namespace std;

class Basic{
	protected:
		int TimeGoi;
		int DonGiaGoi;
		int LuuLuong;
		int DonGiaInternet;
		
	public:
		Basic(int TGoi = 0, int GiaGoi = 1000, int ll = 0, int GiaInternet = 200) 
			: TimeGoi(TGoi), DonGiaGoi(GiaGoi), LuuLuong(ll), DonGiaInternet(GiaInternet){}
		virtual ~Basic(){}
		
		virtual void Nhap();
		virtual void Xuat();
		virtual int CuocDT();
		virtual int CuocInternet();
		virtual int CuocTong();
		void SuDung(int, int);
};

void Basic :: Nhap(){
	cout << "Nhap thoi gian goi: "; cin >> TimeGoi;
	cout << "Nhap luu luong su dung: "; cin >> LuuLuong;
} 

void Basic :: Xuat(){
	cout << "\t - Ten goi cuoc: Basic";
}

int Basic :: CuocDT(){
	return TimeGoi * DonGiaGoi;
}

int Basic

void Basic :: SuDung (int _TimeGoi, int _LuuLuong){
	TimeGoi += _TimeGoi;
	LuuLuong += _LuuLuong;
}

class HOPDONG{
	private:
		string hoTen;
		int soCMND;
		string diaChi;
		string goiCuoc;
		
	public:
		
}; 
