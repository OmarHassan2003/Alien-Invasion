#pragma once
#include "../priNode.h"
#include "../Queue/QueueADT.h"
#include <iostream>

using namespace std;
//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
    priNode<T>* head;
    unsigned long int count;
public:
    priQueue()
    {
        head = NULL;
        count = 0;
    }

    ~priQueue()
    {
        T tmp;
        int p;
        while (dequeue(tmp, p));
    }

    //insert the new node in its correct position according to its priority
    virtual bool enqueue(const T& data, int priority)
    {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri())
        {

            newNode->setNext(head);
            head = newNode;
            count++;
            return true;
        }

        priNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri())
        {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        count++;
        return true;
    }

    bool dequeue(T& topEntry, int& pri)
    {
        if (!count)
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        count--;
        return true;
    }

    bool peek(T& topEntry, int& pri)
    {
        if (!count)
            return false;

        topEntry = head->getItem(pri);
        return true;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    void print() const
    {
        int x;
        priNode<T>* temp = head;
        cout << "[";
        if (!count)
        {
            cout << "]";
            return;
        }
        while (temp != nullptr)
        {
            if (!temp->getNext()) cout << temp->getItem(x);
            else 
            {
                cout << temp->getItem(x) << " ,";
            }
            temp = temp->getNext();
        }
        cout << "]";
    }

    int GetCount() const
    {
        return count;
    }
};
