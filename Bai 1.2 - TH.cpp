#include<iostream>

using namespace std;

class HCN{
	private:
		float d;
		float r;
	
	public:
		void Nhap(){
			cout << "Nhap chieu dai: ";
			cin >> d;
			
			cout << "Nhap chieu rong: ";
			cin >> r;
		}
		
		float TINHCHUVI(){
			return (d + r)*2;
		}
		
		float TINHDIENTICH(){
			return d * r;
		}
		
		void Xuat(){
			cout << "Chieu dai: " << d << endl;
			cout << "Chieu rong: " << r << endl;
			cout << "Chu vi: " << TINHCHUVI() << endl;
			cout << "Dien tich: " << TINHDIENTICH() << endl;
		}
};

int main(){
	int n;
	cout << "Nhap so luong hcn: ";
	cin >> n;
	cout << endl;
	
	HCN dsHCN[n];
	
	cout << endl << "Nhap thong tin dach sach hcn: " << endl;
	for(int i = 0; i < n; i++){
		cout << endl << "Nhap thong tin hcn thu " << i + 1 << ": " << endl; 
		dsHCN[i].Nhap();
	
		cout << endl;
	 }
	 
	cout << endl << "DANH SACH HINH CHU NHAT: " << endl;
	for(int i = 0; i < n; i++){
		cout << "Thong tin hcn thu " << i + 1 << ": " << endl;
		dsHCN[i].Xuat();
	
		cout << endl;
	}
	 
	float maxchuvi;
	int chisocv;
	maxchuvi = dsHCN[0].TINHCHUVI();
	int indemaxchuvi = 0;
	for(int i = 1; i < n; i++){
		float chuvi = dsHCN[i].TINHCHUVI();
		if(chuvi > maxchuvi){
			maxchuvi = chuvi;
			indemaxchuvi = i;
		}
	}	
	 
	float mindientich;
	int chisodt;
	mindientich = dsHCN[0].TINHDIENTICH();
	int indemindientich = 0;
	for(int i = 1; i < n; i++){
		float dientich = dsHCN[i].TINHDIENTICH();
		if(dientich < mindientich){
			mindientich = dientich;
			indemindientich = i;
		}
	}
	 
	cout << "Hinh chu nhap co chu vi lon nhat la: ";
	dsHCN[indemaxchuvi].Xuat();
	cout << endl;
	
	cout << "Hinh chu nhat co dien tich nho nhat la: ";
	dsHCN[indemindientich].Xuat();
	
	return 0;
}

