#include "stdafx.h"
#include "DMfunctions.h"

//using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int* brr = new int[n + 1];
	int a;
	cout << "������� ����� ��� ���������� ��� � ������ �������: "; cin >> a;
	push_front(a, arr, n, brr);
	Print(brr, n + 1);

	int j = 0, k = 0;
	cout << "\n������� ����� ��� ���������� ��� � �������� ������: "; cin >> a;
	cout << "������� ������ ��� ���������� ������ �����: "; cin >> k;
	while (k > n || k < 0)
	{
		cout << "���������� �������� ����� � ������� " << k << ", ������� ����� �� 0 �� " << n <<": "; cin >> k;
	}
	insert(a, k, arr, n, brr);
	Print(brr, n + 1);
	delete[] brr;

	brr = new int[n - 1];
	pop_back(arr, n, brr);
	cout << "\n������� ��������� ������� ��������� �������:\n";
	Print(brr, n - 1);

	pop_front(arr, n, brr);
	cout << "\n������� ������� ������� ��������� �������:\n";
	Print(brr, n - 1);

	cout << "\n������� ������ ��� �������� �����: "; cin >> k;
	while (k > n -1 || k < 0)
	{
		cout << "���������� �������� ����� � ������� " << k << ", ������� ����� �� 0 �� " << n - 1 << ": "; cin >> k;
	}
	erase(k, arr, n, brr);
	Print(brr, n - 1);

	delete[] arr; // memory leak
	delete[] brr;
}