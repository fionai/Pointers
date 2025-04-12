#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello, Pointers!\n";

	int a = 2;
	int* pa = &a;

	cout << a << endl;
	cout << *pa << endl;
	cout << &a << endl;
	cout << pa << endl;
}