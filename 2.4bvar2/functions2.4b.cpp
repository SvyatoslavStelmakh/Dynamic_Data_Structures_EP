#include "Header2.4b.h"

void Create(MyList& list)
{
    Node* pFirstEl = new Node;      //при создании списка по умолчанию создаём первый элемент с пустым payload
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
    while (pCurrentEl->pNext)                       //цикл будет выполняться, пока поле pNext текущего узла не равно nullptr
    {                                               //то есть функция работает неправильно, когда искомый символ находится в последнем узле списка
        if (pCurrentEl->payload.symbol == s)        //то есть нужно добавить дополнительную проверку
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
    Node* NewEl = new Node;         // образуем новый элемент списка
    NewEl->payload.symbol = s;
    NewEl->pNext = nullptr;
    
    Node* pCurrentEl = list.pHead;
    while (pCurrentEl->pNext)       //находим последний элемент списка
    {
        pCurrentEl = pCurrentEl->pNext;
    }
    pCurrentEl->pNext = NewEl;      //добавляем элемент в конец списка
    list.nNodesCnt++;
}

void FillResultList(MyList& list1, MyList& list2, MyList& list)
{
    Node* pCurrentEl = list1.pHead;
    Node* pTemp = nullptr;
    Node* pPrevEl = nullptr;
    while (pCurrentEl->pNext)       //цикл, который перебирает все элементы первого списка
    {
        pPrevEl = FindElement(list2, pCurrentEl->payload.symbol);        //находим указатель на элемент второго списка, который находится перед элементом, в котором находится искомый символ
        if (pPrevEl)        //условие выполняется, если искомый символ был найден
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


