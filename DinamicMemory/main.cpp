#include <string.h>
#include "stdafx.h"

#include "DMfunctions.h"
#include "DMfunctions.cpp"

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

using std::cin;
using std::cout;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1 //работа с одномерными массивами

	int n;
	cout << "Введите размер массива: "; cin >> n;
	char* arr = new char[n];
	FillRand(arr, n);
	Print(arr, n);

	char a;
	cout << "Введите элемент для добавления его в начало массива: "; cin >> a;
	arr = push_front(arr, n, a);
	Print(arr, n);

	cout << "\nВведите элемент для добавления его в конец массива: "; cin >> a;
	arr = push_back(arr, n, a);
	Print(arr, n);

	int j = 0, k = 0;
	cout << "\nВведите элемент для добавления его в массив: "; cin >> a;
	cout << "Введите индекс для добавления нового элемента: "; cin >> k;
	while (k > n || k < 0)
	{
		cout << "Невозможно вставить элемент в позицию " << k << ", введите число от 0 до " << n <<": "; cin >> k;
	}
	arr = insert(arr, n, a, k);
	Print(arr, n);

	cout << "\nУдалили последний элемент массива:\n";
	Print(arr = pop_back(arr, n), n);

	arr = pop_front(arr, n);
	cout << "\nУдалили нулевой элемент массива:\n";
	Print(arr, n);

	cout << "\nВведите индекс для удаления элемента: "; cin >> k;
	while (k > n -1 || k < 0)
	{
		cout << "Невозможно удалить элемент из позиции " << k << ", введите число от 0 до " << n - 1 << ": "; cin >> k;
	}
	arr = erase(arr, n, k);
	Print(arr, n);

	delete[] arr; // memory leak
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows = 3, cols = 5; //для ускорения при отладке ввела сразу
	int n;
	cout << "Введите количество строк: 3\n"; //cin >> rows;
	cout << "Введите количество элементов строки: 5"; //cin >> cols;

	//создаем массив указателей
	int** arr = new int* [rows];

	//выделяем память под строки двумерного динамического массива
	for (int i = 0; i < rows; i++)
		arr[i] = new int[cols];

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
	while (n < 0 || n >= rows)
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
	while (n < 0 || n >= cols)
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
	while (n < 0 || n > rows)
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
	while (n < 0 || n > cols)
	{
		cout << "Введите число от 0 до " << cols - 1 << ": "; cin >> n;
	}
	arr = erase_col(arr, rows, cols, n);
	Print(arr, rows, cols);









	//удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем массив указателей
	delete[] arr;
#endif // DYNAMIC_MEMORY_2

}