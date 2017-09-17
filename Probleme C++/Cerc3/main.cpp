#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#define ppp pair<pair<int,int>,int>
#define xx first.first
#define yy first.second
#define rr second
#define pp pair<double,double>
#define st first
#define fn second
#define NM 2005
using namespace std;
ifstream in("cerc3.in");
ofstream out("cerc3.out");
ppp a[NM];
pp t[NM];
int n,m,te,pas,maxx,nmax,dp[NM],maxdp,v[NM];
double dist(int i)
{
    return sqrt(a[i].xx*a[i].xx+a[i].yy*a[i].yy);
}
double tg(int i)
{
    if(i==0)return 0;
    return a[i].yy*1.0/a[i].xx;
}
bool cmptg(ppp p1,ppp p2)
{
    return(p1.yy*1.0/p1.xx<p2.yy*1.0/p2.xx);
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
        in>>a[i].xx>>a[i].yy>>a[i].rr;
    sort(a+1,a+n+1,cmptg);
    for(int i=1;i<=n;++i)
    {
        if(tg(i)!=tg(i-1))++m;
        v[i]=m;
    }
    out<<m<<" ";
    ///terminat m;
    for(int i=1;i<=n;++i)
    {
        if(v[i]!=v[i-1])
        {
            pas=i;
            te=1;
            while((v[pas]==v[i] && pas<=n))
            {
                t[te].st=dist(pas)+a[pas].rr;
                t[te].fn=dist(pas)-a[pas].rr;
                ++te;
                ++pas;
            }
            sort(t+1,t+te);
            for(int j=1;j<te;++j)swap(t[j].st,t[j].fn);
            for(int j=1;j<te;++j)dp[j]=0;
            for(int ii=1;ii<te;++ii)
            {
                maxdp=0;
                for(int jj=1;jj<ii;++jj)
                    if(t[jj].fn<t[ii].st)maxdp=max(maxdp,dp[jj]);
                dp[ii]=maxdp+1;
            }
            maxdp=0;
            for(int ii=1;ii<te;++ii)maxdp=max(maxdp,dp[ii]);
            if(maxdp>maxx)
            {
                maxx=maxdp;
                nmax=0;
            }
            if(maxdp==maxx)++nmax;
        }
    }
    out<<maxx<<" "<<nmax<<'\n';
    return 0;
}
