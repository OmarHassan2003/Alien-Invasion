#include "SingleLinkedList.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
	/*cout << "The Real Slim Shady" << endl;
	Stack<int> MyStack;
	Node<int>* s1 = new Node<int>;
	int x = 5;
	s1->Ptr_To_Value = &x;
	Node<int>* s2 = new Node<int>;
	int x1 = 6;
	s2->Ptr_To_Value = &x1;
	Node<int>* s3 = new Node<int>;
	int x2 = 7;
	s3->Ptr_To_Value = &x2;
	Node<int>* s4 = new Node<int>;
	int x3 = 8;
	s4->Ptr_To_Value = &x3;
	MyStack.Push(s1);
	MyStack.Push(s2);
	MyStack.Push(s3);
	MyStack.Push(s4);
	MyStack.Print();
	MyStack.Pop();
	MyStack.Pop();
	MyStack.Print();
	cout << *(MyStack.TopElement()->Ptr_To_Value) << endl;
	SingleLinkedList<int>List;
	List.Push_Back(x1);
	List.Push_Back(x);
	List.Push_Back(x3);
	List.Push_Back(x2);
	List.Print();
	cout << "/////////////////////////////////////" << endl;
	List.Sort();
	List.Print();*/

	DoubleLinkedList<int>L1, L2;
	int x ,y;

	cin >> x;
	while (x != -1)
	{
		L1.Push_Back(x);
		cin >> x;
	}
	cin >> y;
	while (y != -1)
	{
		L2.Push_Back(y);
		cin >> y;
	}

	L1.Push_At_Index(L2, 0);
	L1.Print();

	return 0;
}

