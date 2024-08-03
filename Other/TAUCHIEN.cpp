#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class TAU {
	public:
		string hangsx;
		int namsx;
		float vantocmax;
		
		TAU (string hang = "", int nam = 0, float vantoc = 0){
			hangsx = hang;
			namsx = nam;
			vantocmax = vantoc;
		}
		~TAU (){};
	    
		void Nhap (){
			cout << "Nhap hang san xuat: ";
			cin.ignore();
        	getline(cin, hangsx);
        	cout << "Nhap nam san xuat: ";
        	cin >> namsx;
        	cout << "Nhap van toc toi da: ";
        	cin >> vantocmax;
		}
		void Xuat (){
			cout << "Hang san xuat: " << hangsx << endl;
			cout << "Nam san xuat: " << namsx << endl;
			cout << "Van toc toi da: " << vantocmax << endl;
		}
};
class TAUCHIEN : public TAU{
	public:
		int loaitau;
		float trongtai;
	
		TAUCHIEN (int loaitau = 0, float trongtai = 0){
			this -> loaitau = loaitau;
			this -> trongtai = trongtai;
		}
		
		~TAUCHIEN(){}
		
		float getTrongTai() {
	        return trongtai;
	    }
		
		friend istream& operator << (istream& is, TAUCHIEN& TC);

		float tienSuaChua (){
			if (namsx < 1990)
				return 50000000;
			else if (namsx < 2000)
				return 30000000;
			else 
				return 10000000;
		}
		
		bool operator<(TAUCHIEN& TC) {
        	return trongtai < TC.trongtai;
        
        
		friend ostream& operator << (ostream& os, TAUCHIEN& TC);
};

istream& operator >> (istream& is, TAUCHIEN& TC){
	TC.Nhap();
	cout << "Nhap loai tau: ";
	is >> TC.loaitau;
	cout << "Nhap trong tai: ";
	is >> TC.trongtai;
	
	return is;
}

ostream& operator << (ostream& os, TAUCHIEN& TC){
	TC.Xuat();
	os << "Loai tau: " << TC.loaitau << endl;
	os << "Trong tai: " << TC.trongtai << endl;
			
	return os;
}
void NhapDsTAU (TAU* ds, int n){
	for(int i =0; i < n; i++){
		cout << "Nhap thong tin cua tau thu: " << i + 1 << ": " << endl;
		ds[i].Nhap();
        cout << endl;
	}	
}
void HienthiDsTAU (TAU* ds, int n){
	for(int i = 0; i < n; i++){
        cout << "Thong tin tau thu " << i + 1 << ": " << endl;
        ds[i].Xuat();
        cout << endl;
    }
}
void NhapDsTAUCHIEN (TAUCHIEN* ds, int n){
	for(int i =0; i < n; i++){
		cout << "Nhap thong tin cua tau chien thu " << i + 1 << ": " << endl;
		ds[i].Nhap();
        cout << endl;
	}	
}
void HienthiDsTAUCHIEN (TAUCHIEN* ds, int n){
	
	for(int i = 0; i < n; i++){	
		cout << "Thong tin cua tau chien thu " << i + 1 << ": " << endl;
		ds[i].Xuat();
	}
	for (int i = 0; i < n - 1; i++) {
	    for (int j = i + 1; j < n; j++) {
	        if (ds[i].getTrongTai() > ds[j].getTrongTai()) {
	            TAUCHIEN x;
	            x = ds[i];
	            ds[i] = ds[j];
	            ds[j] = x;
	        }
	    }
	}
}
int main(){
	int n;
    
	cout << "Nhap so luong tau: ";
    cin >> n;
    
    TAU* dsTAU = new TAU[n];
    cout << endl << "Nhap thong tin cua cac tau: " << endl;
    NhapDsTAU(dsTAU, n);
    cout << endl << "Danh sach cac tau: " << endl;
    HienthiDsTAU(dsTAU, n);
    
    cout << "Nhap so luong tau chien: ";
    cin >> n;
    
	TAUCHIEN* dsTAUCHIEN = new TAUCHIEN[n];
    cout << endl << "Nhap thong tin cua tau chien: " << endl;
    NhapDsTAUCHIEN(dsTAUCHIEN, n);
    cout << endl << "Danh sach tau chien xep theo thu tu tang dan cua trong tai: " << endl;
    HienthiDsTAUCHIEN(dsTAUCHIEN, n);
    
    return 0;
}
