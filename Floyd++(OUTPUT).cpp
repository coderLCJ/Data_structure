#include<bits/stdc++.h>
#define MAX 16843009
#define MAXSIZE 666
using namespace std;
int arcs[MAXSIZE][MAXSIZE],path[MAXSIZE][MAXSIZE];
void output(int i,int j){
    //if(i==j) return;
     if(path[i][j]==0) cout<<"->"<<j+1;
     else{
         output(i,path[i][j]);
         output(path[i][j],j);
     }
}
void floyd(int n){
    int dist[n][n];
    for(int i=0;i<n;i++)
    arcs[i][i]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=arcs[i][j];
               path[i][j]=0;
        }
    }
    for(int k=0;k<n;k++){
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                        //cout<<"k="<<k+1<<"   "<<"i="<<i+1<<"   j="<<j+1<<endl;
                       // cout<<dist[i][k]+dist[k][j]<<" < "<<dist[i][j]<<endl;
                   dist[i][j]=dist[i][k]+dist[k][j];
                   path[i][j]=k;
                  //for(int i=0;i<4;i++){for(int j=0;j<4;j++)cout<<path[i][j]<<' '; cout<<endl;}

                }
            }
        }
    }
     //for(int i=0;i<4;i++){for(int j=0;j<4;j++)cout<<path[i][j]<<' '; cout<<endl;}
    cout<<dist[0][n-1]<<endl;
    cout<<1;
    output(0,n-1);
    cout<<endl;
}
int main()
{
    int i,j,n,m,d;
    while(cin>>n>>m&&(n!=0||m!=0)){
    memset(arcs,1,sizeof(arcs));
    while(m--)
    {
        cin>>i>>j>>d;
        arcs[i-1][j-1]=d;
        arcs[j-1][i-1]=d;
    }
    floyd(n);
    }
}
/*
9 3
1 8 2
8 6 1
6 9 1
9 3
1 6 2
6 8 1
8 9 1

4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
*/
