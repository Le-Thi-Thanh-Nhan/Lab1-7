#include <iostream>
#include <string>

using namespace std;

class SANPHAM {
	protected:
		int maSP;
		string tenSP;
		int giaSP;
		
	public:
		SANPHAM(int maSP = 0, string tenSP = "", int giaSP = 0){
			this -> maSP = maSP;
			this -> tenSP = tenSP;
			this -> giaSP = giaSP;
		}
		
		~SANPHAM(){}
		
		void Nhap(){
			cout << "Nhap ma san pham: ";
			cin >> maSP;
			cout << "Nhap ten san pham: ";
			cin.ignore();
			getline(cin, tenSP);
			cout << "Nhap don gia san pham: ";
			cin >> giaSP;
		}
		
		void Xuat(){
			cout << "Ma san pham: " << maSP << endl;
			cout << "Ten san pham: " << tenSP << endl;
			cout << "Gia san pham: " << giaSP << endl;
		}
};

class DIEUHOA : public SANPHAM {
	private:
		float congSuat;
		
	public:
		DIEUHOA (int maSP = 0, string tenSP = "", int giaSP = 0, float congSuat = 0) : SANPHAM (maSP, tenSP, giaSP){
			this -> congSuat = congSuat;
		}
		
		~DIEUHOA(){}
		
		friend istream& operator >> (istream& is, DIEUHOA& DH){
			DH.Nhap();
			
			cout << "Nhap cong suat lam lanh cua dieu hoa: ";
			is >> DH.congSuat;
			
			return is;
		}
		
		float donBan(){
			if (congSuat < 9000)
				return giaSP * 1.1;
			else if (congSuat < 18000)
				return giaSP * 1.2;
			else
				return giaSP * 1.3;
		}
		
		bool operator == (int soThuc){
			return congSuat == soThuc;
		}
		
		string getHangsx() {
			return tenSP;
		}
		
		float getcongSuat() {
			return congSuat;
		}
		
		friend ostream& operator << (ostream& os, DIEUHOA& DH){
			DH.Xuat();
			
			os << "Cong suat lam lanh cua dieu hoa: " << DH.congSuat << "BTU" << endl;
			os << "Don gia ban: " << DH.donBan() << endl;
			
			return os;
		}
};

int main(){
	int n;
	cout << "Nhap so luong san pham: ";
	cin >> n;
	cin.ignore();
	SANPHAM* dsSP = new SANPHAM[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin san pham thu " << i + 1 << ":" << endl;
        dsSP[i].Nhap();
    }
   
    cout << endl << "Danh sach san pham:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Thong tin san pham thu " << i + 1 << ":" << endl;
        dsSP[i].Xuat();
    }
    delete[] dsSP;
	cout << endl;
	
	int m;
	cout << "Nhap so luong dieu hoa: ";
    cin >> m;
    cin.ignore();
    DIEUHOA* dsDH = new DIEUHOA[m];
    for (int i = 0; i < m; i++) {
        cout << "Nhap thong tin dieu hoa thu " << i + 1 << ":" << endl;
        cin >> dsDH[i];
	}
    
    cout << endl << "Danh sach cac dieu hoa: " << endl;
	for(int i = 0; i < m; i++){
        if(dsDH[i].getcongSuat() == 9000 && dsDH[i].getHangsx() == "Panasonic"){
            cout << "Thong tin dieu hoa thu " << i + 1 << ": "<< endl;
            cout << dsDH[i] << endl;
        }
    }
	
    return 0;
}
