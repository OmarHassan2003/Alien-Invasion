#pragma once
#include "../Node.h"
#include "StackADT.h"
/************************************Stack Implementation**************************************/
template<typename T>
class Stack :public StackADT<T>
{
	Node<T>* Top;
	unsigned long int count;
public:
	Stack();
	bool isEmpty() const;
	bool push(const T& newEntry);
	bool pop(T& TopEntry);
	bool peek(T& TopEntry) const;
	int GetCount() const;
	void print() const;
	~Stack();
};

template<typename T>
Stack<T>::Stack() {
	Top = nullptr;
	count = 0;
}

template<typename T>
bool Stack<T>::isEmpty() const {
	if (!count) return true;
	else return false;
}

template<typename T>
bool Stack<T>::push(const T& newEntry)
{
	if (!newEntry) return false;
	Node<T>* New = new Node<T>;
	New->setItem(newEntry);
	if (!Top) 
	{
		Top = New;
		Top->setNext(nullptr);
		count++;
	}
	else 
	{
		New->setNext(Top);
		Top = New;
		count++;
	}
	return true;
}

template<typename T>
bool Stack<T>::pop(T& TopEntry)
{
	if (!Top)
	{
		TopEntry = NULL;
		return false;
	}
	else
	{
		Node<T>* temp = Top;
		Top = Top->getNext();
		TopEntry = temp->getItem(); //temp->ptrtovalue ??
		count--;
		delete temp;
		return true;
	}
}

template<typename T>
bool Stack<T>::peek(T& TopEntry) const
{
	if (!Top) 
		return false;
	TopEntry = Top->getItem();
	return true;
}

template<typename T>
void Stack<T>::print() const
{
	Node<T>* temp = Top;
	cout << "[";
	if (!count) {
		cout << "]";
		return;
	}
	while (temp != nullptr)
	{
		if (!temp->getNext())
			cout << temp->getItem();
		else
		{
			cout << temp->getItem() << " ,";
		}
		temp = temp->getNext();
	}
	cout << "]";
}

template<typename T>
Stack<T>::~Stack()
{
	Node<T>* temp = Top;
	while (Top) 
	{
		Top = Top->getNext();
		delete temp;
		temp = Top;
	}
	count = 0;
}

template<typename T>
int Stack<T>::GetCount() const
{
	return count;
}