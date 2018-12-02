#include<bits/stdc++.h>
using namespace std;
int arcs[1001][1001],n;
int visted[1001]={0};
queue<int> q;
void bfs(int v){
     visted[v]=1;
     cout<<v<<' ';
     q.push(v);
     while(q.size()!=0){
           v=q.front();
           q.pop();
           for(int i=0;i<n;i++){
            if(arcs[v][i]==1&&!visted[i]){
                cout<<i<<' ';
                visted[i]=1;
                q.push(i);
            }
           }
     }
}
int main(){
    int m,f,e;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
             cin>>arcs[i][j];
    bfs(0);
    printf("\n");
}

