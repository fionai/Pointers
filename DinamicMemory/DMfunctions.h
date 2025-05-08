#pragma once

#include "stdafx.h"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], const int n, int value);
int* push_front(int arr[], const int n, int value); //добавляет число а в начало массива
int* insert(int arr[], const int n, int a, int k); //добавляет число а по указанному индексу k 
int* pop_back(int arr[], const int n); //удаляет последний элемент массива
int* pop_front(int arr[], const int n);	//удаляет нулевой элемент массива
int* erase(int arr[], const int n, int k);		//удаляет элемент массива по указанному индексу k