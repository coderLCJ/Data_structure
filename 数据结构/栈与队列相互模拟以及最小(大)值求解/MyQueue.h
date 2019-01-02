#ifndef MyQueue_H
#define MyQueue_H
#include<stack>
using namespace std;

class MyQueue
{
private:
	stack<int>stackA,stackB;
public:
	void EnQueue(int);
	int DeQueuep();
};

void MyQueue::EnQueue(int key)
{
	stackA.push(key);
}

int MyQueue::DeQueuep()
{
	if(stackB.empty())
	{
		while(!stackA.empty())
		{
			stackB.push(stackA.top());
			stackA.pop();
		}
		if(stackB.empty())
			throw new exception("╤сапря©у!");
	}
	int ret=stackB.top();
	stackB.pop();
	return ret;
}
#endif MyQueue_H