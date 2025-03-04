#include "Header2.4b.h"

void Add(Node*& top, char symbol)
{
    Node* nv = new Node;  // �������� ����� ������� ������ 
    nv->s = symbol;
    nv->link = nullptr;
    if (!top)   // ���� ������ ����
    {
        top = nv;   // ������ ������� ������
        return;
    }
    else
    {
        // ��������� � ������ ������ 
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