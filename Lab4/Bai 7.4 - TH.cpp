#include<iostream>
#include<string>
using namespace std;

class HANGHOA{
	protected:
		string ma;
		string ten;
		float gia;
	public:
		HANGHOA(string ma="", string ten="", float gia=0){
			this -> ma = ma;
			this -> ten = ten;
			this -> gia = gia;
		}
		
	~HANGHOA(){}
	
	void Nhap(){
		cin.ignore();
		cout<<"Nhap ma hang: ";
		getline(cin,ma);
		cout<<"Nhap ten hang: ";
		getline(cin,ten);
		cout<<"Nhap don gia: ";
		cin>>gia;
	}
	
	void Xuat(){
		cout<<"Ma hang: " <<ma <<endl;
		cout<<"Ten hang: " <<ten <<endl;
		cout<<"Don gia: " <<gia <<endl;
	}
	
	string getma(){
		return ma;
	}
	
	string getten(){
		return ten;
	}
};

class MT : public HANGHOA{
	protected:
		float tocdo;
		float soluong;
	public:
		MT(string ma="", string ten="", float gia=0, float tocdo=0, float soluong=0) : HANGHOA(ma,ten,gia){
			this -> tocdo = tocdo;
			this -> soluong = soluong;
		}
	
	~MT(){}
	
	friend istream& operator >>(istream& is, MT&mt){
		mt.Nhap();
		
		cout<<"Nhap toc do: ";
		is>>mt.tocdo;
		cout<<"Nhap so luong: ";
		is>>mt.soluong;
		return is;
	}
	
	friend ostream& operator <<(ostream& os, MT&mt){
		mt.Xuat();
		
		os<<"Toc do: " <<mt.tocdo <<endl;
		os<<"so luong: " <<mt.soluong <<endl;
		os<<"Thanh tien: " <<mt.ThanhTien() <<endl;
		return os;
	}
	
	float ThanhTien(){
		return soluong* gia;
	}
	
	float gettocdo(){
		return tocdo;
	}
};

class MTXT : public MT{
	private:
		float trongluong;
	public:
		MTXT(string ma="", string ten="", float gia=0,float tocdo=0, float soluong=0, float trongluong=0) : MT(ma,ten,gia,tocdo,soluong){
			this -> trongluong = trongluong;
		}
	
	~MTXT(){}
	
	friend istream& operator >> (istream& is, MTXT& mtxt){
		is >> (MT&)mtxt;
		
		cout<<"Nhap trong luong: ";
		is>>mtxt.trongluong;
		return is;
	}
	
	float PhiBaoTri(){
		return 0.05* gia;
	}
	
	friend ostream& operator <<(ostream& os, MTXT& mtxt){
		os << (MT&)mtxt;
		
		os<<"Trong luong: " <<mtxt.trongluong <<endl;
		os<<"Phi bao tri : " <<mtxt.PhiBaoTri() <<endl;
		return os;
	}
};

int main(){
	int n;
	cout<<"Nhap so luong may tinh xach tay: ";
	cin>>n;
	
	MTXT* mtxt = new MTXT[n];
	for(int i=0; i<n; i++){
		cout<<"Nhap danh sach may tinh xach tay " <<i+1 <<":" <<endl;
		cin>>mtxt[i];
		cout<<endl;
	}

	cout<<"Liet ke may tinh xach tay theo ten" <<endl;
	string MaTim;
    cout << "Nhap ma may tinh xach tay can tim: ";
	cin >> MaTim;
    bool find = false;
    for (int i=0; i<n; i++) {
        if (mtxt[i].getma() == MaTim) {
            cout << mtxt << endl;
            find = true;
            break;
        }
    }
    if (!find) {
        cout << "Khong tim thay may tinh xach tay voi ma " << MaTim << endl;
    }

    float TongPhi = 0;
        for (int i=0; i<n; i++) {
            TongPhi += mtxt[i].PhiBaoTri();
        }
    cout << "Tong phi bao tri cua cac may tinh la: " << TongPhi << endl;

    MTXT min = mtxt[0];
    for (int i = 0; i < n; i++){
        if (mtxt[i].gettocdo() < min.gettocdo()){
            mtxt[i] = min;
        }
    }
    cout << "May tinh xach tay co toc do thap nhat: " << min << endl;
    

    string MaSua;
    cout << "Nhap ma may tinh xach tay can sua: ";
    cin >> MaSua;
    bool found = false;
        for (int i=0; i<n; i++) {
            if (mtxt[i].getma() == MaSua) {
                cout << "Nhap thong tin moi cho may tinh xach tay:\n";
                cin >> mtxt[i];
                found = true;
                break;
            }
        }
    if (!found) {
        cout << "Khong tim thay may tinh xach tay voi ma " << MaSua << endl;
    }

    string XoaMa;
    cout<<"Tim may tinh xach tay can xoa: ";
    cin.ignore();
    getline(cin, XoaMa);

    bool tim = false;
    for (int i = 0; i < n; i++){
        if (mtxt[i].getma() == XoaMa){
           for (int j = i; j < n-1; j++){
               mtxt[j] = mtxt[j + 1];
           }
           tim = true;
           n--;
           break;
        }
    }

    if (!tim){
        cout << "khong tim thay may tinh xach tay can xoa" <<XoaMa <<endl;
    }
    
    cout<<"Danh sach tang dan cua ma may " <<endl;
    for(int i=0; i<n; i++){
    	for(int j=i+1; j<n; j++){
    		if(mtxt[i].getma() > mtxt[j].getma()){
    			MTXT x;
    			x = mtxt[i];
    			mtxt[i] = mtxt[j];
    			mtxt[j] = x;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		cout<<"Thong tin thu " <<i+1 <<":" <<endl;
		cout<<mtxt[i];
		cout<<endl;
	}
	
	return 0;
}
