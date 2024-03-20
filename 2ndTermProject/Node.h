#pragma once
#include <iostream>
using namespace std;

template<class T>
struct Node
{
    T* Ptr_To_Value;
    Node<T>* NextNode;
    Node<T>* PrevNode;
};
