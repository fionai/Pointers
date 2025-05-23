﻿#include "stdafx.h"
#include "DMfunctions.h"
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

using std::cin;
using std::cout;
using std::endl;

//using namespace std;

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1


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
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows = 4, cols = 5; //для ускорения при отладке ввела сразу
	int n;
	cout << "Введите количество строк: 3\n"; //cin >> rows;
	cout << "Введите количество элементов строки: 5"; //cin >> cols;

	//создаем массив указателей
	int** arr = new int* [rows];
	Allocate(arr, rows, cols);

	//Заполняем массив
	FillRand(arr, rows, cols);

	cout << "\n================Печать с помощью арифметики указателей:===============\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << *(*(arr + i) + j) << "\t";
		cout << endl;
	}

	arr = push_row_front(arr, rows, cols);
	cout << "\n\nДобавили строку в начале\n";
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	cout << "\n\nДобавили строку в конце\n";
	Print(arr, rows, cols);
	
	cout << "\n\nВведите индекс добавляемой строки: "; cin >> n;	
	while (n < 0 || n > rows)
	{
		cout << "Введите число от 0 до " << rows << ": "; cin >> n;
	}
	arr = insert_row(arr, rows, cols, n);
	Print(arr, rows, cols);

	arr = push_col_front(arr, rows, cols);
	cout << "\n\nДобавили столбец в начале\n";
	Print(arr, rows, cols);

	arr = push_col_back(arr, rows, cols);
	cout << "\n\nДобавили столбец в конце\n";
	Print(arr, rows, cols);

	cout << "\n\nВведите индекс добавляемого столбца: "; cin >> n;
	while (n < 0 || n > cols)
	{
		cout << "Введите число от 0 до " << cols << ": "; cin >> n;
	}
	arr = insert_col(arr, rows, cols, n);
	Print(arr, rows, cols);

	arr = pop_row_front(arr, rows, cols);
	cout << "\n\nУдалили строку в начале\n";
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	cout << "\n\nУдалили строку в конце\n";
	Print(arr, rows, cols);

	cout << "\n\nВведите индекс удаляемой строки: "; cin >> n;
	while (n < 0 || n >= rows)
	{
		cout << "Введите число от 0 до " << rows-1 << ": "; cin >> n;
	}
	arr = erase_row(arr, rows, cols, n);
	Print(arr, rows, cols);

	arr = pop_col_front(arr, rows, cols);
	cout << "\n\nУдалили столбец в начале\n";
	Print(arr, rows, cols);

	arr = pop_col_back(arr, rows, cols);
	cout << "\n\nУдалили столбец в конце\n";
	Print(arr, rows, cols);

	cout << "\n\nВведите индекс удаляемого столбца: "; cin >> n;
	while (n < 0 || n >= cols)
	{
		cout << "Введите число от 0 до " << cols - 1 << ": "; cin >> n;
	}
	arr = erase_col(arr, rows, cols, n);
	Print(arr, rows, cols);

	Clear(arr, rows, cols);
#endif // DYNAMIC_MEMORY_2

}