// Overload.cpp 

#include "pch.h"
#include <iostream>
/*
ПЕРЕГРУЗКА (Overloading)- объявление нескольких функций (а также методов классов и операторов, которые тоже явл-ся функциями) с одинаковыми именами, но разным набором аргументов.*/
/* matrix & operator += (matrix & second_matr)
{
	 for (int stroki=0; stroki < strok; stroki++)
	 {
		for (int stolbs=0; stolbs < stolb; stolbs++)
	   {
		   this -> setElem (i,j,first_matr [i][j] + second_matr.getElem(i,j))
		}
	 }

	return  (*this);
}

*/
double fmc1(double p1, char p2)
{
	std::cout << "fnc1(double, char)";
	return p1 + p2;
}
double fmc1(double p1, char p2)
{}
int fmc1(int p1, char p2)
{}
/*Различие функций по одному выходному параметру не являтся перегрузкой.
Для компилятора критерием является сигнатура функции- имя + последовательность аргументов + их типы
Даже если аргументы имеют разные названия, но типы и последовательность одинаковые компилятор считает такой случай не перегрузкой, а повторным объявлением, что является ошибкой:
int fnc1(double a,char b)
{
  std::cout << "fnc1(double,char)" << endl;
  return a-b;
}
*/
class sample_class
{
public:
	sample_class()
	{

	}
	int property1;// property- свойство(англ)
	double property2;
	int fnc1(double p1, char p2)
	{
		std::cout << "sample_class::fnc1 (double, char)" << '\n';
		return p1 + p2;
	}
	int fnc1(int p1, short p2)
	{
		std::cout << "sample_class::fnc1 (int, short)" << '\n';
		return p1 + p2;
	}
	/* Компилятор ищет точные совпадения типов аргументов,если не нашел, компилятор пытается использоватьприведение типов (char -> int,...) и снова ищет совпадения.
	Если не нашел, использует стандартные преобразования типов (все указатели в void, float -> double, doube ->int,....)
	При перегрузке может возникнуть неоднозначность: fnc1(0,'b');
	*/
	/*
	 int main()
	 {
	 ...
	 matr A,B,C;
	 ...
	 A.sum (B); // C=A+B; -overload operator+
	 ...
	 return 0;
	 }
	*/
	/* унарные и бинарные операторы перезагружаются по-разному
	  Унарные- в самом классе (получается новый метод класса)
	  Бинарные- как отдельную функцию
	  Бинарные операторы прописываются вне класса, таккак результат не обязательно записывается в один из операндов, а может записываться в некий третий объект
	  В унарных операторах результат записывается в тот же самый объект, для кот. вызван оператор, поэтому унарный стоит отнести к методам класса
	*/
	sample_class & operator += (const sample_class & operand)
		//здесь - const "защита от забывчивости"- не дает изменить внутри метода операнд, кот. по логике и не должен меняться
	{
		property1 = property1 + operand.property1;
		this->property2 = this->property2 + operand.property2; //с this -эффект не меняется
		return (*this);
	}
};

