#include<iostream>
using namespace std;
template < class T >
struct Node{
      T date;
      struct Node *next;
};
template < class T >
class Linklist{
public:
      Linklist(){
        front=new Node<T>;
        front->next=NULL;
      }
      Linklist(T a[],int n);
      ~Linklist();
      void Printlist();
      int Getlength();
      Node<T> *Get(int i);
      int Locate(T x);
      void Insert(int i,T x);
      T Delete(int i);
private:
      Node<T> *front;
      int length=0;
};
template < class T >
Linklist< T >::Linklist(T a[],int n){    //头插法
      front =new Node<T>;
      front->next=NULL;
      for(int i=n-1;i>=0;i--){
          Node<T> *s=new Node<T>;
          s->date=a[i];
          s->next=front->next;
          front->next=s;
      }
      length=n;
}
template < class T >
Linklist<T>::~Linklist(){
      Node<T> *p=front;
      while(p){
        front=p;
        p=p->next;
        delete front;
      }
      cout<<"析构函数运行完成"<<endl;
}
template < class T >
int Linklist< T >::Getlength(){
      return length;
}
template < class T >
void Linklist< T >::Printlist(){
    cout<<"遍历链表中的所有元素:"<<endl;
     Node<T> *p=front->next;
     while(p){
        cout<<p->date<<' ';
        p=p->next;
     }
     cout<<endl;
}
template < class T >
void Linklist< T >::Insert(int i,T x){
     Node<T> *p=front->next;
     if(i!=1)
        p=Get(i-1);
     if(p){
        Node<T> *s=new Node<T>;
        s->date=x;
        s->next=p->next;
        p->next=s;
        length++;
     }
     else
        throw "error";
}
template < class T >
T Linklist< T >::Delete(int i){
     Node<T> *p=front->next;
     if(i!=1)
        p=Get(i-1);
     if(!p&&!p->next)
        throw "error";
     Node<T> *q=p->next;
     p->next=q->next;
     T x=q->date;
     delete q;
     length--;
     return x;
}
template < class T >
Node<T>* Linklist< T >::Get(int i){
     Node<T> *p=front->next;
     int j=1;
     while(p&&j!=i){
         p=p->next;
         j++;
     }
     return p;
}
template < class T >
int Linklist< T >::Locate(T x){
     Node<T> *p=front->next;
     int j=1;
     while(p){
         if(p->date==x)
            return j;
         p=p->next;
         j++;
     }
     return -1;
}
int main(){
      int a[]={1,2,3,4,5,6,7,8,9,10};
      Linklist<int> list(a,10);
      list.Printlist();
      cout<<"链表长度"<<endl;
      cout<<list.Getlength()<<endl;
      cout<<"元素2的地址"<<endl;
      cout<<list.Get(2)<<endl;
      cout<<"元素6的位置"<<endl;
      cout<<list.Locate(6)<<endl;
      cout<<"位置5插入元素-1"<<endl;
      list.Insert(5,-1);
      list.Printlist();
      cout<<"删除位置10的元素"<<endl;
      list.Delete(10);
      list.Printlist();
}
