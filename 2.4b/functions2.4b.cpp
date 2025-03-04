#include "Header2.4b.h"

void Add(Node*& top, char symbol)
{
    Node* nv = new Node;  // образуем новый элемент списка 
    nv->s = symbol;
    nv->link = nullptr;
    if (!top)   // если список пуст
    {
        top = nv;   // первый элемент списка
        return;
    }
    else
    {
        // вставляем в начало списка 
        nv->link = top;
        top = nv;
    }
}

void Output(Node * top)
{
    while (top)
    {
        std::cout << top->s << ' ';
        top = top->link;
    }
    std::cout << "\n";
}