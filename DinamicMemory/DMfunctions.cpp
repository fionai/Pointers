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
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void push_front(int a, int arr[], const int n, int brr[]) //добавляет А в начало массива
{
	brr[0] = a;
	for (int i = 0; i < n; i++)
		brr[i + 1] = arr[i];
}
void insert(int a, int k, int arr[], const int n, int brr[]) //добавляет число а по указанному индексу k 
{
	for (int i = 0; i <= n; i++)
	{
		if (i < k)
			brr[i] = arr[i];
		else if (i == k)
			brr[i] = a;
		else if (i > k)
			brr[i] = arr[i - 1];
	}
}
void pop_back(int arr[], const int n, int brr[]) //удаляет последний элемент массива
{
	for (int i = 0; i < n - 1; i++)
		brr[i] = arr[i];
}
void pop_front(int arr[], const int n, int brr[])	//удаляет нулевой элемент массива
{
	for (int i = 0; i < n - 1; i++)
		brr[i] = arr[i + 1];
}
void erase(int k, int arr[], const int n, int brr[])		//удаляет элемент массива по указанному индексу k
{
	for (int i = 0; i < n; i++)
	{
		if (i < k)
			brr[i] = arr[i];
		else if (i > k)
			brr[i - 1] = arr[i];
	}

}