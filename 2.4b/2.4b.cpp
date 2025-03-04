#include "Header2.4b.h"

int main()
{
	Node* top1 = nullptr;
	Node* top2 = nullptr;
	Node* result = nullptr;

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
		Add(top1, str1[i]);
	}

	for (int i = 0; i < len2; i++)
	{
		Add(top2, str2[i]);
	}

	Output(top1);
	Output(top2);

	
}