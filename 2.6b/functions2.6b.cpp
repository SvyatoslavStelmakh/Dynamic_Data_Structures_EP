#include "Header2.6b.h"

void Create(MyList& list)
{
    Node* pFirstEl = new Node;      //��� �������� ������ �� ��������� ������ ������ ������� � ������ payload
    pFirstEl->pNext = nullptr;
    pFirstEl->pPrev = nullptr;
    pFirstEl->count = 0;
    list.pHead = pFirstEl;
    list.pTail = pFirstEl;
}

void Delete(MyList& list)       //������� ��� �������� ������
{
    Node* pTemp = nullptr;
    while (list.pHead)
    {
        pTemp = list.pHead;
        list.pHead = pTemp->pNext;
        delete pTemp;
    }

}

void AddElement(MyList& list, double num)
{
    Node* NewEl = new Node;         // �������� ����� ������� ������
    NewEl->payload.number = num;
    NewEl->pNext = nullptr;
    list.nNodesCnt++;
    NewEl->count = list.nNodesCnt;      //�������� ��������, ������� ��������� � ������
    
    list.pTail->pNext = NewEl;      //��������� ������� � ����� ������
    NewEl->pPrev = list.pTail;      //����������� ������� ��������� �� ������� �������
    list.pTail = NewEl;             //��������� ��������� �� ��������� ������� ������

}

void Print(const MyPayload& item)
{
    std::cout << item.number;
}

void Print(const MyList& list)
{
    for (Node* p = list.pHead; p != nullptr; p = p->pNext)
    {
        Print(p->payload);
    }
    std::cout << "\n";
}

Node* FindElement(MyList& list, double num)
{
    Node* pCurrentEl = list.pHead;
    while (pCurrentEl->pNext)                           //���� ����� �����������, ���� ���� pNext �������� ���� �� ����� nullptr
    {                                                   //�� ���� ���� ����� �� �����������, ����� ������� ������ ��������� � ��������� ���� ������
        if (pCurrentEl->payload.number == num)          //�� ���� ����� �������� �������������� ��������
        {
            return pCurrentEl;
        }
        
        pCurrentEl = pCurrentEl->pNext;
    }

    if (pCurrentEl->payload.number == num)
    {
        return pCurrentEl;
    }

    return nullptr;
}

void DeleteElement(MyList& list, double number)
{
    Node* pDesiredEl = FindElement(list, number);

    if (!pDesiredEl)
    {
        std::cout << "Symbol wasn't found in the list.\n";
        return;
    }

    Node* pNextEl = pDesiredEl->pNext;      //������ ��������� �� �������, �������� �� ���������
    Node* pPrevEl = pDesiredEl->pPrev;      //������ ��������� �� �������, ������� ��������� ����� ���������
    pNextEl->pPrev = pPrevEl;
    pPrevEl->pNext = pNextEl;
    delete pDesiredEl;
}

double CalculateExpression(MyList& list, int n)
{
    double result = 1;
    Node* pFirst = list.pHead->pNext;   //��������� �� ������ ������
    Node* pLast = list.pTail;           //��������� �� ����� ������

    while (true)
    {
        
        result *= pFirst->payload.number - pLast->payload.number;

        if (pFirst->count == n)
            break;

        pFirst = pFirst->pNext;
        pLast = pLast->pPrev;
       

    }

    return result;
}