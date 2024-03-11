#pragma once

#include <iostream>
#include "SingleLinkedList.h"
using namespace std;
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
	Node<T>* Top() const;
	~Stack();
};