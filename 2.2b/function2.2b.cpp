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
			matrix[index(i, j, N)] = (j+1);
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

void RaiseDegree(double* matrix, double* result, int N, int degree)
{
	double* pResultTemp = new double[N * N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			pResultTemp[index(i, j, N)] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		pResultTemp[index(i, i, N)] = 1;
	}

	for (int d = 1; d <= degree; d++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; ++k) {
					result[index(i, j, N)] += pResultTemp[index(i, k, N)] * matrix[index(k, j, N)];
				}
			}
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				pResultTemp[index(i, j, N)] = result[index(i, j, N)];
			}
		}
	}

	delete[] pResultTemp;
}

void RaiseDegree(double** matrix, double** result, int N, int degree)
{
	double** pResultTemp = new double* [N];
	for (int i = 0; i < N; i++)
		pResultTemp[i] = new double[N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			pResultTemp[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		pResultTemp[i][j] = 1;
	}

	for (int d = 1; d <= degree; d++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; ++k) {
					result[i][j] += pResultTemp[i][j] * matrix[i][j];
				}
			}
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				pResultTemp[i][j] = result[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
		delete[] pResultTemp[i];
	delete[] pResultTemp;
}