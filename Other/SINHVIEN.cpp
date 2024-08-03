#include <iostream>
#include <string>

using namespace std;

class NGUOI {
	protected:
		string Ten;
		int namSinh;
		int CMND;
		
	public:
		NGUOI (string Ten = "", int namSinh = 0, int CMND = 0){
			this -> Ten = Ten;
			this -> namSinh = namSinh;
			this -> CMND = CMND;
		}
		
		~NGUOI(){}
		
		void Nhap(){
			cout << "Nhap ho ten:";
			cin >> Ten;
			cout << "Nhap nam sinh:";
			cin >> namSinh;
			cout << "Nhap so chung minh nhan dan:";
			cin >> CMND;
		}
		
		void Xuat(){
			cout << "Ho ten:" << Ten << endl;
			cout << "Nam sinh:" << namSinh << endl;
			cout << "So chung minh nhan dan:" << CMND << endl;
		}
};

class SINHVIEN : public NGUOI {
	private:
		int maSV;
		string nganhHoc;
		float diemTB;
		
	public:
		SINHVIEN (string Ten = "", int namSinh = 0, int CMND = 0, int maSV = 0, string nganhHoc = "", float diemTB = 0) : NGUOI (Ten, namSinh, CMND) {
			this -> maSV = maSV;
			this -> nganhHoc = nganhHoc;
			this -> diemTB = diemTB;
		}
		
	~SINHVIEN (){}
	
	friend istream& operator >> (istream& is, SINHVIEN& SV){
		SV.Nhap();
	
		cout << "Nhap ma sinh vien: ";
		is >> SV.maSV;
		cout << "Nhap nganh hoc: ";
		cin.ignore();
		getline (is, SV.nganhHoc);
		cout << "Nhap diem trung binh: ";
		is >> SV.diemTB;
		
		return is;
	}
	
	bool operator < (SINHVIEN& SV) {
		return diemTB < SV.diemTB;
	}
	
	float getDiemTB(){
		return diemTB;
	}
	
	float HocBong (){
		if (diemTB >= 8)
			return 5000000;
		else if (diemTB > 7)
			return 3000000;
		else
			return 0;
	}
	
	friend ostream& operator << (ostream& os, SINHVIEN& SV){
		SV.Xuat();
		
		os << "Ma sinh vien: " << SV.maSV << endl;
		os << "Nganh hoc: " << SV.nganhHoc << endl;
		os << "Diem trung binh: " << SV.diemTB << endl;
		os << "So tien hoc bong: " << SV.HocBong() << endl;
		
		return os;
	}
};

int main(){
	int n;
	cout << "Nhap so luong nguoi: ";
	cin >> n;
	cout << endl;
	
	cin.ignore();
	NGUOI* dsNG = new NGUOI[n];

	for (int i = 0; i < n; i++){
		cout << "Nhap thong tin nguoi thu " << i + 1 << ": " << endl;
		dsNG[i].Nhap();
		cout << endl;
	}
	
	cout << endl << "============= DANH SACH NGUOI =================" << endl;
	for (int i = 0;i < n; i++){
		cout << "Thong tin nguoi thu " << i + 1 << ": " << endl;
		dsNG[i].Xuat();
		cout << endl;
	}
	delete[] dsNG;
	cout << endl << "==========================================" << endl;
	
	int m;
	cout << "Nhap so luong sinh vien: ";
	cin >> m;
	cout << endl;
	
	SINHVIEN* dsSV = new SINHVIEN[m];
	
	for (int i = 0; i < m; i++){
		cout << "Nhap thong tin sinh vien thu " << i + 1 << ": " << endl;
		cin >> dsSV[i];
		cout << endl;
	}
	
	for (int i = 0; i < m - 1; i++) {
	    for (int j = i + 1; j < m; j++) {
		    if (dsSV[i].getDiemTB() < dsSV[j].getDiemTB()){
		        SINHVIEN x;
		        x = dsSV[i];
		        dsSV[i] = dsSV[j];
		        dsSV[j] = x;
		    }
		}
	}
	
	cout << endl << "============= DANH SACH SINH VIEN CO DIEM TRUNG BINH GIAM DAN =================" << endl;
	for (int i = 0; i < m; i++){
		cout << "Thong tin sinh vien thu " << i + 1 << ": " << endl;
		cout << dsSV[i];
		cout << endl;
	}
	
	return 0;
}
