#pragma once
#include "Node.h"
/************************************Stack Implementation**************************************/
template<typename T>
class Stack 
{
	Node<T>* Top;
	unsigned long int count;
public:
	Stack();
	bool Push(Node<T>*);
	bool Pop();
	Node<T>* TopElement() const;
	bool IsEmpty();
	void Print() const;
	~Stack();
};

template<typename T>
Stack<T>::Stack() {
	Top = NULL;
	count = 0;
}

template<typename T>
bool Stack<T>::Push(Node<T>* NodeToBeAdded) 
{
	if (!NodeToBeAdded) return false;
	Node<T>* New = new Node<T>;
	New = NodeToBeAdded;
	if (!Top) 
	{
		Top = New;
		Top->NextNode = NULL;
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
bool Stack<T>::Pop()
{
	if (!Top) return false;
	else
	{
		Node<T>* temp = Top;
		Top = Top->NextNode;
		delete temp;
		count--;
		return true;
	}
}

template<typename T>
Node<T>* Stack<T>::TopElement() const
{
	if (!Top) return NULL;
	Node<T>* temp = Top;
	return temp;
}

template<typename T>
bool Stack<T>::IsEmpty() {
	if (!count) return true;
	else return false;
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

template<typename T>
void Stack<T>::Print() const
{
	Node<T>* temp = Top;
	if (!count) {
		cout << "NO ELEMENTS !" << endl;
		return;
	}
	while (temp != NULL) {
		cout << *(temp->Ptr_To_Value) << '\t';
		temp = temp->NextNode;
	}
	cout << endl;
}