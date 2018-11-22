#include<bits/stdc++.h>
#define MAX 16843009
#define MAXSIZE 666
using namespace std;
int arcs[MAXSIZE][MAXSIZE];
int findmin(int disk[],bool S[],int n)
{
    int k=0,min=MAX;
    for(int i=0; i<n; i++)
    {
        if(!S[i]&&disk[i]<min)
        {
            min=disk[i];
            k=i;
        }
    }
    if(min==MAX)
        return -1;
    return k;
}
void print(int d[],int p[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<'V'<<i<<":";
        d[i]==MAX?cout<<"MAX\t{V"<<i<<',':cout<<d[i]<<"\t{V"<<i<<',';
        int pre=p[i];
        while(pre!=-1)
        {
            cout<<'V'<<pre;
            pre=p[pre];
            cout<<',';
        }
        cout<<"}"<<endl;
    }
    cout<<endl;
}
void Dijkstra(int v,int n)     //v为出发点
{
    bool S[MAXSIZE]= {false};
    int disk[n],path[n];
    for(int i=0; i<n; i++)
    {
        disk[i]=arcs[v][i];
        if(disk[i]!=MAX)
            path[i]=v;
        else
            path[i]=-1;  //无前驱
    }
    // for(int i=0;i<n;i++) cout<<path[i]<<' ';cout<<endl;
    S[v]=true;
    disk[v]=0;
    for(int i=0; i<n; i++)
    {
        v=findmin(disk,S,n);
        if(v==-1)
        {
            print(disk,path,n);
            return;
        }
        //cout<<v<<endl;
        S[v]=true;
        for(int j=0; j<n; j++)
        {
            //cout<<arcs[v][j]+disk[v]<<disk[j]<<endl;
            if(!S[j]&&(arcs[v][j]+disk[v]<disk[j]))
            {
                disk[j]=arcs[v][j]+disk[v];
                path[j]=v;

            }
        }
        //for(int i=0;i<n;i++) cout<<disk[i]<<' ';cout<<endl;
    }
}
int main()
{
    int i,j,d,n,m;
    while(cin>>n>>m)
    {
        memset(arcs,1,sizeof(arcs));
        while(m--)
        {
            cin>>i>>j>>d;
            arcs[i][j]=d;
        }
        Dijkstra(0,n);

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
*/
