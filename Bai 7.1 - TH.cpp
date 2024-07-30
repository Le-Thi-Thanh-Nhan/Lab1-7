#include <iostream>

using namespace std;

class GiaoVien {
private:
    char hoTen[30];
    int tuoi;
    char bangCap[15];
    char chuyenNganh[20];
    float bacLuong;

public:
    void nhapThongTin() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        cin.getline(hoTen, 30);

        cout << "Nhap tuoi: ";
        cin >> tuoi;

        cout << "Nhap bang cap: ";
        cin.ignore();
        cin.getline(bangCap, 15);

        cout << "Nhap chuyen nganh: ";
        cin.getline(chuyenNganh, 20);

        cout << "Nhap bac luong: ";
        cin >> bacLuong;
    }

    float tinhLuong() {
        return bacLuong * 1490;
    }

    void xuatThongTin() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Bang cap: " << bangCap << endl;
        cout << "Chuyen nganh: " << chuyenNganh << endl;
        cout << "Tien luong: " << tinhLuong() << endl;
    }
};

int main() {
    GiaoVien giaoVien;

    cout << "Nhap thong tin cho giao vien:\n";
    giaoVien.nhapThongTin();

    cout << "\nThong tin cua giao vien:\n";
    giaoVien.xuatThongTin();

    return 0;
}

