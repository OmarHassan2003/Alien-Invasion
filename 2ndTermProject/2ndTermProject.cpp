#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "Queue/DoubleLinkedQueue.h"
//#include "priQueue.h"

#include "RandomGenerator/RandomGenerator.h"

int main()
{
	RandomGenerator InputData;
	InputData.Read();
	InputData.Print();

	Stack<int> S1;
	Queue<int> Q1;
	DoubleLinkedQueue<int> D1;
	int s, q, d;
	S1.push(8);
	S1.print();
	S1.peek(s);
	cout << s << endl;
	S1.pop(s);
	cout << S1.isEmpty() << endl;
	S1.print();

	Q1.enqueue(6);
	Q1.print();
	Q1.peek(q);
	cout << q << endl;
	Q1.dequeue(q);
	cout << Q1.isEmpty() << endl;
	Q1.print();


	D1.enqueue(4);
	D1.print();
	D1.peek(d);
	cout << d << endl;
	D1.dequeue(d);
	cout << Q1.isEmpty() << endl;
	D1.print();
}

