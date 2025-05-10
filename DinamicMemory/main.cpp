#include "stdafx.h"
#include "DMfunctions.h"
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define tab "\t"

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

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	//создаем массив указателей
	int** arr = new int* [rows];

	//выделяем память под строки двумерного динамического массива
	for (int i = 0; i < rows; i++)
		arr[i] = new int[cols];

	//Заполняем массив
	FillRand(arr, rows, cols);

	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	cout << "\n\nДобавили строку в конце\n";
	Print(arr, rows, cols);

	//удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем массив указателей
	delete[] arr;

}