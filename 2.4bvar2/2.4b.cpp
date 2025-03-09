#include "Header2.4b.h"

int main()
{
	MyList L1, L2, L;

	Create(L1);
	Create(L2);
	Create(L);

	const int MAX = 80;
	char str1[MAX] = { 0 };
	char str2[MAX] = { 0 };

	std::cout << "Enter first string : ";
	std::cin.getline(str1, MAX);

	std::cout << "Enter second string : ";
	std::cin.getline(str2, MAX);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	for (int i = 0; i < len1; i++)
	{
		AddElement(L1, str1[i]);
	}

	for (int i = 0; i < len2; i++)
	{
		AddElement(L2, str2[i]);
	}

	std::cout << "L1: ";
	Print(L1);
	std::cout << "L2: ";
	Print(L2);

	FillResultList(L1, L2, L);

	std::cout << "L: ";
	Print(L);

	Delete(L1);
	Delete(L2);
	Delete(L);
}