#include<iostream>
using std::cout;
using std::endl;

void Hanoi(int n,char src,char dest,char tran)
{
	if(n==1)
	{	
		cout<<"��"<<1<<"�Ƶ�"<<dest<<" ";
	    return ;
	}
	Hanoi(n-1,src,tran,dest);
	cout<<"��"<<n<<"�Ƶ�"<<dest<<" ";
	Hanoi(n-1,tran,dest,src);
}

int main()
{
	Hanoi(4,'A','C','B');
	return 0;
}