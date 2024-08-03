#include<iostream>
#include<string>
using namespace std;

class OTO{
	private:
		string hangSX;
		int namSX;
		float giatruocThue;
	public:
		OTO(string hangSX = "", int namSX = 0, int giatruocThue = 0){
			this -> hangSX = hangSX;
			this -> namSX = namSX;
			this -> giatruocThue = giatruocThue;
		}
	
	int getnamSX(){
		return namSX;
	}
	
	int getgiatruocThue (){
		return giatruocThue;
	}
	
	friend istream& operator >> (istream& is, OTO& OT){
		cout<<"Nhap hang san xuat: ";
		is.ignore();
		getline(is,OT.hangSX);
		cout<<"Nhap nam san xuat: ";
		is>>OT.namSX;
		cout<<"Nhap don gia truoc thue: ";
		is>>OT.giatruocThue;
		
		return is;
	}
	
	friend ostream& operator << (ostream& os, OTO& OT){
		os<<"Hang san xuat: " << OT.hangSX <<endl;
		os<<"Nam san xuat: " << OT.namSX <<endl;
		os<<"Don gia truoc thue: " << OT.giatruocThue <<endl;
		
		return os;
	}
};

class XEKHACH : public OTO{
	private:
		int soGhe;
	public:
		XEKHACH(string hangSX = "", int namSX = 0, int giatruocThue = 0, int soGhe = 0) : OTO(hangSX,namSX,giatruocThue){
			this -> soGhe = soGhe;
		}
	
	friend istream& operator >> ( istream& is, XEKHACH& XK){
		is>>(OTO&)XK;
		
		cout<<"Nhap so ghe: ";
		
		is>>XK.soGhe;
		return is;
	}
	
	friend ostream& operator << ( ostream& os, XEKHACH& XK){
		os<<(OTO&)XK;
		os<<"So ghe: " << XK.soGhe <<endl;
		return os;
	}
	
	bool operator > (XEKHACH& XK){
		return soGhe > XK.soGhe;
	}
	
	float p(){
		if(soGhe > 29)
			return 0.2;
		else if(17 < soGhe <=29)
			return 0.15;
		else if(10 < soGhe <16)
			return 0.1;
		else
			return 0.08;
	}
	
	float GIASAUTHUE(){
		return getgiatruocThue() + getgiatruocThue() *p();
	}
	
	int getsoGhe(){
		return soGhe;
	}
		
	
};

int main(){
	
	int m;
	cout<<"Nhap so luong OTO: ";
	cin>>m;
	
	OTO* dsOTO = new OTO[m];
	cout<<"Nhap danh sach thong tin oto: " <<endl;
	for(int i = 0; i < m; i++){
		cout<<"nNhap thong tin oto thu: " << i + 1 << ":" <<endl;
		cin>>dsOTO[i];
		cout<<endl;
	}
	
	cout<<endl<<"========== DANH SACH TANG DAN THEO NAM SAN XUAT ==========" <<endl;
	for(int i = 0; i < m; i++){
		for(int j = i + 1; j < m; j++){
			if(dsOTO[i].getnamSX() > dsOTO[j].getnamSX()){
				OTO x;
				x = dsOTO[i];
				dsOTO[i] = dsOTO[j];
				dsOTO[j] = x;
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		cout<<"Thong tin oto thu " << i + 1 << ":" <<endl;
		cout<<dsOTO[i];
		cout<<endl;
	}
	
	delete[] dsOTO;
	cout<<endl<<"==================================" <<endl;
	
	
	int n;
	cout<<"Nhap so luong xe khach: ";
	cin>>n;
	
	XEKHACH* dsXK = new XEKHACH[n];
	cout<<"Nhap danh dach thong tin xe khach " <<endl;
	for(int i = 0; i < n; i++){
		cout<<"Nhap thong tin xe khach " << i + 1 << ":" <<endl;
		cin>>dsXK[i];
		cout<<endl;
	}
	
	cout<<endl<<"========== DANH  SACH TANG DAN THEO SO GHE KEM THEO GIA SAU THUE ==========" <<endl;
	for(int i = 0; i < n; i++){
		for(int j = i+ 1; j < n; j++){
			if(dsXK[i].getsoGhe() > dsXK[j].getsoGhe()){
				XEKHACH x;
				x = dsXK[i];
				dsXK[i] = dsXK[j];
				dsXK[j] = x;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		cout<<"Thong tin xe khach thu: " << i + 1 << ":" <<endl;
		cout<<dsXK[i];
		cout<<"Gia sau thue: " << dsXK[i].GIASAUTHUE() <<endl;
		cout<<endl;
	}
	
	return 0;
}


