#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
using namespace std;
ifstream in("colaj.in");
ofstream out("colaj.out");
int x,y,z,u,n,m,p,deinlocuit,sem,minn,a[8005],ultimazona=0,precedenta,start=0,repetari,maxx,asus,ajos;
vector <pair<pair<int,int>,pair<int,int> > > v;
pair<pair<int,int>,pair<int,int> > fr;
int isus,ijos;


int main()
{
    in>>n;
    in>>m>>p;
    --m;
    --p;
    for(int i=0;i<=p;++i)a[i]=1;
    for(int i=1;i<=n;++i)
    {
        in>>x>>y>>z>>u;
        fr.ff=x;
        fr.fs=0;
        fr.sf=y;
        fr.ss=u-1;
        v.pb(fr);
        fr.ff=z;
        fr.fs=1;
        fr.sf=y;
        fr.ss=u-1;
        v.pb(fr);
    }
    sort(v.begin(),v.end());
    ///1--Cand se adauga zona
    ///0 cand se ocupa zona
    while(start<v.size() && v[start].ff==0)
    {
        fr=v[start];
        ++start;
        for(int i=fr.sf;i<=fr.ss;++i)a[i]=0;
    }
    if(a[0]!=0)++ultimazona;
    if(start!=0)
    {
        for(int i=1;i<=p;++i)
        {
            if(a[i-1]==0 && a[i]==1)
            {
                ++ultimazona;
            }
            if(a[i]!=0)a[i]=ultimazona;
        }
    }
    for(int k=start;k<v.size();++k)
    {
        fr=v[k];
        if(fr.fs==0)for(int i=fr.sf;i<=fr.ss;++i)a[i]=0;
        else
        {
            ++ultimazona;
            for(int i=fr.sf;i<=fr.ss;++i)a[i]=ultimazona;
        }
        for(int i=1;i<p;++i)
        {
            if(a[i]>0)
            {
                if(a[i]<a[i-1])
                {
                    --ultimazona;
                    ajos=a[i-1];
                    for(int jos=i-1;jos>=0 && a[jos]==ajos;--jos)a[jos]=a[i];
                }
                if(a[i]<a[i+1])
                {
                    --ultimazona;
                    asus=a[i+1];
                    for(int sus=i+1;sus<=p && a[sus]==asus;++sus)a[sus]=a[i];
                }
            }
        }
        for(int i=0;i<=p;++i)maxx=max(maxx,a[i]);
    }
    if(v[v.size()-1].ff<m)
    {
        if(a[0]!=0)++repetari;
        for(int i=1;i<=p;++i)if(a[i]!=a[i-1])++repetari;
        ultimazona=ultimazona-repetari;
    }
    out<<ultimazona;
    return 0;
}
