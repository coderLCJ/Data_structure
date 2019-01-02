
#include"Generalized.h"

void TestGeneralized()
{
	Generalized l("(a,b,(c,d),(e,(f),h))");
	Generalized l1;
	l1 = l;
	l.Print();
	cout << endl;
	cout << "size:" << l.Size() << endl;
	cout << "depth:" << l.Depth() << endl;

	l1.Print();
	cout << endl;
	cout << "size:" << l1.Size() << endl;
	cout << "depth:" << l1.Depth() << endl;
}
int main()
{
	TestGeneralized();
	getchar();
	return 0;
}

