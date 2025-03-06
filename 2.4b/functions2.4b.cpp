#include "Header2.4b.h"

void Add(Node*& pHead, char symbol)
{
    Node* NewEl = new Node;  // �������� ����� ������� ������ 
    NewEl->s = symbol;
    NewEl->link = nullptr;
    if (!pHead)   // ���� ������ ����
    {
        pHead = NewEl;   // ������ ������� ������
        return;
    }
    else
    {
        // ��������� � ������ ������ 
        NewEl->link = pHead;
        pHead = NewEl;
    }
}

bool FindSymbol(Node* pHead, char symbol, Node*& pPrevEl)
{
    Node* pCurrentEl = pHead;
    pPrevEl = pHead;
    //����� �������� c �������� = symbol 
    while (pCurrentEl && pCurrentEl->s != symbol)
    {
        pPrevEl = pCurrentEl;
        pCurrentEl = pCurrentEl->link;
    }
    // ���������� ����� ����������� �������� 
    if (pCurrentEl == nullptr) // ��� ������ return pv != nullptr; 
        return false;
    return true;
}

void Delete(Node*& pHead, char symbol)
{
    Node* pCurrentEl, *pPrevEl;
    // ����� �������� � ������ = key 
    if (!FindSymbol(pHead, symbol, pPrevEl)) // ���� �� ����� 
        return;
    if (pPrevEl == pHead) // ������� ������ ������� 
    {
        pCurrentEl = pHead;   
        pHead = pHead->link;
    }
    else  // ������� ������� �� �������� ��� ����� ������ 
    {
        pCurrentEl = pPrevEl->link;
        pPrevEl->link = pCurrentEl->link;
    }
    delete pCurrentEl;           // ������������ ������ 
}

void Output(Node* pHead)
{
    while (pHead)
    {
        std::cout << pHead->s << ' ';
        pHead = pHead->link;
    }
    std::cout << "\n";
}

void FillList(Node* pHead1, Node* pHead2, Node* pResult)
{
    Node *pPrevEl;

    while (pHead1)
    {
        if (FindSymbol(pHead2, pHead1->s, pPrevEl))
        {
            if (!FindSymbol(pResult, pHead1->s, pPrevEl))
            {
                Add(pResult, pHead1->s);
            }
        }
        pHead1 = pHead1->link;
    }
}