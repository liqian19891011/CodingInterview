#include "MyQueue.h"


void MyQueue::inQueue(int value)
{
	s1.push(value);
}
int MyQueue::deQueue()
{
	int element;
	if(!s2.empty())
	{
		element = s2.top();
		s2.pop();
	}
	else
	{
		int temp;
		while(!s1.empty())
		{
			temp = s1.top();
			s2.push(temp);
			s1.pop();
		}
		element = s2.top();
		s2.pop();
	}

	return element;
}
int MyQueue::size()
{
	return s1.size() + s2.size();
}
bool MyQueue::isEmpty()
{
	if(this->size() == 0)
		return true;
	else
		return false;
}
void MyQueue::clear()
{
	while(this->size() != 0)
		deQueue();
}

void MyQueue::sortStack()
{
	stack<int> assist;
	int temp;

	while(!stackForSorting.empty())
	{
		if(assist.empty())
		{
			temp = stackForSorting.top();
			stackForSorting.pop();
			assist.push(temp);
		}
		else
		{
			temp = stackForSorting.top();
			if(temp <= assist.top())
			{
				stackForSorting.pop();
				assist.push(temp);
			}
			else
			{
				stackForSorting.pop();
				while(!assist.empty())
				{
					stackForSorting.push(assist.top());
					assist.pop();
					if(!assist.empty())
					{
						if(temp < assist.top())
							break;
					}
				}
				assist.push(temp);
			}
		}
	}

	stackForSorting = assist;

	
}
