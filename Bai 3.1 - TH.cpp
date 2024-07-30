#include <iostream>

using namespace std;

class SoPhuc {
private:
    int phanThuc;
    int phanAo;

public:
    SoPhuc(int thuc, int ao) : phanThuc(thuc), phanAo(ao) {}

    ~SoPhuc() {}

    void inSoPhuc() {
        cout << phanThuc << " + " << phanAo << "i" << endl;
    }

    SoPhuc tinhTong(SoPhuc other) {
        int tongThuc = phanThuc + other.phanThuc;
        int tongAo = phanAo + other.phanAo;
        return SoPhuc(tongThuc, tongAo);
    }
};

int main() {
    SoPhuc sp1(2, 3);
    SoPhuc sp2(1, 2);
    SoPhuc sp3(4, 5);

    SoPhuc tong = sp1.tinhTong(sp2).tinhTong(sp3);

    cout << "Tong 3 so phuc la: ";
    tong.inSoPhuc();

    return 0;
}

