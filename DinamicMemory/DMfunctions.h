#pragma once

#include "stdafx.h"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void push_front(int a, int arr[], const int n, int brr[]); //добавляет число а в начало массива
void insert(int a, int k, int arr[], const int n, int brr[]); //добавляет число а по указанному индексу k 
void pop_back(int arr[], const int n, int brr[]); //удаляет последний элемент массива
void pop_front(int arr[], const int n, int brr[]);	//удаляет нулевой элемент массива
void erase(int k, int arr[], const int n, int brr[]);		//удаляет элемент массива по указанному индексу k