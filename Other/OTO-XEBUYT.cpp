#include <iostream>
#include <string>

using namespace std;

class OTO {
	protected:
		string hangSX;
		int soGhe;
		long int giaChuaThue;
		
	public:
		OTO (string hangSX = "", int soGhe = 0, long int giaChuaThue = 0){
			this -> hangSX = hangSX;
			this -> soGhe = soGhe;
			this -> giaChuaThue = giaChuaThue;
		}
		
		~OTO(){}
		
		void Nhap(){
			cout << "Nhap hang san xuat: ";
			cin.ignore();
			getline(cin, hangSX);
			cout << "Nhap so ghe: ";
			cin >> soGhe;
			cout << "Nhap gia chua thue: ";
			cin >> giaChuaThue;
		}
		
		void Xuat(){
			cout << "Hang san xuat: " << hangSX << endl;
			cout << "So ghe: " << soGhe << endl;
			cout << "Gia chua thue: " << giaChuaThue << endl;
		}
};

class XEBUYT : public OTO {
	private:
		string soTuyen;
		float trongTai;
		
	public:
		XEBUYT (string hangSX = "", int soGhe = 0, long int giaChuaThue = 0, string soTuyen = "", float trongTai = 0) : OTO (hangSX, soGhe, giaChuaThue) {
			this -> soTuyen = soTuyen;
			this -> trongTai = trongTai;
		}
		
	~XEBUYT (){}
	
	friend istream& operator >> (istream& is, XEBUYT& XB){
		XB.Nhap();
	
		cout << "Nhap so tuyen: ";
		cin.ignore();
		getline(is, XB.soTuyen);
		cout << "Nhap trong tai: ";
		is >> XB.trongTai;
		
		return is;
	}
	
	bool operator < (int soThuc) {
		return trongTai < soThuc;
	}
	
	float giaThanh(){
		return (giaChuaThue + giaChuaThue * 0.12);
	}
	
	float getTrongTai(){
		return trongTai;
	}
	
	friend ostream& operator << (ostream& os, XEBUYT& XB){
		XB.Xuat();
		
		os << "So tuyen: " << XB.soTuyen << endl;
		os << "Trong tai: " << XB.trongTai << endl;
		os << "Gia sau thue: " << XB.giaThanh() << endl;
		
		return os;
	}
};

int main(){
	int n;
	cout << "Nhap so luong o to: ";
	cin >> n;
	
	cin.ignore();
	OTO* dsOTO = new OTO[n];
	cout << "Nhap thong tin danh sach o to: " << endl;
	for (int i = 0; i < n; i++){
		cout << "Nhap thong tin o to thu " << i + 1 << ": " << endl;
		dsOTO[i].Nhap();
		
		cout << endl;
	}
	
	cout << endl << "============= DANH SACH O TO =================" << endl;
	for (int i = 0; i < n; i++){
		cout << "Thong tin o to thu " << i + 1 << ": " << endl;
		dsOTO[i].Xuat();
		
		cout << endl;
	}
	delete[] dsOTO;
	cout << endl << "======================================================" << endl;
	
	
	cout << "Nhap so luong xe buyt: ";
	cin >> n;
	
	XEBUYT* dsXEBUYT = new XEBUYT[n];
	cout << "Nhap thong tin danh sach xe buyt: " << endl;
	for (int i = 0; i < n; i++){
		cout << "Nhap thong tin xe buyt thu " << i + 1 << ": " << endl;
		cin >> dsXEBUYT[i];
		
		cout << endl;
	}
	
	cout << endl << "============= DANH SACH XE BUYT CO TRONG TAI TU 500 TRO LEN =================" << endl;
	for (int i = 0;i < n; i++){
		if (dsXEBUYT[i].getTrongTai() > 500){
			cout << "Thong tin xe buyt thu " << i + 1 << ": " << endl;
			cout << dsXEBUYT[i];
		}
		
		cout << endl;
	}
	delete[] dsXEBUYT;
	
	return 0;
}
