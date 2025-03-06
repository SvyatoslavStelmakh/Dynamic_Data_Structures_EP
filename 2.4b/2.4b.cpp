#include "Header2.4b.h"

int main()
{
	Node* pHead1 = nullptr;
	Node* pHead2 = nullptr;
	Node* pResult = nullptr;

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
		Add(pHead1, str1[i]);
	}

	for (int i = 0; i < len2; i++)
	{
		Add(pHead2, str2[i]);
	}

	Output(pHead1);
	Output(pHead2);

	FillList(pHead1, pHead2, pResult);

	Output(pResult);
}