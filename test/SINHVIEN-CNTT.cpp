#include <iostream>
#include <string>

using namespace std;

class SINHVIEN {
	protected:
		string maSV;
		string Ten;
		string Lop;
		
	public:
		SINHVIEN (string maSV = "", string Ten = "", string Lop = ""){
			this -> maSV = maSV;
			this -> Ten = Ten;
			this -> Lop = Lop;
		}
		
		~SINHVIEN(){}
		
		void Nhap(){
			cout << "Nhap ma sinh vien: ";
			cin.ignore();
			getline(cin, maSV);
			cout << "Nhap ho ten sinh vien: ";
			getline(cin, Ten);
			cout << "Nhap ten lop: ";
			getline(cin, Lop);
		}
		
		void Xuat(){
			cout << "Ma sinh vien: " << maSV << endl;
			cout << "Ho ten sinh vien: " << Ten << endl;
			cout << "Lop: " << Lop << endl;
		}
};

class SVCNTT : public SINHVIEN {
	private:
		float DiemTH;
		string DiemRL;
		
	public:
		SVCNTT (string maSV = "", string Ten = "", string Lop = "", float DiemTH = 0, string DiemRL = "") : SINHVIEN (maSV, Ten, Lop) {
			this -> DiemTH = DiemTH;
			this -> DiemRL = DiemRL;
		}
		
	~SVCNTT(){}
	
	friend istream& operator >> (istream& is, SVCNTT& CNTT){
		CNTT.Nhap();
	
		cout << "Nhap diem thuc hanh: ";
		is >> CNTT.DiemTH;
		cout << "Nhap diem ren luyen: ";
		cin.ignore();
		getline(is, CNTT.DiemRL);
		
		return is;
	}
	
	bool operator == (string GiaTri) {
		return DiemRL == GiaTri;
	}
	
	string HocBong(){
		if (DiemRL == "A" && DiemTH >= 8.5)
			return "100%";
		else if (DiemRL == "A" && DiemTH >= 7)
			return "50%";
		else 
			return "0";
	}
	
	float getDiemTH(){
		return DiemTH;
	}
	
	friend ostream& operator << (ostream& os, SVCNTT& CNTT){
		CNTT.Xuat();
		
		os << "Diem thuc hanh: " << CNTT.DiemTH << endl;
		os << "Diem ren luyen: " << CNTT.DiemRL << endl;
		os << "Hoc bong: " << CNTT.HocBong() << endl;
		
		return os;
	}
};

int main(){
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cout << endl;
	
	cin.ignore();
	SINHVIEN* dsSV = new SINHVIEN[n];
	
	cout << "Nhap thong tin danh sach sinh vien: " << endl;
	for (int i = 0; i < n; i++){
		cout << "Nhap thong tin sinh vien thu " << i + 1 << ": " << endl;
		dsSV[i].Nhap();
		
		cout << endl;
	}
	
	cout << endl << "============= DANH SACH SINH VIEN =================" << endl;
	for (int i = 0;i < n; i++){
		cout << "Thong tin sinh vien thu " << i + 1 << ": " << endl;
		dsSV[i].Xuat();
		
		cout << endl;
	}
	delete[] dsSV;
	cout << endl << "======================================================" << endl;
	
	int m;
	cout << "Nhap so luong sinh vien cong nghe thong tin: ";
	cin >> m;
	cout << endl;
	
	cin.ignore();
	SVCNTT* dsSVCNTT = new SVCNTT[m];
	cout << "Nhap thong tin danh sach sinh vien cong nghe thong tin: " << endl;
	for (int i = 0; i < m; i++){
		cout << "Nhap thong tin sinh vien thu " << i + 1 << ": " << endl;
		cin >> dsSVCNTT[i];
		
		cout << endl;
	}
	
	cout << endl << "============= DANH SACH SINH VIEN CONG NGHE THONG TIN CO HOC BONG 100% =================" << endl;
	for (int i = 0;i < m; i++){
		if (dsSVCNTT[i].HocBong() == "100%"){
			cout << "Thong tin sinh vien thu " << i + 1 << ": " << endl;
			cout << dsSVCNTT[i];
			
			cout << endl;
		}
	}
	
	cout << endl << "============= DANH SACH SINH VIEN CONG NGHE THONG TIN THEO THU TU TANG DAN CUA DIEM THUC HANH =================" << endl;
	for (int i = 0; i < m - 1; i++) {
	    for (int j = i + 1; j < m; j++) {
		    if (dsSVCNTT[i].getDiemTH() > dsSVCNTT[j].getDiemTH()) {
		        SVCNTT x;
		        x = dsSVCNTT[i];
		        dsSVCNTT[i] = dsSVCNTT[j];
		        dsSVCNTT[j] = x;
		    }
		}
	}
	for (int i = 0;i < m; i++){
		cout << "Thong tin sinh vien thu " << i + 1 << ": " << endl;
		cout << dsSVCNTT[i];
		
		cout << endl;
	}
	
	delete[] dsSVCNTT;
	
	return 0;
}
