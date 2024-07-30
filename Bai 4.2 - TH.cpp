#include<iostream>
using namespace std;


class SV{
	private:
		int soBD;
		string hoten;
		float ly;
		float toan;
		float hoa;
		float tongdiem;
	
	public:
		
		SV() {
			soBD = 0;
			hoten = "";
			ly = 0;
			toan = 0;
			hoa = 0;
			tongdiem = 0;
		}
		SV(int soBD , string hoten , float ly , float toan , float hoa ,float tongdiem ){
			this -> soBD = soBD;
			this -> hoten = hoten;
			this -> toan = toan;
			this -> ly = ly;
			this -> hoa = hoa;
			this -> tongdiem = tongdiem;
		}
	
	~SV(){}
	
	void Nhap(){
		
		cout<<"Nhap so bao danh: ";
		cin>>soBD;
		cout<<"Nhap ho ten: ";
		cin.ignore();
		getline(cin,hoten);
		cout<<"Nhap diem toan: ";
		cin>>toan;
		cout<<"Nhap diem ly: ";
		cin>>ly;
		cout<<"Nhap diem hoa: ";
		cin>>hoa;
		tongdiem = toan + ly + hoa;
        
	}
	float tongDiem(){
		return tongdiem ;
	}
	
	void In(){
		cout<<"So bao danh: " <<soBD <<endl;
		cout<<"Ho ten: " <<hoten <<endl;
		cout<<"Diem toan: " <<toan <<endl;
		cout<<"Diem hoa: " <<hoa <<endl;
		cout<<"Diem ly: " <<ly <<endl;
		cout<<"Tong diem: " <<tongdiem <<endl;
	}
};

int main(){
	int n;
	cout<<"Nhap so luong sinh vien: ";
	cin>>n;
	
	cin.ignore();
	SV* dsSV = new SV[n];
	cout << "Nhap thong tin danh sach SV: " << endl;
	for (int i = 0; i < n; i++){
		cout << "Nhap thong tin nguoi thu " << i + 1 << ": " << endl;
		dsSV[i].Nhap();
		
		cout << endl;
	}
	
	cout << endl << "============= DANH SACH SINH VIEN =================" << endl;
	for (int i = 0;i < n; i++){
		cout << "Thong tin nguoi thu " << i + 1 << ": " << endl;
		dsSV[i].In();
		
		cout << endl;
		cout << "Danh sach sinh vien trung tuyen:" << endl;
        for (int i = 0; i < n; ++i) {
            if (dsSV[i].tongDiem() >= 20) {
                dsSV[i].In();
            	cout<<endl;
        	}
		}
	}
	return 0;
}
