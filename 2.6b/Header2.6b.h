#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>		//функции rand srand
#include <time.h>		//для рандомного числа

struct MyPayload
{
    double number;
};

// один элемент списка
struct Node
{
    int count;
    MyPayload payload;  // полезная нагрузка
    Node* pNext;        //указатель на следующий элемент списка
    Node* pPrev;        //указатель на предыдущий элемент
};

struct MyList
{
    Node* pHead;    // указатель на первый элемент списка
    
    Node* pTail;    //указатель на последний элемент списка
    int nNodesCnt = 0;  // общее количество элементов
};

void Create(MyList& list);
void Delete(MyList& list);
void AddElement(MyList& list, double num);
void Print(const MyPayload& item);
void Print(const MyList& list);
Node* FindElement(MyList& list, double num);
void DeleteElement(MyList& list, double number);
double CalculateExpression(MyList& list, int n);