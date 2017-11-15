#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#define pb push_back
#define inf 1000000000
using namespace std;
ifstream in("flori.in");
ofstream out("flori.out");
int n,m,lg,x,cur,flori[1005],fata[1005],fr[1005],gr[1005],minn,nr;
vector <int> v[1005],sol;

int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)in>>flori[j];
        for(int j=0;j<=1000;++j)fr[j]=0;
        minn=inf;
        for(int j=1;j<=m;++j)
        {
            if(gr[flori[j]]!=0)
            {
                fr[gr[flori[j]]]=1;
                minn=min(minn,gr[flori[j]]);
            }
        }
        if(minn<inf)
        {
            for(int j=0;j<=1000;++j)if(fr[gr[j]]==1)gr[j]=minn;
            for(int j=1;j<=m;++j)gr[flori[j]]=minn;
        }
        else
        {
            ++lg;
            for(int j=1;j<=m;++j)gr[flori[j]]=lg;
        }
        fata[i]=flori[1];
    }
    for(int i=1;i<=n;++i)
    {
        v[gr[fata[i]]].pb(i);
    }
    for(int i=1;i<=1000;++i)
    {
        if(v[i].size())
        {
            for(auto j:v[i])out<<j<<" ";
            out<<'\n';
        }
    }
    return 0;
}
