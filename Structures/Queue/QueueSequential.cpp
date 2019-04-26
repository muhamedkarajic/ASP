#pragma once

#include "Red.h"

template <class Type>
class QueueSequential : public Queue<Type>
{
private:
    int max;
    int counter;
    int end;
    int begin;
    Type *array;
    void expandQueue()
    {
        int newMax = max * 2;
        Type *newArray = new Type[newMax];
        int newI = 0;
        int oldI = begin;
        while (newI < counter)
        {
            newArray[newI++] = array[oldI++];
            if (oldI == max)
                oldI = 0;
        }
        max = newMax;
        delete[] array;
        array = newArray;
        begin = 0;
        end = counter;
    }

public:
    QueueSequential(int max = 10)
    {
        this->max = max;
        counter = 0;
        end = 0;
        begin = 0;
        array = new Type[max];
    }
    void add(Type value)
    {
        if (counter == max)
            expandQueue();

        array[end] = value;
        end++;
        if (end == max)
            end = 0;

        counter++;
    }

    Type remove()
    {
        if (isEmpty())
            throw exception("Error. It's not possible to erase an element from an empty array.");

        Type x = array[begin];
        begin++;
        if (begin == max)
            begin = 0;

        counter--;
        return x;
    }

    bool isEmpty()
    {
        return counter == 0;
    }

    void print(string pre = "", string post = ", ")
    {
        int i = begin;
        int c = 0;
        while (c++ < counter)
        {
            cout << pre << array[i++] << post;
            if (i == max)
                i = 0;
        }
    }

    bool contains(Type value)
    {
        for (int i = 0; i < counter; i++)
            if (isEqual(array[i], value))
                return true;
        return false;
    }
};
