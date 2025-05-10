#pragma once

#include "stdafx.h"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, int value); //добавляет число value в конец массива
int* push_front(int arr[], int& n, int value); //добавляет число value в начало массива
int* insert(int arr[], int& n, int a, int k); //добавляет число  по указанному индексу k 
int* pop_back(int arr[], int& n); //удаляет последний элемент массива
int* pop_front(int arr[], int& n);	//удаляет нулевой элемент массива
int* erase(int arr[], int& n, int k);		//удаляет элемент массива по указанному индексу k

int** push_row_front(int** arr, int& rows, const int cols); //добавляет строку в начало массива
int** push_row_back(int** arr, int& rows, const int cols); //добавляет строку в конец массива
int** insert_row(int** arr, int& rows, const int cols, int n); //добавляет строку в указанное место

int** push_col_front(int** arr, const int rows, int& cols); //добавляет столбец в начало массива
int** push_col_back(int** arr, const int rows, int& cols); //добавляет столбец в конец массива
int** insert_col(int** arr, const int rows, int& cols, int n); //добавляет столбец в указанное место

int** pop_row_front(int** arr, int& rows, const int cols); //удаляет строку из начала массива
int** pop_row_back(int** arr, int& rows, const int cols); //удаляет строку в конце массива
int** erase_row(int** arr, int& rows, const int cols, int n); //удаляет строку в указанном месте

int** pop_col_front(int** arr, const int rows, int& cols); //удаляет столбец из начала массива
int** pop_col_back(int** arr, const int rows, int& cols); //удаляет столбец в конце массива
int** erase_col(int** arr, const int rows, int& cols, int n); //удаляет столбец в указанном месте
