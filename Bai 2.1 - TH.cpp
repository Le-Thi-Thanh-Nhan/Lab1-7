#include <iostream>
#include <string>

using namespace std;

class DaThuc2
{
	private:
		int a, b, c;
	public:
		DaThuc2 (int da=0,int db=0,int dc=0)
		{
			a=da; b=db; c= dc;
		}
		~ DaThuc2 ()
		{
		}
		void in();
		DaThuc2 tong(DaThuc2 dt1);
};
void DaThuc2::in()
{
	cout<<a<<"x^2";
	if (b>=0)
		cout<<"+"<<b<<"x";
	else
		cout<<"-"<<b<<"x";
	if (c>=0)
		cout<<"+"<<c;
	else
		cout<<c;
}
DaThuc2 DaThuc2::tong(DaThuc2 dt)
{
	DaThuc2 t;
	t.a=a+dt.a;
	t.b=b+dt.b;
	t.c=c+dt.c;
	return t;
}
int main()
{
	DaThuc2 dt1(3,4,5);
	DaThuc2 dt2(6,7,-8);	
	DaThuc2 tong2;
	tong2=dt1.tong(dt2);
	cout<<"Tong 2 da thuc la: ";
	tong2.in();
	cout<<endl;
	return 1;
}

