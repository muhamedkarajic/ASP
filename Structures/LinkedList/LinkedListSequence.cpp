#pragma once

#include "List.h"

template <class Type>
class LinkedListSequence : public List<Type>
{
private:
    Type *array;
    int counter;
    int max;
    void expandList()
    {
        int newMax = max * 2;
        Type *newArray = new Type[newMax];
        for (int i = 0; i < max; i++)
            newArray[i] = array[i];
        delete[] array;
        array = newArray;
        max = newMax;
    }

public:
    LinkedListSequence(int max = 10)
    {
        this->max = max;
        array = new Type[max];
        counter = 0;
    }

    LinkedListSequence(Type *array, int size, int max = 10) : LinkedListSequence(max)
    {
        for (int i = 0; i < size; i++)
            add(array[i]);
    }

    LinkedListSequence(List<Type> *list, int max = 10) : LinkedListSequence(max)
    {
        for (int i = 0; i < list->count(); i++)
        {
            add(list->get(i));
        }
    }

    LinkedListSequence(List<Type> &list, int max = 10) : LinkedListSequence(&list, max)
    {
    }

    void add(Type v)
    {
        if (max == counter)
            expandList();

        array[counter] = v;
        counter++;
    }

    Type remove()
    {
        if (isEmpty())
            throw exception("Error. It's not possible to remove a element from an empty array.");

        counter--;
        Type t = array[counter];
        return t;
    }

    bool isEmpty()
    {
        return (counter == 0);
    }

    int count()
    {
        return counter;
    }

    void print(string pre = "", string post = ", ")
    {
        int i = 0;
        while (i < counter)
            cout << pre << array[i++] << post;
        cout << endl;
    }

    Type &get(int i)
    {
        if (i > counter)
            throw exception("Index is bigger then the size.");

        return array[i];
    }

    Type &operator[](int i)
    {
        return get(i);
    }

    void set(int i, Type v)
    {
        get(i) = v;
    }

    bool contains(Type v)
    {
        for (int i = 0; i < counter; i++)
            if (array[i] == v)
                return true;
        return false;
    }

    Type *getArray()
    {
        return array;
    }

    Type *formatArray()
    {
        Type *array = new Type[this->counter];

        for (int i = 0; i < this->counter; i++)
            array[i] = this->array[i];

        return array;
    }
};
