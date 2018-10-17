#include <bits/stdc++.h>
using namespace std;
static int i;
void move(int n,char a,char c){
     i++;
     printf("%2d. Move disk %d from %c to %c\n",i,n,a,c);
}
void hanoi(int n,char a,char b,char c){
     if(n==1){
        move(n,a,c);
     }
     else{
        hanoi(n-1,a,c,b);
        move(n,a,c);
        hanoi(n-1,b,a,c);
     }
}
int main()
{
    int n;
    while(cin>>n){
        i=0;
        hanoi(n,'X','Y','Z');
        cout<<endl;
    }
}
