#include <iostream>
using namespace std;
/************************************Single Linked List Implementation**************************************/
template<typename T>
struct Node
{
    Node* NextNode;
    T* Ptr_To_Value;
};
template<class T>
class SingleLinkedList
{
    Node<T>* HeadNode;
    unsigned long long int Counter;
public:
    SingleLinkedList(T* Head_Node_Value = NULL);
    Node<T>* GetHeadNode() const;
    unsigned long long int GetCounter() const; //Size of Linked List
    void Push_Back(T& Passed_Node_Value);
    void Push_Back(SingleLinkedList<T>& Passed_List);
    void Push_After(T& Passed_Node_Value, long long int Pos = -1);
    void Push_After(SingleLinkedList<T>& Passed_List, unsigned long long int Pos);
    void Delete_Element(long long int Pos = -1);
    bool Swap(unsigned long long int First_Index, unsigned long long int Second_Index);
    T* Return_Ptr_To_Element(long long int Pos = -1);
    unsigned long long int GetFreqOf(T* Passed_T, Node<T>* = NULL);
    void ClearList(Node<T>* = NULL);
    void CopyList(SingleLinkedList<T>& DestinationList);
    void Sort();
    bool IsEmpty();
    void Print();
    ~SingleLinkedList();
};
template<class T>
SingleLinkedList<T>::SingleLinkedList(T* Head_Node_Value)
{
    Counter = 0;
    if (Head_Node_Value)
    {
        HeadNode = new Node<T>;
        HeadNode->Ptr_To_Value = Head_Node_Value;
        HeadNode->NextNode = NULL;
        Counter++;
    }
}
template<class T>
Node<T>* SingleLinkedList<T>::GetHeadNode() const
{
    return HeadNode;
}
template<class T>
unsigned long long int SingleLinkedList<T>::GetCounter() const
{
    return Counter;
}
template<class T>
void SingleLinkedList<T>::Push_Back(T& Passed_Node_Value)
{
    T* Value = new T;
    *Value = Passed_Node_Value;
    if (Counter == 0)
    {
        HeadNode = new Node<T>;
        HeadNode->Ptr_To_Value = Value;
        HeadNode->NextNode = NULL;
    }
    else
    {
        Node<T>* LoopNode = HeadNode;
        while (LoopNode->NextNode != NULL)
            LoopNode = LoopNode->NextNode;
        Node<T>* TempNode = new Node<T>;
        TempNode->Ptr_To_Value = Value;
        TempNode->NextNode = NULL;
        LoopNode->NextNode = TempNode;
    }
    Counter++;
}
template<class T>
void SingleLinkedList<T>::Push_Back(SingleLinkedList<T>& Passed_List)
{
    if (this == &Passed_List)
    {
        SingleLinkedList<T>* Temp_List = new SingleLinkedList<T>;
        Passed_List.CopyList(*Temp_List);
        Node<T>* LoopNode = HeadNode;
        while (LoopNode->NextNode)
            LoopNode = LoopNode->NextNode;
        LoopNode->NextNode = Temp_List->GetHeadNode();
        Counter *= 2;
    }
    else
    {
        Node<T>* LoopNode = HeadNode;
        while (LoopNode->NextNode != NULL)
            LoopNode = LoopNode->NextNode;
        LoopNode->NextNode = Passed_List.GetHeadNode();
        Counter += Passed_List.GetCounter();
    }
}
template<class T>
void SingleLinkedList<T>::Push_After(T& Passed_Node_Value, long long int Pos)
{
    if (Pos >= Counter || Pos == -1)
        Push_Back(Passed_Node_Value);
    else
    {
        Node<T>* Loop_Node = HeadNode;
        Node<T>* Temp_Node;
        Temp_Node = new Node<T>;
        for (unsigned long long int i = 0;i < Pos;i++)
            Loop_Node = Loop_Node->NextNode;
        Temp_Node->NextNode = Loop_Node->NextNode;
        Temp_Node->Ptr_To_Value = &Passed_Node_Value;
        Loop_Node->NextNode = Temp_Node;
    }
    Counter++;
}
template<class T>
void SingleLinkedList<T>::Push_After(SingleLinkedList<T>& Passed_List, unsigned long long int Pos)
{
    if (Pos >= Counter)
        Push_Back(Passed_List);
    else if (Passed_List.GetHeadNode())
    {
        Node<T>* Loop_Node = HeadNode;
        Node<T>* Loop_Node_For_List = Passed_List.GetHeadNode();
        for (unsigned long long int i = 0;i < Pos;i++)
            Loop_Node = Loop_Node->NextNode;
        while (Loop_Node_For_List->NextNode != NULL)
            Loop_Node_For_List = Loop_Node_For_List->NextNode;
        Loop_Node_For_List->NextNode = Loop_Node->NextNode;
        Loop_Node->NextNode = Passed_List.GetHeadNode();
        Counter++;
    }
}
template<class T>
void SingleLinkedList<T>::Delete_Element(long long int Pos)
{
    if (HeadNode)
    {
        if (Pos == -1)
        {
            if (Counter == 1)
            {
                Node<T>* Temp_Node = HeadNode->NextNode;
                delete HeadNode;
                HeadNode = Temp_Node;
            }
            else
            {
                Node<T>* Loop_Node = HeadNode;
                Node<T>* Co_Loop_Node = NULL;
                while (Loop_Node->NextNode)
                {
                    Co_Loop_Node = Loop_Node;
                    Loop_Node = Loop_Node->NextNode;
                }
                Co_Loop_Node->NextNode = NULL;
                delete Loop_Node;
                Loop_Node = NULL;
            }
        }
        else if (Pos == 0)
        {
            Node<T>* Temp_Node = HeadNode->NextNode;
            delete HeadNode;
            HeadNode = Temp_Node;
        }
        else if (Pos < Counter)
        {
            Node<T>* Loop_Node = HeadNode;
            Node<T>* Co_Loop_Node = HeadNode;
            for (unsigned long long int i = 0;i < Pos;i++)
                Loop_Node = Loop_Node->NextNode;
            for (unsigned long long int i = 0;i < Pos - 1;i++)
                Co_Loop_Node = Co_Loop_Node->NextNode;
            Co_Loop_Node->NextNode = Loop_Node->NextNode;
            delete Loop_Node;
            Loop_Node = NULL;
        }
        Counter--;
    }
}
template<class T>
bool SingleLinkedList<T>::Swap(unsigned long long int First_Index, unsigned long long int Second_Index)
{
    if (HeadNode && (First_Index > Second_Index))
    {
        T* Temp_Node0 = Return_Ptr_To_Element(First_Index);
        T* Temp_Node1 = Return_Ptr_To_Element(Second_Index);
        Delete_Element(First_Index);
        Delete_Element(Second_Index - 1);
        Push_After(*Temp_Node0, Second_Index - 2);
        Push_After(*Temp_Node1, First_Index - 1);
        return true;
    }
    else
        return false;

}
template<class T>
T* SingleLinkedList<T>::Return_Ptr_To_Element(long long int Pos)
{
    if (HeadNode)
        if (Pos == -1 || Pos == Counter)
        {
            Node<T>* LoopNode = HeadNode;
            while (LoopNode->NextNode != NULL)
                LoopNode = LoopNode->NextNode;
            return LoopNode->Ptr_To_Value;
        }
        else if (Pos < Counter)
        {
            Node<T>* Loop_Node = HeadNode;
            for (long long int i = 0;i < Pos;i++)
                Loop_Node = Loop_Node->NextNode;
            return Loop_Node->Ptr_To_Value;
        }
        else
            return NULL;
    else
        return NULL;
}
template<class T>
unsigned long long int SingleLinkedList<T>::GetFreqOf(T* Passed_T, Node<T>* Temp_Node)
{
    if (Temp_Node == NULL)
    {
        if (HeadNode)
            return GetFreqOf(Passed_T, HeadNode);
        else
            return 0;
    }
    else if (Temp_Node->Ptr_To_Value == Passed_T)
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
void SingleLinkedList<T>::ClearList(Node<T>* Temp_Node)
{
    if (HeadNode)
    {
        if (Temp_Node == NULL)
        {
            Counter--;
            ClearList(HeadNode);
            //delete HeadNode;
            HeadNode = NULL;
        }
        else if (Counter > 0)
        {
            Counter--;
            ClearList(Temp_Node->NextNode);
            delete Temp_Node;
            Temp_Node = NULL;
        }
    }
}
template<class T>
void SingleLinkedList<T>::CopyList(SingleLinkedList<T>& DestinationList)
{
    DestinationList.ClearList();
    for (unsigned long long int i = 0;i < Counter;i++)
        DestinationList.Push_Back(*(this->Return_Ptr_To_Element(i)));
}
template<class T>
void SingleLinkedList<T>::Sort()
{
    MergeSort(this);
}
template<class T>
bool SingleLinkedList<T>::IsEmpty()
{
    return (HeadNode == NULL) ? true : false;
}
template<class T>
void SingleLinkedList<T>::Print()
{
    if (!Counter)
    {
        cout << "No Elements in List To Be Printed" << endl;
        return;
    }
    Node<T>* LoopNode = HeadNode;
    while (LoopNode)
    {
        cout << (*LoopNode->Ptr_To_Value) << endl;
        LoopNode = LoopNode->NextNode;
    }
}
template<class T>
SingleLinkedList<T>::~SingleLinkedList()
{
    this->ClearList();
}
/*******************************************Merge Sorting ALgorithm****************************************/
template<class T>
void Merge(SingleLinkedList<T>* MergedList, SingleLinkedList<T>& LeftList, SingleLinkedList<T>& RightList)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;
    const unsigned long long int sizeLeft = LeftList.GetCounter(), sizeRight = RightList.GetCounter();
    while (i < sizeLeft && j < sizeRight)
    {
        if (*LeftList.Return_Ptr_To_Element(i) < *RightList.Return_Ptr_To_Element(j))
            *MergedList->Return_Ptr_To_Element(k++) = *LeftList.Return_Ptr_To_Element(i++);
        else
            *MergedList->Return_Ptr_To_Element(k++) = *RightList.Return_Ptr_To_Element(j++);
    }
    while (i < sizeLeft)
        *MergedList->Return_Ptr_To_Element(k++) = *LeftList.Return_Ptr_To_Element(i++);
    while (j < sizeRight)
        *MergedList->Return_Ptr_To_Element(k++) = *RightList.Return_Ptr_To_Element(j++);
}
template<class T>
void MergeSort(SingleLinkedList<T>* Passed_list)
{
    const unsigned long long int size = Passed_list->GetCounter();
    if (size > 1)
    {
        SingleLinkedList<T>LeftList, RightList;
        for (unsigned int i = 0;i < size - size / 2;i++)
            LeftList.Push_Back(*Passed_list->Return_Ptr_To_Element(i));
        for (unsigned int i = size - size / 2;i < size;i++)
            RightList.Push_Back(*Passed_list->Return_Ptr_To_Element(i));
        MergeSort(&LeftList);
        MergeSort(&RightList);
        Merge(Passed_list, LeftList, RightList);
    }
    else
        return;
}
