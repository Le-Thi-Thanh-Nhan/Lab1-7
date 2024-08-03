#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Developer{
	protected:
		string HoTen;
		int NamSinh;
		double HeSoLuong;
		
	public:
		Developer(string ten = "", int ns = 0, double hsl = 0) : HoTen(ten), NamSinh(ns), HeSoLuong(hsl){}
		
		~Developer(){}
		
		void Nhap(){
			cout << "Nhap ho ten: ";
			cin.ignore();
			getline(cin, HoTen);
			cout << "Nhap nam sinh: ";
			cin >> NamSinh;
			cout << "Nhap he so luong: ";
			cin >> HeSoLuong;
		}
		
		void Xuat(){
			cout << "Ho ten: " << HoTen << endl;
			cout << "Nam sinh: " << NamSinh << endl;
			cout << "He so luong: " << HeSoLuong << endl;
		}
				
		double getHeSoLuong(){
			return HeSoLuong;
		}
		
		int getNamSinh(){
			return NamSinh;
		}
		
};

class Teamleader : public Developer{
	private:
		double LuongTrachNhiem;
		int NamCongTac;
		
	public:
		Teamleader(string HoTen ="", int NamSinh = 0, double HeSoLuong = 0, double LuongTN = 0, int NamCT = 0) : Developer(HoTen, NamSinh, HeSoLuong){
			LuongTrachNhiem = LuongTN;
			NamCongTac = NamCT;
		}
		
		~Teamleader(){}
		
		friend istream& operator >> (istream& is, Teamleader& Team){
			Team.Nhap();
			
			cout << "Nhap luong trach nhiem: ";
			cin >> Team.LuongTrachNhiem;
			cout << "Nhap so nam cong tac: ";
			cin >> Team.NamCongTac;
			
			return is;
		}
		
		double TinhTienLuong(){
			return HeSoLuong * 1300000 + NamCongTac * 90000 + LuongTrachNhiem;
		}
		
		bool operator != (int SoThuc){
			return NamCongTac != SoThuc;
		}
		
		friend ostream& operator << (ostream& os, Teamleader& Team){
			Team.Xuat();
			
			os << "Luong trach nhiem: " << Team.LuongTrachNhiem << endl;
			os << "So nam cong tac: " << Team.NamCongTac << endl;
			os << "Tien luong: " << Team.TinhTienLuong() << endl;
			
			return os;
		}

		int getNamCongTac(){
			return NamCongTac;
		}
};

int main(){
	int n;
	cout << "Nhap so luong teamleader: ";
	cin >> n;
	cout << endl;
	
	Teamleader dsTeam[n];
	
	cout << "Nhap thong tin cho " << n << " teamleader: " << endl;
	for(int i = 0; i < n; i++){
		cout << "Nhap thong tin teamleader thu " << i + 1 << ": " << endl;
		cin >> dsTeam[i];
		
		cout << endl;
	}
	
	cout << endl << "DANH SACH " << n << " TEAMLEADER: " << endl;
	for(int i = 0; i < n; i++){
		cout << dsTeam[i];
		
		cout << endl;
	}
	
	cout << "DANH SACH TEAMLEADER CO HE SO LUONG KHAC 2.34: " << endl;
	for(int i = 0; i < n; i++){
		if(dsTeam[i].getHeSoLuong() != 2.34){
			cout << dsTeam[i] << endl;
		}
	}
	
	Teamleader tempDanhSach[n];
	
	for (int i = 0; i < n - 1; ++i) {
    	for (int j = 0; j < n - i - 1; ++j) {
        	if (tempDanhSach[j].getNamSinh() > tempDanhSach[j + 1].getNamSinh()) {
                swap(tempDanhSach[j], tempDanhSach[j + 1]);
            }
        }
    }
    
    ofstream outFile("output.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < n; ++i) {
            if (tempDanhSach[i].getNamCongTac() > 10) {
                outFile << tempDanhSach[i] << endl;
            }
        }
        outFile.close();
        cout << "Danh sach da duoc sap xep va luu vao output.txt" << endl;
    } else {
        cout << "Khong the mo file de ghi!" << endl;
    }
    
	return 0;
}
