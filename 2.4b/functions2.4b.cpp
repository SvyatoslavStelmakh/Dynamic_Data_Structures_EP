#include "Header2.4b.h"

void FreeList(Node*& pHead)
{
    while (pHead->next != nullptr) 
    {
        Node* temp = pHead;
        pHead = pHead->next;
        delete temp;
    }
}

void Add(Node*& pHead, char symbol)
{
    Node* NewEl = new Node;  // �������� ����� ������� ������ 
    NewEl->s = symbol;
    NewEl->next = pHead;
    pHead = NewEl;
}

bool FindSymbol(Node* pHead, char symbol)
{
    while (pHead->next != nullptr) 
    {
        if (pHead->s == symbol) 
        { // ���� ������ ������� ������, ���������� true
            return true;
        }
        pHead = pHead->next;
    }
    return false;
}

void Output(Node*& pHead)
{
    while (pHead)
    {
        std::cout << pHead->s << ' ';
        pHead = pHead->next;
    }
    std::cout << "\n";
}

void FillList(Node* pHead1, Node* pHead2, Node* pResult)
{
    while (pHead1)
    {
        if (FindSymbol(pHead2, pHead1->s))
        {
            if (!FindSymbol(pResult, pHead1->s))
            {
                Add(pResult, pHead1->s);
            }
        }
        pHead1 = pHead1->next;
    }
}

//bool FindSymbol(Node* pHead, char symbol, Node*& pPrevEl)
//{
//    Node* pCurrentEl = pHead;
//    pPrevEl = pHead;
//    //����� �������� c �������� = symbol 
//    while (pCurrentEl && pCurrentEl->s != symbol)
//    {
//        pPrevEl = pCurrentEl;
//        pCurrentEl = pCurrentEl->next;
//    }
//    // ���������� ����� ����������� �������� 
//    if (pCurrentEl == nullptr) // ��� ������ return pv != nullptr; 
//        return false;
//    return true;
//}

//void Delete(Node*& pHead, char symbol)
//{
//    Node* pCurrentEl;
//    Node* pPrevEl;
//    //����� �������� c �������� = symbol
//    if (!FindSymbol(pHead, symbol, pPrevEl)) // ���� �� ����� 
//        return;
//    if (pPrevEl == pHead) // ������� ������ ������� 
//    {
//        pCurrentEl = pHead;
//        pHead = pHead->next;
//    }
//    else  // ������� ������� �� �������� ��� ����� ������ 
//    {
//        pCurrentEl = pPrevEl->next;
//        pPrevEl->next = pCurrentEl->next;
//    }
//    delete pCurrentEl;           // ������������ ������ 
//}