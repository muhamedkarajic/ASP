#pragma once

#include <iostream>
using namespace std;

template <class Type>
struct Node
{
    Type info;
    Node *next;

    Node(Type info, Node<Type> *next) : info(info)
    {
        this->next = next;
    }
};
