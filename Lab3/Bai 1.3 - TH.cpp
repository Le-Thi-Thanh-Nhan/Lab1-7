#include <iostream>

using namespace std;

class SOPHUC{
	private:
		float thuc, ao;
		
	public:
		friend istream& operator >> (istream& is, SOPHUC& SP){
			cout << "Nhap phan thuc: ";
			is >> SP.thuc;
			cout << "Nhap phan ao: ";
			is >> SP.ao;
			
			return is;
		} 
		
		friend ostream& operator << (ostream& os, SOPHUC& SP){
			if(SP.ao >= 0)
				os << SP.thuc << "+j*" << SP.ao << endl;
			else
				os << SP.thuc << "-j*" << SP.ao << endl;
				
			return os;
		}
};

int main(){
	SOPHUC  A, B;
	
	cout << "Nhap so phuc A: " << endl;
	cin >> A;
	cout << "Nhap so phuc B: " << endl;
	cin >> B;
	cout << "Hai so phuc: " << endl;
	cout << "A: " << A << endl;
	cout << "B: " << B;
	
	return 0;
}
