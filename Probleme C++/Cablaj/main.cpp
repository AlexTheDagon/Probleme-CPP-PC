#include <iostream>
#include <fstream>
#include <math.h>
#define NM 3005
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#include <bits/stdc++.h>
using namespace std;
ifstream in("cablaj.in");
ofstream out("cablaj.out");
double cmin[NM],sol,minn;
int n,viz[NM],poz;
pii crd[NM];
double dist(pii n1,pii n2)
{
    return 1.0*sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));
}
int main()
{
    in>>n;
    viz[1]=1;
    for(int i=1;i<=n;++i)
    {
        in>>crd[i].x>>crd[i].y;
        cmin[i]=dist(crd[1],crd[i]);
    }
    for(int i=1;i<n;++i)
    {
        minn=100000;
        for(int j=2;j<=n;++j)
        {
            if(cmin[j]<minn && !viz[j])
            {
                minn=cmin[j];
                poz=j;
            }
        }
        viz[poz]=1;
        sol+=minn;
        for(int j=1;j<=n;++j)
            if(!viz[j])
                cmin[j]=min(cmin[j],dist(crd[poz],crd[j]));
    }
    out<<fixed<<setprecision(6)<<sol;
    return 0;
}
