#pragma once

#include "stdafx.h"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void push_front(int a, int arr[], const int n, int brr[]); //��������� ����� � � ������ �������
void insert(int a, int k, int arr[], const int n, int brr[]); //��������� ����� � �� ���������� ������� k 
void pop_back(int arr[], const int n, int brr[]); //������� ��������� ������� �������
void pop_front(int arr[], const int n, int brr[]);	//������� ������� ������� �������
void erase(int k, int arr[], const int n, int brr[]);		//������� ������� ������� �� ���������� ������� k