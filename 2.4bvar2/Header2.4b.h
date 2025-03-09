#pragma once
#include <stdio.h>
#include <iostream>
#include <iomanip>

struct MyPayload
{
    char symbol;
};

// один элемент списка
struct Node
{
    MyPayload payload; // полезная нагрузка
    Node* pNext;       //указатель на следующий элемент списка
};

struct MyList
{
    Node* pHead;    // указатель на первый элемент списка
    int nNodesCnt;  // общее количество элементов
};

void Create(MyList& list);
void Delete(MyList& list);
void Print(const MyPayload& item);
void Print(const MyList& list);
Node* FindElement(MyList& list, char s);
void DeleteElement(MyList& list, char s);
void AddElement(MyList& list, char s);
void FillResultList(MyList& list1, MyList& list2, MyList& list);