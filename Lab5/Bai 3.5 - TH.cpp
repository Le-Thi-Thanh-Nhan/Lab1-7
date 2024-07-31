#include <iostream>

using namespace std;

class MayIn {
protected:
    int soHieu;
    int soLuong;
public:
    MayIn(int soHieu, int soLuong) : soHieu(soHieu), soLuong(soLuong) {}
    
    void nhapKho(int q) {
        soLuong += q;
    }
    
    void xuatKho(int q) {
        if (soLuong >= q) {
            soLuong -= q;
        } else {
            cout << "Khong du so luong trong kho!" << endl;
        }
    }
    
    virtual void inSoLuong() {
        cout << "So luong may in so hieu " << soHieu << ": " << soLuong << endl;
    }
};

class MayInLaser : public virtual MayIn {
private:
    int dpi;
public:
    MayInLaser(int soHieu, int soLuong, int dpi) : MayIn(soHieu, soLuong), dpi(dpi) {}
    
    void inSoLuong(){
        cout << "So luong may in laser so hieu " << soHieu << ": " << soLuong << endl;
    }
};

class MayInMau : public virtual MayIn {
private:
    int bangMau;
public:
    MayInMau(int soHieu, int soLuong, int bangMau) : MayIn(soHieu, soLuong), bangMau(bangMau) {}
    
    void inSoLuong(){
        cout << "So luong may in mau so hieu " << soHieu << ": " << soLuong << endl;
    }
};

class MayInLaserMau : public MayInLaser, public MayInMau {
public:
    MayInLaserMau(int soHieu, int soLuong, int dpi, int bangMau) : MayIn(soHieu, soLuong), MayInLaser(soHieu, soLuong, dpi), MayInMau(soHieu, soLuong, bangMau) {}
    
    void inSoLuong(){
        cout << "So luong may in laser mau so hieu " << soHieu << ": " << soLuong << endl;
    }
};

int main() {
    MayIn mayIn(1, 10);
    MayInLaser mayInLaser(2, 5, 1200);
    MayInMau mayInMau(3, 7, 100);
    MayInLaserMau mayInLaserMau(4, 3, 1200, 200);
    
    mayIn.inSoLuong();
    mayInLaser.inSoLuong();
    mayInMau.inSoLuong();
    mayInLaserMau.inSoLuong();
    
    return 0;
}
