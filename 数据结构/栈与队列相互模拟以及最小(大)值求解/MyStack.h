#ifndef MyStack_H
#define MyStack_H

#include<queue>
using namespace std;

class MyStack
{
private:
	queue<int>queueA,queueB;
	bool tag;
public:
	MyStack()
	{
		tag=false;
	}
	void push(int);
	int pop();
};

void MyStack::push(int key)
{
	if(!tag)queueA.push(key);
	else queueB.push(key);
}

int MyStack::pop()
{
	if(!tag)
	{
		if(queueA.empty())
			throw new exception("Õ»Îª¿Õ");
			while(queueA.size()>1)
			{
				queueB.push(queueA.front());
				queueA.pop();
			}
	 tag=true;
	 int ret=queueA.front();
	 queueA.pop();
	 return ret;
	}
	else
	{
		if(queueB.empty())
			throw new exception("Õ»Îª¿Õ");
			while(queueB.size()>1)
			{
				queueA.push(queueB.front());
				queueB.pop();
			}
	 tag=false;
	 int ret=queueB.front();
	 queueB.pop();
	 return ret;
	}
}

#endif MyStack_H