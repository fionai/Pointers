#include "DMfunctions.h"


void FillRand(int arr[], const int n)
{
	int n_time = time(NULL) % 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = (rand() + n_time) % 100;
		n_time = (n_time + time(NULL) + 1) % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] = rand() % 100;
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << arr[i][j] << "\t";
		cout << endl;
	}
}

int* push_back(int arr[], int& n, int value)
{
	int* buf = new int[n + 1];
	for (int i = 0; i < n; i++)
		buf[i] = arr[i];
	buf[n] = value;
	delete[] arr;
	n++;
	return buf;
}
int* push_front(int arr[], int& n, int value)// , int brr[]) //добавляет А в начало массива
{
	int* buf = new int[n + 1];
	for (int i = 0; i < n; i++)
		buf[i+1] = arr[i];
	buf[0] = value;
	delete[] arr;
	n++;
	return buf;
}
int* insert(int arr[], int& n, int value, int k) //добавляет число а по указанному индексу k 
{
	int* buf = new int[n + 1];
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
int* pop_back(int arr[], int& n) //удаляет последний элемент массива
{
	int* buf = new int[--n];
	for (int i = 0; i < n; i++)
		buf[i] = arr[i];
	delete[] arr;
	return buf;
}
int* pop_front(int arr[], int& n)	//удаляет нулевой элемент массива
{
	int* buf = new int[--n];
	for (int i = 0; i < n; i++)
		buf[i] = arr[i+1];
	delete[] arr;
	return buf;
}
int* erase(int arr[], int& n, int k)		//удаляет элемент массива по указанному индексу k
{
	int* buf = new int[--n];
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

int** push_row_back(int** arr, int& rows, const int cols)
{
	//создаем буферный массив указателей нужного размера
	int** buf = new int* [rows+1];

	//копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
		buf[i] = arr[i];

	//удаляем исходный массив указателей
	delete[] arr;
	
	//добавляем новую строку и записываем ее адрес в массив указателей
	buf[rows] = new int[cols] {};

	//при добавлении в массив строки, количество строк увеличивается на 1
	rows++;

	//возвращаем новый массив на место вызова
	return buf;
}