#include <iostream>
#include <fstream>
using namespace std;
ifstream in("zmeu2.in");
ofstream out("zmeu2.out");
int n,p,d[205],c[205],p1,p2,k,fin[205],pr[205],dmin,nodviz,sol=1000000000;
bool s[205][205],viz[205];
void dfs(int nod)
{
    ++nodviz;
    if(nod==p)
    {
        if(nodviz>2 && n>0)sol=min(dmin,sol);
    }
    else
    {
        viz[nod]=1;
        for(int i=1;i<=p;++i)
        {
            if(viz[i]==0 && s[nod][i])
            {
                dmin+=d[i];
                n-=c[i];
                if(dmin<=sol || n>0)dfs(i);
                dmin-=d[i];
                n+=c[i];
            }
        }
        viz[nod]=0;
    }
    --nodviz;
}
int main()
{
    in>>n>>p>>k;
    for(int i=1;i<=p;++i)
        for(int j=1;j<=p;++j)s[i][j]=1;
    for(int i=1;i<=p;++i)in>>d[i]>>c[i];
    for(int i=1;i<=k;++i)
    {
        in>>p1>>p2;
        s[p1][p2]=0;
    }
    dmin=d[1];
    n-=c[1];
    dfs(1);
    if(sol!=1000000000)out<<sol<<'\n';
    else out<<"-1";
    return 0;
}
