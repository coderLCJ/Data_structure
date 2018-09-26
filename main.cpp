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
CLinklist< T >::CLinklist(T a[],int n){        //β�巨����������
      rear =new Node<T>;
      Node<T> *r=rear;                         //����βָ��
      for(int i=0;i<n;i++){
          Node<T> *s=new Node<T>;              //��1�������½��
          s->date=a[i];                        //��2����a[i]д���½���������
          r->next=s;                           //��3�����½����뵽����
          r=s;                                 //��4���޸�βָ��
      }
      r->next=rear;                            //���ն˽���ָ����ָ��ͷ���
      rear=r;                                  //��rearָ��ָ��β���
      length=n;
}
template < class T >
CLinklist<T>::~CLinklist(){
      Node<T> *k,*p=rear->next;
      while(p!=rear){
            k=p;
            cout<<p->date<<' ';                 //��ʾ�ͷŽ������ݣ����ڲ鿴�����������Ƿ�����
            p=p->next;
            delete k;
      }
      cout<<p->date<<' ';
      delete p;                                 //��ʱָ��ָ��β��㣬�ͷ����һ�����
      cout<<"���������������"<<endl;
}
template < class T >
void CLinklist< T >::Printlist(){
     cout<<"���������е�����Ԫ��:"<<endl;
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
     if(b.rear==b.rear->next)       //��bΪ����������Ҫ����
        return ;
     Node<T> *q=b.rear->next;       //����b����ı�ͷ��ַ
     b.rear->next=rear->next;       //b�����βԪ�ص�ָ����ָ��ǰ����ı�ͷ
     rear->next=q->next;            //��ǰ�����βԪ�ص�ָ����ָ��b�������ʼԪ��
     rear=b.rear;                   //������ɣ��޸�������ı�βָ��
     b.rear=q->next=q;              //��b������Ϊ��ѭ������
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
