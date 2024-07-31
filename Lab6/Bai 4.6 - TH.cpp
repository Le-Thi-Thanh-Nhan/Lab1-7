#include <iostream>
#include <cmath>
using namespace std;

class HinhHoc {
public:
    virtual void nhap() = 0;
    virtual void xuat() = 0;
    virtual float chuVi() = 0;
    virtual float dienTich() = 0;
    virtual float theTich() { return 0; }
};

class HinhHaiChieu : public HinhHoc {
 
};

class HinhBaChieu : public HinhHoc {
    
};

class Tron : public HinhHaiChieu {
private:
    float r;
public:
    void nhap() {
        cout << "Nhap ban kinh: ";
        cin >> r;
    }
    void xuat() {
        cout << "Hinh tron co ban kinh la: " << r << endl;
    }
    float chuVi() {
        return 2 * 3.14 * r;
    }
    float dienTich() {
        return 3.14 * r * r;
    }
};

class Cunhat : public HinhHaiChieu {
private:
    float d, r;
public:
    void nhap() {
        cout << "Nhap chieu dai va chieu rong: ";
        cin >> d >> r;
    }
    void xuat() {
        cout << "Hinh chu nhat co chieu dai va chieu rong la: " << d << ", " << r << endl;
    }
    float chuVi() {
        return 2 * (d + r);
    }
    float dienTich() {
        return d * r;
    }
};

class Vuong : public HinhHaiChieu {
private:
    float a;
public:
    void nhap() {
        cout << "Nhap canh: ";
        cin >> a;
    }
    void xuat() {
        cout << "Hinh vuong co canh la: " << a << endl;
    }
    float chuVi() {
        return 4 * a;
    }
    float dienTich() {
        return a * a;
    }
};

class Cau : public HinhBaChieu {
private:
    float r;
public:
    void nhap() {
        cout << "Nhap ban kinh: ";
        cin >> r;
    }
    void xuat() {
        cout << "Hinh cau co ban kinh la: " << r << endl;
    }
    float chuVi() {
        return 2 * 3.14 * r;
    }
    float dienTich() {
        return 4 * 3.14 * r * r;
    }
    float theTich() {
        return (4.0/3) * 3.14 * r * r * r;
    }
};

class Lapphuong : public HinhBaChieu {
private:
    float a;
public:
    void nhap() {
        cout << "Nhap canh: ";
        cin >> a;
    }
    void xuat() {
        cout << "Hinh lap phuong co canh la: " << a << endl;
    }
    float chuVi() {
        return 12 * a;
    }
    float dienTich() {
        return 6 * a * a;
    }
    float theTich() {
        return a * a * a;
    }
};

void tinhTong(HinhHoc* ds[], int n) {
    float tongChuVi = 0, tongDienTich = 0, tongTheTich = 0;
    for (int i = 0; i < n; ++i) {
        tongChuVi += ds[i]->chuVi();
        tongDienTich += ds[i]->dienTich();
        tongTheTich += ds[i]->theTich();
    }
    cout << "Tong chu vi cac hinh hai chieu: " << tongChuVi << endl;
    cout << "Tong dien tich cac hinh hai chieu: " << tongDienTich << endl;
    cout << "Tong the tich cac hinh ba chieu: " << tongTheTich << endl;
}

int main() {
    HinhHoc* ds[100];
    int n;
    cout << "Nhap so luong hinh: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int luaChon;
        while (true) {
            cout << "Nhap lua chon (1 - Hinh tron, 2 - Hinh chu nhat, 3 - Hinh vuong, 4 - Hinh cau, 5 - Hinh lap phuong): ";
            cin >> luaChon;
            if (luaChon == 1) {
                ds[i] = new Tron();
                break;
            } else if (luaChon == 2) {
                ds[i] = new Cunhat();
                break;
            } else if (luaChon == 3) {
                ds[i] = new Vuong();
                break;
            } else if (luaChon == 4) {
                ds[i] = new Cau();
                break;
            } else if (luaChon == 5) {
                ds[i] = new Lapphuong();
                break;
            } else {
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            }
        }
        ds[i]->nhap();
    }
    for (int i = 0; i < n; ++i) {
        ds[i]->xuat();
    }
    tinhTong(ds, n);
    return 0;
}

