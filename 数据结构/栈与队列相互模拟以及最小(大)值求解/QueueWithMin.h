#ifndef QueueWithMin_H
#define QueueWithMin_H

#include"StackWithMin.h"
const int INF=1<<30;

class QueueWithMin
{
private:
	StackWithMin staMinA,staMinB;
public:
	void EnQueue(int);
	int min();
	int DeQueuep();
};

void QueueWithMin::EnQueue(int key)
{
	staMinA.push(key);
}

int QueueWithMin::DeQueuep()
{
	if(staMinB.empty())
	{
		while(!staMinA.empty())
		{
			staMinB.push(staMinA.top());
			staMinA.pop();
		}
		if(staMinB.empty())
			throw new exception("╤сапря©у!");
	}
	int ret=staMinB.top();
	staMinB.pop();
	return ret;
}

int QueueWithMin::min()
{
	int retAMIn=INF,retBMIn=INF;
	if(!staMinA.empty())
	   retAMIn=staMinA.min();
	if(!staMinB.empty())
	retBMIn=staMinB.min();
	return retAMIn<retBMIn?retAMIn:retBMIn;
}

#endif QueueWithMin_H