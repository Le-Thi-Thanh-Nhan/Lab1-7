#include<iostream>
#include <string>

using namespace std;

class ANPHAM{
	protected:
		string ten;
		float gia;
	public: 
		ANPHAM(string ten ="", float gia =0){
			this -> ten = ten;
			this -> gia = gia;
		}
	
	void Nhap(){
		cout<<"Nhap ten: ";
		cin.ignore();
		getline(cin,ten);
		cout<<"Nhap gia thanh: ";
		cin>>gia;
	}
	
	void Xuat(){
		cout<<"Ten: " <<ten <<endl;
		cout<<"Gia thanh: " <<gia <<endl;
	}
	
	string getten(){
		return ten;
	}
};

class SACH : public ANPHAM{
	private:
		int sotrang;
	public:
		SACH(string ten ="", float gia =0, int sotrang =0) : ANPHAM(ten,gia){
			this -> sotrang = sotrang;
		}
	
	void Nhap(){
		ANPHAM :: Nhap();
		cout<<"Nhap so trang: ";
		cin>>sotrang;
	}
	
	void Xuat(){
		ANPHAM :: Xuat();
		cout<<"So trang: ";
		cout<<sotrang;
	}
	
	int getsotrang(){
		return sotrang;
	}
};

class CD : public ANPHAM{
	private:
		float sophut;
	public:
		CD(string ten ="", float gia =0, float sophut = 0) : ANPHAM(ten,gia){
			this -> sophut = sophut;
		}
	
	void Nhap(){
		ANPHAM :: Nhap();
		cout<<"Nhap so phut: ";
		cin>>sophut;
	}
	
	void Xuat(){
		ANPHAM :: Xuat();
		cout<<"So phut: " <<sophut <<endl;
	}
};

int main(){
	int n;
	cout<<"Nhap so luong sach: ";
	cin>>n;
	
	SACH* sach = new SACH[n];
	for(int i=0; i<n; i++){
		cout<<"Nhap thong tin sach thu " <<i+1 <<":" <<endl;
		sach[i].Nhap();
		cout<<endl;
	}
	
	cout<<"Danh sach nhung sach co so trang > 500 " <<endl;
	for(int i=0; i<n; i++){
		if(sach[i].getsotrang() > 500){
		
			sach[i].Xuat();
			cout<<endl;
		}
	}
	
	cout<<"Nhap so luong CD: ";
	cin>>n;
	
	CD* cd = new CD[n];
	for(int i=0; i<n; i++){
		cout<<"Nhap thong tin CD thu " <<i+1 <<":" <<endl;
		cd[i].Nhap();
		cout<<endl;
	}
	
	string tentim;
    cout << "Nhap ten dia CD can tim: ";
    cin.ignore();
    getline(cin, tentim);
    cout << "Dia CD duoc tim thay: " << endl;
    for (int i=0; i<n; i++) {
        if (cd[i].getten() == tentim) {
            cd[i].Xuat();
            cout << endl;
            break;
        }
    }

    return 0;
}

