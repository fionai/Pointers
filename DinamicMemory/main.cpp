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

	int a;
	cout << "Введите число для добавления его в начало массива: "; cin >> a;
	arr = push_front(arr, n, a);
	Print(arr, n);

	cout << "\nВведите число для добавления его в конец массива: "; cin >> a;
	arr = push_back(arr, n, a);
	Print(arr, n);

	int j = 0, k = 0;
	cout << "\nВведите число для добавления его в массив: "; cin >> a;
	cout << "Введите индекс для добавления нового числа: "; cin >> k;
	while (k > n || k < 0)
	{
		cout << "Невозможно вставить число в позицию " << k << ", введите число от 0 до " << n <<": "; cin >> k;
	}
	arr = insert(arr, n, a, k);
	Print(arr, n);

	cout << "\nУдалили последний элемент массива:\n";
	//arr = pop_back(arr, n);
	//Print(arr, n);
	Print(arr = pop_back(arr, n), n);

	arr = pop_front(arr, n);
	cout << "\nУдалили нулевой элемент массива:\n";
	Print(arr, n);

	cout << "\nВведите индекс для удаления числа: "; cin >> k;
	while (k > n -1 || k < 0)
	{
		cout << "Невозможно удалить число из позиции " << k << ", введите число от 0 до " << n - 1 << ": "; cin >> k;
	}
	arr = erase(arr, n, k);
	Print(arr, n);

	delete[] arr; // memory leak
}