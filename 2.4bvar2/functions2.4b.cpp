#include "Header2.4b.h"

void Create(MyList& list)
{
    Node* pFirstEl = new Node;      //��� �������� ������ �� ��������� ������ ������ ������� � ������ payload
    pFirstEl->pNext = nullptr;      
    list.pHead = pFirstEl;
    list.nNodesCnt++;
}

void Delete(MyList& list)
{
    Node* pTemp = nullptr;
    while (list.pHead)
    {
        pTemp = list.pHead;
        list.pHead = pTemp->pNext;
        delete pTemp;
    }

}

void Print(const MyPayload& item)
{
    std::cout << item.symbol;
}

void Print(const MyList& list)
{
    for (Node* p = list.pHead; p != nullptr; p = p->pNext)
    {
        Print(p->payload);
    }
    std::cout << "\n";
}

Node* FindElement(MyList& list, char s)
{
    Node* pCurrentEl = list.pHead;
    Node* pPrevEl = nullptr;
    while (pCurrentEl->pNext)                       //���� ����� �����������, ���� ���� pNext �������� ���� �� ����� nullptr
    {                                               //�� ���� ������� �������� �����������, ����� ������� ������ ��������� � ��������� ���� ������
        if (pCurrentEl->payload.symbol == s)        //�� ���� ����� �������� �������������� ��������
        {
            return pPrevEl;
        }
        pPrevEl = pCurrentEl;
        pCurrentEl = pCurrentEl->pNext;
    }

    if (pCurrentEl->payload.symbol == s)
    {
        return pPrevEl;
    }

    return nullptr;
}

void DeleteElement(MyList& list, char s)
{
    Node* pPrevEl = FindElement(list, s);

    if (!pPrevEl)
    {
        std::cout << "Symbol wasn't found in the list.\n";
        return;
    }

    Node* pNextEl = pPrevEl->pNext->pNext;
    delete pPrevEl->pNext;
    pPrevEl->pNext = pNextEl;
}

void AddElement(MyList& list, char s)
{
    Node* NewEl = new Node;         // �������� ����� ������� ������
    NewEl->payload.symbol = s;
    NewEl->pNext = nullptr;
    
    Node* pCurrentEl = list.pHead;
    while (pCurrentEl->pNext)       //������� ��������� ������� ������
    {
        pCurrentEl = pCurrentEl->pNext;
    }
    pCurrentEl->pNext = NewEl;      //��������� ������� � ����� ������
    list.nNodesCnt++;
}

void FillResultList(MyList& list1, MyList& list2, MyList& list)
{
    Node* pCurrentEl = list1.pHead;
    Node* pTemp = nullptr;
    Node* pPrevEl = nullptr;
    while (pCurrentEl->pNext)       //����, ������� ���������� ��� �������� ������� ������
    {
        pPrevEl = FindElement(list2, pCurrentEl->payload.symbol);        //������� ��������� �� ������� ������� ������, ������� ��������� ����� ���������, � ������� ��������� ������� ������
        if (pPrevEl)        //������� �����������, ���� ������� ������ ��� ������
        {  
           pPrevEl = FindElement(list, pCurrentEl->payload.symbol);

           if(!pPrevEl)
               AddElement(list, pCurrentEl->payload.symbol);
        }
       
        pCurrentEl = pCurrentEl->pNext;
    }
        
    
    
    pPrevEl = FindElement(list2, pCurrentEl->payload.symbol);

    if (pPrevEl)
    {
        pPrevEl = FindElement(list, pCurrentEl->payload.symbol);

        if (!pPrevEl)
            AddElement(list, pCurrentEl->payload.symbol);
        
    }
}


