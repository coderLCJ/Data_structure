#include<iostream>
#include"MyQueue.h"
#include"MyStack.h"
#include"StackWithMin.h"
#include"QueueWithMin.h"
using namespace std;

int main()
{
	cout<<"ջģ����е�Ч��"<<endl;
	MyQueue myQue;
	for(int i=1;i<=5;i++)
			myQue.EnQueue(i);

	for(int i=1;i<=5;i++)
			cout<<myQue.DeQueuep()<<endl;

	cout<<"����ģ��ջ��Ч��"<<endl;
	MyStack mySta;
	for(int i=1;i<=5;i++)
		mySta.push(i);

	for(int i=1;i<=5;i++)
		cout<<mySta.pop()<<endl;

	
	cout<<"ջ����СֵЧ��"<<endl;
	StackWithMin myStackWithMin;
	for(int i=1;i<=5;i++)
	{
		myStackWithMin.push(i);
		cout<<"��ǰջ����СԪ��Ϊ:"<<myStackWithMin.min()<<endl;
	}

	cout<<"���е���СֵЧ��"<<endl;
	QueueWithMin myQueueWithMin;
	for(int i=1;i<=5;i++)
	{
		myQueueWithMin.EnQueue(i);
		cout<<"��ǰ���е���СԪ��Ϊ:"<<myQueueWithMin.min()<<endl;
	}
	
	system("pause");
	return 0;
}