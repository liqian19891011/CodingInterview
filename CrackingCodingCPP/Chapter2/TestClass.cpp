#include <iostream>
#include <assert.h>
#include "TestClass.h"
#include "MyQueue.h"

using namespace std;

void TestClass::TestMyQueue()
{
	MyQueue queue;
	
	int size = queue.size();
	assert(size == 0);
	assert(queue.isEmpty());
	
	queue.inQueue(1);
	assert(queue.size() == 1);
	assert(queue.deQueue() == 1);
	assert(queue.isEmpty());
	
	queue.inQueue(1);
	queue.inQueue(2);
	queue.inQueue(3);
	queue.inQueue(4);
	assert(queue.size() == 4);
	
	assert(queue.deQueue() == 1);
	assert(queue.size() == 3);
	
	assert(queue.deQueue() == 2);
	assert(queue.size() == 2);
	
	assert(queue.deQueue() == 3);
	assert(queue.size() == 1);
	
	assert(queue.deQueue() == 4);
	assert(queue.size() == 0);
}

void TestClass::TestSort()
{
	MyQueue queue;
	
	queue.stackForSorting.push(3);
	queue.stackForSorting.push(7);
	queue.stackForSorting.push(2);
	queue.stackForSorting.push(9);
	queue.stackForSorting.push(6);
	queue.stackForSorting.push(5);
	queue.stackForSorting.push(8);

	queue.sortStack();

	//tranverse the assist stack
	while(!queue.stackForSorting.empty())
	{
		cout<<queue.stackForSorting.top()<<"  ";
		queue.stackForSorting.pop();
	}
	cout<<endl;
}