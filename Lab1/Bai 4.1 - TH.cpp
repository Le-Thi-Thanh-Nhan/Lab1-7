#include <iostream>

using namespace std;

class VecTor3 {
private:
    int a, b, c;

public:

    VecTor3(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}

    ~VecTor3() {}

    void input() {
        cout << "Nhap toa do a: ";
        cin >> a;
        cout << "Nhap toa do b: ";
        cin >> b;
        cout << "Nhap toa do c: ";
        cin >> c;
    }

    void Xuat() {
        cout << "(" << a << ", " << b << ", " << c << ")";
    }

    VecTor3 operator+(const VecTor3& other) {
        return VecTor3(a + other.a, b + other.b, c + other.c);
    }
};

int main() {
    VecTor3 vector1, vector2, vectorSum;

    cout << "Nhap thông tin cho vector 1:\n";
    vector1.input();

    cout << "Nhap thông tin cho vector 2:\n";
    vector2.input();

    vectorSum = vector1 + vector2;

    cout << "Vector 1: ";
    vector1.Xuat();
    cout << endl;

    cout << "Vector 2: ";
    vector2.Xuat();
    cout << endl;

    cout << "Tong 2 vector: ";
    vectorSum.Xuat();
    cout << endl;

    return 0;
}

