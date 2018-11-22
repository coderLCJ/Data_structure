#include<bits/stdc++.h>
#define MAX 16843009
#define MAXSIZE 666
using namespace std;
int arcs[MAXSIZE][MAXSIZE];
void floyd(int n){
    int dist[n][n],path[n][n];
    memset(dist,1,sizeof(dist));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=arcs[i][j];
            if(dist[i][j]!=MAX)
                path[i][j]=i;
            else
                path[i][j]=-1;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=k;    //过k到j
                }

            }
        }
    }
    cout<<dist[0][n-1]<<endl;   //0到最后一个顶点的最短路径长度
}
int main()
{
    int i,j,d,n,m;
    while(cin>>n>>m&&(n!=0||m!=0))
    {
        memset(arcs,1,sizeof(arcs));
        while(m--)
        {
            cin>>i>>j>>d;
            arcs[i][j]=d;
        }
        floyd(n);

    }

}
/*
6 8
0 5 100
0 4 30
0 2 10
1 2 5
2 3 50
3 5 10
4 5 60
4 3 20

3 5
0 1 4
0 2 11
1 0 6
1 2 2
2 0 3
*/
