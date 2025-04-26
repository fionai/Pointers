
#include "stdafx.h"
#include "DMfunctions.h"
//using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n = 10, n_e = 0, n_o = 0;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "Исходный массив: \n";
	Print(arr, n);
	n_e = CountE(arr, n);
	n_o = n - n_e;
	//cout << "в массиве " << n_e << " четных чисел и " << n_o << " нечетных.\n";

	int* arr_o = new int[n_o];
	int* arr_e = new int[n_e];
	Separate(arr, arr_e, arr_o, n, n_e, n_o);
	cout << "Четные числа: ";
	Print(arr_e, n_e);
	cout << "Нечетные числа: ";
	Print(arr_o, n_o);

	delete[] arr;
	delete[] arr_e;
	delete[] arr_o;

}
