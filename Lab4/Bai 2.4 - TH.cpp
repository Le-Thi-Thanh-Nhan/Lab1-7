#include <iostream>
#include <string>

using namespace std;

class MYDATE{
	protected:
		int d, m, y;
		
	public:
		MYDATE(int day, int month, int year) : d(day), m(month), y(year){}
		
		MYDATE() : d(0), m(0), y(0){}
		
		~MYDATE(){}
		
	void Nhap(){
		cout << "Nhap ngay: ";
		cin >> d;
		cout << "Nhap thang: ";
		cin >> m;
		cout << "Nhap nam: ";
		cin >> y;
	}
	
	void Xuat(){
		cout << d << " / " << m << " / " << y << endl;
	}
	
	int getYear(){
		return y;
	}
};

class PERSON : public MYDATE{
	private:
		string name;
		string address;
		int phone;
		
	public:
		PERSON() : MYDATE(){}
		
		PERSON(int day, int month, int year, string ten, string diachi, int sdt) : MYDATE(day, month ,year){
			name = ten;
			address = diachi;
			phone = sdt;
		}
		
		~PERSON(){}
		
		void Nhap(){
			MYDATE :: Nhap();
			
			cout << "Nhap ten: ";
			cin.ignore();
			getline(cin, name);
			cout << "Nhap dia chi: ";
			getline(cin, address);
			cout << "Nhap so dien thoai: ";
			cin >> phone;
		}
		
		void Xuat(){
			MYDATE :: Xuat();
			
			cout << "Ho ten: " << name << endl;
			cout << "Dia chi: " << address << endl;
			cout << "So dia chi: " << phone << endl;
		}
		
		bool operator > (PERSON& PS){
			return getYear() > PS.getYear();
		}
};

int main(){
	int n;
	cout << "Nhap so luong nguoi: ";
	cin >> n;
	cout << endl;
	
	PERSON dsNG[n];
	
	cout << "Nhap thong tin danh sach: " << endl;
	for(int i = 0; i < n; i++){
		cout << endl << "Nhap thong tin cua nguoi thu " << i + 1 << ": " << endl;
		dsNG[i].Nhap();
		
		cout << endl;
	}
	
	cout << "DANH SACH NGUOI XAP XEP THEO CHIEU TANG DAN CUA NAM SINH: " << endl;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(dsNG[i].getYear() > dsNG[j].getYear()){
				PERSON x;
				x = dsNG[i];
				dsNG[i] = dsNG[j];
				dsNG[j] = x;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cout << endl << "Thong tin nguoi thu " << i + 1 << ": " << endl;
		dsNG[i].Xuat();
		
		cout << endl;
	}
	
	return 0;
}

