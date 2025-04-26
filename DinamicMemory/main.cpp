#include "stdafx.h"

//using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	


	delete[] arr; // memory leak

}