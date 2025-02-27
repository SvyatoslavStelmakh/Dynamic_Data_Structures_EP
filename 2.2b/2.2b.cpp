#include "Header2.2b.h"

int main()
{
	int N = 0;
	short choice = 0;
	std::cout << "Enter the order of the matrix: ";
	std::cin >> N;

	int* pMatrix = new int[N * N];
	int* pResult = new int[N * N];

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
			FillMatrixConstants(pMatrix, N);
			break;
		}
		case WithRand:
		{
			FillMatrixRandom(pMatrix, N);
			break;
		}
		case ByUser:
		{
			FillMatrixUser(pMatrix, N);
			break;
		}
		default:
		{
			std::cout << "invalid value entered, try again" << std::endl;
			goto menu;
		}
	}

	OutputMatrix(pMatrix, N);

	int degree = 0;
	std::cout << "Enter degree: ";
	std::cin >> degree;

	for (int i = 1; i <= degree; i++)
	{

	}
		

	delete[] pMatrix;
}