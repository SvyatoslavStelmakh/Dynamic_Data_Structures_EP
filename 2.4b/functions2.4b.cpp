#include "Header2.4b.h"

void Add(Node*& pHead, char symbol)
{
    Node* NewEl = new Node;  // образуем новый элемент списка 
    NewEl->s = symbol;
    NewEl->link = nullptr;
    if (!pHead)   // если список пуст
    {
        pHead = NewEl;   // первый элемент списка
        return;
    }
    else
    {
        // вставляем в начало списка 
        NewEl->link = pHead;
        pHead = NewEl;
    }
}

bool FindSymbol(Node* pHead, char symbol, Node*& pPrevEl)
{
    Node* pCurrentEl = pHead;
    pPrevEl = pHead;
    //поиск элемента c символом = symbol 
    while (pCurrentEl && pCurrentEl->s != symbol)
    {
        pPrevEl = pCurrentEl;
        pCurrentEl = pCurrentEl->link;
    }
    // запоминаем адрес предыдущего элемента 
    if (pCurrentEl == nullptr) // или просто return pv != nullptr; 
        return false;
    return true;
}

void Delete(Node*& pHead, char symbol)
{
    Node* pCurrentEl, *pPrevEl;
    // поиск элемента с ключом = key 
    if (!FindSymbol(pHead, symbol, pPrevEl)) // если не нашли 
        return;
    if (pPrevEl == pHead) // удаляем первый элемент 
    {
        pCurrentEl = pHead;   
        pHead = pHead->link;
    }
    else  // удаляем элемент из середины или конца списка 
    {
        pCurrentEl = pPrevEl->link;
        pPrevEl->link = pCurrentEl->link;
    }
    delete pCurrentEl;           // освобождение памяти 
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