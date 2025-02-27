#include "Header2.2b.h"

int index(int i, int j, int N) // ������� ��� ����������� ������ �������� [i][j] � ���������� �������
{
	return (i * N + j);
}

void FillMatrixConstants(int* matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[index(i, j, N)] = 1;
		}
	}
}

void FillMatrixRandom(int* matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[index(i, j, N)] = rand() % 21 - 10;
		}
	}
}

void FillMatrixUser(int* matrix, int N)
{
	for (int i = 0; i < N; i++)				//������
	{
		for (int j = 0; j < N; j++)			//�������
		{
			std::cout << std::setw(5) << "a" << i + 1 << j + 1 << " ";
			std::cin >> matrix[index(i, j, N)];
		}
		std::cout << std::endl;
	}
}

void OutputMatrix(int* matrix, int N)
{
	for (int i = 0; i < N; i++)				//������
	{
		for (int j = 0; j < N; j++)			//�������
		{
			std::cout << std::setw(5) << matrix[index(i, j, N)];
		}
		std::cout << std::endl;
	}
}