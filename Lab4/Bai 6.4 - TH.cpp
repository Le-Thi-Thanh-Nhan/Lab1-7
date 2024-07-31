#include<iostream>
#include <string>

using namespace std;

class PET{
	protected:
		int tuoi;
		float cannang;
	public:
		PET(int tuoi=0, float cannang=0){
			this -> tuoi = tuoi;
			this -> cannang = cannang;
		}
};

class DOG : public PET{
	private:
		string maumat;
		string sothich;
	public:
		DOG(int tuoi=0, float cannang=0, string maumat="", string sothich="") : PET(tuoi,cannang){
			this -> maumat = maumat;
			this -> sothich = sothich;
		}
		
		friend istream& operator >> (istream&is, DOG&dog){
			
			cout<<"Nhap tuoi: ";
			is>>dog.tuoi;
			cout<<"Nhap can nang: ";
			is>>dog.cannang;
			cout << "Nhap mau mat: ";
			is.ignore();
			getline(is, dog.maumat);
			cout << "Nhap so thich: ";
			getline(is, dog.sothich);
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, DOG& dog){
			
			os<<"Tuoi: " <<dog.tuoi <<endl;
			os<<"Can nang: " <<dog.cannang <<endl;
			os<<"Mau mat: " <<dog.maumat <<endl;
			os<<"so thich: " <<dog.sothich <<endl;
			
			return os;
		}
		
		float getcannang(){
			return cannang;
		}
		
		int gettuoi(){
			return tuoi;
		}
};


int main(){
	int n;
	cout<<"Nhap so luong Dog: ";
	cin>>n;
	
	DOG* dog = new DOG[n];
	for(int i=0; i<n; i++){
		cout<<"Nhap danh sach dog " <<i+1 <<":" <<endl;
		cin>>dog[i];
		cout<<endl;
	}
	
	cout<<"Danh sach Dog theo chieu tang dan cua can nang" <<endl;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(dog[i].getcannang() > dog[j].getcannang()){
				DOG x;
				x = dog[i];
				dog[i] = dog[j];
				dog[j] = x;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		cout<<"Thong tin dog thu " <<i+1 <<":" <<endl;
		cout<<dog[i];
		cout<<endl;
	}
	
	cout<<"Dog co tuoi tu 2 den 5 " <<endl;
	for(int i=0; i<n; i++){
		if(dog[i].gettuoi() >=2 && dog[i].gettuoi() <=5){
			cout<<"Thong tin dog thu " <<i+1 <<":" <<endl;
			cout<<dog[i];
			cout<<endl;
		}
	}
	
	float tongCanNang = 0; 
	for(int i=0; i<n; i++){
    	tongCanNang += dog[i].getcannang();
	}

	cout << "Tong can nang cua cac con dog: " << tongCanNang << endl;

	delete[] dog;

	return 0;
}

