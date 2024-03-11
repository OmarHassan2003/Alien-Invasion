#pragma once
#include "Node.h"
/************************************Queue Implementation**************************************/

template <typename T>
class Queue
{
	Node<T>* Front;
	Node<T>* Rear;
	int count;
public:
	Queue();
	bool EnQueue(Node<T>*);
	bool DeQueue();
	Node<T>* PickFront();
	bool IsEmpty();
	//bool PriorityEnQueue();
	//bool PriorityDeQueue();
	~Queue();
};

template<typename T>
Queue<T>::Queue()
{
	Front = NULL;
	Rear = NULL;
	count = 0;
}

template<typename T>
inline bool Queue<T>::EnQueue(Node<T>* New_Node)
{
	Node<T>* New = new Node<T>;
	New = New_Node;
	if (!count)
		Front = New;
	else
		Rear->NextNode = New;

	Rear = New;
	count++;
	return true;
}

template<typename T>
bool Queue<T>::DeQueue()
{
	if (!count)
		return false;
	else
	{
		Node<T>* N = Front;
		Front = Front->NextNode;
		delete N;
		return true;
	}
}

template<typename T>
Node<T>* Queue<T>::PickFront()
{
	Node<T>* N = Front;
	if (!count)
		return NULL;
	else
		return N;
}

template<typename T>
bool Queue<T>::IsEmpty()
{
	return !count ;
}

template<typename T>
inline Queue<T>::~Queue()
{
	Node<T>* N = Front;
	while (N)
	{
		Front = Front->NextNode;
		delete N;
		N = Front;
	}
	Rear = NULL;
	count = 0;
}

