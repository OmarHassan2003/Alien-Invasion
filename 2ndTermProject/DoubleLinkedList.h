#include "Node.h"
/************************************Single Linked List Implementation**************************************/
template<class T>
class DoubleLinkedList
{
    Node<T>* HeadNode;
    Node<T>* TailNode;
    unsigned long long int Counter;
public:
    DoubleLinkedList(T* value = NULL);
    Node<T>* GetHeadNode() const;
    Node<T>* GetTailNode() const;
    unsigned long long int GetCounter() const;
    void Push_Back(T& Passed_Value);
    void Push_Back(DoubleLinkedList<T>& Passed_List);
    void Push_At_Index(T& Passed_Value, long long int index = -1);
    void Push_At_Index(DoubleLinkedList<T>& Passed_List, long long int index = -1);
    void ShallowCopy(DoubleLinkedList<T>& Copied_List);
    void DeepCopy(DoubleLinkedList<T>& CopiedList);
    T* ReturnPtrToElementAtIndex(long long int index = -1);
    void DeleteElementAtIndex(long long int index = -1);
    unsigned long long int GetFreqOf(T& Passed_T, Node<T>* = NULL);
    void ClearList();
    void Print();
    void Sort();
    ~DoubleLinkedList();
};
template<class T>
void DoubleLinkedList<T>::Sort()
{
    MergeSort(this);
}
template<class T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    //this->ClearList();
}
template<class T>
void DoubleLinkedList<T>::ClearList()
{
    if (HeadNode)
    {
        const unsigned long long int List_Size = Counter;
        for (unsigned long long int i = 0;i < List_Size;i++)
            DeleteElementAtIndex();
    }
}
template<class T>
unsigned long long int DoubleLinkedList<T>::GetFreqOf(T& Passed_T, Node<T>* Temp_Node)
{
    if (Temp_Node == NULL)
    {
        if (HeadNode)
            return GetFreqOf(Passed_T, HeadNode);
        else
            return 0;
    }
    else if (*Temp_Node->Ptr_To_Value == Passed_T)
    {
        if (Temp_Node->NextNode != NULL)
            return 1 + GetFreqOf(Passed_T, Temp_Node->NextNode);
        else
            return 1;
    }
    else
    {
        if (Temp_Node->NextNode != NULL)
            return GetFreqOf(Passed_T, Temp_Node->NextNode);
        else
            return 0;
    }
}
template<class T>
void DoubleLinkedList<T>::Push_At_Index(DoubleLinkedList<T>& Passed_List, long long int index)
{
    if (!HeadNode || index == -1 || index >= Counter - 1)
    {
        Push_Back(Passed_List);
        Counter -= Passed_List.GetCounter();
    }
    else if (index == 0)
    {
        DoubleLinkedList<T>* L = new DoubleLinkedList<T>;
        L->DeepCopy(Passed_List);
        Node<T>* TempNode = L->GetTailNode();
        TempNode->NextNode = HeadNode;
        HeadNode->PrevNode = TempNode;
        HeadNode = L->GetHeadNode();
    }
    else
    {
        DoubleLinkedList<T>* L = new DoubleLinkedList<T>;
        L->DeepCopy(Passed_List);
        Node<T>* Loop_Node = HeadNode;
        for (unsigned long long int i = 0;i < index;i++)
            Loop_Node = Loop_Node->NextNode;
        Loop_Node->PrevNode->NextNode = L->GetHeadNode();
        L->GetHeadNode()->PrevNode = Loop_Node->PrevNode;
        L->GetTailNode()->NextNode = Loop_Node;
        Loop_Node->NextNode->PrevNode = L->GetTailNode();
    }
    Counter += Passed_List.GetCounter();
}
template<class T>
void DoubleLinkedList<T>::DeleteElementAtIndex(long long int index)
{
    if (HeadNode)
    {
        if (index == -1 || index >= Counter - 1)
        {
            if (Counter == 1)
            {
                delete HeadNode;
                HeadNode = NULL;
                TailNode = NULL;
            }
            else
            {
                Node<T>* Temp_Node = TailNode->PrevNode;
                Temp_Node->NextNode = NULL;
                delete TailNode;
                TailNode = Temp_Node;
            }
        }
        else if (index == 0)
        {
            if (Counter == 1)
            {
                delete HeadNode;
                HeadNode = NULL;
                TailNode = NULL;
            }
            else
            {
                Node<T>* Temp_Node = HeadNode->NextNode;
                delete HeadNode;
                HeadNode = Temp_Node;
            }
        }
        else
        {
            Node<T>* Loop_Node = HeadNode;
            for (unsigned long long int i = 0;i < index;i++)
                Loop_Node = Loop_Node->NextNode;
            Loop_Node->PrevNode->NextNode = Loop_Node->NextNode;
            Loop_Node->NextNode->PrevNode = Loop_Node->PrevNode;
            delete Loop_Node;
            Loop_Node = NULL;
        }
        Counter--;
    }
}
template<class T>
T* DoubleLinkedList<T>::ReturnPtrToElementAtIndex(long long int index)
{
    if (HeadNode)
    {
        if (index == -1 || index >= Counter - 1)
            return TailNode->Ptr_To_Value;
        else
        {
            Node<T>* Loop_Node = HeadNode;
            for (unsigned long long int i = 0;i < index;i++)
                Loop_Node = Loop_Node->NextNode;
            return Loop_Node->Ptr_To_Value;
        }
    }
    else
        return NULL;
}
template<class T>
DoubleLinkedList<T>::DoubleLinkedList(T* value)
{
    if (value)
    {
        T* Temp_Value = new T;
        *Temp_Value = *value;
        HeadNode = new Node<T>;
        HeadNode->Ptr_To_Value = Temp_Value;
        HeadNode->NextNode = NULL;
        HeadNode->PrevNode = NULL;
        TailNode = HeadNode;
        Counter = 1;
    }
    else
    {
        HeadNode = NULL;
        TailNode = NULL;
        Counter = 0;
    }
}
template<class T>
Node<T>* DoubleLinkedList<T>::GetHeadNode() const
{
    return HeadNode;
}
template<class T>
Node<T>* DoubleLinkedList<T>::GetTailNode() const
{
    return TailNode;
}
template<class T>
unsigned long long int DoubleLinkedList<T>::GetCounter() const
{
    return Counter;
}
template<class T>
void DoubleLinkedList<T>::Push_Back(T& Passed_Value)
{
    T* Temp_Value = new T;
    *Temp_Value = Passed_Value;
    if (TailNode)
    {
        Node<T>* Temp_Node = new Node<T>;
        Temp_Node->Ptr_To_Value = Temp_Value;
        Temp_Node->NextNode = NULL;
        Temp_Node->PrevNode = TailNode;
        TailNode->NextNode = Temp_Node;
        TailNode = Temp_Node;
    }
    else
    {
        HeadNode = new Node<T>;
        HeadNode->Ptr_To_Value = Temp_Value;
        HeadNode->NextNode = NULL;
        HeadNode->PrevNode = NULL;
        TailNode = HeadNode;
    }
    Counter++;
}
template<class T>
void DoubleLinkedList<T>::Push_Back(DoubleLinkedList<T>& Passed_List)
{
    if (Passed_List.GetHeadNode())
    {
        DoubleLinkedList<T>* L = new DoubleLinkedList<T>;
        L->DeepCopy(Passed_List);
        if (TailNode)
        {
            TailNode->NextNode = L->GetHeadNode();
            TailNode = L->GetTailNode();
        }
        else
        {
            HeadNode = L->GetHeadNode();
            TailNode = L->GetTailNode();
        }
        Counter += L->GetCounter();
    }
}
template<class T>
void DoubleLinkedList<T>::Push_At_Index(T& Passed_Value, long long int index)
{
    if (!HeadNode || index == -1 || index > Counter - 1)
    {
        this->Push_Back(Passed_Value);
        Counter--;
    }
    else if (index == 0)
    {
        T* Temp_Value = new T;
        *Temp_Value = Passed_Value;
        Node<T>* Temp_Node = new Node<T>;
        Temp_Node->Ptr_To_Value = Temp_Value;
        Temp_Node->PrevNode = NULL;
        HeadNode->PrevNode = Temp_Node;
        Temp_Node->NextNode = HeadNode;
        HeadNode = Temp_Node;
    }
    else
    {
        T* Temp_Value = new T;
        *Temp_Value = Passed_Value;
        Node<T>* Loop_Node = HeadNode;
        for (unsigned long long int i = 0;i < index;i++)
            Loop_Node = Loop_Node->NextNode;
        Node<T>* Temp_Node = new Node<T>;
        Temp_Node->Ptr_To_Value = Temp_Value;
        Loop_Node->PrevNode->NextNode = Temp_Node;
        Temp_Node->PrevNode = Loop_Node->PrevNode;
        Loop_Node->PrevNode = Temp_Node;
        Temp_Node->NextNode = Loop_Node;
    }
    Counter++;
}
template<class T>
void DoubleLinkedList<T>::ShallowCopy(DoubleLinkedList<T>& Copied_List)
{
    ClearList();
    if (this != &Copied_List && Copied_List.GetHeadNode())
    {
        HeadNode = Copied_List.GetHeadNode();
        TailNode = Copied_List.GetTailNode();
        Counter = Copied_List.GetCounter();
    }
}
template<class T>
void DoubleLinkedList<T>::DeepCopy(DoubleLinkedList<T>& CopiedList)
{
    ClearList();
    if (this != &CopiedList && CopiedList.GetHeadNode())
    {
        const unsigned long long int Copied_List_Size = CopiedList.GetCounter();
        for (unsigned long long int i = 0; i < Copied_List_Size;i++)
        {
            T* Copied_Value = new T;
            *Copied_Value = *CopiedList.ReturnPtrToElementAtIndex(i);
            this->Push_Back(*Copied_Value);
        }
    }
}
template<class T>
void Merge(DoubleLinkedList<T>* MergedList, DoubleLinkedList<T>& LeftList, DoubleLinkedList<T>& RightList)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    const unsigned long long int sizeLeft = LeftList.GetCounter(), sizeRight = RightList.GetCounter();
    while (i < sizeLeft && j < sizeRight)
    {
        if (*LeftList.ReturnPtrToElementAtIndex(i) < *RightList.ReturnPtrToElementAtIndex(j))
            *MergedList->ReturnPtrToElementAtIndex(k++) = *LeftList.ReturnPtrToElementAtIndex(i++);
        else
            *MergedList->ReturnPtrToElementAtIndex(k++) = *RightList.ReturnPtrToElementAtIndex(j++);
    }
    while (i < sizeLeft)
        *MergedList->ReturnPtrToElementAtIndex(k++) = *LeftList.ReturnPtrToElementAtIndex(i++);
    while (j < sizeRight)
        *MergedList->ReturnPtrToElementAtIndex(k++) = *RightList.ReturnPtrToElementAtIndex(j++);
}
template<class T>
void MergeSort(DoubleLinkedList<T>* Passed_list)
{
    const unsigned long long int size = Passed_list->GetCounter();
    if (size > 1)
    {
        DoubleLinkedList<T>LeftList, RightList;
        for (unsigned int i = 0;i < size - size / 2;i++)
            LeftList.Push_Back(*Passed_list->ReturnPtrToElementAtIndex(i));
        for (unsigned int i = size - size / 2;i < size;i++)
            RightList.Push_Back(*Passed_list->ReturnPtrToElementAtIndex(i));
        MergeSort(&LeftList);
        MergeSort(&RightList);
        Merge(Passed_list, LeftList, RightList);
    }
    else
        return;
}
template<class T>
void DoubleLinkedList<T>::Print()
{
    if (HeadNode)
    {
        Node<T>* TempNode = HeadNode;
        while (TempNode)
        {
            cout << *TempNode->Ptr_To_Value << " ";
            TempNode = TempNode->NextNode;
        }
    }
    else
        cout << "No Elements to be Printed";
    cout << endl;
}
