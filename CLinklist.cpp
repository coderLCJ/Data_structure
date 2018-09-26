#include<iostream>
using namespace std;
template < class T >
struct Node{
      T date;
      struct Node *next;
};
template < class T >
class CLinklist{
public:
      CLinklist(){
        rear=new Node<T>;
        rear->next=rear;
      }
      CLinklist(T a[],int n);
      void Connect(CLinklist<T> &b);
      ~CLinklist();
      void Printlist();
private:
      Node<T> *rear;
      int length=0;
};
template < class T >
CLinklist< T >::CLinklist(T a[],int n){        //尾插法建立单链表
      rear =new Node<T>;
      Node<T> *r=rear;                         //建立尾指针
      for(int i=0;i<n;i++){
          Node<T> *s=new Node<T>;              //（1）建立新结点
          s->date=a[i];                        //（2）将a[i]写入新结点的数据域
          r->next=s;                           //（3）将新结点加入到链表
          r=s;                                 //（4）修改尾指针
      }
      r->next=rear;                            //将终端结点的指针域指向头结点
      rear=r;                                  //将rear指针指向尾结点
      length=n;
}
template < class T >
CLinklist<T>::~CLinklist(){
      Node<T> *k,*p=rear->next;
      while(p!=rear){
            k=p;
            cout<<p->date<<' ';                 //显示释放结点的数据，便于查看是析构函数是否完整
            p=p->next;
            delete k;
      }
      cout<<p->date<<' ';
      delete p;                                 //此时指针指向尾结点，释放最后一个结点
      cout<<"析构函数运行完成"<<endl;
}
template < class T >
void CLinklist< T >::Printlist(){
     cout<<"遍历链表中的所有元素:"<<endl;
     if(rear==rear->next){
        cout<<"void"<<endl;
        return;
      }
     Node<T> *p=rear->next;
     while(p!=rear){
        cout<<p->next->date<<' ';
        p=p->next;
     }
     cout<<endl;
}
template < class T >
void CLinklist< T >::Connect(CLinklist<T> &b){
     if(b.rear==b.rear->next)       //若b为空链表，则不需要链接
        return ;
     Node<T> *q=b.rear->next;       //保存b链表的表头地址
     b.rear->next=rear->next;       //b链表表尾元素的指针域指向当前链表的表头
     rear->next=q->next;            //当前链表表尾元素的指针域指向b链表的起始元素
     rear=b.rear;                   //链接完成，修改新链表的表尾指针
     b.rear=q->next=q;              //将b链表置为空循环链表
}
int main(){
      int a[]={1,2,3,4,5,6};
      int b[]={7,8,9,10};
      CLinklist<int> list1(a,6);
      list1.Printlist();
      CLinklist<int> list2(b,4);
      list2.Printlist();
      list1.Connect(list2);
      list1.Printlist();
      list2.Printlist();
}
