#include <iostream>
#include <string>
using namespace std;

class PTGT {
public:
    string  hangsx;
    int namsx;
    float giaChuaThue;
    PTGT (string hang = "", int nam = 0, float gia = 0){
        hangsx = hang;
        namsx = nam;
        giaChuaThue = gia;
    }
    ~PTGT (){};
    void Nhap(){
        cout << "Nhap hang san xuat: ";
        cin.ignore();
        getline(cin, hangsx);
        cout << "Nhap nam san xuat: ";
        cin >> namsx;
        cout << "Nhap gia chua thue: ";
        cin >> giaChuaThue;
    }
    void Xuat(){
        cout << "Hang san xuat: "<< hangsx << endl;
        cout << "Nam san xuat: " << namsx << endl;
        cout << "Gia chua thue: " << giaChuaThue << endl;
    }
    };
class XEKHACH : public PTGT {
private:
    int soTuyen;
    int soGhe;
public:
    XEKHACH (int tuyen = 0, int ghe = 0) {
        soTuyen = tuyen;
        soGhe = ghe;
    }
    ~XEKHACH (){};
    friend istream& operator >> (istream& is, XEKHACH& xk);
    float giaSauThue();
    
     bool operator< (int SoNguyen) {
        return (namsx < SoNguyen);
    }
    
    bool operator> (int SoNguyen) {
        return soGhe > SoNguyen;
    }
    friend ostream& operator << (ostream& os, XEKHACH& xk);
};
istream& operator >> (istream& is, XEKHACH& xk){
    xk.Nhap();
    cout << "Nhap so ghe: ";
    is >> xk.soGhe;
    cout << "Nhap so tuyen: ";
    is>> xk.soTuyen;
    
    return is;
}
float XEKHACH :: giaSauThue(){
    return giaChuaThue + giaChuaThue * 0.08;
}

ostream& operator << (ostream& os, XEKHACH& xk){
    xk.Xuat();
    os << "So ghe: " << xk.soGhe << endl;
    os << "So tuyen: "<< xk.soTuyen << endl;
    
    return os;
}
void NhapdanhsachPTGT (PTGT* ds, int n){
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin cho phuong tien giao thong thu " << i + 1<< ": "<< endl;
        ds[i].Nhap();
        cout << endl;
    }
}
void HienthidanhsachPTGT (PTGT* ds, int n){
    for(int i = 0; i < n; i++){
        cout << "Thong tin phuong tien giao thong thu " << i + 1 << ": " << endl;
        ds[i].Xuat();
        cout << endl;
    }
}
void NhapDSxekhach (XEKHACH* ds, int n){
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin xe khach thu " << i + 1 << ": " << endl;
        cin >> ds[i];
    }
}
void HienthiDSxekhachcohon29cho(XEKHACH* ds, int n){
    for(int i = 0; i < n; i++){
        if(ds[i] > 29){
            cout << "Thong tin xe khach thu " << i + 1 << ": "<< endl;
            cout << ds[i] << endl;
        }
    }
}
int main(){
    int n;
    
	cout << "Nhap so luong phuong tien giao thong: ";
    cin >> n;
    
    PTGT* dsPTGT = new PTGT[n];
    cout << endl << "Nhap thong tin cua ca phuong tien giao thong: " << endl;
    NhapdanhsachPTGT(dsPTGT, n);
    cout << endl << "Danh sach cac phuong tien giao thong: ";
    HienthidanhsachPTGT(dsPTGT, n);
    
    cout << "Nhap so luong xe khach: ";
    cin >> n;
    XEKHACH* dsXEKHACH = new XEKHACH[n];
    cout << endl << "Nhap thong tin cua xe khach: " << endl;
    NhapDSxekhach(dsXEKHACH, n);
    cout << endl << "Danh sach xe khach co hon 29 cho: " << endl;
    HienthiDSxekhachcohon29cho(dsXEKHACH, n);
    
    return 0;
}
