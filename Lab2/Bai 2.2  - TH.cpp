#include <iostream>

using namespace std;

class PHANSO{
	private:
		int TuSo;
		int MauSo;
		
	public:
		int UCLN(int a, int b) {
	        while (b != 0) {
	            int temp = b;
	            b = a % b;
	            a = temp;
	        }
	        return a;
	    }
		
		void Nhap(){
			cout << "Nhap tu so: ";
			cin >> TuSo;
			
			cout << "Nhap mau so: ";
			cin >> MauSo;
		}
		
		void ToiGian(){
			int u = UCLN(TuSo, MauSo);
			TuSo /= u;	
			MauSo /= u;	
		}
		
		void Xuat(){
			cout << TuSo << "/" << MauSo << endl;
		}	
		
		PHANSO cong(PHANSO ps) {
	        PHANSO ketQua;
	        ketQua.TuSo = TuSo * ps.MauSo + ps.TuSo * MauSo;
	        ketQua.MauSo = MauSo * ps.MauSo;
	        ketQua.ToiGian();
	        return ketQua;
    	}
    
	    PHANSO nhan(PHANSO ps) {
	        PHANSO ketQua;
	        ketQua.TuSo = TuSo * ps.TuSo;
	        ketQua.MauSo = MauSo * ps.MauSo;
	        ketQua.ToiGian();
	        return ketQua;
	    }
};

int main(){
	int n;
	cout << "Nhap so luong phan so: ";
	cin >> n;
	cout << endl;
	
	PHANSO dsPS[n];
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan so thu " << i + 1 << ": " << endl;
        dsPS[i].Nhap(); 
        
        cout << endl;
    }
   
	cout << endl << "======= DANH SACH GOM " << n << " PHAN SO =======" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Phan so thu " << i + 1 << ": " << endl;
        dsPS[i].Xuat();
        
        cout << endl;
    }
    
    PHANSO tong = dsPS[0];
    PHANSO tich = dsPS[0];
    
    for (int i = 1; i < n; i++) {
		tong = tong.cong(dsPS[i]);
		tich = tich.nhan(dsPS[i]);
	}
	
	cout << "Tong cac phan so: ";
    tong.Xuat();
    cout << endl;

    cout << "Tich cac phan so: ";
    tich.Xuat();
    cout << endl;
    
    return 0;
}
