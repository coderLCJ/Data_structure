#include<iostream>
#include"MyQueue.h"
#include"MyStack.h"
#include"StackWithMin.h"
#include"QueueWithMin.h"
using namespace std;

int main()
{
	cout<<"栈模拟队列的效果"<<endl;
	MyQueue myQue;
	for(int i=1;i<=5;i++)
			myQue.EnQueue(i);

	for(int i=1;i<=5;i++)
			cout<<myQue.DeQueuep()<<endl;

	cout<<"队列模拟栈的效果"<<endl;
	MyStack mySta;
	for(int i=1;i<=5;i++)
		mySta.push(i);

	for(int i=1;i<=5;i++)
		cout<<mySta.pop()<<endl;

	
	cout<<"栈的最小值效果"<<endl;
	StackWithMin myStackWithMin;
	for(int i=1;i<=5;i++)
	{
		myStackWithMin.push(i);
		cout<<"当前栈的最小元素为:"<<myStackWithMin.min()<<endl;
	}

	cout<<"队列的最小值效果"<<endl;
	QueueWithMin myQueueWithMin;
	for(int i=1;i<=5;i++)
	{
		myQueueWithMin.EnQueue(i);
		cout<<"当前队列的最小元素为:"<<myQueueWithMin.min()<<endl;
	}
	
	system("pause");
	return 0;
}