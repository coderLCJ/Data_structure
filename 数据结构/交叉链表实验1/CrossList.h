#ifndef CROSS_LIST_H
#define CROSS_LIST_H
#include"CrossNode.h"
#include<iostream>
#include<iomanip>

template <typename ElemType>
class CrossList
{
protected:
	int rows,cols,num;
	CrossNode<ElemType> **rowHead,**colHead;

public:
	CrossList();   //Ĭ�Ϲ���һ���վ��󣬼���Ϊ�㣬��Ϊ��
    CrossList(int _rows,int _cols);   //����һ����Ϊ_rows,��Ϊ_cols�Ŀ�ϡ�����
	CrossList(int _rows,int _cols,int _num,const Triple<ElemType> *tris); 
	~CrossList();
	void Clear();
	int SetElem(int row,int col,const ElemType &v);  //row,col����0��ʼ����,����״̬
	int GetELem(int row,int col,ElemType &v);
	template <typename ElemType>
	friend ostream & operator<<(ostream &out,CrossList<ElemType> &crosslist);
};

template <typename ElemType>
CrossList<ElemType>::CrossList():rows(0),cols(0),num(0),rowHead(NULL),colHead(NULL)
{
}

template <typename ElemType>
CrossList<ElemType>::CrossList(int _rows,int _cols)
{
	rows=_rows;
	cols=_cols;
	num=0;
	rowHead=new CrossNode<ElemType>*[rows];
	colHead=new CrossNode<ElemType>*[cols];
	for(int i=0;i<rows;i++)
		rowHead[i]=NULL;
	for(int i=0;i<cols;i++)
		colHead[i]=NULL;
}

template <typename ElemType>
CrossList<ElemType>::CrossList(int _rows,int _cols,int _num,const Triple<ElemType> *tris)
{
	rows=_rows;
	cols=_cols;
	num=0;
	int i;
	rowHead=new CrossNode<ElemType>*[rows];
	colHead=new CrossNode<ElemType>*[cols];
	for(i=0;i<rows;i++)
		rowHead[i]=NULL;
	for(i=0;i<cols;i++)
		colHead[i]=NULL;
	for(i=0;i<_num;i++)
		SetElem(tris[i].row,tris[i].col,tris[i].value);
	
}

template <typename ElemType>
CrossList<ElemType>::~CrossList()
{
	Clear();
	if(rowHead!=NULL)
		delete[] rowHead;
	if(colHead!=NULL)
		delete[] colHead;
}

template <typename ElemType>
void CrossList<ElemType>::Clear()
{
	num=0;
	if(colHead!=NULL)
		for(int i=0;i<cols;i++)
			colHead[i]=NULL;
	if(rowHead!=NULL)
	{
		for(int i=0;i<rows;i++)
			if(rowHead[i]!=NULL)
			{
				CrossNode<ElemType> *p=rowHead[i];
				while(p)
				{
					rowHead[i]=p->right;
					delete p;
					p=rowHead[i];
				}
			}
	}
			
}

template <typename ElemType>
int CrossList<ElemType>::SetElem(int row,int col,const ElemType &v)
{
     if (v==0)
     {
			CrossNode<ElemType> *p=rowHead[row],*pre=NULL;
			while (p!=NULL&&p->triElem.col<col)   //p!=NULL���ų�����Ϊ�ջ�setElem��col���ڴ��з���Ԫ���������
			{
				pre=p;
				p=p->right;
			}
			if (p!=NULL&&p->triElem.col==col)   //p!=NULL���ų�����Ϊ�ջ�setElem��col���ڴ��з���Ԫ���������
			{
				if (p==rowHead[row])    //��row�е�һ������Ԫ�ؾ�ΪҪ�����Ԫ�أ���else������һ��������pre��������Ҫ�ֿ�
	                 rowHead[row]=p->right;
				else
				     pre->right=p->right;    //��������������������������������
				if (colHead[col]==p)
		             colHead[col]=p->down;
				else
				{
					pre=colHead[col];
					while (pre->down!=p)
						pre=pre->down;
					pre->down=p->down;   //��������������
				}
				delete p;
				num--;
			}
     } 
     else
     {
			CrossNode<ElemType> *p=rowHead[row],*pre=NULL;
			while (p!=NULL&&p->triElem.col<col)
			{
				pre=p;
				p=p->right;
			}
			if (p!=NULL&&p->triElem.col==col)   //�ýڵ���ڣ�ֻ���޸���ֵ
			{
				p->triElem.value=v;
			}
			else    //�ڵ㲻���ڣ������ӽڵ�
			{
				Triple<ElemType> tri(row,col,v);
				CrossNode<ElemType> *ePtr=new CrossNode<ElemType>(tri);
				if(rowHead[row]==p)   //rowHead[row]==NULL����Ҫ���ӵĽڵ����С�ڸ��е�һ������Ԫ����
					rowHead[row]=ePtr;
				else
					pre->right=ePtr;
				ePtr->right=p;
				p=colHead[col];
				pre=NULL;
				while (p!=NULL&&p->triElem.row<row)
				{
					pre=p;
					p=p->down;
				}
				if (colHead[col]==p)
                     colHead[col]=ePtr;
				else
					pre->down=ePtr;
				ePtr->down=p;
				num++;
			}
     }
	 return 1;   //���سɹ�
}

template <typename ElemType>
int CrossList<ElemType>::GetELem(int row,int col,ElemType &v)
{
        if(row>=rows||col>=cols||row<0||col<0)
			return 0;   //����ʧ��
		CrossNode<ElemType> *p=rowHead[row];
		while(p!=NULL&&p->triElem.col<col)
            p=p->right;
		if(p!=NULL&&p->triElem.col==col)
			v=p->triElem.value;
		else
			v=0;
		return 1;   //���سɹ�
}

template <typename ElemType>
ostream & operator<<(ostream &out,CrossList<ElemType> &crosslist)
{
	ElemType e;
	for (int i=0;i<crosslist.rows;i++)
	{
		cout<<"[  ";
		for (int j=0;j<crosslist.cols;j++)
		{
			crosslist.GetELem(i,j,e);
			cout<<left<<setw(3)<<e;
		}
		cout<<"]"<<endl;
	}
	return out;
}
#endif