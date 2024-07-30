#include <iostream>
#include <string>

using namespace std;

class NGUOI {
	private:
		string hoTen;
		int tuoi;
		string ngheNghiep;
		string quocTich;
		
	public:
		NGUOI() : hoTen(""), tuoi(0), ngheNghiep(""), quocTich(""){
		}
		
		NGUOI(string ten, int t, string nghe, string QT) : hoTen(ten), tuoi(t), ngheNghiep(nghe), quocTich(QT){
		}
		
		~NGUOI(){}
		
		void Nhap(){
			cout << "Nhap ho ten: ";
			cin.ignore();
			getline(cin, hoTen);
			
			cout << "Nhap nghe nghiep: ";
			getline(cin, ngheNghiep);
			
			cout << "Nhap quoc tich: ";
			getline(cin, quocTich);
			
			cout << "Nhap tuoi: ";
			cin >> tuoi;
		}
		
		void Xuat(){
			cout << "Ho ten: " << hoTen << endl;
			cout << "Tuoi: " << tuoi << endl;
			cout << "Nghe nghiep: " << ngheNghiep << endl;
			cout << "Quoc tich: "<< quocTich << endl;
		}
		
		string getTen(){
			return hoTen;
		}
		
		int getTuoi(){
			return tuoi;
		}
		
		string getngheNghiep(){
			return ngheNghiep;
		}
		
		string getQuocTich(){
			return quocTich;
		}
};

int main(){
	int n;	
    cout << "Nhap so luong nguoi: ";
    cin >> n;
    
    NGUOI dsNG[n];
    
    cout << endl << "Nhap thong tin danh sach nguoi: " << endl;
    for(int i = 0; i < n; i++){
    	cout << "Nhap thong tin nguoi thu " << i + 1 << ": " << endl;
    	dsNG[i].Nhap();
    	
    	cout << endl;
	}
	
	cout << endl << "DANH SACH NGUOI THEO THU TU TANG DAN CUA TEN: " << endl;
	for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; j++) {
            if (dsNG[i].getTen() > dsNG[j].getTen()) {
                swap(dsNG[i], dsNG[j]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
		cout << "Thong tin nguoi thu " << i +1 << endl;
		dsNG[i].Xuat();
			
		cout << endl;
	}
	
	cout << endl << "NHUNG NGUOI CO NGHE NGHIEP LA BAC SI: " << endl;
	for(int i = 0; i < n; i++){
		if(dsNG[i].getngheNghiep() == "Bac si"){
			cout << "Thong tin nguoi thu " << i +1 << endl;
			dsNG[i].Xuat();
			
			cout << endl;
		}
	}
	
	string TimKiemQuocTich;
    cout << "Nhap quoc tich can tim: ";
    cin.ignore(1);
    getline(cin, TimKiemQuocTich);
    bool Test = false;
    cout << endl;

    for (int i = 0; i < n; i++) {
        if (dsNG[i].getQuocTich() == TimKiemQuocTich) {
        	cout << "Danh sach nhung nguoi co quoc tich " << TimKiemQuocTich << endl;
            dsNG[i].Xuat();
            
            cout << endl;
            Test = true;
        
			for (int j = i; j < n - 1; j++) {
	            dsNG[j] = dsNG[j + 1];
	        }
	        n--;
	        break;
        }
        if (Test) {
	        cout << "Da xoa nguoi co quoc tich " << TimKiemQuocTich << " khoi danh sach.\n";
		}
		else {
		    cout << "Khong tim thay nguoi co quoc tich " << TimKiemQuocTich << " trong danh sach.\n";
		}
    }
    
    string TimKiemTen;
    cout << "Nhap ten can tim: ";
    getline(cin, TimKiemTen);
    bool found = false;
    cout << endl;
    
	for (int i = 0; i < n; i++) {
        if (dsNG[i].getTen() == TimKiemTen) {
        	cout << "DANH SACH NHUNG NGUOI CO TEN CAN TIM: " << endl;
            dsNG[i].Xuat();
            found = true;
            break;
            
            cout << endl;
        }
        if (!found) {
        	cout << "Khong tim thay nguoi co ten " << TimKiemTen << " trong danh sach" << endl;
        	cout << "Nhap them thong tin cho nguoi: " << endl;
			dsNG[n].Nhap();
			n++;
			
			cout << endl;
		}	
    }
    
    int MaxTuoi;
    int chisoTuoi;
	MaxTuoi = dsNG[0].getTuoi();
	int indemaxTuoi = 0;
	for(int i = 1; i < n; i++){
		int tuoiTac = dsNG[i].getTuoi();
		if (tuoiTac > MaxTuoi){
			MaxTuoi = tuoiTac;
			indemaxTuoi = i;
		}
	}
	
	int MinTuoi;
    int chisotuoi;
	MinTuoi = dsNG[0].getTuoi();
	int indeminTuoi = 0;
	for(int i = 1; i < n; i++){
		int tuoitac = dsNG[i].getTuoi();
		if (tuoitac < MaxTuoi){
			MaxTuoi = tuoitac;
			indeminTuoi = i;
		}
	}
	
	cout << endl << "NGUOI LON TUOI NHAT LA: " << endl;
	dsNG[indemaxTuoi].Xuat();
	
	cout << endl << "NGUOI NHO TUOI NHAT LA :" << endl;
	dsNG[indeminTuoi].Xuat();
	
	return 0;
}
