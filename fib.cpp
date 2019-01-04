#include <bits/stdc++.h>
using namespace std;
const int MAX=10000;
void s2(int A[2][2]){
    int a=A[0][0],b=A[0][1],c=A[1][0],d=A[1][1];
    A[0][0]=(a*a%MAX+b*c%MAX)%MAX;
    A[0][1]=(a*b%MAX+b*d%MAX)%MAX;
    A[1][0]=(a*c%MAX+d*c%MAX)%MAX;
    A[1][1]=(b*c%MAX+d*d%MAX)%MAX;

}
void s1(int A[2][2],int B[2][2]){
    int a=B[0][0],b=B[0][1],c=B[1][0],d=B[1][1];
    B[0][0]=(a*A[0][0]%MAX+b*A[1][0]%MAX)%MAX;
    B[0][1]=(a*A[0][1]%MAX+b*A[1][1]%MAX)%MAX;
    B[1][0]=(c*A[0][0]%MAX+d*A[1][0]%MAX)%MAX;
    B[1][1]=(c*A[0][1]%MAX+d*A[1][1]%MAX)%MAX;
}
void fib(int A[2][2],int B[2][2],int k){
    while(k){
        if(k&1!=0)
           s1(A,B);
        s2(A);
        k>>=1;
    }
    printf("%d\n",B[0][0]);
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n!=-1){
        int A[2][2]={1,1,1,0};
        int B[2][2]={1,0,0,1};
        if(n==0)
            printf("0\n");
        else if(n==1||n==2)
            printf("1\n");
        else
            fib(A,B,n-1);
    }
}

