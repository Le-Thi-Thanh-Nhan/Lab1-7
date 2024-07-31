#include <iostream>
#include <cstring>

using namespace std;

struct NS {
    int ngay;
    int thang;
    int nam;
};

class KhachHang {
private:
    char hoTen[30]; 
    NS ngaySinh; 
    char soCMT[10]; 
    char hoKhau[50]; 
public:
    KhachHang() {
		strcpy(hoTen, "");
        ngaySinh.nam = 0;
        ngaySinh.ngay = 0;
        ngaySinh.thang = 0;
        strcpy(soCMT, "");
        strcpy(hoKhau, "");
	}

    KhachHang(const char* ten, NS ns, const char* cmt, const char* hk) {
        strcpy(hoTen, ten);
        ngaySinh = ns;
        strcpy(soCMT, cmt);
        strcpy(hoKhau, hk);
    }

    ~KhachHang() {}

    void xuatThongTin() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Ngay sinh: " << ngaySinh.ngay << "/" << ngaySinh.thang << "/" << ngaySinh.nam << endl;
        cout << "So CMT: " << soCMT << endl;
        cout << "Ho khau: " << hoKhau << endl;
    }
};

int main() {

    KhachHang kh("Nguyen Van A", {10, 5, 1990}, "123456789", "Ha Noi");

    kh.xuatThongTin();

    return 0;
}

