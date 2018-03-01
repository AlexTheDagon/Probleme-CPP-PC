#include <iostream>
#include <bits/stdc++.h>
#define PI 3.14159265
#define pb push_back
#define NM 205
#define inf 1000000000
using namespace std;
ifstream in("snipers.in");
ofstream out("snipers.out");
struct pct
{
    int x,y,id,sgn;
};
bool cmp(pct a,pct b)
{
    return atan2(a.y,a.x)<atan2(b.y,b.x);
}
int n,sol[NM];
void solve(vector<pct> v)
{
    pct origin;
    origin.y=inf;
    for(int i=0;i<v.size();++i)
    {
        if(v[i].y<origin.y)origin=v[i];
        else if(v[i].y==origin.y && v[i].x<origin.x)origin=v[i];
    }
    for(int i=0;i<v.size();++i)
    {
        v[i].x-=origin.x;
        v[i].y-=origin.y;
    }///translatare
    sort(v.begin(),v.end(),cmp);
    int sum=origin.sgn,sem=0;
    vector<pct> v1,v2;
    for(int i=1;i<v.size();++i)
    {
        sum+=v[i].sgn;
        if(sum==0 && sem==0)
        {
            sem=1;
            if(origin.sgn==-1)swap(v[i],origin);
            sol[origin.id]=v[i].id;
        }
        else
        {
            if(sem==0)v1.pb(v[i]);
            else v2.pb(v[i]);
        }
    }
    if(v1.size())solve(v1);
    if(v2.size())solve(v2);
}
vector<pct> a;
pct act;
int main()
{
    in>>n;
    for(int i=1;i<=2*n;++i)
    {
        in>>act.x>>act.y;
        act.id=i;
        if(i<=n)act.sgn=1;
        else act.sgn=-1;
        a.pb(act);
    }
    solve(a);
    for(int i=1;i<=n;++i)out<<sol[i]-n<<'\n';
    return 0;
}
