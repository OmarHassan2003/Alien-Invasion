#pragma once
#include "Queue.h"
#include "DoubleNode.h"


template<class T>
class DoubleLinkedQueue : public Queue<T>
{
	DoubleNode<T> Front, Rear;
	unsigned long int count;
public:
	DoubleLinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& FrontEntry);
	bool peek(T& FrontEntry) const;

	void print() const;
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
	return !count;
}

template<class T>
bool DoubleLinkedQueue<T>::enqueue(const T& newEntry)
{
	if (!newEntry)
		return false;

	DoubleNode<T>* New = new Node<T>;
	New->setItem(newEntry);

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
		return false;
	else
	{
		FrontEntry = Front->getItem();
		Front = Front->getNext();
		Front->setPrev(nullptr);
		count--;
		return true;
	}
}

template<class T>
inline bool DoubleLinkedQueue<T>::peek(T& FrontEntry) const
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
inline void DoubleLinkedQueue<T>::print() const
{
	DoubleNode<T>* temp = Front;
	if (!count) {
		cout << "NO ELEMENTS !" << endl;
		return;
	}
	while (temp != nullptr) {
		cout << *(temp->getItem()) << '\t';//should be changed to the armyunit details
		temp = temp->NextNode;
	}
	cout << endl;
}


