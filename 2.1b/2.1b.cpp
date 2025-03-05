#include <iostream>
#include <stdlib.h>		
#include <time.h>		

int main()
{
	long long size = 0;
	const int size2 = 10000001;
	int number = 0;
	std::cout << "Enter size of the array: ";
	std::cin >> size;
	
	int* pAmount = new int[size2];
	int* pResult = new int[size2];

	//обнуляем массив, в котором будем хранить количество чисел
	for (int i = 0; i < size2; i++)
	{
		pAmount[i] = 0;
	}
	//обнуляем результирующий массив
	for (long long i = 0; i < size2; i++)
	{
		pResult[i] = 0;
	}

	std::cout << "Enter the way to initialize array:" << std::endl;
	std::cout << "1. with random numbers" << std::endl;
	std::cout << "2. by user" << std::endl;
	std::cout << "3. test variant" << std::endl;

	short choice;
	std::cin >> choice;
	srand(time(NULL));
	//отмечаем количество вхождений каждого числа в исходном массиве
	//каждыый индекс массива Amount соответствует числу исходного массива, элемент массива Amount хранит количество вхождений числа равного индексу

	std::cout << "Array:" << std::endl;
menu:
	switch (choice)
	{
		case 1:
		{
			for (long long i = 0; i < size; i++)
			{
				number = rand() % 10000000 + 1;
				std::cout << number << " ";
				pAmount[number]++;
			}
			break;
		}
		case 2:
		{
			for (long long i = 0; i < size; i++)
			{
				std::cin >> number;

				pAmount[number]++;
			}
			break;
		}
		case 3:
		{
			for (long long i = 0; i < size; i++)
			{
				number = 10000000;
				std::cout << number << " ";
				if (pAmount[number] > 1)
				{
					continue;
				}
				pAmount[number]++;
			}
			break;
		}
		default:
		{
			std::cout << "invalid value entered, try again" << std::endl;
			goto menu;
		}
	}
	std::cout << std::endl;
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