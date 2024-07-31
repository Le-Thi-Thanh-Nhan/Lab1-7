#include <iostream>

using namespace std;

class CongNhan {
private:
    char hoTen[30];
    int tuoi;
    char queQuan[30];
    float bacLuong;

public:
    void nhapThongTin() {
        cout << "Nhap ho tên: ";
        cin.ignore();
        cin.getline(hoTen, 30);

        cout << "Nhap tuoi: ";
        cin >> tuoi;

        cout << "Nhap que quan: ";
        cin.ignore();
        cin.getline(queQuan, 30);

        cout << "Nhap bac luong: ";
        cin >> bacLuong;
    }

    float tinhLuong() {
        float luong = bacLuong * 2500;
        float phuCap = 0.2 * luong;
        return luong + phuCap;
    }

    void xuatThongTin() {
        cout << "Ho tên: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "Que quan: " << queQuan << endl;
        cout << "Tien luong: " << tinhLuong() << endl;
    }
};

int main() {
    CongNhan congNhan;

    cout << "Nhap thong tin cho cong nhan:\n";
    congNhan.nhapThongTin();

    cout << "\nThong tin cua cong nhan:\n";
    congNhan.xuatThongTin();

    return 0;
}

