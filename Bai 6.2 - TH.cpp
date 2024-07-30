#include<iostream>
#include<cstring>
using namespace std;

class DocGia
{	
	protected: 
		char ma[30], ho[30], ten[30];
		int sthl;
	public:
	virtual void Nhap()
	{ 
		cout<<"\n Nhap ma: "; cin.getline(ma,30);
		cout<<"\n Nhap ho: "; cin.getline(ho,30);
		cout<<"\n Nhap ten: "; cin.getline(ten,30);
		cout<<"\n Nhap so thang hieu luc: "; cin>>sthl;
		cin.ignore();
	}
	virtual void Xuat()
	{
		cout<<"\n Ma: "<<ma;
		cout<<"\n Ho: "<<ho;
		cout<<"\n Ten: "<<ten;
		cout<<"\n So thang hieu luc cua the: "<<sthl ;
	} 	 
	virtual float TienThe() = 0; // ham thuan ao
 	virtual int Tim() = 0; // ham ao
};

class DGTre: public DocGia 
{
	    int ns;
	public:
     void Nhap()
	{	 
		cin.ignore();
		DocGia:: Nhap();
		cout<<" \n Nhap nam sinh: "; cin>>ns;
		cin.ignore();
	}
	virtual void Xuat()
	{
		DocGia:: Xuat();
		cout<<"\n Nam sinh: "<<ns;
	}
	float TienThe()
	{
		return sthl * 20000;
	}
	int Tim()
	{ if(sthl<10) return 1;
		
		return 0;
	}
};

class DGLon: public DocGia 
{
	char nghe[30];
 public:
 virtual void Nhap()
 {	 
	cin.ignore();
	DocGia:: Nhap();
    cout<<" \n Nhap nghe nghiep: ";cin.getline(nghe,30);
	}
 virtual void Xuat()
	{
		DocGia:: Xuat();
		cout<<"\n  Nghe nghiep: "<<nghe;
	}
 float TienThe()
	{
		return sthl * 30000;
	}
 int Tim()
	{ 
		if(strcmp( nghe, "Giang vien")==0)
				 return 1;
			return 0;
		}
};
class QuanLyDG 
{
public:
	DocGia *d[30];
	int n ;	
 void Nhap()
 {
	 int chon, i=0; float s=0 ;
     while(1)
     {
     cout<<"\n*DocgiaTreEm /DocGiaNguoiLon/Dung (1,2,3):";
	  cin>>chon; 
      if (chon==3) break;
      if (chon==1) d[i]=new DGTre();   
      if (chon==2) d[i]=new DGLon();
      d[i]->Nhap();    
      s= s + d[i]->TienThe(); 
	 i++;
	 n=i;
     }
      	cout<<"\n Tong Tien Lam The :"<<s;
   }
void TimKiem()
{
	cout<<"\n Danh sach doc gia can tim: "<<endl;
	for(int j=0; j<n;j++)
   		if(d[j]->Tim()==1)
   		 {	
		   	d[j]->Xuat(); 
		    cout<<"\n------------------------"<<endl;
   		}
   }	 	
};

int main() 
{ 
QuanLyDG a;
cout<<"\n CHUONG TRINH QUAN LY DOC GIA"<<endl;
a.Nhap();
a.TimKiem();
return 0;
}

