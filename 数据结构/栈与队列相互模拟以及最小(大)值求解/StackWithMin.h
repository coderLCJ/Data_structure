#ifndef StackWithMin_H
#define StackWithMin_H

#include<stack>
using namespace std;

class StackWithMin
{
private:
	stack<int>stackEle,stackMin;
public:
	int min();
	void push(int);
	void pop();
	int top();
	bool empty();
};

int StackWithMin::min()
{
	if(stackMin.empty())
		throw new exception("Õ»Îª¿Õ!");
	return stackMin.top();
}

void StackWithMin::push(int key)
{
	stackEle.push(key);
	if(stackMin.empty())
		stackMin.push(key);
	else
	{
	if(key>stackMin.top())
		stackMin.push(stackMin.top());
	else stackMin.push(key);
	}
}

int StackWithMin::top()
{
	if(stackEle.empty())
		throw new exception("Õ»Îª¿Õ!");
	return stackEle.top();
}

void StackWithMin::pop()
{
	if(stackMin.empty())
		throw new exception("Õ»Îª¿Õ!");
	stackEle.pop();
	stackMin.pop();
}

bool StackWithMin::empty()
{
	return stackMin.empty();
}

#endif StackWithMin_H