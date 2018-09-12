#include <bits/stdc++.h>
using namespace std;
int n,a[2000],k=0,sum=0;
string jie[20000];
void print()
{
    for(int i=0;i<8;i++)
      jie[k]+=char(a[i]+'0');
    sum++;
    k++;
}
int jc(int step)
{
    for(int i=0;i<step;i++)
    {
        if(a[i]==a[step]||abs(a[i]-a[step])==abs(i-step))
            return 0;
    }
    return 1;
}
void queen(int step)
{
    for(int i=0;i<8;i++)
    {
       a[step]=i;
       if(jc(step))
       {
          if(step==7)
             print();
          else
             queen(step+1);
       }
    }
}
int main()
{ 
    queen(0);
    for(int i=0;i<k;i++)
      cout<<jie[i]<<endl;
}
