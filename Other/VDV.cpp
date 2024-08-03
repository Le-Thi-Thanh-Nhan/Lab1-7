#include <iostream>
#include <string>

using namespace std;

class VDV {
	protected:
		string Ten;
		float chieuCao;
		int soNamThiDau;
		
	public:
		VDV (string Ten = "", float chieuCao = 0, int soNamThiDau = 0){
			this -> Ten = Ten;
			this -> chieuCao = chieuCao;
			this -> soNamThiDau = soNamThiDau;
		}
		
		~VDV(){}
		
		void Nhap(){
			cout << "Nhap ho ten:";
			cin >> Ten;
			cout << "Nhap chieu cao:";
			cin >> chieuCao;
			cout << "Nhap so nam thi dau :";
			cin >> soNamThiDau;
		}
		
		void Xuat(){
			cout << "Ho ten:" << Ten << endl;
			cout << "Chieu cao:" << chieuCao << endl;
			cout << "So nam thi dau:" << soNamThiDau << endl;
		}
};

class DIENKINH : public VDV {
	private:
		int soHuyChuong;
		float cuLiThiDau;
		
	public:
		DIENKINH (string Ten = "", float chieuCao = 0, int soNamThiDau = 0, int soHuyChuong = 0, float cuLiThiDau = 0) : VDV (Ten, chieuCao, soNamThiDau) {
			this -> soHuyChuong = soHuyChuong;
			this -> cuLiThiDau = cuLiThiDau;
		}
		
	~DIENKINH (){}
	
	friend istream& operator >> (istream& is, DIENKINH& DK){
		DK.Nhap();
	
		cout << "Nhap so huy chuong: ";
		is >> DK.soHuyChuong;
		cout << "Nhap cu li thi dau: ";
		is >> DK.cuLiThiDau;
		
		return is;
	}
	
	bool operator > (DIENKINH& DK) {
		return soHuyChuong > DK.soHuyChuong;
	}
	
	float getSoHuyChuong(){
		return soHuyChuong;
	}
	
	float TienThuong (){
		return soHuyChuong * 2000000 + soNamThiDau * 1000000;
	}
	
	friend ostream& operator << (ostream& os, DIENKINH& DK){
		DK.Xuat();
		
		os << "So huy chuong dat duoc: " << DK.soHuyChuong << endl;
		os << "Cu li thi dau: " << DK.cuLiThiDau << endl;
		os << "So tien thuong: " << DK.TienThuong() << endl;
		
		return os;
	}
};

int main(){
	int n;
	cout << "Nhap so luong van dong vien: ";
	cin >> n;
	cout << endl;
	
	cin.ignore();
	VDV* dsVDV = new VDV[n];

	for (int i = 0; i < n; i++){
		cout << "Nhap thong tin van dong vien thu " << i + 1 << ": " << endl;
		dsVDV[i].Nhap();
		cout << endl;
	}
	
	cout << endl << "============= DANH SACH VAN DONG VIEN =================" << endl;
	for (int i = 0;i < n; i++){
		cout << "Thong tin van dong vien thu " << i + 1 << ": " << endl;
		dsVDV[i].Xuat();
		cout << endl;
	}
	delete[] dsVDV;
	cout << endl << "==========================================" << endl;
	
	int m;
	cout << "Nhap so luong van dong vien dien kinh: ";
	cin >> m;
	cout << endl;
	
	DIENKINH* dsDK = new DIENKINH[m];
	
	for (int i = 0; i < m; i++){
		cout << "Nhap thong tin van dong vien dien kinh " << i + 1 << ": " << endl;
		cin >> dsDK[i];
		cout << endl;
	}
	
	for (int i = 0; i < m - 1; i++) {
	    for (int j = i + 1; j < m; j++) {
		    if (dsDK[i].getSoHuyChuong() > dsDK[j].getSoHuyChuong()){
		        DIENKINH x;
		        x = dsDK[i];
		        dsDK[i] = dsDK[j];
		        dsDK[j] = x;
		    }
		}
	}
	
	cout << endl << "============= DANH SACH VAN DONG VIEN DIEN KINH THEO THU TU TANG DAN THEO SO HUY CHUONG DAT DUOC =================" << endl;
	for (int i = 0; i < m; i++){
		cout << "Thong tin van dong vien dien kinh thu " << i + 1 << ": " << endl;
		cout << dsDK[i];
		cout << endl;
	}
	
	return 0;
}
