// lab3_bubble.cpp : 

#include "pch.h"
#include <iostream>
int main()
{
	int bubble[10]{ 8, 4, 6, 5, 7, 0, 2, 3, 1, 9 };
	int tem; //временная переменная для обмена элементов местами
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (bubble[j] > bubble[j + 1]) {
				tem = bubble[j];
				bubble[j] = bubble[j + 1];
				bubble[j + 1] = tem;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		std::cout << bubble[i] << "\t";
	}
	return 0;
}



