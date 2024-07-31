#include <iostream>
#include <string>

using namespace std;

class HCN{
	private:
		float d,r;
	
	public:

		void Nhap(){
			cout<<"Nhap chieu dai: ";	
			cin>>d;
			cout<<"Nhap chieu rong: ";	
			cin>>r;
		}
		void In(){
			cout<<"("<<d<<","<<r<<")";
		}
		float TinhChuVi(){
			return 2*(d+r);
		}
		float TinhDienTich(){
			return d*r;
		}
};

int main(){
	HCN h;
	cout<<"Nhap thong tin hinh chu nhat: " <<endl;
	h.Nhap();
	cout<<"In thong tin hinh chu nhat: ";
	h.In();
	cout<<"Co chu vi la: " <<h.TinhChuVi() <<"va co dien tich la: " <<h.TinhDienTich();
	cout<<endl;
	return 0;
}
