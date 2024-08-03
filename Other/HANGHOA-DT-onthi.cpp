#include <iostream>
#include <string>
#include <list>

using namespace std;

class HANGHOA {
	protected:
		int MaHang;
		string TenHang;
		float DonGia;
		
	public:
		HANGHOA (int MaHang = 0, string TenHang = "", float DonGia = 0){
			this ->MaHang = MaHang;
			this ->TenHang = TenHang;
			this ->DonGia = DonGia;
		}
		
		~HANGHOA(){}
		
		void Nhap(){
			cout << "Nhap ma hang:";
			cin >> MaHang;
			cout << "Nhap ten hang:";
			cin >> TenHang;
			cout << "Nhap don gia:";
			cin >> DonGia;
		}
		
		void Xuat(){
			cout << "Ma hang:" << MaHang << endl;
			cout << "Ten hang:" << TenHang << endl;
			cout << "Don gia:" << DonGia << endl;
		}
};

class DT : public HANGHOA {
	private:
		float tenHDH;
		float soLuong;
		
	public:
		DT (int MaHang = 0, string TenHang = "", float DonGia = 0, float tenHDH = 0, float soLuong = 0) : HANGHOA (MaHang, TenHang, DonGia) {
			this -> tenHDH = tenHDH;
			this -> soLuong = soLuong;
		}
		
	~DT (){}
	
	friend istream& operator >> (istream& is, DT& dt){
		dt.Nhap();
	
		cout << "Nhap ten he dieu hanh: ";
		is >> dt.tenHDH;
		cout << "Nhap so luong dien thoai: ";
		is >> dt.soLuong;
		
		return is;
	}
	
	bool operator < (DT& dt) {
		return soLuong < dt.soLuong;
	}
	
	float getsoLuong(){
		return soLuong;
	}
	
	float ThanhTien (){
		return soLuong * DonGia;
	}
	
	friend ostream& operator << (ostream& os, DT& dt){
		dt.Xuat();
		
		os << "Ten he dieu hanh: " << dt.tenHDH << endl;
		os << "So luong may tinh: " << dt.soLuong << endl;
		os << "Thanh tien: " << dt.ThanhTien() << endl;
		
		return os;
	}
};

int main(){
	int n;
	cout << "Nhap so luong hang hoa: ";
	cin >> n;
	cout << endl;
	
	cin.ignore();
	HANGHOA* dsHH = new HANGHOA[n];

	for (int i = 0; i < n; i++){
		cout << endl;
		
		cout << "Nhap thong tin hang hoa thu " << i + 1 << ": " << endl;
		dsHH[i].Nhap();
		
		cout << endl;
	}
	
	cout << endl << "============= DANH SACH " << n << "HANG HOA =================" << endl;
	for (int i = 0;i < n; i++){
		cout << endl;
		
		cout << "Thong tin hang hoa thu " << i + 1 << ": " << endl;
		dsHH[i].Xuat();
		
		cout << endl;
	}
	delete[] dsHH;
	cout << endl << "======================================================================================" << endl;
	
	int m;
	cout << "Nhap so luong dien thoai: ";
	cin >> m;
	cout << endl;
	
	DT* dsdt = new DT[m];
	
	cout << endl << "Nhap danh sach dien thoai: " << endl;
	for (int i = 0; i < m; i++){
		cout << endl;
		
		cout << "Nhap thong tin dien thoai thu " << i + 1 << ": " << endl;
		cin >> dsdt[i];
		
		cout << endl;
	}
	
	cout << endl << "============= DANH SACH DIEN THOAI THEO THU TU GIAM DAN CUA SO LUONG =================" << endl;
	for(int i = 0; i < m; i++){
		for(int j = i + 1; j < m; j++){
			if(dsdt[i].getsoLuong() < dsdt[j].getsoLuong()){
				DT x;
				x = dsdt[i];
				dsdt[i] = dsdt[j];
				dsdt[j] = x;
			}
		}
	}
	
	for (int i = 0; i < m; i++){
    	cout << endl;
    		
		cout << "Thong tin may tinh thu " << i + 1 << ": " << endl;
		cout << dsdt[i];
		
		cout << endl;
	}
	
	delete[] dsdt;
	
	return 0;
}
