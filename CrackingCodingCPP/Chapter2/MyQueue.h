#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stack>
using namespace std;

//This is a Queue class implemented by two stacks
class MyQueue
{
private:
	stack<int> s1;		//for original stack order
	stack<int> s2;		//for reversed stack order
public:
	void inQueue(int value);
	int deQueue();
	int size();
	bool isEmpty();
	void clear();

	//This is the exercise for 3.6, sort a stack only use push/pop/peek/isEmpty
	stack<int> stackForSorting;
	void sortStack();

};

#endif /*SETOFSTACKS_H*/