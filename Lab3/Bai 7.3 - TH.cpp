#include <iostream>
#include <string>

using namespace std;

class OTO {
private:
    string maHang;
    string tenHangSanXuat;
    double donGia;
    double dungTichXilanh;
    double trongLuong;

public:
    OTO(string maHang = "", string tenHangSanXuat = "", double donGia = 0, double dungTichXilanh = 0, double trongLuong = 0) : maHang(maHang), tenHangSanXuat(tenHangSanXuat), donGia(donGia), dungTichXilanh(dungTichXilanh), trongLuong(trongLuong) {};

    ~OTO(){};

    friend istream& operator>>(istream& is, OTO& car) {
	    cout << "Nhap thong tin oto:\n";
	    cout << "Ma hang: ";
	    is >> car.maHang;
	    cout << "Ten hang san xuat: ";
	    is >> car.tenHangSanXuat;
	    cout << "Don gia: ";
	    is >> car.donGia;
	    cout << "Dung tich xilanh: ";
	    is >> car.dungTichXilanh;
	    cout << "Trong luong: ";
	    is >> car.trongLuong;
	    return is;
	}

    double TinhTienVanChuyen(){
	    if (trongLuong > 2.0)
	        return 100000;
	    else if (trongLuong > 1.0)
	        return 50000;
	    else
	        return 30000;
	}

    bool operator==(double soThuc) const {
    	return dungTichXilanh == soThuc;
	}
    
    friend ostream& operator<<(ostream& os, const OTO& car){
	    os << "Ma hang: " << car.maHang << endl;
	    os << "Ten hang san xuat: " << car.tenHangSanXuat << endl;
	    os << "Don gia: " << car.donGia << endl;
	    os << "Dung tich xilanh: " << car.dungTichXilanh << endl;
	    os << "Trong luong: " << car.trongLuong << endl;
	    return os;
	}
    
    string gettenHangSanXuat(){
	    return tenHangSanXuat;
	}
};

int main() {
    int n;
    cout << "Nhap so luong oto: ";
    cin >> n;
    cout << endl;

    OTO* danhSachOto = new OTO[n];

    cout << "Nhap danh sach oto: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> danhSachOto[i];
    }

    cout << "Danh sach oto co dung tich xilanh bang 2.5:\n";
    for (int i = 0; i < n; ++i) {
        if (danhSachOto[i] == 2.5) {
            cout << danhSachOto[i];
        }
    }

    string tenHangSanXuatNhap;
    cout << "Nhap ten hang san xuat can kiem tra: ";
    cin >> tenHangSanXuatNhap;

    bool toyotaFound = false;
    for (int i = 0; i < n; ++i) {
        if (danhSachOto[i].gettenHangSanXuat() == tenHangSanXuatNhap) {
        	cout << "Danh sach oto co ten hang la " << tenHangSanXuatNhap << ": " << endl;
        	cout << danhSachOto[i];
        	
        	cout << endl;
            toyotaFound = true;
            
			for (int j = i; j < n - 1; ++j) {
                danhSachOto[j] = danhSachOto[j + 1];
            }
            break;
        }
    }

    if (!toyotaFound) {
        cout << "Khong co oto co ten han la " << tenHangSanXuatNhap << ": " << endl;
        cout << "Nhap them thong tin cho oto: " << endl;
        OTO toyotaCar("123", "TOYOTA", 50000, 2.0, 1.5);
        for (int i = n - 1; i >= 0; --i) {
            danhSachOto[i + 1] = danhSachOto[i];
        }
        danhSachOto[0] = toyotaCar;
        n++;
    }
    else{
    	cout << "Da xoa thong tin xe hang " << tenHangSanXuatNhap << ". " << endl;
	}

    delete[] danhSachOto;

    return 0;
}

