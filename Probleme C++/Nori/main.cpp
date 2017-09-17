#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>
#define NM 100005
#define x first
#define y second
using namespace std;
const long double inf=1e9;
ifstream in("nori.in");
ofstream out("nori.out");
int n,m,a,b,sir[100005],afis[100005],r,u,l;
long double d,t,dist,aux;
vector<long double>::iterator low,up;
vector<long double > dr;
pair<long double,int> dr2[100005];
pair <long double,long double> c[NM];
long double tg(int i,int j)
{
    if(i==0)return inf;
    return (1.0*j)/(1.0*i);
}
int main()
{
    in>>n;
    for(int i=0;i<n;++i)
    {
        in>>a>>b>>r;
        t=tg(a,b);
        aux=tg(sqrt(d+r*r),r);
        c[i].x=(t-aux)*1.0*(1.0+t*aux*1.0);
        c[i].y=(t+aux)*1.0*(1.0-t*aux*1.0);
        if(c[i].x>c[i].y)swap(c[i].x,c[i].y);
        cout<<t<<" "<<aux<<endl;
    }
    in>>m;
    for(int i=0;i<m;++i)
    {
        in>>a>>b;
        dr.push_back(tg(a,b));
        dr2[i].x=tg(a,b);
        dr2[i].y=i;
    }
    sort(dr.begin(),dr.begin()+n);
    sort(dr2,dr2+n);
    for(int i=0;i<n;++i)
    {
        low=lower_bound(dr.begin(),dr.begin()+n,c[i].x);
        up=upper_bound(dr.begin(),dr.begin()+n,c[i].y);
        u=distance(dr.begin(),up);
        l=distance(dr.begin(),low);
        cout<<u<<" "<<l<<endl;
        --sir[u];
        ++sir[l];
    }

    for(int i=1;i<m;++i)sir[i]+=sir[i-1];
    for(int i=0;i<m;++i)if(sir[i]!=0)afis[dr2[i].y]=1;
    for(int i=0;i<m;++i)out<<afis[i];
    return 0;
}
