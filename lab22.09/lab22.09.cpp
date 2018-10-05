// lab2209.cpp: определяет точку входа для консольного приложения.
//Тема:Массивы
// массив-блок из нескольких однотипных данных
// задавать массивом удобно:
// 1)векторы и матрицы
// 2) множество точек 2D и 3D геометрии
// 3)просто какой-либо числовой ряд, таблица и т.д.
// 4) строка-массив символов 
// 5) видеобуфер


// тип_данных имя_массива[размер]
// тип_данных имя_массива[размер] = {значение_для_всех}
// тип_данных имя_массива[размер] = {значение1, значение2, значение3}
//обращение к элементам массива: имя_массива{индекс}
// нумерация элементов массива начинается с 0 до длина-1
//тип_данных имя_массива[размер1][размер2]- int {3}-столбец{3}-строка
//int{3}{3}={{0}}-массив 0
//{{a11,a12,a13}
//{a21,a22,a23}
//{a31,a32,a33}}
#include "pch.h"
#include <iostream>

int main()
{


	int arr1[3][3] = {
		{ 2,3,5 },
		{ 2,2,3 },
		{ 3,4,5 },
	};
	int arr2[3][3] = {
		{ 4,5,6 },
		{ 5,3,1 },
		{ 3,6,7 },
	};
	int arr3[3][3] = { {0} };
	int arr4[3][3] = { { 0 } };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr3[i][j] += arr1[i][j] * arr2[i][j];

		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << arr3[i][j] << '\t';
		}
		std::cout << '\n';
	}

	std::cout << '\n';
	std::cout << '\n';

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				arr4[i][j] += arr1[i][k] * arr2[k][j];
			}

		}

	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << arr4[i][j] << '\t';
		}
		std::cout << '\n';
	}
	return 0;
}