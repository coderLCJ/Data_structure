#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
//结点类型
enum Type
{
	HEAD,//头结点
	VALUE,//数据
	SUB,//子表
};

//广义表结构
struct GeneralizedNode
{
public:
	//无参构造函数
	GeneralizedNode()
		:_type(HEAD)
		,_next(NULL)
	{}

	//有参的构造函数
	GeneralizedNode(Type type, char ch);
	
public:
	Type _type;
	GeneralizedNode* _next;

	union
	{
		char _value;//数据结点
		GeneralizedNode* _subLink;//子表结点
	};
};

GeneralizedNode::GeneralizedNode(Type type, char ch = 0)
	:_type(type)
	, _next(NULL)
{
	if (_type == VALUE)
	{
		_value = ch;
	}
	else if (_type == SUB)
	{
		_subLink = NULL;
	}
}

//广义表类
class Generalized
{
public:
	//无参构造函数
	Generalized()
		:_head(NULL)
	{}
	//有参构造函数
	Generalized(const char* str)
		:_head(NULL)
	{
		_head = CreateList(str);
	}

	//拷贝构造函数
	Generalized(const Generalized& g)
	{
		_head=_CopyList(g._head);
	}
	GeneralizedNode* _CopyList(GeneralizedNode* head);
	//赋值运算符的重载
	Generalized& operator=(Generalized g)
	{
		swap(_head, g._head);
		return *this;
	}

	//析构函数
	~Generalized()
	{
		_Delete(_head);
	}
	void _Delete(GeneralizedNode* head);
public:
	void Print()
	{
		_Print(_head);
	}
	size_t Size()
	{
		return _Size(_head);
	}
	size_t Depth()
	{
		return _Depth(_head);
	}

protected:
	//判断数据是否有效
	bool IsVaild(const char ch);
	//创建广义表
	GeneralizedNode* CreateList(const char* &str);
	void _Print(GeneralizedNode* head);
	size_t _Size(GeneralizedNode* head);
	size_t _Depth(GeneralizedNode* head);
private:
	GeneralizedNode* _head;
};

GeneralizedNode* Generalized::_CopyList(GeneralizedNode* head)
{
	GeneralizedNode* cur = head;
	GeneralizedNode* _head = new GeneralizedNode();//创建头结点
	GeneralizedNode* index = _head;
	while (cur)
	{
		if (cur->_type == VALUE)
		{
			index->_next = new GeneralizedNode(VALUE, cur->_value);
			index = index->_next;
		}
		else if (cur->_type == SUB)
			{
				GeneralizedNode*SubNode = new GeneralizedNode(SUB);
				index->_next = SubNode;
				SubNode->_subLink= _CopyList(cur->_subLink);
				index = index->_next;
			}
		cur = cur->_next;
	}
	return _head;
}

void Generalized::_Delete(GeneralizedNode* head)
{
	GeneralizedNode* cur = head;
	while (cur)
	{
		GeneralizedNode* del = cur;
		if (cur->_type == SUB)
		{
			_Delete(cur->_subLink);
		}
		cur = cur->_next;
		delete del;
	}
}

bool Generalized::IsVaild(const char ch)
{
	if ((ch >= '0'&&ch <= '9')
		|| (ch >= 'a'&&ch <= 'z')
		|| (ch >= 'A'&&ch <= 'Z'))
	{
		return true;
	}
	return false;
}

GeneralizedNode* Generalized::CreateList(const char* &str)
{
	assert(str &&*str == '(');//断言防止传的广义表格式不对，或者为空
	str++;//跳过第一个(

	GeneralizedNode* head = new GeneralizedNode();//创建头结点
	GeneralizedNode* cur = head;
	while (*str)
	{
		if (IsVaild(*str))
		{


			cur->_next = new GeneralizedNode(VALUE, *str);
			cur = cur->_next;
			str++;
		}
		else if (*str == '(')//新的子表
		{
			GeneralizedNode* SubNode = new GeneralizedNode(SUB);
			SubNode->_subLink = CreateList(str);
			cur->_next = SubNode;
			cur = cur->_next;
		}
		else if (*str == ')')//广义表结束
		{
			str++;//返回之前需要给str++指向下一个
			return head;
		}
		else//空格或者逗号
		{
			str++;
		}
	}

	assert(false);
	return NULL;
}

void Generalized::_Print(GeneralizedNode* head)
{
	GeneralizedNode* cur = head;
	if (cur == NULL)
	{
		cout << "()" << endl;
		return;
	}

	while (cur)
	{
		if (cur->_type == HEAD)
		{
			cout << "(";
		}
		else if (cur->_type == VALUE)
		{
			cout << cur->_value;
			//_value不是最后一个值
			if (cur->_next)
			{
				cout << ",";
			}
		}
		else if (cur->_type == SUB)
		{
			_Print(cur->_subLink);
			if (cur->_next)
			{
				cout << ",";
			}
		}
		cur = cur->_next;
	}
	//输出每个表最后一个(
	cout << ")";
}


size_t Generalized::_Size(GeneralizedNode* head)
{
	GeneralizedNode* cur = head;
	size_t count = 0;
	while (cur)
	{
		if (cur->_type == VALUE)
		{
			count++;
		}
		if (cur->_type == SUB)
		{
			count = count + _Size(cur->_subLink);
		}
		cur = cur->_next;
	}
	return count;
}


size_t Generalized::_Depth(GeneralizedNode* head)
{
	GeneralizedNode* cur = head;
	size_t depth = 1;//空表深度为1
	while (cur)
	{
		if (cur->_type == VALUE)
		{
			depth++;
		}
		if (cur->_type == SUB)
		{
			size_t newDepth = _Depth(cur->_subLink);
			if (newDepth > depth)
			{
				depth = newDepth;
			}
		}
		cur = cur->_next;
	}
	return depth;
}
