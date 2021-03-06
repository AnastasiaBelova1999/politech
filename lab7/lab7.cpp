#include <iostream>

/* int arr[11][12] = {0};  - в таком объявлении только константные размерности
	стековая память ограничена, при неправильном использовании стек переполняется (stack overflow)
	размерности массивов, выделяемых в стековой памяти, фиксированы и задаются константами
	int b[1000][1000] = {0} ; - переполнение стека
	для использования свободной памяти ОС (heap - куча_)
	объявляются динамические переменные по синтаксису
	указатель_на_тип_ имя_переменной = new тип;
	или тип *имя_переменной = new тип;
	работа с динамической памятью происходит через указатели
	Преимущества:
	1. доступно гораздо больше памяи, нежели в стеке
	2. размеры массивов и структур данных можно определять и менять во время работы приложения
	Особенность:
	Если приложение предназначено для длительной работы,
	во избежание переполнения памяти созданные переменные и блоки памяти после испльзования
	должны быть освобождены с помощью оператора delete:
	delete имя_переменной;

	int * ptr_int = new int; // в неопределенной памяти создается блок
	// размером с int и указатель на него возвращается в переменную ptr_int
	// вызов утечки памяти
	for (int i = 0; i < 1000; i++)
	{
		long long * b = new long long;
		1. каждый заход в стеке создается новый указатель
		2. выделяется блок new long long; в куче (нераспределенной памяти), приписанной к этой программе
		3. стековая переменная b исчезает
		4. а блок по-прежнему остается там же
		5. при следующем заходе выделяется новый блок// совершать нужные действия  с переменной

		delete b; // удалить блок памяти пока не потерян указатель на нее
	}
	// пара операторов new/delere -  это одно из нововведений с++ относительно С
	 в динамической памяти могут выделяться только одномерные массивы
	тип * имя_указателя = new типь [длина];
	удаляются одномерные массивы с помощью записи
	delete [] имя_указателя
	int * matr = new int[11 * 12];
	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			matr[row * 11 + col] = row * 11 + col;
		}
	}
	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			std::cout << matr[row * 11 + col] << "\t";
		}
	}
}
*/
	

class dynamic_matrix
{
private:
	int rows;
	int columns;
	int * matr;
public:
	dynamic_matrix();
	~dynamic_matrix()
	{
	};
	bool input();
	bool print();
	bool summMatrix(dynamic_matrix matr1);
	bool multMatrix(dynamic_matrix matr1);
	bool transp();
	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	int getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row*col];
		}
		std::cout << "Cannot get element. Index Error!\n";
		return	-1;
	}
	void del()
	{
		if (matr != 0)
		{
			delete matr;
			std::cout << "Null";
		}
		else std::cout << "DONT NULL";
	};
};

bool dynamic_matrix::input()
{
	std::cout << "Введите количество строк";
	std::cin >> rows;
	if (rows < 1 || rows>10)
		return false;
	std::cout << "Введите количество столбцов";
	std::cin >> columns;
	if (columns < 1 || columns > 10)
		return false;
	int **matr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		matr[i] = new int[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i][j];
		}
	}
	return true;
}

bool dynamic_matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matr[i*j] << '\t';
		}
		std::cout << '\n';
	}
	return true;

}
bool dynamic_matrix::summMatrix(dynamic_matrix matr1)
{

	if ((rows == matr1.getRows()) && (columns == matr1.getColumns()))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i*j] += matr1.getElem(i, j);
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

bool dynamic_matrix::multMatrix(dynamic_matrix matr1)
{
	int *matr3 = new int[matr1.columns*rows];
	if (rows == matr1.columns)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr1.columns; j++)
			{
				int lm = 0;
				for (int k = 0; k < rows; k++)
				{
					lm += matr[i*k] * matr1.matr[k*j];
				}
				matr[i*j] = lm;
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
bool dynamic_matrix::transp()
{
	int *matr3 = new int[rows*columns];
	if (rows != columns)
	{
		std::cout << "Мы транспонируем только квадратные матрицы.\n" << std::endl;
	}
	else
	{
		int ch = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = i; j < columns; j++) {
				int ch = matr[i*j];
				matr[i*j] = matr[j*i];
				matr[j*i] = ch;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				std::cout << matr[i*j] << "\t";
			std::cout << std::endl;
		}
		std::cout << "\n";
		std::cout << std::endl << "Done" << std::endl;
		return true;
	}

};

int main()
{
	setlocale(0, "");

	dynamic_matrix matrA, matrB;
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
	matrA.del();
	matrB.del();
	system("pause");
	return 0;
}