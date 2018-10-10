#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template<class T>
struct DNode{
      T date;
      DNode<T> * prior;
      DNode<T> * next;
};
template<class T>
class List{
public:
      List(){
          front=new DNode<T>;
          front->next=front;
          front->prior=front;
      }
      List(T a[],int n){
          front=new DNode<T>;
          DNode<T> *r=front;
          front->next=front;
          front->prior=front;
          DNode<T> *t=front;
          for(int i=n-1;i>=0;i--){
              DNode<T> * s=new DNode<T>;
              s->date=a[i];
              s->next=front->next;
              s->prior=r;
              r=s;
              front->next=s;

          }
          r->prior=t;
      }
      void put(){
          DNode<T> *p=front->next;
          while(p->next!=front){
              cout<<p->date<<' ';
              p=p->next;
          }
          cout<<p->date<<endl;

      }
      void put1(){
          int t=0;
          DNode<T> *p=front->prior;
          while(t++<10){
              cout<<p->date<<' ';
              p=p->prior;
          }

      }
private:
      DNode<T> * front;
};
int main(){
      int a[10]={1,2,3,4,5,6,7,8,9,0};

      List<int> list1(a,10);
      list1.put();
      list1.put1();
}
