#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#define x first
#define y second
using namespace std;
ifstream in("rj.in");
ofstream out("rj.out");
string v;
int dx[]={0,-1,0,1,-1,1,1,-1,},dy[]={-1,0,1,0,1,1,-1,-1};
int n,m,x,y,a[101][101],fi,fj,p,is,js,timp;
int ii,jj,sem=1;
queue <pair <int,int>  > rom,jul;
pair <int,int> fr;
int main()
{
    in>>n>>m;
    getline(in,v);
    for(int i=0;i<n;++i)
    {
        getline(in,v);
        for(int j=0;j<m;++j)
        {
            if(v[j]=='R')is=i+1,js=j+1;
            if(v[j]=='J')fi=i+1,fj=j+1;
            if(v[j]=='X')a[i+1][j+1]=-1;
        }
    }
    a[is][js]=1;
    a[fi][fj]=1;
    rom.push({is,js});
    jul.push({fi,fj});
    while(sem!=0)
    {
        fr=rom.front();
        rom.pop();
        for(int d=0;d<8;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ii>0 && ii<=n && jj>0 && jj<=m && a[ii][jj]==0)
            {
                a[ii][jj]=1;
                rom.push(make_pair(ii,jj));
            }
        }
        fr=jul.front();
        jul.pop();
        for(int d=0;d<8 && sem==1;++d)
        {
            ii=fr.x+dx[d];
            jj=fr.y+dy[d];
            if(ii>0 && ii<=n && jj>0 && jj<=m)
            {
                if(a[ii][jj]==0)
                {
                    a[ii][jj]=1;
                    jul.push(make_pair(ii,jj));
                }
                else sem=0;
            }
        }

    }

    return 0;
}
