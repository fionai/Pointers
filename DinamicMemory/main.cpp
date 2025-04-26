#include "stdafx.h"
#include "DMfunctions.h"

//using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int* brr = new int[n + 1];
	int a;
	cout << "Введите число для добавления его в начало массива: "; cin >> a;
	push_front(a, arr, n, brr);
	Print(brr, n + 1);

	int j = 0, k = 0;
	cout << "\nВведите число для добавления его в исходный массив: "; cin >> a;
	cout << "Введите индекс для добавления нового числа: "; cin >> k;
	while (k > n || k < 0)
	{
		cout << "Невозможно вставить число в позицию " << k << ", введите число от 0 до " << n <<": "; cin >> k;
	}
	insert(a, k, arr, n, brr);
	Print(brr, n + 1);
	delete[] brr;

	brr = new int[n - 1];
	pop_back(arr, n, brr);
	cout << "\nУдалили последний элемент исходного массива:\n";
	Print(brr, n - 1);

	pop_front(arr, n, brr);
	cout << "\nУдалили нулевой элемент исходного массива:\n";
	Print(brr, n - 1);

	cout << "\nВведите индекс для удаления числа: "; cin >> k;
	while (k > n -1 || k < 0)
	{
		cout << "Невозможно вставить число в позицию " << k << ", введите число от 0 до " << n - 1 << ": "; cin >> k;
	}
	erase(k, arr, n, brr);
	Print(brr, n - 1);

	delete[] arr; // memory leak
	delete[] brr;
}