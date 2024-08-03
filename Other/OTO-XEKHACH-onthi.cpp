#include <iostream>
#include <string>

using namespace std;

class OTO{
	private:
		string hangSX;
		int namSX;
		int giaTruocThue;
		
	public:
		OTO(string hangSX = "", int namSX = 0, int giaTruocThue = 0){
			this -> hangSX = hangSX;
			this -> namSX = namSX;
			this -> giaTruocThue = giaTruocThue;
		}
		
		int getnamSX(){
			return namSX;
		}
		
		int getgiaTruocThue(){
			return giaTruocThue;
		}
		
		friend istream& operator >> (istream& is, OTO& O){
			cout << "Nhap hang san xuat: ";
			is.ignore();
			getline(is, O.hangSX);
			cout << "Nhap nam san xuat: ";
			is >> O.namSX;
			cout << "Nhap gia truoc thue: ";
			is >> O.giaTruocThue;
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, OTO O){
			os << "Hang san xuat: " << O.hangSX << endl;
			os << "Nam san xuat: " << O.namSX << endl;
			os << "Gia chua thue: " << O.giaTruocThue << endl;
			
			return os;
		}
};

class XEKHACH : public OTO{
	private:
		int soGhe;
		
	public:
		XEKHACH(string hangSX = "", int namSX = 0, int giaTruocThue = 0, int soGhe = 0) : OTO(hangSX, namSX, giaTruocThue){
			this -> soGhe = soGhe;
		}
		
		friend istream& operator >> (istream& is, XEKHACH& XK){
			is >> (OTO&)XK;
			
			cout << "Nhap so ghe: ";
			is >> XK.soGhe;
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, XEKHACH XK){
			os << (OTO)XK;
			
			cout << "So ghe: " << XK.soGhe;
			
			return os;
		}
		
		bool operator > (XEKHACH XK){
			return soGhe > XK.soGhe;
		}
		
		float p(){
			if (soGhe > 29)
				return 0.2;
			else if (soGhe > 17)
				return 0.15;
			else
				return 0.08;
		}
		
		float GiaSauThue(){
			return getgiaTruocThue() + getgiaTruocThue() * p();
		}
		
		int getSoGhe(){
			return soGhe;
		}
};

int main(){
	int m;
	cout << "Nhap so luong oto: ";
	cin >> m;
	cout << endl;
	
	OTO* dsOTO = new OTO[m];
	
	cout << endl << "Nhap danh sach OTO: " << endl;
	for(int i = 0; i < m; i++){
		cout << endl;
		
		cout << "Nhap thong tin OTO thu " << i + 1 << ": " << endl;
		cin >> dsOTO[i];
		
		cout << endl;
	}
	
	cout << endl << "======= DANG SACH " << m << " OTO THEO THU TU TANG DAN CUA NAM SAN XUAT =======" << endl;
	for (int i = 0; i < m; i++){
		for(int j = i + 1; j < m; j++){
			if(dsOTO[i].getnamSX() > dsOTO[j].getnamSX()){
				OTO x;
				x = dsOTO[i];
				dsOTO[i] = dsOTO[j];
				dsOTO[j] = x;
			}
		}
	}
	
	for (int i = 0; i < m; i++){
		cout << endl;
		
		cout <<"Thong tin OTO thu " << i + 1 << ": " << endl;
		cout << dsOTO[i];
		
		cout << endl;
	}
	delete[] dsOTO;
	cout << "===================================================================" << endl;
	
	int n;
	cout << "Nhap so luong xe khach: ";
	cin >> n;
	cout << endl;
	
	XEKHACH* dsXK = new XEKHACH[n];
	
	cout << endl << "Nhap danh sach xe khach: " << endl;
	for(int i = 0; i < n; i++){
		cout << endl;
		
		cout << "Nhap thong tin xe khach thu " << i + 1 << ": " << endl;
		cin >> dsXK[i];
		
		cout << endl;
	}
	
	cout << endl << "======= DANH SACH " << n << " XE KHACH THEO THU TU TANG DAN CUA SO GHE KEM THEO GIA SAU THUE ======" << endl;
	for(int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if(dsXK[i].getSoGhe() > dsXK[j].getSoGhe()){
				XEKHACH x;
				x = dsXK[i];
				dsXK[i] = dsXK[j];
				dsXK[j] = x;
			}
		}
	}
	
	for (int i = 0; i < n; i++){
		cout << endl;
		
		cout << "Thong tin xe khach thu " << i + 1 << ": " << endl;
		cout << dsXK[i] << endl;
		cout << "Gia sau thue: " << dsXK[i].GiaSauThue() << endl;
		
		cout << endl;
	}
	delete[] dsXK;
	
	return 0;
}
