#include<bits/stdc++.h>
#define MAXSIZE 1000
using namespace std;
int adjvex[MAXSIZE],sum=0;
int lowcost[MAXSIZE];
int arcs[MAXSIZE][MAXSIZE],vnum,n,i,j,p;
int mininum();
void prim(){
    for(int i=0;i<vnum;i++){
        lowcost[i]=arcs[0][i];
        adjvex[i]=0;
    }
    lowcost[0]=0;
    for(int i=1;i<vnum;i++){
        int k=mininum();
        //cout<<"V"<<adjvex[k]+1<<"->V"<<k+1<<endl;
        lowcost[k]=0;
        for(int j=0;j<vnum;j++){        //更新辅助数组
            if(lowcost[j]!=0&&arcs[k][j]<lowcost[j]){
                lowcost[j]=arcs[k][j];
                adjvex[j]=k;
            }
        }
        //for(int i=0;i<vnum;i++) cout<<lowcost[i]<<' ';


    }
}
int mininum(){
    int mini=1000,k=0;
    for(int i=1;i<vnum;i++){
        if(lowcost[i]!=0&&lowcost[i]<mini){
             mini=lowcost[i];
             k=i;
        }
    }
    sum+=mini;
    return k;
}
int main()
{
    cin>>vnum>>n;
    memset(arcs,127,sizeof(arcs));
    while(n--){
         cin>>i>>j>>p;
         arcs[i-1][j-1]=p;arcs[j-1][i-1]=p;
    }
    //for(int i=0;i<vnum;i++){
        //for(int j=0;j<vnum;j++) cout<<arcs[i][j]<<' '; cout<<endl;}
    prim();
    cout<<sum;

}
