#include <iostream>
#include <string>
using namespace std;

class MAYTINH {
private:
    string maHang;
    string tenHang;
    float donGia;       
    float dungLuongRAM; 
    float trongLuong;   

public:
   
    MAYTINH(string ma = "", string ten = "", float gia = 0, float ram = 0, float tl = 0)
        : maHang(ma), tenHang(ten), donGia(gia), dungLuongRAM(ram), trongLuong(tl) {}

    
    ~MAYTINH() {}

   
    friend istream& operator>>(istream& is, MAYTINH& mt) {
        cout << "Ma hang: ";
        is >> mt.maHang;
        cout << "Ten hang: ";
        is >> mt.tenHang;
        cout << "Don gia: ";
        is >> mt.donGia;
        cout << "Dung luong RAM: ";
        is >> mt.dungLuongRAM;
        cout << "Trong luong : ";
        is >> mt.trongLuong;
        return is;
    }

    
    float tienVanChuyen() {
        if (trongLuong > 2)
            return 100000;
        else if (trongLuong > 1)
            return 50000;
        else
            return 30000;
    }

    
    bool operator==(const MAYTINH& other) const {
        return maHang == other.maHang;
    }
    
    float getDungLuongRAM(){
		return dungLuongRAM;
	}
	
	string getTen(){
		return tenHang;
	}
};

int main() {
    int n;
    cout << "Nhap so luong may tinh: ";
    cin >> n;
    cout << endl;

    MAYTINH* dsMT = new MAYTINH[n];

    for (int i = 0; i < n; ++i) {
    	cout<< "Nhap thong tin may tinh thu " << i + 1 << ":" << endl;
        cin >> dsMT[i];
        cout << endl;
    }

    
    cout << endl << "==============Danh sach may tinh co dung luong RAM bang 16================" << endl;
    for (int i = 0; i < n; ++i) {
        if (dsMT[i].getDungLuongRAM() == 16) {
            cout << dsMT[i].getTen() << endl;
        }
    }

    
    string tenHangSony = "SONY";
    bool found = false;
    

    
    delete[] dsMT;

    return 0;
}

