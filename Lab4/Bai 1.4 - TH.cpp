#include <iostream>
#include <string>

using namespace std;

class BenhNhan{
	protected:
		string ten;
		string que;
		int namSinh;
		
	public:
		void Nhap(){
			cout << "Nhap ho ten benh nhan: ";
			cin.ignore();
			getline(cin, ten);
			cout << "Nhap que quan: ";
			getline(cin, que);
			cout << "Nhap nam sinh: ";
			cin >> namSinh;
		}
		
		void Xuat(){
			cout << "Ho ten: " << ten << endl;
			cout << "Que quan: " << que << endl;
			cout << "Nam sinh: " << namSinh << endl;
		}
		
		int getNamSinh(){
			return namSinh;
		}
};

class BenhAn : public BenhNhan {
	private:
		string tenBA;
		double VienPhi;
		
	public:
		void Nhap(){
			BenhNhan :: Nhap();
			
			cout << "Nhap ten benh an: ";
			cin.ignore();
			getline (cin, tenBA);
			cout << "Nhap so tien vien phi: ";
			cin >> VienPhi;
		}
		
		void Xuat(){
			BenhNhan :: Xuat();
			
			cout << "Ten benh an: " << tenBA << endl;
			cout << "Vien phi: " << VienPhi << endl;
		}
		
		int Tuoi(int HienTai){
			return HienTai - getNamSinh();
		}
		
		double getVienPhi(){
			return VienPhi;
		}
};

int main(){
	int n;
	int HienTai;
	cout << "Nhap so luong benh an: ";
	cin >> n;
	cout << endl;
	cout << "Nhap nam hien tai: ";
	cin >> HienTai;
	cout << endl;
	
	BenhAn dsBA[n];
	
	cout << "Nhap thong tin danh sach benh an: " << endl;
	for(int i = 0; i < n; i++){
		cout << endl << "Nhap thong tin benh a thu " << i + 1 << ": " << endl;
		dsBA[i].Nhap();
		
		cout << endl;
	}
	
	cout << "DANH SACH XAP XEP BENH AN THEO TUOI GIAM DAN CUA CAC BENH NHAN: " << endl;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(dsBA[i].Tuoi(HienTai) < dsBA[j].Tuoi(HienTai)){
				BenhAn x;
				x = dsBA[i];
				dsBA[i] = dsBA[j];
				dsBA[j] = x;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << endl << "Thong tin benh an thu " << i + 1 << ": " << endl;
		dsBA[i].Xuat();
		
		cout << endl;
	}
	
	cout << "DANH SACH BENH AN CUA NHUNG BENH NHAN TREN 50 TUOI: " << endl;
	for(int i = 0; i < n; i++){
		if(dsBA[i].Tuoi(HienTai) > 50){
			cout << endl << "Thong tin benh an thu " << i + 1 << ": " << endl;
			dsBA[i].Xuat();
			
			cout << endl;
		}
	}
	
	cout << "THONG TIN BENH AN CO VIEN PHI CAO NHAT: " << endl;
	float maxVienPhi;
	int chisovp;
	maxVienPhi = dsBA[0].getVienPhi();
	int indemaxVienPhi = 0;
	for(int i = 1; i < n; i++){
		float vienphi = dsBA[i].getVienPhi();
		if(vienphi > maxVienPhi){
			maxVienPhi = vienphi;
			indemaxVienPhi = i;
		}
	}
	
	dsBA[indemaxVienPhi].Xuat();
	
	return 0;	
}
