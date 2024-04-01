#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "DoubleLinkedQueue.h"
//#include "priQueue.h"

int main()
{
	Stack<int> S1;
	Queue<int> Q1;
	DoubleLinkedQueue<int> D1;
	//priQueue<int> P1;

	S1.push(8);
	S1.print();
	Q1.enqueue(6);
	Q1.print();
}

