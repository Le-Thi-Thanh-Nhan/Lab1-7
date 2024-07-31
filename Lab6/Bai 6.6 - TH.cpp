#include <iostream>
using namespace std;

class GiaoDich {
protected:
    string maGiaoDich;
    int ngay, thang, nam;
    float donGia, dienTich;
public:
    virtual void nhap() = 0;
    virtual void xuat() = 0;
    virtual float thanhTien() = 0;
    bool checkThangNam(int thangCheck, int namCheck) {
        return thang == thangCheck && nam == namCheck;
    }
};

class GiaoDichDat : public GiaoDich {
private:
    char loaiDat;
public:
    void nhap() {
        cout << "Nhap ma giao dich: ";
        cin >> maGiaoDich;
        cout << "Nhap ngay giao dich (ngay thang nam): ";
        cin >> ngay >> thang >> nam;
        cout << "Nhap don gia: ";
        cin >> donGia;
        cout << "Nhap loai dat (A, B, C): ";
        cin >> loaiDat;
        cout << "Nhap dien tich: ";
        cin >> dienTich;
    }
    void xuat() {
        cout << "Ma giao dich: " << maGiaoDich << ", Ngay giao dich: " << ngay << "/" << thang << "/" << nam
             << ", Don gia: " << donGia << ", Loai dat: " << loaiDat << ", Dien tich: " << dienTich
             << ", Thanh tien: " << thanhTien() << endl;
    }
    float thanhTien() {
        if (loaiDat == 'A') {
            return dienTich * donGia * 1.5;
        } else {
            return dienTich * donGia;
        }
    }
};

class GiaoDichNha : public GiaoDich {
private:
    string loaiNha, diaChi;
public:
    void nhap() {
        cout << "Nhap ma giao dich: ";
        cin >> maGiaoDich;
        cout << "Nhap ngay giao dich (ngay thang nam): ";
        cin >> ngay >> thang >> nam;
        cout << "Nhap don gia: ";
        cin >> donGia;
        cout << "Nhap loai nha (cao cap, thuong): ";
        cin.ignore();
        getline(cin, loaiNha);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
        cout << "Nhap dien tich: ";
        cin >> dienTich;
    }
    void xuat() {
        cout << "Ma giao dich: " << maGiaoDich << ", Ngay giao dich: " << ngay << "/" << thang << "/" << nam
             << ", Don gia: " << donGia << ", Loai nha: " << loaiNha << ", Dia chi: " << diaChi
             << ", Dien tich: " << dienTich << ", Thanh tien: " << thanhTien() << endl;
    }
    float thanhTien() {
        if (loaiNha == "cao cap") {
            return dienTich * donGia;
        } else {
            return dienTich * donGia * 0.9;
        }
    }
};

int main() {
    GiaoDich* ds[100];
    int n;
    cout << "Nhap so luong giao dich: ";
    cin >> n;
    float tongTienDat = 0;
    int soLuongDat = 0;
    for (int i = 0; i < n; ++i) {
        int luaChon;
        while (true) {
            cout << "Nhap lua chon (1 - Giao dich dat, 2 - Giao dich nha): ";
            cin >> luaChon;
            if (luaChon == 1) {
                ds[i] = new GiaoDichDat();
                soLuongDat++;
                break;
            } else if (luaChon == 2) {
                ds[i] = new GiaoDichNha();
                break;
            } else {
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            }
        }
        ds[i]->nhap();
        tongTienDat += ds[i]->thanhTien();
    }
    for (int i = 0; i < n; ++i) {
        ds[i]->xuat();
    }
    cout << "Tong so luong giao dich dat: " << soLuongDat << endl;
    cout << "Tong so luong giao dich nha: " << n - soLuongDat << endl;
    cout << "Trung binh thanh tien cua giao dich dat: " << tongTienDat / soLuongDat << endl;
    cout << "Cac giao dich cua thang 9 nam 2013: " << endl;
    for (int i = 0; i < n; ++i) {
        if (ds[i]->checkThangNam(9, 2013)) {
            ds[i]->xuat();
        }
    }
    return 0;
}

