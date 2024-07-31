#include <iostream>
#include<string>
using namespace std;
template <class T>
class Stack
{
	int size=0;
	T stack[50];
public:
	Stack(T *p, int size=0)
	{
		this->size = size;
	}
	void push()
	{
		cout << "Nhap gia tri: ";
		cin >> stack[size];
		size++;
	}
	void pop()
	{
		size--;
		cout << stack[size] << "\t";		
	}
};
int main()
{

	int arr[1],n;
	cout << "Nhap kich thuoc stack: "; cin >> n;
	Stack<int> stack(arr,0);
	for (int i = 0; i < n; i++)
	{
		stack.push();
	}
	for (int i = 0; i < n; i++)
	{
		stack.pop();
	}
}

