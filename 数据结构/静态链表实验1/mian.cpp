#include"StaticList.h"
#include<iostream>
using namespace std;
int main()
{
	StaticList<char> sl;
	sl.InsertElem('A');
	sl.InsertElem('B');
	sl.InsertElem('C');
	sl.InsertElem(3,'D');
	sl.Traverse();
	cout<<endl;
	sl.DeleteElem(1);
	sl.Traverse();
	return 0;
}
