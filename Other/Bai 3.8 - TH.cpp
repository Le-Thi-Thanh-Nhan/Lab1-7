#include <iostream>

using namespace std;

class BanDoc {
protected:
	string soHieu, ten;

public:
	string getSoHieu() {
		return soHieu;
	}
	
	string getTen() {
		return ten;
	}
	
	void Nhap() {
		fflush(stdin);
		cout << "\nNhap so hieu: ";
		getline(cin, soHieu);
		
		cout << "Nhap ten: ";
		getline(cin, ten);
	}
	
	void Xuat() {
		cout << "\nSo hieu: " << soHieu
			<< "\nTen: " << ten;
	}
};

class Sach {
protected:
	string maSach, ten;
	
public:
	string getMa() {
		return maSach;
	}
	
	void Nhap() {
		fflush(stdin);
		cout << "\nNhap ma sach: ";
		getline(cin, maSach);
		
		cout << "Nhap ten sach: ";
		getline(cin, ten);
	}
	
	void Xuat() {
		cout << "\nMa sach: " << maSach
			<< "\nTen sach: " << ten;
	}
};

class PhieuMuon {
protected:
	BanDoc* banDoc; 
	Sach* sach;
	int maPhieu;
	
public:
	PhieuMuon() {
		banDoc = NULL;
		sach = NULL;
	}

	PhieuMuon(BanDoc* banDoc, Sach* sach) {
		this->banDoc = banDoc;
		this->sach = sach;
	}
	
	void Xuat() {
		banDoc->Xuat();
		sach->Xuat();
	}
	
	BanDoc* getBanDoc() {
		return banDoc;
	}
	
	Sach* getSach() {
		return sach;
	}
	
	~PhieuMuon() {
		delete[] banDoc;
		delete[] sach;	
	}
};

class ThuVien {
private:
	PhieuMuon** phieuMuon;
	Sach** sach;
	
	int soPhieuMuon,
		soSach;	

	PhieuMuon* TaoPhieuMuon(int viTriSach, BanDoc* banDoc) {
		if (viTriSach == -1) return NULL;

		Sach* sach = this->sach[viTriSach];
		for (int i = viTriSach; i < soSach; i++) {
			this->sach[i] = this->sach[i + 1];
		}
		soSach--;
		
		PhieuMuon* phieuMuon = new PhieuMuon(banDoc, sach);
		this->phieuMuon[soPhieuMuon] = phieuMuon;
		soPhieuMuon++;
		return phieuMuon;
	}
public:
	ThuVien() {
		phieuMuon = new PhieuMuon*[100];
		sach = new Sach*[100];
		soPhieuMuon = 0;
		soSach = 0;
	}

	void NhapSach(Sach* sach) {
		if (soSach >= 100) {
			cout << "\nTu sach da day.\n";
			return;
		}
		
		this->sach[soSach] = sach;
		soSach++;
	}

	void TraSach(PhieuMuon* phieuMuon) {
		this->sach[soSach] = phieuMuon->getSach();
		soSach++;
	}

	int getViTriSach(string maSach) {
		for (int i = 0; i < soSach; i++) {
			if (this->sach[i]->getMa() == maSach) {
				return i;
			}
		}
		
		return -1;
	}
	
	PhieuMuon* MuonSach(string maSach, BanDoc* banDoc) {
		int viTriTrongTu = this->getViTriSach(maSach);

		return this->TaoPhieuMuon(viTriTrongTu, banDoc);
	}
	
	void thongKePhieuMuon() {
		cout << "\n\nDanh sach thong tin cac phieu muon: \n";
		for (int i = 0; i < soPhieuMuon; i++) {
			phieuMuon[i]->Xuat();
			cout << endl;
		}
	}
	
	void thongKeDauSach() {
		cout << "\n\nDanh sach cac dau sach co trong thu vien: \n";
		for (int i = 0; i < soSach; i++) {
			sach[i]->Xuat();
			cout << endl;
		}
	}
	
	~ThuVien() {
		delete[] phieuMuon;
		delete[] sach;
	}
};

int main() {
	ThuVien* uneti = new ThuVien();
	
	BanDoc** banDoc = new BanDoc*[10];

	cout << "Nhap so luong ban doc: ";
	int n;
	cin >> n;
	cout << "\n\nNhap danh sach ban doc: ";
	for (int i = 0; i < n; i++) {
		banDoc[i] = new BanDoc();
		banDoc[i]->Nhap();
	}

	int m;
	cout << "\n\nNhap so luong dau sach: ";
	cin >> m;
	cout << "\n\nNhap danh sach cac dau sach vao thu vien uneti: ";
	for (int i = 0; i < m; i++) {
		Sach* sach = new Sach();
		sach->Nhap();
		uneti->NhapSach(sach);
	}
	
	fflush(stdin);
	string maSach;
	while (true) {
		cout << "\n\nNhap ma sach can muon: ";
		getline(cin, maSach);	
		
		if (uneti->getViTriSach(maSach) != -1) {
			break;
		}
		cout << "Sach khong ton tai.";
	}
	string maBanDoc;
	BanDoc* banDocCanMuonSach;
	while(true) {
		cout << "\nNhap so hieu ban doc can muon sach: ";
		getline(cin, maBanDoc);
		bool timThay = false;
		for (int i = 0; i < n; i++) {
			if (banDoc[i]->getSoHieu() == maBanDoc) {
				banDocCanMuonSach = banDoc[i];
				timThay = true;
				break;
			}
		}
		if (timThay) {
			break;
		} else {
			cout << "Khong tim thay ban doc.";
		}
	}
	
	PhieuMuon* phieuMuon = uneti->MuonSach(maSach, banDocCanMuonSach);
	
	cout << "\n\nThong tin phieu muon: ";
	phieuMuon->Xuat();
	
	uneti->thongKeDauSach();
	
	uneti->thongKePhieuMuon();
	
	delete[] uneti;
	
	return 0;
}

