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

	for (int i = 1; i <= 2 * n; i++)
	{
		std::cout << "a" << i << " ";
		std::cin >> number;
		AddElement(list, number);
	}

	std::cout << "List: ";
	Print(list);

	std::cout << "Expression value: " << CalculateExpression(list, n);
		
	Delete(list);
	
}

//menu:
//	std::cout << "Choose the way to initialize the list:" << std::endl;
//	std::cout << 1 << " the elements are initialized with prescribed constants" << std::endl;
//	std::cout << 2 << " the elements are initialized with random numbers" << std::endl;
//	std::cout << 3 << " the elements are initialized by the user" << std::endl;
//
//	std::cin >> choice;
//
//	switch (choice)				//выбор инициализации массива
//	{
//		case 1:
//		{
//			for (int i = 1; i <= 2 * n; i++)
//			{
//				AddElement(list, i);
//			}
//		
//			break;
//		}
//		case 2:
//		{
//			for (int i = 1; i <= 2 * n; i++)
//			{
//				number = rand() % 11;
//				AddElement(list, number);
//			}
//			break;
//		}
//		case 3:
//		{
//			for (int i = 1; i <= 2 * n; i++)
//			{
//				std::cout << "a" << i << " ";
//				std::cin >> number;
//				AddElement(list, number);
//			}
//			break;
//		}
//		default:
//		{
//			std::cout << "invalid value entered, try again" << std::endl;
//			goto menu;
//		}
//	}