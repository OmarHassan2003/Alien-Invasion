#pragma once

template<class T>
class DoubleNode
{
	DoubleNode* PrevNode, *NextNode;
	T item;
public:
	DoubleNode();
	DoubleNode(const T& r_Item);
	DoubleNode(const T& r_Item, DoubleNode<T>* nextNodePtr);
	void setItem(const T& r_Item);
	void setNext(DoubleNode<T>* nextNodePtr);
	void setPrev(DoubleNode<T>* nextNodePtr);
	T getItem() const;
	DoubleNode<T>* getNext() const;
	DoubleNode<T>* getPrev() const;
};

template<class T>
inline DoubleNode<T>::DoubleNode()
{
	PrevNode = nullptr;
	NextNode = nullptr;
}

template<class T>
inline DoubleNode<T>::DoubleNode(const T& r_Item)
{
	item = r_Item;
	PrevNode = nullptr;
	NextNode = nullptr;
}

template<class T>
inline DoubleNode<T>::DoubleNode(const T& r_Item, DoubleNode<T>* nextNodePtr)
{
	item = r_Item;
	NextNode = nextNodePtr;
	PrevNode = nullptr;
}

template<class T>
inline void DoubleNode<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template<class T>
inline void DoubleNode<T>::setNext(DoubleNode<T>* nextNodePtr)
{
	NextNode = nextNodePtr;
}

template<class T>
inline void DoubleNode<T>::setPrev(DoubleNode<T>* prevNodePtr)
{
	PrevNode = prevNodePtr;
}

template<class T>
inline T DoubleNode<T>::getItem() const
{
	return item;
}

template<class T>
inline DoubleNode<T>* DoubleNode<T>::getNext() const
{
	return NextNode;
}

template<class T>
inline DoubleNode<T>* DoubleNode<T>::getPrev() const
{
	return PrevNode;
}

