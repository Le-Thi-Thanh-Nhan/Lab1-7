#include<string>
#include <iostream>
#include<vector>
using namespace std;
template <class T>
class Stack
{
	int size = 0;
	T stack[50];
public:
	Stack(T* p, int size = 0)
	{
		this->size = size;
	}
	~Stack() {}
	void push()
	{
		cout << "Nhap gia tri: ";
		cin >> stack[size];
		size++;
	}
	bool is_full(int n)
	{
		return size == n;
	}
	void pop()
	{
		size--;
		cout << "\t" << stack[size] ;
	}
	bool is_empty(int n)
	{
		return size == 0;
	}
};

class MayTinh
{
	string name, color;
	float capacity, speed;
public:
	MayTinh(string name="",string color="",float capacity=0,float speed=0)
	{
		this->name = name;
		this->color = color;
		this->capacity = capacity;
		this->speed = speed;
	}
	~MayTinh() {}
	friend istream &operator>>(istream& is, MayTinh& mt)
	{
		cout << "\n\tNhap ten hang: "; cin.ignore(); getline(is, mt.name);
		cout << "\tNhap mau sac: "; getline(is, mt.color);
		cout << "\tNhap dung luong: "; is >> mt.capacity;
		cout << "\tNhap toc do: "; is >> mt.speed;
		return is;
	}
	friend ostream& operator<<(ostream& os, MayTinh mt)
	{
		os << "\tTen hang: " << mt.name
			<< "\t\tMau sac: " << mt.color
			<< "\t\tDung luong: " << mt.capacity
			<< "\t\tToc do: " << mt.speed << endl;
		return os;
	}
};

int main()
{
	/*typedef Stack<MayTinh> may_tinh;*/
	int n;
	cout << "Nhap kich thuoc stack: "; cin >> n;
	MayTinh arr[1];
	Stack<MayTinh> stack(arr, 0);
	for (int i = 0; i < n; i++)
	{
		stack.push();
		if (stack.is_full(n) == true)
			cout << " - Stack day!!" << endl << endl;
	}
	for (int i = 0; i < n; i++)
	{
		stack.pop();
		if (stack.is_empty(n) == true)
			cout << " - Stack rong!!" << endl;
	}
}
