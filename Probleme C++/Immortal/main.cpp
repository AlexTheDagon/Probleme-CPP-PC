#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define NM 22
using namespace std;
ifstream in("immortal.in");
ofstream out("immortal.out");
struct point
{
    int x1,y1,x2,y2;
};
int vi[]={0,0,1,-1};
int vj[]={1,-1,0,0};
int si[]={0,0,2,-2};
int sj[]={2,-2,0,0};
int n,m,nri,sem;
bool inside(int i,int j)
{
    return(i>0 && i<=n && j>0 && j<=m);
}
point sol[NM],poz[NM];
int im[NM][NM];
void back(int ramas)
{
    if(ramas==1)
    {
        sem=1;
        return;
    }
    int ii,jj,is,js,x,y;
    for(int i=nri;i>0;--i)
    {
        if(im[poz[i].x1][poz[i].y1])
        {
            x=poz[i].x1;
            y=poz[i].y1;
            for(int d=0;d<4;++d)
            {
                ii=x+vi[d];
                jj=y+vj[d];
                is=x+si[d];
                js=y+sj[d];
                if(inside(is,js) && im[ii][jj] && !im[is][js])
                {
                    poz[i]={is,js,0,0};
                    im[ii][jj]=0;
                    im[x][y]=0;
                    im[is][js]=1;
                    back(ramas-1);
                    if(sem)
                    {
                        sol[ramas]={x,y,is,js};
                        return;
                    }
                    poz[i]={x,y,0,0};
                    im[ii][jj]=1;
                    im[x][y]=1;
                    im[is][js]=0;
                }
            }
        }
    }
}
int a,b;
int main()
{
    in>>n>>m>>nri;
    for(int i=1;i<=nri;++i)
    {
        in>>a>>b;
        im[a][b]=1;
        poz[i]={a,b,0,0};
    }
    back(nri);
    for(int i=nri;i>1;--i)
        out<<sol[i].x1<<" "<<sol[i].y1<<" "<<sol[i].x2<<" "<<sol[i].y2<<'\n';
    out.close();
    return 0;
}
