#include <iostream>
#include <string>

using namespace std;

class PERSON{
	protected:
		string name;
		string address;
		int phone;
		
	public:
		PERSON(): name(""), address(""), phone(0){}
		
		PERSON(string ten, string diaChi, int sdt) :  name(ten), address(diaChi), phone(sdt){}
		
		void Nhap(){
			cout << "Nhap ten: ";
			cin.ignore();
			getline(cin, name);
			cout << "Nhap dia chi: ";
			getline(cin, address);
			cout << "Nhap so dien thoai: ";
			cin >> phone;
		}
		
		void Xuat(){
			cout << "Ho ten: " << name << endl;
			cout << "Dia chi: " << address << endl;
			cout << "So dia chi: " << phone << endl;
		}
		
		string getDiaChi(){
			return address;
		}
};

class OFFICER : public PERSON{
	protected:
		double salary;
		
	public:
		OFFICER() : PERSON(){}
		
		OFFICER(string name, string address, int phone, double luong) : PERSON(name, address, phone){
			salary = luong;
		}
		
		void Nhap(){
			PERSON :: Nhap();
			
			cout << "Nhap luong: ";
			cin >> salary;
		}
		
		void Xuat(){
			PERSON :: Xuat();
			
			cout << "Luong: " << salary << endl;
		}
		
		double getLuong(){
			return salary;
		}
};

class MAGANGER : public OFFICER{
	private:
		double extra;
		
	public:
		MAGANGER() : OFFICER(){}
		
		MAGANGER(string name, string address, int phone, double salary, double phuCap) : OFFICER(name, address, phone, salary){
			extra = phuCap;
		}
		
		void Nhap(){
			OFFICER :: Nhap();
			
			cout << "Nhap phu cap: ";
			cin >> extra;
		}
		
		void Xuat(){
			OFFICER :: Xuat();
			
			cout << "Phu cap: " << extra << endl;
		}
};

int main(){
	int n;
	cout << "Nhap so luong quan li: ";
	cin >> n;
	cout << endl;
	
	MAGANGER dsQL[n];
	
	cout << "Nhap danh sach quuan li: " << endl;
	for(int i = 0; i < n; i++){
		cout << "Nhap thong tin quan li thu " << i + 1 << ": " << endl;
		dsQL[i].Nhap();
		
		cout << endl;
	}
	
	cout << "DANH SACH QUAN LI: " << endl;
	for(int i = 0; i < n; i++){
		cout << "Thong tin quan li thu " << i + 1 << ": " << endl;
		dsQL[i].Xuat();
		
		cout << endl;
	}
	
	cout << "Danh sach doi tuong o Ha Noi va co luong khacs 10 trieu: " << endl;
	for(int i = 0; i < n; i++){
		if(dsQL[i].getDiaChi() == "Ha Noi" && dsQL[i].getLuong() != 10000000){
			cout << "Thong tin quan li thu " << i + 1 << ": " << endl;
			dsQL[i].Xuat();
			
			cout << endl;
		}
	}
	
	return 0;
}
