// lab10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include "..\lib351\lib 351.h"
	int main()
	{
		setlocale(LC_ALL, "ru");

		matrix matrA, matrB;
		matrA.input();
		matrA.print();
		matrB.input(); matrB.print();
		std::cout << "";
		matrA.transp(); matrA.print();
		matrA.multiplication(2); matrA.print();
		matrA.summMatrix(matrB); matrA.print();
		matrA.multMatrix(matrB); matrA.print();
	}


