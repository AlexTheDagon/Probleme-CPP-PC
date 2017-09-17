#include <iostream>
#include <fstream>
#include <queue>
#define NM 105
#define x first
#define y second
#define mm make_pair
using namespace std;
ifstream in("insule.in");
ofstream out("insule.out");
int n,m,a[NM][NM],nr,l,lmin=1<<30,r,g,b,ii,jj;
char c[NM][NM],init;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
queue <pair<int,int> > q,v;
pair<int,int> fr;
int ok(int i,int j)
{
    return(i<=n && i>0 && j<=m && j>0);
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)in>>c[i][j];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(c[i][j]!='0' && a[i][j]==0)
            {
                init=c[i][j];
                if(init=='1')++r;
                else
                {
                    if(init=='2')++g;
                    else ++b;
                }
                a[i][j]=-1;
                q.push(mm(i,j));
                while(!q.empty())
                {
                    fr=q.front();

                    q.pop();
                    for(int d=0;d<4;++d)
                    {
                        ii=fr.x+dx[d];
                        jj=fr.y+dy[d];
                        if(ok(ii,jj) && a[ii][jj]==0)
                        {
                            if(c[ii][jj]==init)
                            {
                                q.push(mm(ii,jj));
                                a[ii][jj]=-1;
                            }
                            if(c[ii][jj]=='0' && init=='1' && a[ii][jj]==0)
                            {
                                v.push(mm(ii,jj));
                                a[ii][jj]=1;
                            }

                        }
                    }
                }
            }
        }
    }
    out<<r<<" "<<g<<" "<<b;
    while(!v.empty())
    {
        q.push(v.front());
        v.pop();
        while(!q.empty())
        {
            fr=q.front();
            q.pop();
            for(int d=0;d<4;++d)
            {
                ii=fr.x+dx[d];
                jj=fr.y+dy[d];
                if(ok(ii,jj))
                {
                    if(a[ii][jj]==0 || a[ii][jj]>a[fr.x][fr.y]+1)
                    {
                        a[ii][jj]=a[fr.x][fr.y]+1;
                        q.push(mm(ii,jj));
                    }
                    else if(c[ii][jj]=='2' && a[fr.x][fr.y]>0)lmin=min(lmin,a[fr.x][fr.y]);
                }
            }
        }
    }
    out<<" "<<lmin;
    return 0;
}
