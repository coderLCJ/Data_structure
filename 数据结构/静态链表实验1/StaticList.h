#ifndef STATIC_LIST_H   //��̬����
#define STATIC_LIST_H
#include"Node.h"
#include<iostream>
using std::cout;
#define DEFAULT_SIZE 30
template<typename ElemType>
class StaticList
{
protected:
	int head;
	int avail;
	int length;
	Node<ElemType> *sll;

public:
	StaticList(int size);
	~StaticList();
	int InsertElem(const ElemType &e);
	int InsertElem(int i,const ElemType &e);
	void Traverse();
	int DeleteElem(int i);//��ɾ��Ԫ�ش�����
};

template<typename ElemType>
StaticList<ElemType>::StaticList(int size=DEFAULT_SIZE)
{
	sll=new Node<ElemType>[size];
	for(int i=1;i<size-1;i++)
		sll[i].next=i+1;
	sll[0].next=-1;
	sll[size-1].next=-1;
	head=0;
	avail=1;
	length=0;
}
template<typename ElemType>
StaticList<ElemType>::~StaticList()
{
	if(sll!=NULL)
	    delete[] sll;
}
template<typename ElemType>
int StaticList<ElemType>::InsertElem(const ElemType &e)  //�ڱ�ͷ����Ԫ��
{
	if(avail==-1)
		return 0;    //�ռ�����������ʧ��
	int i=avail;
	avail=sll[avail].next;
	sll[i].data=e;
	sll[i].next=sll[head].next;
	sll[head].next=i;
	length++;
	return 1;
}
template<typename ElemType>
int  StaticList<ElemType>::InsertElem(int i,const ElemType &e)  //��ָ��λ�ò���Ԫ��
{
	if(i<1||i>length+1)
		 return 0;   //����ʧ��
	 if(avail==-1)
		 return 0;    //�ռ�����������ʧ��
	 int p=head,k=avail;
	 for(int j=0;j<i-1;j++)
		  p=sll[p].next;
     avail=sll[avail].next;
	 sll[k].data=e;
	 sll[k].next=sll[p].next;
	 sll[p].next=k;
	 length++;
	     return 1;   //���سɹ�
}
template<typename ElemType>
void StaticList<ElemType>::Traverse()
{
	int p=head;
	while(sll[p].next!=-1)
	{
		cout<<sll[sll[p].next].data;
		p=sll[p].next;
	}
}
template<typename ElemType>
int StaticList<ElemType>::DeleteElem(int i)
{
	if(i<1||i>length)
		return 0;  //����ʧ��
	int p=head,k=avail;
    for(int j=0;j<i-1;j++)
		  p=sll[p].next;
	avail=sll[p].next;
    sll[p].next=sll[avail].next;
	sll[avail].next=k;

}
#endif
