#pragma once
#include "Node.h"
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
	New = newEntry;
	if (!Top) 
	{
		Top = New;
		Top->NextNode = nullptr;
		count++;
	}
	else 
	{
		New->NextNode = Top;
		Top = New;
		count++;
	}
	return true;
}

template<typename T>
bool Stack<T>::pop(T& TopEntry)
{
	if (!Top) return false;
	else
	{
		Node<T>* temp = Top;
		Top = Top->NextNode;
		TopEntry = temp; //temp->ptrtovalue ??
		count--;
		return true;
	}
}

template<typename T>
bool Stack<T>::peek(T& TopEntry) const
{
	if (!Top) 
	{
		TopEntry = nullptr;
		return false;
	}
	TopEntry = Top;
	return true;
}

template<typename T>
void Stack<T>::print() const
{
	Node<T>* temp = Top;
	if (!count) {
		cout << "NO ELEMENTS !" << endl;
		return;
	}
	while (temp != nullptr) {
		cout << *(temp->Ptr_To_Value) << '\t';//should be changed to the armyunit details
		temp = temp->NextNode;
	}
	cout << endl;
}

template<typename T>
Stack<T>::~Stack()
{
	Node<T>* temp = Top;
	while (Top) 
	{
		Top = Top->NextNode;
		delete temp;
		temp = Top;
	}
	count = 0;
}