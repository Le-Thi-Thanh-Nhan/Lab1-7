#include <iostream>
using namespace std;

class DocGia {
protected:
    int ma;
    string ho;
    string ten;
    int thang;

public:
    virtual void Nhap() {
        cout << "Ma: ";
        cin >> ma;
        cout << "Ho: ";
        cin.ignore();
        getline(cin, ho);
        cout << "Ten: ";
        getline(cin, ten);
        cout << "So thang hieu luc: ";
        cin >> thang;
    }

    virtual void Xuat() {
        cout << "\nMa: " << ma;
        cout << "\nHo: " << ho;
        cout << "\nTen: " << ten;
        cout << "\nSo thang hieu luc: " << thang << endl;
    }

    virtual float TienThe() = 0;
};

class DGTre : public DocGia {
protected:
    int ns;

public:
    void Nhap() {
        DocGia::Nhap();
        cout << "Nam sinh: ";
        cin >> ns;
    }

    void Xuat() {
        cout << "Doc gia tre em: " << endl;
        DocGia::Xuat();
        cout << "Nam sinh: " << ns << endl;
    }

    float TienThe() {
        return thang * 300000;
    }
};

class DGLon : public DocGia {
protected:
    string nghe;

public:
    void Nhap() {
        DocGia::Nhap();
        cout << "Nghe nghiep: ";
        cin.ignore();
        getline(cin, nghe);
    }

    void Xuat() {
        cout << "Doc gia nguoi lon: " << endl;
        DocGia::Xuat();
        cout << "Nghe nghiep: " << nghe << endl;
    }

    float TienThe() {
        return thang * 300000;
    }
};

class QuanLi {
public:
    int n;
    DocGia* DG[30];
    float s;

    QuanLi() {
        n = 0;
        s = 0;
    }

    void Nhap() {
    	cout << endl << "Nhap so luong doc gia: ";
        cin >> n;
        int chon, i = 0;
        while (1) {
            cout << "\n1. Doc gia tre em\n2. Doc gia nguoi lon\n3. Exit\nChon loai doc gia: ";
            cin >> chon;
            if (chon == 3)
                break;
            if (chon == 1)
                DG[i] = new DGTre();
            else if (chon == 2)
                DG[i] = new DGLon();
            DG[i]->Nhap();
            s += DG[i]->TienThe();
            i++;
            n = i;
        }
        cout << "\nTong tien lam the: " << s << endl;
    }

    void TimKiem() {
        cout << "\nDanh sach doc gia co nghe nghiep Giangvien: ";
        for (int j = 0; j < n; j++) {
            if (DG[j]->TienThe() > 0) {
                DG[j]->Xuat();
            }
        }
    }
    
    void XuatTheoLoai() {
        int loai;
        cout << "\nChon loai doc gia (1: Tre em, 2: Nguoi lon): ";
        cin >> loai;
        cout << "\nDanh sach doc gia theo loai: ";
        for (int j = 0; j < n; j++) {
            if (loai == 1 && dynamic_cast<DGTre*>(DG[j])) {
                DG[j]->Xuat();
            } else if (loai == 2 && dynamic_cast<DGLon*>(DG[j])) {
                DG[j]->Xuat();
            }
        }
    }
};

int main() {
    QuanLi QL;
    cout << "\nCHUONG TRINH QUAN LY DOC GIA: ";
    QL.Nhap();
    QL.TimKiem();
    QL.XuatTheoLoai();
    return 0;
}

