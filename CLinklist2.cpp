#include<iostream>
using namespace std;
struct Node{
      int date;
      struct Node *next;
};
class CLinklist{
public:
      CLinklist(int a[],int n);
      void  insert(int i,int e);
      void Delete(int i);
      Node *get(int i);
      ~CLinklist();
      void Printlist();
private:
      Node *rear;
      int length=0;
};
CLinklist::CLinklist(int a[],int n){        //尾插法建立循环链表
      rear =new Node;
      Node *r=rear;                         //建立尾指针
      for(int i=0;i<n;i++){
          Node *s=new Node;                 //（1）建立新结点
          s->date=a[i];                     //（2）将a[i]写入新结点的数据域
          r->next=s;                        //（3）将新结点加入到链表
          r=s;                              //（4）修改尾指针
      }
      r->next=rear;                         //将终端结点的指针域指向头结点
      length=n;
}
void CLinklist::insert(int i,int e){
      Node *p=rear->next;
      if(i!=1){
         p=get(i-1);
      }
      Node *s=new Node;
      s->date=e;
      s->next=p->next;
      p->next=s;
      length++;
}
void CLinklist::Delete(int i){
      Node *p=rear;
      if(i!=1){
         p=get(i-1);
      }
      Node *q=p->next;
      p->next=q->next;
      delete q;
      length--;
}
Node *CLinklist::get(int i){
      Node *p=rear->next;
      int j=1;
      while(j<=length&&j!=i){
         p=p->next;
         j++;
     }
     return p;
}
CLinklist::~CLinklist(){
      Node *k,*p=rear->next;
      while(p!=rear){
            k=p;
            p=p->next;
            delete k;
      }
      delete p;                                 //此时指针指向尾结点，释放最后一个结点
}
void CLinklist::Printlist(){
     int j=0;
     Node *p=rear;
     while(j++<length-1){
        cout<<p->next->date<<' ';
        p=p->next;
     }
     if(length!=0)
     cout<<p->next->date;
     cout<<endl;
}
int main(){
     int a[0];
     CLinklist list(a,0);
     int n;
     while(cin>>n){
         if(n==0){
            list.Printlist();
         }
         else if(n==1){
            int i,e;
            cin>>i>>e;
            list.insert(i,e);
         }
         else{
            int i;
            cin>>i;
            list.Delete(i);
         }
     }
}
