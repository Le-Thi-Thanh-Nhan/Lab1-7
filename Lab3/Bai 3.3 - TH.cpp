#include <iostream>
#include <cstring>
using namespace std;

class GV{
	private:
		char hoten[30];
		int tuoi;
		char bangcap[15];
		char chuyennganh[20];
		float bacluong;
	
	public:
		GV(const char* ht = "", int tuoi = 0, const char* bc = "", const char* cn = "", float bacluong = 0.0){
			strcpy(this->hoten, ht);
			this->tuoi = tuoi;
			strcpy(this->bangcap, bc);
			strcpy(this->chuyennganh, cn);
			this->bacluong = bacluong;
		}
	
	friend istream& operator >> (istream& is, GV& gv){
		cin.ignore();
		cout<<"Nhap ho ten: ";
		is.getline(gv.hoten,30);
		
		cout<<"Nhap tuoi: ";
		is>>gv.tuoi;
		
		cout<<"Nhap bang cap: ";
		is.ignore();
		is.getline(gv.bangcap,15);
		
		cout<<"Nhap chuyen nganh: ";
		is.getline(gv.chuyennganh,20);
		
		cout<<"Nhap bac luong: ";
		is>>gv.bacluong;
		
		return is;
	}
	
	friend ostream& operator << (ostream& os, const GV& gv){
		os<<"Ho ten: " << gv.hoten <<endl;
		os<<"Tuoi: " << gv.tuoi <<endl;
		os<<"Bang cap: " << gv.bangcap <<endl;
		os<<"Chuyen nganh: " << gv.chuyennganh <<endl;
		os<<"Bac luong: " << gv.bacluong <<endl;
		return os;
	}
	
	float TienLuong(){
		return bacluong * 610;
	}
	
	bool LuongNhoHon2000(){
		return TienLuong() < 2000;
	}
	
	char* gethoten(){
		return hoten;
	}
	
};

int main(){
	int n;
	cout<<"Nhap so luong giao vien: ";
	cin>>n;
	
	GV* gv = new GV[n];
	
	for(int i = 0; i < n; i++){
		cout<<"Nhap danh sach giao vien thu " << i + 1 << ":" <<endl;
		cin>>gv[i];
	}
	
	cout << "\nDanh sach cac giao vien co luong nho hon 2000:\n";
    bool coGV = false; 
    for (int i = 0; i < n; ++i) {
        if (gv[i].LuongNhoHon2000()) {
            cout << gv[i] << endl;
            coGV = true;
        }
    }
    
    if (!coGV) {
        cout << "Khong co giao vien nao co luong nho hon 2000.\n";
    }
	
    GV gvMoi;
    cout << "Nhap thong tin cho giao vien moi:\n";
    cin >> gvMoi;

    bool TonTai = false;
    for (int i = 0; i < n; ++i) {
        if (strcmp(gv[i].gethoten(), gvMoi.gethoten()) == 0) {
            cout << "Giao vien " << gvMoi.gethoten() << " co luong la: " << gv[i].TienLuong() << endl;
            TonTai = true;
            break;
        }
    }
    if (!TonTai && n < 100) {
        gv[n] = gvMoi;
    }

    cout << "\nDanh sach sau khi chen giao vien moi:\n";
    for (int i = 0; i < n; ++i) {
        cout << gv[i] << endl;
    }

    delete[] gv; 
    return 0;
}







