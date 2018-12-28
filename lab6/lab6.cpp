#include "pch.h"
#include <iostream>

//Наследование. Заимствование. Свойства методов родительского класса в производном классе.
//1.ОПРЕДЕЛЕНИЕ И СИНТАКСИС
//СИНТАКСИС:
//class имя_произв_класса: [тип_наследования] имя_родительского_класса1,
//В род.В заголовке при наследовании
//классе			public:			protected:		 private:
//public			public:			protected:		 private:
//protected		    protected:		protected:		 private:
//private			недоступно		недоступно		 недоступно
//2.Метод, переопределенный в дочерним классе полностью заменит унаследованный родительский метод
//Чтобы при запуске нового дочернего метода также выполнять и родительский необходимо указать явно
//в родительском классе void weapon::reload(){};
//в дочернем классе void rifle:: reload():weapon::reload(), ... {};
//3.Если объявить метод со словом virtual, в данном классе можно не проводить реализацию метода,
//и определить его (привести реализацию) только в дочерних классах
//4.void fnc1(const тип1 параметр1, тип 2 параметр2)
//{
// Параметр1=10;
//}
//Объявление константого метода класса запрещает ему менять какое-либо из свойств объекта
//                                             \/
//void fnc1( тип1 параметр1, тип 2 параметр2) const
//{
// Параметр1=10;
//}
//4* Приведение типов
//При попытке сложить/умножить/вычесть/разделить
//int i = -15;
//double d = 1000.5e+03; // = 1000.5 * 10^3 = 1000.5 * pow(10, 3) = 1000500 = 1000.5e03
//float result1;
//long long result2;
//result1 = i + d;
//result2 = i / d;
//const char *ch1 = "123"; // {'1', '2', '3', 0} = {'1', '2', '3', '\0'}
//const char *ch2 = "456";
//? ? ? = ch1 + ch2;
//std::string "1233456"
//getchar();
//return 0;

class matrix
{
private:
	double matr[10][10];
	int rows;
	int columns;
public:
	matrix();
	~matrix();
	bool input();
	bool print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	bool transp();
	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	double getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		return -1;
		std::cout << "Connot get element.Index Error!\n";
		return -1;
	}
};
class vector
{
private: 
	double vec[10];
	int n;
public:
	
	int getN() { return n; }
	int vecEl(int n)
	{
		if ((n < 11) && (n > 1))
		{
			return vec[n];
		}
		else
			std::cout << "Error";
	}
	bool vecEnter()
	{
		std::cout << "Введите количество векторов";
		std::cin >> n;
		if ((n > 10) && (n < 1))
		{
			std::cout << "Error";
		}
		else
			for (int i = 0; i < n; i++)
			{
				std::cout << vec[i] << '\t';
				std::cout << '\n';
			}
		return true;
	}

	bool multVEC(vector vec2)
	{
			if (n == vec2.getN())
			{ 
				int nsr = 0;
				for (int i = 0; i < n; i++)
				{
				
					{
						nsr += vec[i] * vec2.vecEl(i);
					}
					std::cout << nsr;
				}
				std::cout << std::endl << "Done" << std::endl;
				return true;
			}
			else
			{
				std::cout << std::endl << "Error" << std::endl;
				return false;
			}
	}
	
	void kvec(int k)
	{
		for (int i = 0; i < n; i++)
		{
			vec[i] *= k;
			std::cout << vec[i] << ' ';

		}
	};

};



int main()
{
		setlocale(0, "");

		matrix matrA, matrB;
		matrA.input();
		std::cout << "Матрица A \n";
		matrA.print();

		matrB.input();
		std::cout << "Матрица B \n";
		matrB.print();

		matrA.transp();
		matrA.print();
		

		matrA.summMatrix(matrB);
		std::cout << "A + B \n";
		matrA.print();

		matrA.multMatrix(matrB);
		std::cout << "A * B \n";
		matrA.print();

		vector vecA;
		vecA.vecEnter();
		int k;
		std::cout << "k=";
		std::cin >> k;
		vecA.kvec(k);

		vecA.vecEnter();
		vecA.kvec(5);
		getchar();
		return 0;//
}

matrix::matrix()
{
	
}

matrix::~matrix()

{
}



bool matrix::input()
{  
	std::cout << "Введите количество строк";
	std::cin >> rows;
	if (rows < 1 || rows>10)
		return false;
	std::cout << "Введите количество столбцов";
	std::cin >> columns;
	if (columns < 1 || columns > 10)
		return false;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i][j];
		}
	}
	return true;
}
bool matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matr[i][j] << '\t';
		}
		std::cout << '\n';
	}
	return true;
}
bool matrix::summMatrix(matrix matr1)
{
	if ((rows == matr1.getRows()) && (columns == matr1.getColumns()))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i][j] += matr1.getElem(i, j);
			}
		}
		std::cout << std::endl << "Done" << std::endl;
		return true;
	}
	else
	{
		std::cout << std::endl << "Error" << std::endl;
		return false;
	}
}

bool matrix::multMatrix(matrix matr1)
{
	if (rows == matr1.columns)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr1.columns; j++)
			{
				int lm = 0;
				for (int k = 0; k < rows; k++)
				{
					lm += matr[i][k] * matr1.matr[k][j];
				}
				matr[i][j] = lm;
			}
		}
		std::cout << std::endl << "Done" << std::endl;
		return true;
	}
	else
	{
		std::cout << std::endl << "Error" << std::endl;
		return false;
	}
}
bool matrix::transp()
{
	if (rows != columns)
	{
		std::cout << "Мы транспонируем только квадратные матрицы.\n" << std::endl;
	}
	else
	{
		int ch = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = i; j < columns; j++) {
				int ch = matr[i][j];
				matr[i][j] = matr[j][i];
				matr[j][i] = ch;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				std::cout << matr[i][j] << "\t";
			std::cout << std::endl;
		}
		std::cout << "\n";
		std::cout << std::endl << "Done" << std::endl;
		return true;
	}
	
};


