#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    Node* NextNode;
    T* Ptr_To_Value;
};
