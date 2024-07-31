#include <iostream>
#include <string>

using namespace std;

class STUDENT{
	protected:
		int maSV;
		string hoTen;
		string gioiTinh;
		
	public:
		STUDENT(int ma = 0, string ten = "", string gt = "") : maSV(ma), hoTen(ten), gioiTinh(gt){}
		
		~STUDENT(){}
		
		friend istream& operator >> (istream& is, STUDENT& hs){
			cout << "Nhap ma sinh vien: ";
			is >> hs.maSV;
			cout << "nhap ho ten: ";
			cin.ignore();
			getline(is, hs.hoTen);
			cout << "Nhap gioi tinh: ";
			getline(is, hs.gioiTinh);
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, STUDENT& hs){
			os << "Ma sinh vien: " << hs.maSV << endl;
			os << "Ho ten: " << hs.hoTen << endl;
			os << "Gioi tinh: " << hs.gioiTinh << endl;
			
			return os;
		}
		
		string getGioiTinh(){
			return gioiTinh;
		}
		
		string getTen(){
			return hoTen;
		}
};

class MONHOC{
	protected:
		int maMon;
		string tenMon;
		
	public:
		MONHOC(int maM = 0, string tenM = "") : maMon(maM), tenMon(tenM){}
		
		~MONHOC(){}
		
		friend istream& operator >> (istream& is, MONHOC& mon){
			cout << "Nhap ma mon: ";
			is >> mon.maMon;
			cout << "Nhap ten mon hoc: ";
			cin.ignore();
			getline(is, mon.tenMon);
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, MONHOC& mon){
			os << "Ma mon: " << mon.maMon << endl;
			os << "Ten mon hoc: " << mon.tenMon << endl;
			
			return os;
		}
		
		string getTenMon(){
			return tenMon;
		}
};

class DIEMMH : public STUDENT, public MONHOC{
	private:
		double diemThi;
		
	public:
		DIEMMH(int maSV = 0, string hoTen = "", int maMon = 0, string tenMon = "", double diem = 0)
			: STUDENT(maSV, hoTen), MONHOC(maMon, tenMon), diemThi(diem){}
			
		~DIEMMH(){}
		
		friend istream& operator >> (istream& is, DIEMMH& Diem){
			is >> (STUDENT&)Diem;
			is >> (MONHOC&)Diem;
			
			cout << "Nhap diem thi: ";
			is >> Diem.diemThi;
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, DIEMMH& Diem){
			os << (STUDENT&)Diem;
			os << (MONHOC&)Diem;
			
			os << "Diem thi: " << Diem.diemThi << endl;
			
			return os;
		}
		
		double getDiem(){
			return diemThi;
		}
};

int main(){
	int n;
	cout << "Nhap so luong: ";
	cin >> n;
	cout << endl;
	
	DIEMMH dsDiem[n];
	
	cout << "Nhap thong tin cho danh sach: " << endl;
	for(int i = 0; i < n; i++){
		cout << "Nhap thong tin doi tuong thu " << i + 1<< ": " << endl;
		cin >> dsDiem[i];
		
		cout << endl;
	}
	
	cout << "DANH SACH VUA NHAP: " << endl;
	for(int i = 0; i < n; i++){
		cout << "Thong tin doi tuong thu " << i + 1 << ": " << endl;
		cout << dsDiem[i];
		
		cout << endl;
	}
	
	cout << "DANH SACH SINH VIEN NAM: " << endl;
	for(int i = 0; i < n; i++){
		if(dsDiem[i].getGioiTinh() == "Nam"){
			cout << "Thong thi sinh vien thu " << i + 1 << ": " << endl;
			cout << dsDiem[i];
		}
	}
	
	double Sum = 0;
	for(int i = 0; i < n; i++){
		Sum += dsDiem[i].getDiem();
	}
	double diemTB = Sum / n;
	cout << "DIEM TRUNG BINH CUA CAC MON HOC: " << diemTB << endl;
	
	string tenSV;
	cout << "Nhap ten sinh vien can tim: ";
	cin.ignore();
	getline(cin, tenSV);
	
	bool findSV = false;
	for(int i = 0; i < n; i++){
		if(dsDiem[i].getTen() == tenSV){
			cout << "Thong tin diem cua sinh vien " << tenSV << ": " << endl;
			cout << dsDiem[i];
			findSV = true;
			break;
		}
	}
	if(!findSV){
		cout << "Khong tim thay sinh vien ten " << tenSV << "." << endl;
	}
	
	double minDiem;
    int indexMinDiem = -1;
    for (int i = 0; i < n; ++i) {
        if (dsDiem[i].getTenMon() == "Toan" && dsDiem[i].getDiem() < minDiem) {
            minDiem = dsDiem[i].getDiem();
            indexMinDiem = i;
        }
    }
    if (indexMinDiem != -1) {
        cout << "Thong tin diem mon hoc Toan co diem thi nho nhat:" << endl;
        dsDiem[indexMinDiem];
    } else {
        cout << "Khong tim thay diem mon hoc Toan" << endl;
    }
    
    cout << "DANH SACH DIEM MON HOC THEO CHIEU GIAM CUA DIEM THI: " << endl;
    for(int i = 0; i < n - 1; i++){
    	for(int j = i + 1; j < n; j++){
    		if(dsDiem[i].getDiem() < dsDiem[j].getDiem()){
    			DIEMMH x;
    			x = dsDiem[i];
    			dsDiem[i] = dsDiem[j];
    			dsDiem[j] = x;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << "Thong tin diem thu " << i + 1 << ": " << endl;
		cout << dsDiem[i];
		
		cout << endl;
	}
	
	return 0;
}
