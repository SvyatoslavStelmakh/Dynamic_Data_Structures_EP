#include "Header2.2b.h"

int index(int i, int j, int N) // функция для определения номера элемента [i][j] в одномерном массиве
{
	return (i * N + j);
}

void FillMatrixConstants(double* matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[index(i, j, N)] = (j + 1);
		}
	}
}

void FillMatrixConstants(double** matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = (j + 1);
		}
	}
}

void FillMatrixRandom(double* matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[index(i, j, N)] = rand() % 21 - 10;
		}
	}
}

void FillMatrixRandom(double** matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = rand() % 21 - 10;
		}
	}
}
void FillMatrixUser(double* matrix, int N)
{
	for (int i = 0; i < N; i++)				//строка
	{
		for (int j = 0; j < N; j++)			//столбец
		{
			std::cout << std::setw(5) << "a" << i + 1 << j + 1 << " ";
			std::cin >> matrix[index(i, j, N)];
		}
		std::cout << std::endl;
	}
}

void FillMatrixUser(double** matrix, int N)
{
	for (int i = 0; i < N; i++)				//строка
	{
		for (int j = 0; j < N; j++)			//столбец
		{
			std::cout << std::setw(5) << "a" << i + 1 << j + 1 << " ";
			std::cin >> matrix[i][j];
		}
		std::cout << std::endl;
	}
}

void OutputMatrix(double* matrix, int N)
{
	for (int i = 0; i < N; i++)				//строка
	{
		for (int j = 0; j < N; j++)			//столбец
		{
			std::cout << std::setw(5) << matrix[index(i, j, N)];
		}
		std::cout << std::endl;
	}
}

void OutputMatrix(double** matrix, int N)
{
	for (int i = 0; i < N; i++)				//строка
	{
		for (int j = 0; j < N; j++)			//столбец
		{
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << std::endl;
	}
}

void RaiseDegree(double* matrix, double* result, int N, int degree)		//возведение матрицы в степень для одномерного массива
{
	// Инициализация result как единичной матрицы
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result[index(i, j, N)] = (i == j) ? 1.0 : 0.0;
		}
	}

	// Временная матрица для хранения промежуточных результатов
	double* temp = new double [N * N];
	
	// Возведение матрицы в степень
	for (int d = 1; d <= degree; d++)
	{
		// Обнуляем temp
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				temp[index(i, j, N)] = 0.0;
			}
		}

		// Умножение матриц: temp = result * matrix
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					temp[index(i, j, N)] += result[index(i, k, N)] * matrix[index(k, j, N)];
				}
			}
		}

		// Копируем temp в result
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				result[index(i, j, N)] = temp[index(i, j, N)];
			}
		}
	}

	// Освобождаем память
	delete[] temp;
}

void RaiseDegree(double** matrix, double** result, int N, int degree)		//возведение матрицы в степень для двумерного массива
{
	// Инициализация result как единичной матрицы
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			result[i][j] = (i == j) ? 1.0 : 0.0;
		}
	}

	// Временная матрица для хранения промежуточных результатов
	double** temp = new double* [N];
	for (int i = 0; i < N; i++) 
	{
		temp[i] = new double[N];
	}

	// Возведение матрицы в степень
	for (int d = 1; d <= degree; d++) 
	{
		// Обнуляем temp
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++) 
			{
				temp[i][j] = 0.0;
			}
		}

		// Умножение матриц: temp = result * matrix
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++) 
			{
				for (int k = 0; k < N; k++) 
				{
					temp[i][j] += result[i][k] * matrix[k][j];
				}
			}
		}

		// Копируем temp в result
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++) 
			{
				result[i][j] = temp[i][j];
			}
		}
	}

	// Освобождаем память
	for (int i = 0; i < N; i++) 
	{
		delete[] temp[i];
	}
	delete[] temp;
}