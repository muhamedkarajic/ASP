#pragma once

#include "List.h"
#include "Node.h"

template <class Type>
class LinkedListSingly : public List<Type>
{
  private:
    int counter;
    Node<Type>* node;

  public:
    LinkedListSingly()
    {
        counter = 0;
        node = nullptr;
    }

    LinkedListSingly(Type *array, int size) : LinkedListSingly()
    {
        for (int i = 0; i < size; i++)
            add(array[i]);
    }

    LinkedListSingly(List<Type> *list) : LinkedListSingly()
    {
        for (int i = 0; i < list->count(); i++)
            add(list.get(i));
    }

    LinkedListSingly(List<Type> &list) : LinkedListSingly(&list) {}

    void add(Type v)
    {
        Node<Type> *t = new Node<Type>(v, node);
        node = t;
        counter++;
    }

    Type remove()
    {
        if (isEmpty())
            throw exception("Error. It's not possible to remove an element from an empty array.");

        counter--;
        Node<Type>* t = node;
        node = node->next;
        Type x = t->info;
        delete t;
        return x;
    }

    bool remove(Type tip)
    {
        Node<Type> *t = node;
        Node<Type> *pt = nullptr;

        while (t != nullptr)
        {
            if (tip == t->info)
                break;
            pt = t;
            t = t->next;
        }
        if (t == nullptr)
            return false;

        if (pt == nullptr)
            node = t->next;
        else
            pt->next = t->next;

        delete t;
        return true;
    }

    bool isEmpty()
    {
        return (node == nullptr);
    }

    int getCounter() const { return counter; }

    void print(string pre = "", string post = ", ")
    {
        Node<Type> *t = node;
        while (t != nullptr)
        {
            cout << pre << t->info << post;
            t = t->next;
        }
        cout << endl;
    }

    Type &get(int i)
    {
        if (i > counter)
            throw exception("Index is bigger then counter.");

        Node<Type> *t = node;
        for (int j = 0; j < (counter - i - 1); j++)
            t = t->next;
            
        return t->info;
    }

    Type &operator[](int i)
    {
        return get(i);
    }

    void set(int i, Type value)
    {
        get(i) = value;
    }

    bool contains(Type value)
    {
        Node<Type> *t = node;
        while (t != nullptr)
        {
            if (t->info == value)
                return true;
            t = t->next;
        }
        return false;
    }

    Type *formatArray()
    {
        Type *array = new Type[this->counter];

        int b = 0;
        Node<Type> *t = node;
        while (t != nullptr)
        {
            array[b++] = t->info;
            t = t->next;
        }
        return array;
    }
};
