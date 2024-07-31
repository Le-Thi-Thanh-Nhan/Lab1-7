#include <iostream>
using namespace std;

class ThueBao {
public:
    virtual void nhap() = 0;
    virtual void xuat() = 0;
    virtual float tinhCuoc() = 0;
};

class DialUp : public ThueBao {
private:
    float thoiGianTruyCap;
public:
    void nhap() {
        cout << "Nhap thoi gian truy cap (phut): ";
        cin >> thoiGianTruyCap;
    }
    void xuat() {
        cout << "Thue bao Dial Up, thoi gian truy cap: " << thoiGianTruyCap << " phut" << endl;
    }
    float tinhCuoc() {
        return 30000 + thoiGianTruyCap * 30;
    }
};

class ADSL : public ThueBao {
private:
    float duLieuTruyenTai;
public:
    void nhap() {
        cout << "Nhap dung luong du lieu truyen tai (MB): ";
        cin >> duLieuTruyenTai;
    }
    void xuat() {
        cout << "Thue bao ADSL, dung luong du lieu truyen tai: " << duLieuTruyenTai << " MB" << endl;
    }
    float tinhCuoc() {
        return 50000 + duLieuTruyenTai * 50;
    }
};

class T1 : public ThueBao {
public:
    void nhap() {
        // Khong can nhap thong tin gi them
    }
    void xuat() {
        cout << "Thue bao T1" << endl;
    }
    float tinhCuoc() {
        return 2000000; // Cuoc co dinh
    }
};

int main() {
    ThueBao* ds[100];
    int n;
    cout << "Nhap so luong thue bao: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int luaChon;
        while (true) {
            cout << "Nhap lua chon (1 - Dial Up, 2 - ADSL, 3 - T1): ";
            cin >> luaChon;
            if (luaChon == 1) {
                ds[i] = new DialUp();
                break;
            } else if (luaChon == 2) {
                ds[i] = new ADSL();
                break;
            } else if (luaChon == 3) {
                ds[i] = new T1();
                break;
            } else {
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            }
        }
        ds[i]->nhap();
    }

    float tongCuoc = 0;
    int maxIndex = 0;
    for (int i = 0; i < n; ++i) {
        ds[i]->xuat();
        float cuoc = ds[i]->tinhCuoc();
        tongCuoc += cuoc;
        // Tim thue bao ADSL co cuoc lon nhat
        ADSL* adsl = (ADSL*)ds[i];
        if (adsl != nullptr && cuoc > ds[maxIndex]->tinhCuoc()) {
            maxIndex = i;
        }
    }
    cout << "Tong cuoc: " << tongCuoc << endl;
    cout << "Thue bao ADSL co cuoc lon nhat: " << endl;
    ds[maxIndex]->xuat();
    return 0;
}

