#pragma once
#include <stdio.h>
#include <iostream>
#include <iomanip>
struct Node
{
    char s;
    Node* link;
};

void Add(Node*& top, char symbol);
void Output(Node* top);