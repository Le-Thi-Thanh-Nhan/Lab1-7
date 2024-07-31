#include <iostream>

using namespace std;

class DaThuc3{
	private:
		int a, b, c, d;
		
	public:
		DaThuc3() : a(0), b(0), c(0), d(0){}
		
		friend istream& operator >> (istream& is, DaThuc3& DT3){
			cout << "Nhap he so bac 3(a): ";
			is >> DT3.a;
			cout << "Nhap he so bac 2(b): ";
			is >> DT3.b;
			cout << "Nhap he so bac 1(c): ";
			is >> DT3.c;
			cout << "Nhap he so ac 0(d): ";
			is >> DT3.d;
			
			return is;
		}
		
		friend ostream& operator << (ostream& os, DaThuc3& DT3){
			os << DT3.a << "x3 + " << DT3.b << "x2 + " << DT3.c << "x + " << DT3.d << endl;
			
			return os;
		}
		
		DaThuc3 operator + (DaThuc3& DT3){
			DaThuc3 Tong;
			Tong.a = a + DT3.a;
			Tong.b = b + DT3.b;
			Tong.c = c + DT3.c;
			Tong.d = d + DT3.d;
			
			return Tong;
		}
		
		DaThuc3 operator - (DaThuc3& DT3){
			DaThuc3 Hieu;
			Hieu.a = a - DT3.a;
			Hieu.b = b - DT3.b;
			Hieu.c = c - DT3.c;
			Hieu.d = d - DT3.d;
			
			return Hieu;
		}
};

int main(){
	DaThuc3 DT1, DT2, tong, hieu;
	
	cout << "Nhap da thuc thu nhat: " << endl;
	cin >> DT1;
	cout << "Nhap da thu thu hai: " << endl;
	cin >> DT2;
	
	tong = DT1 + DT2;
	hieu = DT1 - DT2;
	
	cout << "Tong cua 2 da thu la: " << tong << endl;
	cout << "Hieu cua 2 da thuc la: " << hieu << endl;
	
	return 0;  
}
