#pragma once

#include "Queue.h"

template <class Type>
class QueueLinked : public Queue<Type>
{
private:
    Node<Type> *begin;
    Node<Type> *end;

public:
    QueueLinked()
    {
        begin = nullptr;
        end = nullptr;
    }
    void add(Type v)
    {
        Node<Type> *t = new Node<Type>(v, nullptr);
        if (!isEmpty())
        {
            end->next = t;
            end = t;
        }
        else
        {
            end = t;
            begin = t;
        }
    }

    Type remove()
    {
        if (isEmpty())
            throw exception("Error. It's not possible to remove an element from an empty array.");

        Node<Type> *t = begin;
        begin = begin->next;

        Type x = t->info;
        delete t;

        if (begin == nullptr)
            end = nullptr;

        return x;
    }

    bool isEmpty()
    {
        return begin == nullptr;
    }

    void print(string pre = "", string post = ", ")
    {
        Node<Type> *t = begin;
        while (t != nullptr)
        {
            cout << pre << t->info << post;
            t = t->next;
        }
    }

    bool contains(Type v)
    {
        Node<Type> *t = begin;
        while (t != nullptr)
        {
            if (isEqual(t->info, v))
                return true;
            t = t->next;
        }
        return false;
    }
};
