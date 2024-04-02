#pragma once
#include "priNode.h"
#include "Queue/QueueADT.h"

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
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    void print() const
    {
        priNode<T>* temp = head;
        if (!count)
        {
            cout << "NO ELEMENTS !" << endl;
            return;
        }
        while (temp != nullptr)
        {
            int temporary = temp->getPri();
            cout << temp->getItem(temporary) << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
};