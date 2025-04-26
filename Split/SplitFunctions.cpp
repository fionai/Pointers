#include "SplitFunctions.h"


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
int CountE(int arr[], const int n)
{
	int n_e = 0;
	for (int i = 0; i < n; i++)
		if (!(arr[i] % 2))
			n_e++;
	return n_e;
}
void Separate(int arr[], int arr_e[], int arr_o[], const int n, const int n_e, const int n_o)
{
	int i_o = 0, i_e = 0;
	for (int i = 0; i < n; i++)
	{
		if (!(arr[i] % 2))
		{
			if (i_e == n_e)
			{
				cout << "Ошибка переполнения четного массива!";
				return;
			}
			else
			{
				arr_e[i_e] = arr[i];
				i_e++;
			}
		}   //if (!(arr[i] % 2))
		else  //if (arr[i] % 2)
		{
			if (i_o == n_o)
			{
				cout << "Ошибка переполнения нечетного массива!";
				return;
			}
			else
			{
				arr_o[i_o] = arr[i];
				i_o++;
			}
		}  //if (arr[i] % 2)

	}
}