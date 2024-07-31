#include<string>
#include <iostream>
using namespace std;
template<class T>
class QUEUE
{
	int size;
	T queue[50];
	int quantily;
public:
	QUEUE(T* p, int size = 0)
	{
		this->size = size;
	}
	~QUEUE() {}
	void en_queue()
	{
		cout << "Nhap gia tri: ";
		cin >> queue[size];		
		quantily = size;
		size++;
	}
	bool is_full(int n)
	{
		return size == n;
	}
	void de_queue()
	{
		size--;
		cout << "\t" << queue[quantily-size];
	}
	bool is_empty(int n)
	{
		return size == 0;
	}
};

class SACH
{
	string code, name, author;
	int capacity;
public:
	SACH(string code="", string name="", string author="", int capacity=0)
	{
		this->code = code;
		this->name = name;
		this->author = author;
		this->capacity = capacity;
	}
	~SACH() {}
	friend istream& operator>>(istream& is, SACH& s)
	{
		cin.ignore();
		cout << "\n\tNhap ma sach: "; getline(is, s.code);
		cout << "\tNhap ten sach: "; getline(is, s.name);
		cout << "\tNhap ten tac gia: "; getline(is, s.author);
		cout << "\tNhap so ban in: "; is>>s.capacity;
		return is;
	}
	friend ostream& operator<<(ostream& os, SACH s)
	{
		os << "\tMa sach: " << s.code
			<< "\tTen sach: " << s.name
			<< "\t\tTac gia: " << s.author
			<< "\t\tSo ban in: " << s.capacity << endl;
		return os;
	}
};

int main()
{

	int n;
	cout << "Nhap kich thuoc hang doi: "; cin >> n;
	SACH arr[1];
	QUEUE<SACH> queue(arr, 0);
	for (int i = 0; i < n; i++)
	{
		queue.en_queue();
		if (queue.is_full(n) == true)
			cout << " - Queue full!!" << endl << endl;
	}
	for (int i = 0; i < n; i++)
	{
		queue.de_queue();
		if (queue.is_empty(n) == true)
			cout << " - Queue empty!!" << endl;
	}

}

