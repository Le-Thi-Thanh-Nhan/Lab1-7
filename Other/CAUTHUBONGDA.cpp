#include <iostream>
#include <string>

using namespace std;

class NGUOI {
protected:
	string Ten;
	int Tuoi;
	int CCCD;
	
public:	
	NGUOI(string Ten = "", int Tuoi = 0, int CCCD = 0){
		this -> Ten = Ten;
		this -> Tuoi = Tuoi;
		this -> CCCD = CCCD;
	}
	~NGUOI(){}
	
	void Nhap (){
		cout << "Nhap ho ten: ";
		cin.ignore();
		getline (cin, Ten);
		cout << "Nhap tuoi: ";
		cin >> Tuoi;
		cout << "Nhap so can cuoc nhan dan: ";
		cin >> CCCD;
	}
	void Xuat (){
		cout << "Ho ten: " << Ten << endl;
		cout << "Tuoi: " << Tuoi << endl;
		cout << "So can cuoc nhan dan: " << CCCD << endl;
	}
};

class CAUTHU : public NGUOI {
	private:
		string viTriThiDau;
		int soBanThang;
		
	public:
		CAUTHU (string Ten = "", int Tuoi = 0, int CCCD = 0, string viTriThiDau = "", int soBanThang = 0) : NGUOI (Ten, Tuoi, CCCD) {
			this -> viTriThiDau = viTriThiDau;
			this -> soBanThang = soBanThang;
		}
		
	~CAUTHU (){}
	
	friend istream& operator >> (istream& is, CAUTHU& CT){
		CT.Nhap();
	
		cout << "Nhap vi tri thi dau: ";
		is >> CT.viTriThiDau;
		cout << "Nhap so ban thang: ";
		is >> CT.soBanThang;
		
		return is;
	}
	
	bool operator > (CAUTHU& CT) {
		return soBanThang > CT.soBanThang;
	}
	
	int getSoBanThang(){
		return soBanThang;
	}
	
	float PHUCAP(){
		if (Tuoi > 30)
			return 5000000;
		else if (Tuoi >20)
			return 3000000;
		else
			return 2000000;
	}
	friend ostream& operator << (ostream& os, CAUTHU& CT){
		CT.Xuat();
		
		os << "Vi tri thi dau: " << CT.viTriThiDau << endl;
		os << "So ban thang: " << CT.soBanThang << endl;
		os << "Phu cap: " << CT.PHUCAP() << endl;
		
		return os;
	}
};

int main(){
	int n;
	cout << "Nhap so luong nguoi: ";
	cin >> n;
	
	cin.ignore();
	NGUOI* dsNGUOI = new NGUOI[n];
	cout << "Nhap thong tin danh sach nguoi: " << endl;
	for (int i = 0; i < n; i++){
		cout << "Nhap thong tin nguoi thu " << i + 1 << ": " << endl;
		dsNGUOI[i].Nhap();
		
		cout << endl;
	}
	
	cout << endl << "============= DANH SACH NGUOI =================" << endl;
	for (int i = 0;i < n; i++){
		cout << "Thong tin nguoi thu " << i + 1 << ": " << endl;
		dsNGUOI[i].Xuat();
		
		cout << endl;
	}
	delete[] dsNGUOI;
	cout << endl << "======================================================" << endl;
	
	int m;
	cout << "Nhap so luong cau thu bong da: ";
	cin >> m;
	
	CAUTHU* dsCAUTHU = new CAUTHU[m];
	cout << "Nhap thong tin danh sach cau thu: " << endl;
	for (int i = 0; i < m; i++){
		cout << "Nhap thong tin cau thu thu " << i + 1 << ": " << endl;
		cin >> dsCAUTHU[i];
		
		cout << endl;
	}
	
	for (int i = 0; i < m - 1; i++) {
	    for (int j = i + 1; j < m; j++) {
		    if (dsCAUTHU[i].getSoBanThang() > dsCAUTHU[j].getSoBanThang()){
		        CAUTHU x;
		        x = dsCAUTHU[i];
		        dsCAUTHU[i] = dsCAUTHU[j];
		        dsCAUTHU[j] = x;
		    }
		}
	}
	
	cout << endl << "============= DANH SACH CAU THU BONG DA THEO THU TU TANG DAN CUA SO BAN THANG GHI DUOC =================" << endl;
	for (int i = 0; i < m; i++){
		cout << "Thong tin cau thu bong da thu " << i + 1 << ": " << endl;
		cout << dsCAUTHU[i];
		
		cout << endl;
	}
	
	delete[] dsCAUTHU;
	
	return 0;
}
