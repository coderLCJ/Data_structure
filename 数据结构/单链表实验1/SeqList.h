#ifndef SEQLIST
#define SEQLIST
#include<bits/stdc++.h>
#define DEFAULT_SIZE 100
using namespace std;
template <typename ElemType>
class SeqList
{
public:
	SeqList(int size=DEFAULT_SIZE);   //������һ�������Ŀձ�
	SeqList(ElemType *data,int n,int size);  //�����������鴴�����Ա�,������n>size�����
	~SeqList();
	SeqList(const SeqList &other);  //���
	SeqList & operator=(const SeqList &other); //�ֵ
	bool isEmpty() const;   //�ж��Ƿ�Ϊ�ձ�
	void Clear();   //����б�
	int InsertElem(const ElemType &e);   //��ĩβ����Ԫ��,����״̬
	int InsertElem(int i,const ElemType &e);   //��ָ��λ�ò���Ԫ��,����״̬
	int DeleteElem(int i,ElemType &e);   //ɾ��ָ��λ��Ԫ��,����״̬
	int SetElem(int i,const ElemType &e);   //�޸�ָ��λ�õ�Ԫ��,����״̬
	int GetElem(int i,ElemType &e) const;  //ȡ��ָ��λ�õ�Ԫ�أ�i��1��ʼ,����״̬
    int LocateElem(const ElemType &e) const;  //��λԪ��
	int GetLength() const;  //ȡ�ó���
	void Traverse(void (*visit)(const ElemType &)) const;   //����

protected:
	int length;
	int maxLength;
	ElemType *elems;
};

template <typename ElemType>
SeqList<ElemType>::SeqList(int size)
{
	elems=new ElemType[size];
	length=0;
	maxLength=size;
}

template <typename ElemType>
SeqList<ElemType>::SeqList(ElemType *data,int n,int size=DEFAULT_SIZE)
{
	elems=new ElemType[size];
	maxLength=size;
	length=n;
	for(int i=0;i<n;i++)
		elems[i]=data[i];
}

template <typename ElemType>
SeqList<ElemType>::~SeqList()
{
	if(elems!=NULL)
		delete[] elems;
}

template <typename ElemType>
SeqList<ElemType>::SeqList(const SeqList &other)
{
	elems=NULL;
	*this=other;
}

template <typename ElemType>
SeqList<ElemType> & SeqList<ElemType>::operator=(const SeqList<ElemType> &other)
{
	length=other.length;
	maxLength=other.maxLength;
	if(elems!=NULL)
		delete[] elems;
	elems=new ElemType[maxLength];
	for(int i=0;i<other.length;i++)
		elems[i]=other.elems[i];
	return *this;
}

template <typename ElemType>
bool SeqList<ElemType>::isEmpty() const
{
	if(length==0)
		return true;
	else
		return false;
}

template <typename ElemType>
void SeqList<ElemType>::Clear()
{
	length=0;
}

template <typename ElemType>
int SeqList<ElemType>::InsertElem(const ElemType &e)
{
	if(length==maxLength)
		return 0;
	else
	{
		elems[length]=e;
		length++;
		return 1;
	}
}

template <typename ElemType>
int SeqList<ElemType>::InsertElem(int i,const ElemType &e)
{
	if(length==maxLength)
		return 0;
	else if(i<1||i>length+1)
		return 0;
	else
	{
		for(int j=length;j>=i;j--)
			elems[j]=elems[j-1];
		elems[i-1]=e;
		length++;
		return 1;
	}
}

template <typename ElemType>
int SeqList<ElemType>::DeleteElem(int i,ElemType &e)
{
	if(i<1||i>length)
		return 0;
	else
	{
		e=elems[i-1];
		for(int j=i;j<length;j++)
			elems[j-1]=elems[j];
		length--;
		return 1;
	}
}

template <typename ElemType>
int SeqList<ElemType>::SetElem(int i,const ElemType &e)
{
	if(i<1||i>length)
		return 0;
	else
	{
		elems[i-1]=e;
		return 1;
	}

}

template <typename ElemType>
int SeqList<ElemType>::GetElem(int i,ElemType &e) const
{
	if(i<1||i>length)
		return 0;
	else
	{
		e=elems[i-1];
		return 1;
	}
}

template <typename ElemType>
int SeqList<ElemType>::LocateElem(const ElemType &e) const
{
	for(int i=0;i<length;i++)
	  if(elems[i]==e)
		return ++i;
	return 0;
}

template <typename ElemType>
int SeqList<ElemType>::GetLength() const
{
	return length;
}

template <typename ElemType>
void SeqList<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
	for(int i=0;i<length;i++)
		(*visit)(elems[i]);
}

#endif
