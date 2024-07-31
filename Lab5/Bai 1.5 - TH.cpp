#include <iostream>
#include <string>

using namespace std;

class MONHOC{
	protected:
		string tenMonHoc;
		int soTiet;
		
	public:
		MONHOC(){}
		
		MONHOC(string tenMH, int st) : tenMonHoc(tenMH), soTiet(st){}
		
		
		~MONHOC(){}
		
		void Xuat(){
			cout << "Ten mon hoc: " << tenMonHoc << endl;
			cout << "So tiet: " << soTiet << endl;
		}
};

class NGUOI{
	protected:
		string hoTen;
		int namSinh;
		
	public:
		NGUOI(){}
		
		NGUOI(string ten, int ns) : hoTen(ten), namSinh(ns){}
		
		~NGUOI(){}
		
		void Xuat(){
			cout << "Ho ten: " << hoTen << endl;
			cout << "Nam sinh: " << namSinh << endl;
		}
};

class GIAOVIEN : public MONHOC, public NGUOI{
	private:
		string boMon;
		
	public:
		GIAOVIEN() : MONHOC(), NGUOI(){}
		
		GIAOVIEN(string tenMH, int soTiet, string hoTen, int namSinh, string mon)
			: MONHOC(tenMH, soTiet), NGUOI(hoTen, namSinh), boMon(mon){}
			
		~GIAOVIEN(){}
		
		void Xuat(){
			MONHOC :: Xuat();
			NGUOI :: Xuat();
			
			cout << "Bo mon: " << boMon << endl;
		}
};

int main(){
	GIAOVIEN *gv = new GIAOVIEN("LTHDT", 4, "LE THI THANH NHAN", 2004, "CNTT");
	
	gv -> Xuat();
	
	delete gv;
	
	return 0;
}

