#include "Header2.6b.h"

void Create(MyList& list)
{
    Node* pFirstEl = new Node;      //при создании списка по умолчанию создаЄм первый элемент с пустым payload
    pFirstEl->pNext = nullptr;
    pFirstEl->pPrev = nullptr;
    pFirstEl->count = 0;
    list.pHead = pFirstEl;
    list.pTail = pFirstEl;
}

void Delete(MyList& list)       //функци€ дл€ очищени€ списка
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
    Node* NewEl = new Node;         // образуем новый элемент списка
    NewEl->payload.number = num;
    NewEl->pNext = nullptr;
    list.nNodesCnt++;
    NewEl->count = list.nNodesCnt;      //нумеруем элементы, которые добавл€ем в список
    
    list.pTail->pNext = NewEl;      //добавл€ем элемент в конец списка
    NewEl->pPrev = list.pTail;      //добавленный элемент указывает на прошлый элемент
    list.pTail = NewEl;             //сохран€ем указатель на последний элемент списка

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
    while (pCurrentEl->pNext)                           //цикл будет выполн€тьс€, пока поле pNext текущего узла не равно nullptr
    {                                                   //то есть тело цикла не выполн€етс€, когда искомый символ находитс€ в последнем узле списка
        if (pCurrentEl->payload.number == num)          //то есть нужно добавить дополнительную проверку
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

    Node* pNextEl = pDesiredEl->pNext;      //создаю указатель на элемент, следющий за удал€емым
    Node* pPrevEl = pDesiredEl->pPrev;      //создаю указатель на элемент, который находитс€ перед удал€емым
    pNextEl->pPrev = pPrevEl;
    pPrevEl->pNext = pNextEl;
    delete pDesiredEl;
}

double CalculateExpression(MyList& list, int n)
{
    double result = 1;
    Node* pFirst = list.pHead->pNext;   //указатель на начало списка
    Node* pLast = list.pTail;           //указатель на конец списка

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