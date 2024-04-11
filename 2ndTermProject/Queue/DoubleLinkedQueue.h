#pragma once
#include "Queue.h"
#include "../DoubleNode.h"


template<class T>
class DoubleLinkedQueue : public Queue<T>
{
	DoubleNode<T>* Front,* Rear;
	unsigned long int count;
public:
	DoubleLinkedQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& FrontEntry);
	bool peek(T& FrontEntry) const;
	bool GetRear(T& RearEntry) const;
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
	return (Front == nullptr);
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
		return false;
		FrontEntry = NULL;
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
inline bool DoubleLinkedQueue<T>::GetRear(T& RearEntry) const
{
	if (!count)
	{
		return false;
		RearEntry = NULL;
	}
	else
	{
		RearEntry = Rear->getItem();
		return true;
	}
}

template<class T>
inline void DoubleLinkedQueue<T>::print() const
{
	DoubleNode<T>* temp = Front;
	if (!count) {
		cout << "NO ELEMENTS" ;
		return;
	}
	while (temp != nullptr) {
		if (!temp->getNext()) cout << temp->getItem();
		else
		{
			cout << temp->getItem() << ",";
		}
		temp = temp->getNext();
	}

}

template<class T>
inline int DoubleLinkedQueue<T>::GetCount() const
{
	return count;
}

template<class T>
inline DoubleLinkedQueue<T>::~DoubleLinkedQueue()
{
	T x;
	for (int i = 0;i < count;i++)
		dequeue(x);
}


