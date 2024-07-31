#include <iostream>

using namespace std;

class MyVector {
public:
    int* data;
    int size;

    MyVector(int sz) : size(sz), data(new int[sz]) {}

    ~MyVector() {
        delete[] data;
    }

    // Ðinh nghia phep gan "=" cho lop vector
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data; // Xoa du lieu cu truoc khi sao chep
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Phep truy xuat thanh phan cua mang "[]"
    int operator[](int index) const {
        return data[index];
    }
};

int main() {
    int size;

    cout << "Nhap kich thuoc cua vector: ";
    cin >> size;

    // Tao doi tuong vector
    MyVector myVector1(size), myVector2(size);

    // Nhap tung phan tu cua vector 1
    cout << "Nhap " << size << " phan tu cua vector 1: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Phan tu " << i + 1 << ": ";
        cin >> myVector1.data[i];
    }

    // Ðinh nghia phep gan "=" va sao chep vector 1 vao vector 2
    myVector2 = myVector1;

    // Hien thi vector da nhap cho vector 1
    cout << "Vector 1 da nhap: ";
    for (int i = 0; i < size; ++i) {
        cout << myVector1.data[i] << " ";
    }

    // Hien thi vector da sao chep cho vector 2
    cout << "\nVector 2 (sao chep tu vector 1): ";
    for (int i = 0; i < size; ++i) {
        cout << myVector2.data[i] << " ";
    }

    // Su dung phep truy xuat "[]" cho vector 2
    int value = myVector2[0];
    cout << "\nGia tri cua phan tu dau tien trong vector 2: " << value;

    return 0;
}
