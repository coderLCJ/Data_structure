#include"TriSparseMatrix.h"

int main()
{
    int rows,cols,num;
	cout<<"���������������������Լ�����Ԫ����:";
	cin>>rows>>cols>>num;
	TriSparseMatrix<int> Mat(rows,cols,num),mat2;
	Mat.FastTranspose(mat2);
	cout<<Mat<<endl;
	cout<<mat2;
	return 0;
}