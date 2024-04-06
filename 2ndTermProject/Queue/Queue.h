#pragma once
#include "../Node.h"
#include "QueueADT.h"
class AlienSoldier;
class EarthSoldier;
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
	return (Front==nullptr);
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
		return false;
	else
	{
		FrontEntry = Front->getItem();
		return true;
	}
}

template<typename T>
void Queue<T>::print() const
{
	cout << count << '\t';
	Node<T>* temp = Front;
	if (!count) {
		cout << "NO ELEMENTS !" << endl;
		return;
	}
	while (temp != nullptr)
	{
		cout << *temp->getItem() << " ";
		temp = temp->getNext();
	}
	cout << endl;
}

template<typename T>
Queue<T>::~Queue()
{
	T temp;
	while (dequeue(temp));
}