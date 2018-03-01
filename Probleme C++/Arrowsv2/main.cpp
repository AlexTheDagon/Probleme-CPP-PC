#include <iostream>
#include <fstream>
#define NM 505
using namespace std;
ifstream in("arrows.in");
ofstream out("arrows.out");
int a[NM][NM],n,m,viz[NM][NM];
int dx[]={0,0,-1,0,1};
int dy[]={0,1,0,-1,0};
int caz,lc[NM][NM],tip,xx,yy,maxx,nrf,lng,k=2;
int inside(int i,int j)
{
    return(i>0 && i<=n && j>0 && j<=m);
}
int dfs(int l,int c,int ind)
{
    if(viz[l][c])
    {
        tip=viz[l][c];
        lng+=lc[l][c];
        if(tip==1 || tip!=ind)return lc[l][c]+1;
        return lng;
    }
    if(!inside(l,c))
    {
        tip=1;
        return 1;
    }
    int d=a[l][c];
    viz[l][c]=ind;
    ++lng;
    lc[l][c]=dfs(l+dx[d],c+dy[d],ind);
    if(tip<2)viz[l][c]=tip;
    if(tip==1 || tip!=ind)return lc[l][c]+1;
    return lng;

}
int main()
{
    in>>caz;
    in>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(!viz[i][j])
            {
                lng=0;
                dfs(i,j,++k);
            }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(viz[i][j]!=1)lc[i][j]*=1000;
    if(caz==1)
    {
        in>>xx>>yy;
        out<<lc[xx][yy];
    }
    if(caz==2)
    {
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                if(viz[i][j]>1)++nrf;
        out<<nrf;
    }
    if(caz==3)
    {
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                maxx=max(maxx,lc[i][j]);
        out<<maxx<<'\n';
    }
    return 0;
}
