#include<iostream>
using namespace std;

class MATHANG{
	protected:
		string mahang;
		string tenhang;
		float dongia;
	public:
		MATHANG(){
			mahang ="";
			tenhang ="";
			dongia =0;
		}
		MATHANG(string mahang, string tenhang, float dongia){
			this -> mahang = mahang;
			this -> tenhang = tenhang;
			this -> dongia = dongia;
		}			
	
	~MATHANG(){}
	
	friend istream& operator >> (istream& is, MATHANG& mh){
		
		cout<<"Nhap ma hang: ";
		is.ignore();
		getline(is,mh.mahang);
		cout<<"Nhap ten hang: ";
		getline(is,mh.tenhang);
		cout<<"Nhap don gia: ";
		is>>mh.dongia;
		return is;
	}
	
	friend ostream& operator <<(ostream& os, MATHANG& mh){
		
		os<<"Ma hang: " <<mh.mahang <<endl;
		os<<"Ten hang: " <<mh.tenhang <<endl;
		os<<"Don gia: " <<mh.dongia <<endl;
		return os;
	}
	
	string getmahang(){
		return mahang;
	}
	
	string gettenhang(){
		return tenhang;
	}
};

class BANHKEO : public MATHANG{
	private:
		string sanxuat;
	public:
		BANHKEO(){
			sanxuat ="";
		}
		BANHKEO(string mahang, string tenhang, float dongia, string sanxuat) : MATHANG(mahang,tenhang,dongia){
			this -> sanxuat = sanxuat;
		}
	
	friend istream& operator >> (istream& is, BANHKEO& bk){
		is >> (MATHANG&)bk; 
		cout<<"Nhap noi san xuat: ";
		cin.ignore();
		getline(is,bk.sanxuat);
		return is;
	}
	
	float Chietkhau(){
		return dongia*0.01;
	}
	
	float getdongia(){
		return dongia;
	}
	
	string getsanxuat(){
		return sanxuat;
	}
	
	friend ostream& operator <<(ostream& os, BANHKEO& bk){
		os << (MATHANG&)bk;
		os<<"Noi san xuat: " <<bk.sanxuat <<endl;
		os<<"Chiet khau: " <<bk.Chietkhau() <<endl;
	}
};

int main(){
	int n;
	cout<<"Nhap so luong banh keo: ";
	cin>>n;
	
	BANHKEO* bk = new BANHKEO[n];
	for(int i=0; i<n; i++){
		cout<<"Nhap so luong banh keo thu " <<i+1 <<":" <<endl;
		cin>>bk[i];
		cout<<endl;
	}
	
	cout<<"Danh sach mat hang co ma khac MO1 " <<endl;
	for(int i=0; i<n; i++){
		if(bk[i].getmahang() != "MO1"){
			cout<<"Mat hang thu " <<i+1 <<":" <<endl;
			cout<<bk[i];
			cout<<endl;
		}
	}
	
	string matim;
    cout << "Nhap ma hang can tim: ";
    cin >> matim;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (bk[i].getmahang() == matim) {
            cout << "Tim thay mat hang: " << bk[i] << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay mat hang co ma " << matim << endl;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (bk[i].gettenhang() == "Banh ngot" && bk[i].getsanxuat() == "Bac Ninh") {
            count++;
        }
    }
    cout << "So luong mat hang co ten la \"Banh ngot\" va san xuat o \"Bac Ninh\": " << count << endl;
	
	cout<<"Danh sach theo chieu giam dan cua don gia " <<endl;
	for(int i=0; i<n; i++){
		for( int j=i+1; j<i; j++){
			if(bk[i].getdongia() < bk[j].getdongia()){
				BANHKEO x;
				bk[i] = x;
				bk[i] = bk[j];
				bk[j] = x;
			}
		}
	}
	
	delete []bk;
	return 0;
}
