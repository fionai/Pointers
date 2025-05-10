#pragma once

#include "DMfunctions.h"

template <typename T>
void FillRand(T arr[], const int n)
{
	int n_time = time(NULL) % 256;
	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() + n_time) % 256;
		n_time = (n_time + time(NULL) + 1) % 256;
	}
}

template <typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

template <typename T>
T* push_back(T arr[], int& n, int value)
{
	T* buf = new T[n + 1];
	for (int i = 0; i < n; i++)
		buf[i] = arr[i];
	buf[n] = value;
	delete[] arr;
	n++;
	return buf;
}
template <typename T>
T* push_front(T arr[], int& n, int value)// , int brr[]) //добавляет значение в начало массива
{
	T* buf = new T[n + 1];
	for (int i = 0; i < n; i++)
		buf[i+1] = arr[i];
	buf[0] = value;
	delete[] arr;
	n++;
	return buf;
}
template <typename T>
T* insert(T arr[], int& n, int value, int k) //добавляет значение по указанному индексу k 
{
	T* buf = new T[n + 1];
	for (int i = 0; i <= n; i++)
	{
		if (i < k)
			buf[i] = arr[i];
		else if (i == k)
			buf[i] = value;
		else if (i > k)
			buf[i] = arr[i - 1];
	}
	delete[] arr;
	n++;
	return buf;
}
template <typename T>
T* pop_back(T arr[], int& n) //удаляет последний элемент массива
{
	T* buf = new T[--n];
	for (int i = 0; i < n; i++)
		buf[i] = arr[i];
	delete[] arr;
	return buf;
}
template <typename T>
T* pop_front(T arr[], int& n)	//удаляет нулевой элемент массива
{
	T* buf = new T[--n];
	for (int i = 0; i < n; i++)
		buf[i] = arr[i+1];
	delete[] arr;
	return buf;
}
template <typename T>
T* erase(T arr[], int& n, int k)		//удаляет элемент массива по указанному индексу k
{
	T* buf = new T[--n];
	for (int i = 0; i < n+1; i++)
	{
		if (i < k)
			buf[i] = arr[i];
		else if (i > k)
			buf[i - 1] = arr[i];
	}
	delete[] arr;
	return buf;
}
template <typename T>
void FillRand(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] = rand() % 100;
}
template <typename T>
void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}
template <typename T>
T** push_row_front(T** arr, int& rows, const int cols)
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [rows + 1];

	//копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
		buf[i + 1] = arr[i];

	//удаляем исходный массив указателей
	delete[] arr;

	//добавляем новую строку и записываем ее адрес в массив указателей
	buf[0] = new T[cols];
	for (int j = 0; j < cols; j++)
		buf[0][j] = 111;

	//при добавлении в массив строки, количество строк увеличивается на 1
	rows++;

	//возвращаем новый массив на место вызова
	return buf;
}
template <typename T>
T** push_row_back(T** arr, int& rows, const int cols)
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [rows+1];

	//копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
		buf[i] = arr[i];

	//удаляем исходный массив указателей
	delete[] arr;
	
	//добавляем новую строку и записываем ее адрес в массив указателей
	buf[rows] = new T[cols];
	for (int j = 0; j < cols; j++)
		buf[rows][j] = 222;

	//при добавлении в массив строки, количество строк увеличивается на 1
	rows++;

	//возвращаем новый массив на место вызова
	return buf;
}
template <typename T>
T** insert_row(T** arr, int& rows, const int cols, int n)
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [rows + 1];


	//копируем адреса строк в буферный массив указателей
	for (int i = 0; i < n; i++)
		buf[i] = arr[i];
	//добавляем новую строку и записываем ее адрес в массив указателей
	buf[n] = new T[cols];
	for (int j = 0; j < cols; j++)
		buf[n][j] = 333;
	for (int i = n+1; i <= rows; i++)
		buf[i] = arr[i-1];

	//удаляем исходный массив указателей
	delete[] arr;

	//при добавлении в массив строки, количество строк увеличивается на 1
	rows++;

	//возвращаем новый массив на место вызова
	return buf;
}
template <typename T>
T** push_col_front(T** arr, const int rows, int& cols) //добавляет столбец в начало массива
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [rows];
	for (int i = 0; i < rows; i++)
		buf[i] = new T[cols + 1];

	//копируем все значения в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		buf[i][0] = 444; //заполняем первый (нулевой) столбец
		for (int j = 0; j < cols; j++)
			buf[i][j + 1] = arr[i][j];
	}

	//удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем исходный массив указателей
	delete[] arr;

	//при добавлении в массив столбца, количество столбцов увеличивается на 1
	cols++;

	//возвращаем новый массив на место вызова
	return buf;
}
template <typename T>
T** push_col_back(T** arr, const int rows, int& cols) //добавляет столбец в конец массива
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [rows];
	for (int i = 0; i < rows; i++)
		buf[i] = new T[cols + 1];

	//копируем все значения в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			buf[i][j] = arr[i][j];
		buf[i][cols] = 555; //заполняем последний столбец
	}

	//удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем исходный массив указателей
	delete[] arr;

	//при добавлении в массив столбца, количество столбцов увеличивается на 1
	++cols;
	//возвращаем новый массив на место вызова
	return buf;
}
template <typename T>
T** insert_col(T** arr, const int rows, int& cols, int n) //добавляет столбец в указанное место
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [rows];
	for (int i = 0; i < rows; i++)
		buf[i] = new T[cols + 1];

	//копируем все значения в буферный массив указателей и вставляем новый элемент в нужную позицию
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < n; j++)
			buf[i][j] = arr[i][j];
		buf[i][n] = 666; //заполняем последний столбец
		for (int j = n; j < cols; j++)
			buf[i][j+1] = arr[i][j];
	}

	//удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем исходный массив указателей
	delete[] arr;

	//при добавлении в массив столбца, количество столбцов увеличивается на 1
	++cols;

	//возвращаем новый массив на место вызова
	return buf;
}
template <typename T>
T** pop_row_front(T** arr, int& rows, const int cols) //удаляет строку из начала массива
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [--rows];

	//копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
		buf[i] = arr[i+1];

	//удаляем начальную строку
	delete[] arr[0];
	//удаляем исходный массив указателей
	delete[] arr;

	//возвращаем новый массив на место вызова
	return buf;
}
template <typename T>
T** pop_row_back(T** arr, int& rows, const int cols) //удаляет строку в конце массива
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [--rows];

	//копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
		buf[i] = arr[i];

	//удаляем начальную строку
	delete[] arr[rows];
	//удаляем исходный массив указателей
	delete[] arr;

	//возвращаем новый массив на место вызова
	return buf;
}
template <typename T>
T** erase_row(T** arr, int& rows, const int cols, int n) //удаляет строку в указанном месте
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [--rows];

	//копируем адреса строк в буферный массив указателей
	for (int i = 0; i < n; i++)
		buf[i] = arr[i];
	for (int i = n; i < rows; i++)
		buf[i] = arr[i+1];

	//удаляем начальную строку
	delete[] arr[n];
	//удаляем исходный массив указателей
	delete[] arr;

	//возвращаем новый массив на место вызова
	return buf;
}

template <typename T>
T** pop_col_front(T** arr, const int rows, int& cols) //удаляет столбец из начала массива
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [rows];
	cols--;
	for (int i = 0; i < rows; i++)
		buf[i] = new T[cols];

	//копируем все нужные значения в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			buf[i][j] = arr[i][j+1];
	}

	//удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем исходный массив указателей
	delete[] arr;

	//возвращаем новый массив на место вызова
	return buf;
}
template <typename T>
T** pop_col_back(T** arr, const int rows, int& cols) //удаляет столбец в конце массива
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [rows];
	cols--;
	for (int i = 0; i < rows; i++)
		buf[i] = new T[cols];

	//копируем все нужные значения в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			buf[i][j] = arr[i][j];
	}

	//удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем исходный массив указателей
	delete[] arr;

	//возвращаем новый массив на место вызова
	return buf;
}
template <typename T>
T** erase_col(T** arr, const int rows, int& cols, int n) //удаляет столбец в указанном месте
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [rows];
	cols--;
	for (int i = 0; i < rows; i++)
		buf[i] = new T[cols];

	//копируем все нужные значения в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < n; j++)
			buf[i][j] = arr[i][j];
		for (int j = n; j < cols; j++)
			buf[i][j] = arr[i][j+1];
	}

	//удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем исходный массив указателей
	delete[] arr;

	//возвращаем новый массив на место вызова
	return buf;
}