#include "Header2.2b.h"

int main()
{	
	int N = 0;
	short choice = 0;
	std::cout << "Enter the order of the matrix: ";
	std::cin >> N;

	double* pMatrix1 = new double[N * N];
	double* pResult1 = new double[N * N];
	double** pMatrix2 = new double* [N];
	for (int i = 0; i < N; i++)
		pMatrix2[i] = new double[N];
	double** pResult2 = new double* [N];
	for (int i = 0; i < N; i++)
		pResult2[i] = new double[N];
		
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			pResult1[index(i, j, N)] = 0;
		}
	}
	
	enum enmArrayInit { WithConst = 1, WithRand, ByUser, };		//перечисление для выбора способа инициализации массива

menu:
	std::cout << "Choose the way to initialize the matrix:" << std::endl;
	std::cout << WithConst << " the elements are initialized with prescribed constants" << std::endl;
	std::cout << WithRand << " the elements are initialized with random numbers" << std::endl;
	std::cout << ByUser << " the elements are initialized by the user" << std::endl;

	std::cin >> choice;

	switch (choice)				//выбор инициализации массива
	{
		case WithConst:
		{
			FillMatrixConstants(pMatrix1, N);
			break;
		}
		case WithRand:
		{
			FillMatrixRandom(pMatrix2, N);
			break;
		}
		case ByUser:
		{
			FillMatrixUser(pMatrix2, N);
			break;
		}
		default:
		{
			std::cout << "invalid value entered, try again" << std::endl;
			goto menu;
		}
	}

	OutputMatrix(pMatrix1, N);

	int degree = 0;
	std::cout << "Enter degree: ";
	std::cin >> degree;

	RaiseDegree(pMatrix1, pResult1, N, degree);
	OutputMatrix(pResult1, N);

	for (int i = 0; i < N; i++)
		delete[] pMatrix2[i];
	delete[] pMatrix2;
	for (int i = 0; i < N; i++)
		delete[] pResult2[i];
	delete[] pResult2;
	
	delete[] pMatrix1;
	delete[] pResult1;
}