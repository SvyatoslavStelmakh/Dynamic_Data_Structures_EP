#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>		//������� rand srand
#include <time.h>		//��� ���������� �����

struct MyPayload
{
    double number;
};

// ���� ������� ������
struct Node
{
    int count;
    MyPayload payload;  // �������� ��������
    Node* pNext;        //��������� �� ��������� ������� ������
    Node* pPrev;        //��������� �� ���������� �������
};

struct MyList
{
    Node* pHead;    // ��������� �� ������ ������� ������
    
    Node* pTail;    //��������� �� ��������� ������� ������
    int nNodesCnt = 0;  // ����� ���������� ���������
};

void Create(MyList& list);
void Delete(MyList& list);
void AddElement(MyList& list, double num);
void Print(const MyPayload& item);
void Print(const MyList& list);
Node* FindElement(MyList& list, double num);
void DeleteElement(MyList& list, double number);
double CalculateExpression(MyList& list, int n);