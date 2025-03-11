#include "Header2.6b.h"

int main()
{
	int n = 0;
	double number = 0;
	short choice;
	std::cout << "Enter n = ";
	std::cin >> n;

	MyList list;
	Create(list);
	
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
			for (int i = 1; i <= 2 * n; i++)
			{
				AddElement(list, i);
			}

			break;
		}
		case WithRand:
		{
			srand(time(NULL));
			for (int i = 1; i <= 2 * n; i++)
			{
				number = rand() % 11;
				AddElement(list, number);
			}
			break;
		}
		case ByUser:
		{
			for (int i = 1; i <= 2 * n; i++)
			{
				std::cout << "a" << i << " ";
				std::cin >> number;
				AddElement(list, number);
			}
			break;
		}
		default:
		{
			std::cout << "invalid value entered, try again" << std::endl;
			goto menu;
		}
	}

	std::cout << "List: ";
	Print(list);

	std::cout << "Expression value: " << CalculateExpression(list, n);
		
	Delete(list);
	
}

