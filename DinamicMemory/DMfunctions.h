#pragma once

#include "stdafx.h"

template <typename T>
void Allocate(T** arr, const int rows, const int cols); //Выделяет память под двумерный динамический массив
template <typename T>
void Clear(T** arr, const int rows, const int cols);    //Удаляет память, занимаемую мерным динамическим массивом


template <typename T>
void FillRand(T arr[], const int n);


template <typename T>
void Print(T arr[], const int n);

template <typename T>
T* push_back(T arr[], int& n, int value); //добавляет значение в конец массива
template <typename T>
T* push_front(T arr[], int& n, int value); //добавляет значение в начало массива
template <typename T>
T* insert(T arr[], int& n, int a, int k); //добавляет значение  по указанному индексу k 
template <typename T>
T* pop_back(T arr[], int& n); //удаляет последний элемент массива
template <typename T>
T* pop_front(T arr[], int& n);	//удаляет нулевой элемент массива
template <typename T>
T* erase(T arr[], int& n, int k);		//удаляет элемент массива по указанному индексу k

template <typename T>
void FillRand(T** arr, const int rows, const int cols);
template <typename T>
void Print(T** arr, const int rows, const int cols);
template <typename T>
T** push_row_front(T** arr, int& rows, const int cols); //добавляет строку в начало массива
template <typename T>
T** push_row_back(T** arr, int& rows, const int cols); //добавляет строку в конец массива
template <typename T>
T** insert_row(T** arr, int& rows, const int cols, int n); //добавляет строку в указанное место
template <typename T>
T** push_col_front(T** arr, const int rows, int& cols); //добавляет столбец в начало массива
template <typename T>
T** push_col_back(T** arr, const int rows, int& cols); //добавляет столбец в конец массива
template <typename T>
T** insert_col(T** arr, const int rows, int& cols, int n); //добавляет столбец в указанное место
template <typename T>
T** pop_row_front(T** arr, int& rows, const int cols); //удаляет строку из начала массива
template <typename T>
T** pop_row_back(T** arr, int& rows, const int cols); //удаляет строку в конце массива
template <typename T>
T** erase_row(T** arr, int& rows, const int cols, int n); //удаляет строку в указанном месте
template <typename T>
T** pop_col_front(T** arr, const int rows, int& cols); //удаляет столбец из начала массива
template <typename T>
T** pop_col_back(T** arr, const int rows, int& cols); //удаляет столбец в конце массива
template <typename T>
T** erase_col(T** arr, const int rows, int& cols, int n); //удаляет столбец в указанном месте
