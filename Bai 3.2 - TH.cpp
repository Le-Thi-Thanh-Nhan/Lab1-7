#include <iostream>
#include <cstring>

using namespace std;

class ThiSinh {
	private:
	    char hoTen[30];
	    float diemToan;
	    float diemVan;
	
	public:
		
	    ThiSinh(const char* ten = "", float toan = 0, float van = 0) { 
	        strcpy(hoTen, ten);
	        diemToan = toan;
	        diemVan = van;
	    }
	
	    ~ThiSinh() {}
	
	    void nhapThongTin() {
	        cout << "Nhap ho ten: ";
	        cin.ignore();
	        cin.getline(hoTen, 30);
	
	        cout << "Nhap diem toan: ";
	        cin >> diemToan;
	
	        cout << "Nhap diem van: ";
	        cin >> diemVan;
	    }
	
	    void xuatThongTin() {
	        cout << "Ho ten: " << hoTen << endl;
	        cout << "Diem Toan: " << diemToan << endl;
	        cout << "Diem Van: " << diemVan << endl;
	    }
	
	    float tinhTongDiem() {
	        return diemToan + diemVan;
	    }
	    
	    const char* gethoTen(){
			return hoTen;
		}
};

int main() {
    const int MAX = 100;
    ThiSinh danhSach[MAX];
    int soLuong = 0;

    cout << "Nhap so luong thi sinh: ";
    cin >> soLuong;
    cout << endl;

    for (int i = 0; i < soLuong; ++i) {
        cout << "Nhap thong tin thi sinh thu " << i + 1 << ": " << endl;
        danhSach[i].nhapThongTin();
        
        cout << endl;
    }

    char tenTimKiem[30];
    cout << "Nhap ho ten thi sinh can tim va xoa: ";
    cin.ignore();
    cin.getline(tenTimKiem, 30);

    for (int i = 0; i < soLuong; ++i) {
        if (strcmp(danhSach[i].gethoTen(), tenTimKiem) == 0) {
            danhSach[i].xuatThongTin();
            for (int j = i; j < soLuong - 1; ++j) {
                danhSach[j] = danhSach[j + 1];
            }
            soLuong--;
            break;
        }
    }

    for (int i = 0; i < soLuong - 1; ++i) {
        for (int j = i + 1; j < soLuong; ++j) {
            if (strcmp(danhSach[i].gethoTen(), danhSach[j].gethoTen()) > 0) {
                swap(danhSach[i], danhSach[j]);
            }
        }
    }

    cout << "\n ====== Danh sach thi sinh sau khi xoa va sap xep ======== \n";
    for (int i = 0; i < soLuong; ++i) {
        cout << "Thong tin hoc sinh thu " << i + 1 << ": " << endl;
		danhSach[i].xuatThongTin();
        
        cout << endl;
    }

    return 0;
}

