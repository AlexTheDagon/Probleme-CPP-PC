#include <iostream>
#include <vector>
#define pb push_back
#define mp make_pair
#define NM 200005
using namespace std;
int a[NM],b[NM],maxx,n,x,y,st,va[NM],vb[NM];
vector<int> v[NM];
void dfsa(int nod)
{
    va[nod]=1;
    for(auto i:v[nod])
    {
        if(!va[i])
        {
            a[i]=a[nod]+1;
            dfsa(i);
        }
    }
}
void dfsb(int nod)
{
    vb[nod]=1;
    for(auto i:v[nod])
    {
        if(!vb[i])
        {
            b[i]=b[nod]+1;
            dfsb(i);
        }
    }
}
int main()
{
    cin>>n>>st;
    for(int i=1;i<n;++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfsa(1);
    dfsb(st);
    for(int i=1;i<=n;++i)
        if(a[i]>b[i] && maxx<2*a[i])maxx=2*a[i];
    cout<<maxx;
    return 0;
}
