#pragma once

#include "DMfunctions.h"

template <typename T>
void Allocate(T** arr, const int rows, const int cols) //Выделяет память под двумерный динамический массив
{
	//выделяем память под строки двумерного динамического массива
	for (int i = 0; i < rows; i++)
		arr[i] = new T[cols];
}
template <typename T>
void Clear(T** arr, const int rows, const int cols)	 //Удаляет память, занимаемую мерным динамическим массивом
{
	//удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//удаляем массив указателей
	delete[] arr;
}

template <typename T>
void FillRand(T arr[], const int n)
{
	int n_time = time(NULL) % 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() + n_time) % 100;
		n_time = (n_time + time(NULL) + 1) % 100;
	}
}
template <typename T>
void FillRand(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
		FillRand(arr[i], cols);			//Оптимизация 1. Вызов другой функции
}

template <typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
	cout << endl;
}
template <typename T>
void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
		Print(arr[i], cols);		//Оптимизация 2.

}

template <typename T>
T* push_back(T arr[], int& n, int value)
{
	arr = insert(arr, n, value, n);		//Оптимизация 3
	return arr;
}
template <typename T>
T* push_front(T arr[], int& n, int value)//добавляет значение в начало массива
{
	arr = insert(arr, n, value, 0);		//Оптимизация 3
	return arr;
}
template <typename T>
T* insert(T arr[], int& n, int value, int k) //добавляет значение по указанному индексу k 
{
	T* buf = new T[n + 1];
	for (int i = 0; i <= n; i++)
	{
		if (i < k)
			buf[i] = arr[i];
		else if (i > k)
			buf[i] = arr[i - 1];
	}
	buf[k] = value;
	delete[] arr;
	n++;
	return buf;
}

template <typename T>
T* pop_back(T arr[], int& n) //удаляет последний элемент массива
{
	arr = erase(arr, n, n - 1);		//Оптимизация 4
	return arr;
}
template <typename T>
T* pop_front(T arr[], int& n)	//удаляет нулевой элемент массива
{
	arr = erase(arr, n, 0);			//Оптимизация 4
	return arr;
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
T** push_row_front(T** arr, int& rows, const int cols, T value)
{
	arr = insert_row(arr, rows, cols, 0, value);   //Оптимизация 5
	return arr;
}
template <typename T>
T** push_row_back(T** arr, int& rows, const int cols, T value)
{
	arr = insert_row(arr, rows, cols, rows, value);   //Оптимизация 5
	return arr;
}
template <typename T>
T** insert_row(T** arr, int& rows, const int cols, int n, T value)
{
	//создаем буферный массив указателей нужного размера
	T** buf = new T* [rows + 1];

	//копируем адреса строк в буферный массив указателей
	for (int i = 0; i < n; i++)
		buf[i] = arr[i];
	//добавляем новую строку и записываем ее адрес в массив указателей
	buf[n] = new T[cols];
	for (int j = 0; j < cols; j++)
		buf[n][j] = value;
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
void push_col_front(T** arr, const int rows, int& cols, T value) //добавляет столбец в начало массива
{
	insert_col(arr, rows, cols, 0, value); //Оптимизация 6
}
template <typename T>
void push_col_back(T** arr, const int rows, int& cols, T value) //добавляет столбец в конец массива
{
	insert_col(arr, rows, cols, cols, value); //Оптимизация 6
}
template <typename T>
void insert_col(T** arr, const int rows, int& cols, int n, T value) //добавляет столбец в указанное место
{
	//копируем все значения в буферный массив указателей и вставляем новый элемент в нужную позицию
	for (int i = 0; i < rows; i++)
	{
		T* buf = new T[cols + 1]{};
		for (int j = 0; j < n; j++)
			buf[j] = arr[i][j];
		buf[n] = value; //заполняем новый столбец
		for (int j = n; j < cols; j++)
			buf[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buf;
		//buf[i] = insert(arr[i], cols, 666, n);
		//cols--;
	}
	//при добавлении в массив столбца, количество столбцов увеличивается на 1
	++cols;
}

template <typename T>
T** pop_row_front(T** arr, int& rows, const int cols) //удаляет строку из начала массива
{
	arr = erase_row(arr, rows, cols, 0);
	return arr;
}
template <typename T>
T** pop_row_back(T** arr, int& rows, const int cols) //удаляет строку в конце массива
{
	arr = erase_row(arr, rows, cols, rows-1);
	return arr;
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
void pop_col_front(T** arr, const int rows, int& cols) //удаляет столбец из начала массива
{
	erase_col(arr, rows, cols, 0);
}
template <typename T>
void pop_col_back(T** arr, const int rows, int& cols) //удаляет столбец в конце массива
{
	erase_col(arr, rows, cols, cols-1);
}
template <typename T>
void erase_col(T** arr, const int rows, int& cols, int n) //удаляет столбец в указанном месте
{
	cols--;
	
	//копируем все нужные значения в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		T* buf = new T[cols];
		for (int j = 0; j < n; j++)
			buf[j] = arr[i][j];
		for (int j = n; j < cols; j++)
			buf[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buf;
	}

}