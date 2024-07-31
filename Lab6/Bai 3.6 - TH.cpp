#include<iostream>
#include<math.h>
using namespace std;

class SHAPE 
{
	public:
	virtual void nhap()=0;
	virtual void xuat()=0;
	virtual float dtich()=0;
	virtual float chuvi()=0;
	friend float sumdt(SHAPE **a[],int n);
	friend float sumcv(SHAPE **a[],int n);
};

class ROUND:public SHAPE 
{
	private:
	    float r;
	public:
	ROUND(float r=0)
	{
		this->r=r;
	}
	void nhap()
	{
		cout<<"Nhap ban kinh: ";
		cin>>r;
	}
	void xuat()
	{
		cout<<"Hinh tron co ban kinh la: "<<r<<endl;
	    cout<<"\n Chu vi: "<<chuvi()<<endl;
		cout<<"\n Dien tich: "<<dtich();
	}
	float dtich()
	{
		return 3.14*r*r;
	}
	float chuvi()
	{
		return 2*3.14*r;
	}
};

class TRI:public SHAPE 
{
	private:
	    float a, b, c;
	public:
	TRI(float a=0, float b=0, float c=0)
	{
		this->a=a;
		this->b=b;
		this->c=c;
	}
	void nhap()
	{
		cout<<"Nhap ba canh tam giac: ";
		cin>>a>>b>>c;
	}
	void xuat()
	{
		cout<<"Hinh tam giac co ba canh la: "<<a<<", "<<b<<", "<<c<<endl;
	    cout<<"\n Chu vi: "<<chuvi()<<endl;
		cout<<"\n Dien tich: "<<dtich();
	}
	float dtich()
	{
		float p = chuvi()/2;
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}
	float chuvi()
	{
		return a+b+c;
	}
};

class REC:public SHAPE 
{
	private:
	    float length, width;
	public:
	REC(float length=0, float width=0)
	{
		this->length=length;
		this->width=width;
	}
	void nhap()
	{
		cout<<"Nhap chieu dai va chieu rong: ";
		cin>>length>>width;
	}
	void xuat()
	{
		cout<<"Hinh chu nhat co chieu dai va chieu rong la: "<<length<<", "<<width<<endl;
	    cout<<"\n Chu vi: "<<chuvi()<<endl;
		cout<<"\n Dien tich: "<<dtich();
	}
	float dtich()
	{
		return length*width;
	}
	float chuvi()
	{
		return 2*(length+width);
	}
};

void sumdt(SHAPE *a[],int n)
{
	float sum1=0;
	for(int i=0;i<n;i++)
	{
		sum1+=a[i]->dtich(); 
	}
	cout<<"\nTong dien tich la: "<<sum1<<endl;
}

void sumcv(SHAPE *a[],int n)
{
	float sum2=0;
	for(int i=0;i<n;i++)
	{
		sum2+=a[i]->chuvi();
	}
	cout<<"Tong chu vi la: "<<sum2<<endl;
}

int main()
{
    SHAPE *s[100];
	cout<<"Nhap so luong hinh: ";
	int n;
	cin>>n;
	int i=0;
	for(int i=0;i<n;i++){
		cout<<"1.Nhap hinh tron"<<endl;
		cout<<"2.Nhap hcn"<<endl;
		cout<<"3.NHap tam giac"<<endl;
		cout<<"4.Exit"<<endl;
		int c;
	cout<<"\n => Moi Nhap lua chon: ";cin>>c;cin>>c;
		if(c==1)
		{
			s[i]=new ROUND();
		}
		else if(c==2)
		{
			s[i]=new REC();
		}
		else if(c==3)
		{
			s[i]=new TRI();
		}
		s[i]->nhap();
	}
for(int i=0;i<n;i++)
		{
		cout<<"\n- Thong tin hinh thu: "<<i+1<<endl;
		s[i]->xuat();
		}
	sumdt(s,n);
	sumcv(s,n);	
}

