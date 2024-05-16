#pragma once
#include "Queue.h"
#include "../DoubleNode.h"


template<class T>
class DoubleLinkedQueue : public Queue<T>
{
	DoubleNode<T>* Front,* Rear;
	int count;
public:
	DoubleLinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool addToFront(const T& newEntry);
	bool dequeue(T& FrontEntry);
	bool peek(T& FrontEntry) const;
	bool peek_rear(T& RearEntry) const;
	bool GetRear(T& RearEntry);
	void print() const;
	int GetCount() const;
	~DoubleLinkedQueue();
};

template<class T>
inline DoubleLinkedQueue<T>::DoubleLinkedQueue()
{
	Front = nullptr;
	Rear = nullptr;
	count = 0;
}

template<class T>
inline bool DoubleLinkedQueue<T>::isEmpty() const
{
	return count == 0;
}

template<class T>
bool DoubleLinkedQueue<T>::enqueue(const T& newEntry)
{
	DoubleNode<T>* New = new DoubleNode<T>(newEntry);
	if (!count)
		Front = New;
	else
	{
		Rear->setNext(New);
		New->setPrev(Rear);
	}
	Rear = New;
	count++;
	return true;
}

template<class T>
bool DoubleLinkedQueue<T>::dequeue(T& FrontEntry)
{
	if (!count)
	{
		FrontEntry = NULL;
		return false;
	}
	DoubleNode<T>* Del = Front;
	FrontEntry = Front->getItem();
	Front = Front->getNext();
	if(Front)
		Front->setPrev(nullptr);

	if (Front == nullptr)
		Rear = nullptr;

	delete Del;
	Del = NULL;
	count--;
	return true;
}

template<class T>
bool DoubleLinkedQueue<T>::peek(T& FrontEntry) const
{
	if (!count)
		return false;
	else
	{
		FrontEntry = Front->getItem();
		return true;
	}
}

template<class T>
bool DoubleLinkedQueue<T>::peek_rear(T& RearEntry) const
{
	if (!count)
		return false;
	else
	{
		RearEntry = Rear->getItem();
		return true;
	}
}

template<class T>
bool DoubleLinkedQueue<T>::GetRear(T& RearEntry)
{
	if (!count)
	{
		RearEntry = nullptr;
		return false;
	}
	else
	{
		DoubleNode<T>* Del = Rear;
		RearEntry = Rear->getItem();
		Rear = Rear->getPrev();
		if (Rear)
			Rear->setNext(nullptr);

		if (Rear == nullptr)
			Rear = nullptr;

		delete Del;
		Del = NULL;
		count--;
		return true;
	}
}

template<class T>
bool DoubleLinkedQueue<T>::addToFront(const T& newEntry)
{
	DoubleNode<T>* New = new DoubleNode<T>(newEntry);
	if (!count)
		Rear = New;
	else
	{
		Front->setPrev(New);
		New->setNext(Front);
	}
	Front = New;
	count++;
	return true;
}

template<class T>
void DoubleLinkedQueue<T>::print() const
{
	DoubleNode<T>* temp = Front;
	cout << "[";
	if (!count) {
		cout << "]";
		return;
	}
	while (temp != nullptr) {
		if (!temp->getNext()) cout << temp->getItem();
		else
		{
			cout << temp->getItem() << " ,";
		}
		temp = temp->getNext();
	}
	cout << "]";
}

template<class T>
int DoubleLinkedQueue<T>::GetCount() const
{
	return count;
}

template<class T>
DoubleLinkedQueue<T>::~DoubleLinkedQueue()
{
	T x;
	for (int i = 0; i < count; i++)
		dequeue(x);
}


