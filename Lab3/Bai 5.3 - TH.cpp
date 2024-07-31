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
	    
		PHANSO(int TuSo = 0, int MauSo = 1){
			this -> TuSo = TuSo;
			this -> MauSo = MauSo;
		}
		
		~PHANSO(){}
	
		void ToiGian(){
			int u = UCLN(TuSo, MauSo);
			TuSo /= u;	
			MauSo /= u;	
		}
		
		PHANSO operator + (PHANSO& PS){
			PHANSO Tong; 	
			Tong.TuSo = TuSo * PS.MauSo + MauSo * PS.TuSo;
			Tong.MauSo = MauSo * PS.MauSo; 		
			Tong.ToiGian();
			
			return Tong;
		}
		
		PHANSO operator - (PHANSO& PS){
			PHANSO Hieu; 	
			Hieu.TuSo = TuSo * PS.MauSo - MauSo * PS.TuSo;
			Hieu.MauSo = MauSo * PS.MauSo; 		
			Hieu.ToiGian();
			
			return Hieu;
		}
		
		PHANSO operator * (PHANSO& PS){
			PHANSO Tich; 	
			Tich.TuSo = TuSo * PS.TuSo;
			Tich.MauSo = MauSo * PS.MauSo; 		
			Tich.ToiGian();
			
			return Tich;
		}
		
		PHANSO operator / (PHANSO& PS){
			PHANSO Thuong; 	
			Thuong.TuSo = TuSo * PS.MauSo;
			Thuong.MauSo = MauSo * PS.TuSo; 		
			Thuong.ToiGian();
			
			return Thuong;
		}
		
		friend istream& operator >> (istream& is, PHANSO& PS){
			cout << "Nhap tu so: ";
			is >> PS.TuSo;
			cout << "Nhap mau so: ";
			is >> PS.MauSo;
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, PHANSO PS){
			os << PS.TuSo << "/" << PS.MauSo << endl;
			
			return os;
		}
};

int main(){
	PHANSO PS1, PS2, tong, hieu, tich, thuong;
	
	cout << "Nhap phan so thu nhat: " << endl;
	cin >> PS1;
	
	cout << "Nhap phan so thu hai: " << endl;
	cin >> PS2;
	
	tong = PS1 + PS2;
	hieu = PS1 - PS2;
	tich = PS1 * PS2;
	thuong = PS1 / PS2;
	
	cout << "Tong: " << tong << endl;
	cout << "Hieu: " << hieu << endl;
	cout << "Tich: " << tich << endl;
	cout << "Thuong: " << thuong;
	
	return 0;
}
