#include<bits/stdc++.h>
#define MAX  10000
using namespace std;
int arc[666][666];
int n,m,s=0;
struct vedge{
      int fromv;
      int endv;
      int weight;
};
vedge elist[666];
bool cmp(vedge p1,vedge p2){
     if(p1.weight!=p2.weight)
        return p1.weight<p2.weight;
}
void sortedge(){
      int k=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arc[i][j]<=MAX){
               elist[k].fromv=i;
               elist[k].endv=j;
               elist[k].weight=arc[i][j];
               k++;
            }
        }
      }
     // cout<<k;
      sort(elist,elist+k,cmp);
}
void kruskal(){
      sortedge();
      int vset[n];
      for(int i=0;i<n;i++)
          vset[i]=i;
      int k=0,j=0;
      while(k!=n-1){
          int m=elist[j].fromv;
          int l=elist[j].endv;
          int sn1=vset[m],sn2=vset[l];
          if(sn1!=sn2){
              //cout<<'V'<<m+1<<"->V"<<l+1<<endl;
              //for(int i=0;i<n;i++)
               // cout<<vset[i]<<' ';
              //cout<<endl;
              s+=arc[m][l];
              k++;
              for(int i=0;i<n;i++){
                if(vset[i]==sn2){
                   vset[i]=sn1;
                }
              }
          }
          j++;
      }
}
int main(){
      int i,j,q;
      cin>>n>>m;
      for(int i=0;i<n;i++)
      memset(arc[i],1,sizeof(arc[i]));
      while(m--){
          cin>>i>>j>>q;
          arc[i-1][j-1]=q;
      }
      kruskal();
      cout<<s;
}
