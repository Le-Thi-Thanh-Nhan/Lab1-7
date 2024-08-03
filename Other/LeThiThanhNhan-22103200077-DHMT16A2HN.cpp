#include <iostream>
#include <string>

using namespace std;

class NGUOI {
protected:
    string hoTen;
    int tuoi;
    int soCMND;
public:
    NGUOI(string hoTen = "", int tuoi = 0, int soCMND = 0)
        : hoTen(hoTen), tuoi(tuoi), soCMND(soCMND) {}

    virtual ~NGUOI() {}

    virtual void Nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap so CMND: ";
        cin >>soCMND;
    }

    virtual void Xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Tuoi: " << tuoi << endl;
        cout << "So CMND: " << soCMND << endl;
    }
};

class CTBD : public NGUOI {
private:
    int soAo;
    int soBanThang;
public:
    CTBD(string hoTen = "", int tuoi = 0, int soCMND = 0, int soAo = 0, int soBanThang = 0)
        : NGUOI(hoTen, tuoi, soCMND), soAo(soAo), soBanThang(soBanThang) {}

    virtual ~CTBD(){}

    void Nhap() {
        NGUOI::Nhap();
        cout << "Nhap so ao: ";
        cin >> soAo;
        cout << "Nhap so ban thang: ";
        cin >> soBanThang;
    }

    void Xuat() {
        NGUOI::Xuat();
        cout << "So ao: " << soAo << endl;
        cout << "So ban thang: " << soBanThang << endl;
        cout << "Phu cap: " << tinhPhuCap() << endl;
    }

    int tinhPhuCap(){
        if (tuoi > 40) return 400;
        else if (tuoi >= 20 && tuoi <= 30) return 300;
        else return 200;
    }

    friend bool operator>(CTBD& ctbd1, CTBD& ctbd2) {
        return ctbd1.soBanThang > ctbd2.soBanThang;
    }

    friend istream& operator>>(istream& is, CTBD& ctbd) {
        ctbd.Nhap();
        return is;
    }

    friend ostream& operator<<(ostream& os, CTBD& ctbd) {
        ctbd.Xuat();
        return os;
    }
};

template <typename T>
void nhapDanhSach(T* ds, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin thu " << i + 1 << ":" << endl;
        ds[i].Nhap();
        
        cout << endl;
    }
}

template <typename T>
void inDanhSach(T* ds, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Thong tin thu " << i + 1 << ":" << endl;
        ds[i].Xuat();
        
        cout << endl;
    }
}

template <typename T>
void xoaViTri(T*& ds, int& n, int k) {
    if (k < 1 || k > n) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }
    for (int i = k - 1; i < n - 1; ++i) {
        ds[i] = ds[i + 1];
    }
    --n;
}

template <typename T>
void chenViTri(T*& ds, int& n, int k, const T& item) {
    if (k < 1 || k > n + 1) {
        cout << "Vi tri khong hop le!" << endl;
        return;
    }
    T* new_ds = new T[n + 1];
    for (int i = 0; i < k - 1; ++i) {
        new_ds[i] = ds[i];
    }
    new_ds[k - 1] = item;
    for (int i = k; i <= n; ++i) {
        new_ds[i] = ds[i - 1];
    }
    delete[] ds;
    ds = new_ds;
    ++n;
}

void sapXepCTBD(CTBD* ds, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ds[i] > ds[j]) {
                swap(ds[i], ds[j]);
            }
        }
    }
}

int main() {
    int n;

    cout << "Nhap so luong nguoi: ";
    cin >> n;
   
    NGUOI* dsNguoi = new NGUOI[n];
    nhapDanhSach(dsNguoi, n);
    inDanhSach(dsNguoi, n);
    cout << endl;

    cout << "Nhap so luong cau thu: ";
    cin >> n;
   
    CTBD* dsCTBD = new CTBD[n];
    nhapDanhSach(dsCTBD, n);
    sapXepCTBD(dsCTBD, n);
    cout << "Danh sach cau thu sau khi sap xep:" << endl;
    inDanhSach(dsCTBD, n);
    cout << endl;

    int k;
    cout << "Nhap vi tri cau thu can xoa: ";
    cin >> k;
    xoaViTri(dsCTBD, n, k);
    cout << "Danh sach cau thu sau khi xoa:" << endl;
    inDanhSach(dsCTBD, n);
    cout << endl;

    CTBD ctbd;
    cout << "Nhap thong tin cau thu can chen: " << endl;
    cin >> ctbd; 
    cout << "Nhap vi tri chen: ";
    cin >> k;
    chenViTri(dsCTBD, n, k, ctbd);
    cout << "Danh sach cau thu sau khi chen:" << endl;
    inDanhSach(dsCTBD, n);
    cout << endl;

    delete[] dsNguoi;
    delete[] dsCTBD;
    return 0;
}
