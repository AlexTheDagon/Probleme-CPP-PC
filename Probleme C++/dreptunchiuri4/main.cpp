#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
#define pb push_back
#define mp make_pair
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
using namespace std;
ifstream in("dreptunghiuri4.in");
ofstream out("dreptunghiuri4.out");
map<int,int> mx,my,nx,ny;
vector <pair<pair<int,int>,pair<int,int> > > v;
pair<pair<int,int>,pair<int,int> > fr;
vector <int> vx,vy;
int n,k;
int x,y,ultx,ulty,zone;
int a[2100][2100];
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>x>>y;
        if(mx.find(x)==mx.end())
        {
            mx[x]=1;
            vx.pb(x);
        }
        if(my.find(y)==my.end())
        {
            my[y]=1;
            vy.pb(y);
        }
        fr.ff=x;
        fr.fs=y;
        in>>x>>y;
        if(mx.find(x)==mx.end())
        {
            mx[x]=1;
            vx.pb(x);
        }
        if(my.find(y)==my.end())
        {
            my[y]=1;
            vy.pb(y);
        }
        fr.sf=x;
        fr.ss=y;
        if(fr.ff>fr.sf)swap(fr.ss,fr.sf);
        if(fr.fs>fr.ss)swap(fr.fs,fr.ss);
        v.pb(fr);
    }
    sort(vy.begin(),vy.end());
    sort(vx.begin(),vx.end());
    ultx=1;
    ulty=1;
    for(int i=0;i<vx.size();++i)
    {
        mx[vx[i]]=ultx;
        ++ultx;
    }
    for(int i=0;i<vy.size();++i)
    {
        my[vy[i]]=ulty;
        ++ulty;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i)
    {
        fr=v[i];
        ++a[mx[fr.ff]][my[fr.fs]];
        ++a[mx[fr.sf]][my[fr.ss]];
        --a[mx[fr.ff]][my[fr.ss]];
        --a[mx[fr.sf]][my[fr.fs]];
    }
    for(int i=1;i<=ultx;++i)
    {
        for(int j=1;j<=ulty;++j)
        {
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=ultx;++i)
    {
        for(int j=1;j<=ulty;++j)
        {
            if(a[i][j]==k)++zone;
        }
    }
    out<<zone;
    return 0;
}
