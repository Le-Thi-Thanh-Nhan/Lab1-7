#include <iostream>
#include <cmath>

using namespace std;

//Tim UOC CHUNG LON NHAT cua 2 so nguyen
int UCLN (int a, int b){
	if (a == 0 || b == 0){
		return a + b;
	}
	while (a != b){
		if (a > b){
			a -= b;
		}
		else{
			b -= a;
		}
	}
	return a;
}

class PHANSO{
	private:
		int TuSo;
		int MauSo;
		
	public:
		PHANSO(int TuSo = 0, int MauSo = 1){
			this -> TuSo = TuSo;
			this -> MauSo = MauSo;
		}
		
		int getTuSo(){
			return TuSo;
		}
		
		void getTuSo(int TuSo){
			this -> TuSo = TuSo;
		}
		
		int getMauSo(){
			return MauSo;
		}
		
		void getMauSo(int MauSo){
			this -> MauSo = MauSo;
		}
		
		//Ham toi gian yeu cau mau so phai duong
		void ToiGian(){
			int u = UCLN(abs(TuSo), abs(MauSo));	//Tim UCLN cua tu so va mau so
			TuSo /= u;		//Chia tu so cho u
			MauSo /= u;		//Chia mau so cho u
			if (MauSo < 0){		//Neu mau so am
				TuSo = -TuSo;		//Doi dau tu so
				MauSo = -MauSo; 	//Doi dau mau so
			}
		}
		
		//Ham toan tu de cong 2 phan so
		PHANSO operator + (PHANSO& PS){
			PHANSO KetQua; 	//Tao mot phan so ket qua
			KetQua.TuSo = TuSo * PS.MauSo + MauSo * PS.TuSo; 	//Tu so = Tong cua tich cheo
			KetQua.MauSo = MauSo * PS.MauSo; 			//Mau so = Tich cua mau so
			KetQua.ToiGian();							//Toi gian ket qua
			
			return KetQua;
		}
		
		friend istream& operator >> (istream& is, PHANSO& PS){
			cout << "Nhap tu so: ";
			is >> PS.TuSo;
			cout << "Nhap mau so: ";
			is >> PS.MauSo;
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, PHANSO PS){
			os << PS.TuSo << "/" << PS.MauSo << endl;
			
			return os;
		}
};

class HONSO : public PHANSO{
	private:
		int PhanNguyen;
		
	public:
		HONSO(int TuSo = 0, int MauSo = 1, int PhanNguyen = 0) : PHANSO(TuSo, MauSo){
			this -> PhanNguyen = PhanNguyen;
		}
		
		bool operator > (HONSO HS){
			
			//Chuyen 2 hon so ve dang phan so
			PHANSO PS1(PhanNguyen * getMauSo() + getTuSo(), getMauSo());
			PHANSO PS2(HS.PhanNguyen * HS.getMauSo() + HS.getTuSo(), HS.getMauSo());
			
			//So sanh 2 phan so bang cach nhan cheo
			return PS1.getTuSo() * PS2.getMauSo() > PS1.getMauSo() * PS2.getTuSo();
		}
		
		friend istream& operator >> (istream& is, HONSO& HS){
			is >> (PHANSO&)HS;
			
			cout << "Nhap phan nguyen: ";
			is >> HS.PhanNguyen;
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, HONSO HS){
			HS.ToiGian(); 		//Toi gian hon so
			
			if (HS.PhanNguyen != 0 && HS.getTuSo() != 0) {
            os << "(" << HS.PhanNguyen << ")" << HS.getTuSo() << "/" << HS.getMauSo();
	        }
	        
	        if (HS.PhanNguyen == 0 && HS.getTuSo() == 0) {
	            os << "0";
	        }
			
			return os;
		}
};

int main(){
	
	int m;
    cout << "Nhap so luong phan so: ";
    cin >> m;
    
	PHANSO* mangA = new PHANSO[m];
    
	for (int i = 0; i < m; i++) {
		cout << endl;
        
		cout << "Nhap phan so thu " << i + 1 << ": " << endl;
        cin >> mangA[i]; 
        
        cout << endl;
    }
   
	cout << endl << "======= MANG A GOM " << m << " PHAN SO =======" << endl;
    for (int i = 0; i < m; i++) {
        cout << endl;
        
        cout << "Phan so thu " << i + 1 << ": " << endl;
        cout << mangA[i];
        
        cout << endl;
    }
    cout << endl << "---------------------------------------------------" << endl;

    PHANSO p;
    cout << "Nhap phan so p:" << endl;
    cin >> p;
	cout << endl;
	  
    cout << "======= MANG A SAU KHI CONG VOI PHAN SO p =======" << endl;
    
	for (int i = 0; i < m; i++) {
        cout << mangA[i] + p << " ";
        
        cout << endl;
    }
    cout << endl << "======================================================" << endl;
    delete[] mangA;
 
    int n;
    cout << "Nhap so luong hon so: ";
    cin >> n;
    cout << endl;
    
    HONSO* mangB = new HONSO[n];
    
    cout << endl << "Nhap mang B: " << endl;
    for (int i = 0; i < n; i++) {
    	cout << endl;
    	
        cout << "Nhap hon so thu " << i + 1 << ": " << endl;
        cin >> mangB[i];
        
        cout << endl;
    }
    
    cout << "======= MANG B GOM " << n << " HON SO ======= " << endl;
    for (int i = 0; i < n; i++) {
    	cout << endl;
    	
    	cout << "Hon so thu " << i + 1 << ": " << endl;
        cout << mangB[i] << endl;
        
        cout << endl;
    }
    cout << endl << "--------------------------------------------------------" << endl;
    
    cout << endl << "======= MANG B SAU KHI SAP XEP THEO CHIEU TANG DAN =======" << endl;
    for (int i = 0; i < n; i++){
    	for (int j = i + 1; j < n; j++){
    		if(mangB[i].getTuSo() * mangB[j].getMauSo() > mangB[i].getMauSo() * mangB[j].getTuSo()){
    			HONSO x;
    			x = mangB[i];
    			mangB[i] = mangB[j];
    			mangB[j] = x;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
    	cout << endl;
    	
    	cout << "Hon so thu " << i + 1 << ": " << endl;
        cout << mangB[i] << endl;
        
        cout << endl;
    }
	
	delete[] mangB;
	
	return 0;
}
