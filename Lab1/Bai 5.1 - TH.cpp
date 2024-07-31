#include <iostream>

using namespace std;

class PhanSo {
private:
    int tu, mau;

public:
    PhanSo(int tu = 0, int mau = 1) {
        this->tu = tu;
        this->mau = mau;
    }

    int timUSCLN(int a, int b) {
        while (a != b) {
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
        }
        return a;
    }

    void toiGianPhanSo() {
        int i = timUSCLN(this -> tu, this -> mau);
        this->tu /= i;
        this->mau /= i;
    }

    void hienThiPhanSo() {
        cout << this->tu << "/" << this->mau << endl;
    }

    PhanSo congPhanSo(const PhanSo& ps) {
        int ts = this->tu * ps.mau + ps.tu * this->mau;
        int ms = this->mau * ps.mau;
        PhanSo phanSoTong(ts, ms);
        phanSoTong.toiGianPhanSo();
        return phanSoTong;
    }
    
    PhanSo truPhanSo(const PhanSo& ps){
    	int ts = this->tu * ps.mau - ps.tu * this->mau;
        int ms = this->mau * ps.mau;
        PhanSo phanSoHieu(ts, ms);
        phanSoHieu.toiGianPhanSo();
        return phanSoHieu;
	}
};

int main() {
    PhanSo phanSo1(16, 3);
    PhanSo phanSo2(4, 8);

    PhanSo tong = phanSo1.congPhanSo(phanSo2);
    PhanSo hieu = phanSo1.truPhanSo(phanSo2);

    cout << "Tong hai phan so: ";
    tong.hienThiPhanSo();

    cout << "Hieu hai phan so: ";
    hieu.hienThiPhanSo();

    return 0;
}

