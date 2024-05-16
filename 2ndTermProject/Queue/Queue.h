#pragma once
#include "../Node.h"
#include "QueueADT.h"
/************************************Queue Implementation**************************************/
template <typename T>
class Queue :public QueueADT<T>
{
	Node<T>* Front;
	Node<T>* Rear;
	unsigned long int count;
public:
	Queue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& FrontEntry);
	bool peek(T& FrontEntry) const;
	int GetCount() const;
	void print() const;
	~Queue();
};

template<typename T>
Queue<T>::Queue()
{
	Front = nullptr;
	Rear = nullptr;
	count = 0;
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	return count == 0;
}

template<typename T>
bool Queue<T>::enqueue(const T& newEntry)
{
	Node<T>* New = new Node<T>(newEntry);
	if (!count)
		Front = New;
	else
		Rear->setNext(New);

	Rear = New;
	count++;
	return true;
}

template<typename T>
bool Queue<T>::dequeue(T& FrontEntry)
{
	if (!count)
		return false;

	Node<T>* Del = Front;
	FrontEntry = Front->getItem();
	Front = Front->getNext();
	if (Front == nullptr)
		Rear = nullptr;

	delete Del;
	count--;
	return true;
}

template<typename T>
bool Queue<T>::peek(T& FrontEntry) const
{
	if (!count)
	{
		FrontEntry = nullptr;
		return false;
	}
	else
	{
		FrontEntry = Front->getItem();
		return true;
	}
}

template<typename T>
void Queue<T>::print() const
{
	Node<T>* temp = Front;
	cout << "[";
	if (!count)
	{
		cout << "]";
		return;
	}
	while (temp != nullptr)
	{
		if (!temp->getNext()) cout << temp->getItem();
		else
		{
			cout << temp->getItem() << " ,";
		}
		temp = temp->getNext();
	}
	cout << "]";
}

template<typename T>
int Queue<T>::GetCount() const
{
	return count;
}

template<typename T>
Queue<T>::~Queue()
{
	T temp;
	while (dequeue(temp));
}