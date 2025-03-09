#pragma once
#include <stdio.h>
#include <iostream>
#include <iomanip>

struct Node
{
    char s;
    Node* next;
};

void FreeList(Node*& pHead);
void Add(Node*& pHead, char symbol);
bool FindSymbol(Node* pHead, char symbol);
//bool FindSymbol(Node* pHead, char symbol, Node*& pPrevEl);
//void Delete(Node*& pHead, char symbol);
void Output(Node*& pHead);
void FillList(Node* pHead1, Node* pHead2, Node* pResult);