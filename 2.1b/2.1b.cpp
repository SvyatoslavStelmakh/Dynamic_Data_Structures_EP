#include <iostream>
#include <stdlib.h>		
#include <time.h>		

int main()
{
	long long size = 0;
	const int size2 = 10000001;
	std::cout << "Enter size of the array: ";
	std::cin >> size;
	int* pArray = new int[size];
	int* pAmount = new int[size2];
	int* pResult = new int[size];

	std::cout << "Enter the way to initialize array:" << std::endl;
	std::cout << "1. with random numbers" << std::endl;
	std::cout << "2. by user" << std::endl;
	std::cout << "3. test variant" << std::endl;

	short choice;
	std::cin >> choice;
	srand(time(NULL));
menu:
	switch (choice)
	{
		case 1:
		{
			for (long long i = 0; i < size; i++)
			{
				pArray[i] = rand() % 10000000 + 1;
			}
			break;
		}
		case 2:
		{
			for (long long i = 0; i < size; i++)
			{
				std::cin >> pArray[i];
			}
			break;
		}
		case 3:
		{
			for (long long i = 0; i < size; i++)
			{
				pArray[i] = static_cast<int>(10e7);
			}
			break;
		}
		default:
		{
			std::cout << "invalid value entered, try again" << std::endl;
			goto menu;
		}
	}
	//вывод исходного массива
	/*std::cout << "Original array" << std::endl;
	for (long long i = 0; i < size; i++)
	{
		std::cout << pArray[i] << " ";
	}
	std::cout << std::endl;*/
	
	//обнуляем массив, в котором будем хранить количество чисел
	for (int i = 0; i < size2; i++)
	{
		pAmount[i] = 0;
	}

	//отмечаем количество вхождений каждого числа в исходном массиве
	//каждыый индекс массива Amount соответствует числу исходного массива, элемент массива Amount хранит количество вхождений числа равного индексу
	for (long long i = 0; i < size; i++)
	{
		pAmount[pArray[i]]++;
	}

	for (long long i = 0; i < size; i++)
	{
		pResult[i] = 0;
	}
	int index = 0;
	for (int i = 0; i < size2; i++)
	{
		if (pAmount[i] > 1)
		{
			pResult[index] = i;
			index++;
		}
	}

	std::cout << "Result array" << std::endl;
	for (int i = 0; i < index; i++)
	{
		std::cout << pResult[i] << " ";
	}
		
	delete[] pAmount;
	delete[] pResult;
	delete[] pArray;
}


/*long long first_j = 1;
bool is_unique = 1;

for (long long i = 0; i < size - 1; i++)
{
	is_unique = 1;
	for (long long j = first_j; j < size; j++)
	{
		if (pArray[i] == pArray[j])
		{
			for (long long k = 0; k <= index; k++)
			{
				if (pArray[i] == pResult[k])
				{
					is_unique = 0;
					break;
				}
			}
			if (is_unique)
			{
				pResult[index] = pArray[i];
				index++;
				break;
			}

		}
	}
	first_j++;
}
*/