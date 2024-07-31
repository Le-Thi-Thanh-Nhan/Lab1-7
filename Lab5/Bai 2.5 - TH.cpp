#include <iostream>
#include <string>

using namespace std;

class NGUOI{
	protected:
		string hoTen;
		int namSinh;
		
	public:
		NGUOI(string ten = "", int ns = 0) : hoTen(ten), namSinh(ns){}
		
		friend istream& operator >> (istream& is, NGUOI& NG){
			cout << "Nhap ho ten: ";
			cin.ignore();
			getline(is, NG.hoTen);
			cout << "Nhap nam sinh: ";
			is >> NG.namSinh;
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, NGUOI& NG){
			os << "Ho ten: " << NG.hoTen << endl;
			os << "Nam sinh: " << NG.namSinh << endl;
			
			return os;
		}
};

class SINHVIEN{
	protected:
		string hanhKiem;
		double Diem;
		
	public:
		SINHVIEN(string hk = "", double diem = 0) : hanhKiem(hk), Diem(diem){}
		
		~SINHVIEN(){}
		
		friend istream& operator >> (istream& is, SINHVIEN& SV){
			cout << "Nhap hanh kiem: ";
			cin.ignore();
			getline(is, SV.hanhKiem);
			cout << "Nhap diem: ";
			cin >> SV.Diem;
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, SINHVIEN& SV){
			os << "Hanh kiem: " << SV.hanhKiem << endl;
			os << "Diem: " << SV.Diem << endl;
			
			return os;
		}
		
		double getDiem(){
			return Diem;
		}
};

class SVTC : public NGUOI, public SINHVIEN{
	private:
		double hocPhi; 
	
	public:
		friend istream& operator >> (istream& is, SVTC& svtc){
			is >> (NGUOI&)svtc;
			is >> (SINHVIEN&)svtc;
			
			cout << "Nhap hoc phi: ";
			is >> svtc.hocPhi;
			
			return is;
		}
		
		double HocBong(){
			if(hanhKiem == "Tot" && Diem >= 8)
				return 5;
			else if(hanhKiem == "Tot" && Diem >= 7)
				return 3;
			else if(hanhKiem == "Kha" && Diem >= 7)
				return 2;
			else
				return 0;
		}
		
		friend ostream& operator << (ostream& os, SVTC& svtc){
			os << (NGUOI&)svtc;
			os << (SINHVIEN&)svtc;
			
			os << "Hoc phi: " << svtc.hocPhi << endl;
			os << "Hoc bong: " << svtc.HocBong() << " trieu" << endl;
			
			return os;
		}
};

int main(){
	int n;
	cout << "Nhap so luong sinh vien tai chuc: ";
	cin >> n;
	cout << endl;
	
	SVTC dsSVTC[n];
	
	cout << "Nhap danh sach " << n << " sinh vien tai chuc: " << endl;
	for(int i = 0; i < n; i++){
		cout << "Nhap thong tin sinh vien tai chuc thu " << i + 1 << ": " << endl;
		cin >> dsSVTC[i];
		
		cout << endl;
	}
	
	cout << "DANH SACH " << n << " SINH VIEN TAI CHUC VUA NHAP: " << endl;
	for(int i = 0; i < n; i++){
		cout << "Thong tin sinh vien cong tac thu " << i + 1 << ": " << endl;
		cout << dsSVTC[i];
		
		cout << endl;
	}
	
	cout << "DANH SACH SINH VIEN DAT HOC BONG: " << endl;
	for(int i = 0; i < n; i++){
		if(dsSVTC[i].HocBong() != 0){
			cout << "Thong tin sinh vien thu " << i + 1 << ": " << endl;
			cout << dsSVTC[i];
			
			cout << endl;
		}
	}
	
	cout << "DANH SACH SINH VIEN TAI CHUC XAP XEP THEO CHIEU TANG DAN CUA DIEM: "  << endl;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(dsSVTC[i].getDiem() > dsSVTC[j].getDiem()){
				SVTC x;
				x = dsSVTC[i];
				dsSVTC[i] = dsSVTC[j];
				dsSVTC[j] = x;
			}
			
		}
	}
	for (int i = 0; i < n; i++){
		cout << "Thong tin sinh vien thu " << i + 1 << ": " << endl;
		cout << dsSVTC[i];
		
		cout << endl;
	}
	
	return 0;
}
