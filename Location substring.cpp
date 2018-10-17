#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,b;
    while(cin>>a>>b){
       int flag=1;
       for(int i=0,P=b.length(),L=a.length()-b.length();i<=L;i++){
           if(a.substr(i,P)==b){
                cout<<i+1<<endl;
                flag=0;
                break;
           }
       }
       if(flag)
          cout<<0<<endl;
    }
}
