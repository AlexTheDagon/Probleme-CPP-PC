#include <iostream>
#include <vector>
#include <stdlib.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define NM 100005
using namespace std;
int a[NM],er[NM],p,pos[NM],n,nr1,nr2;
vector<pair<int,int> > v;
void doSwap(int i, int j)
{
    int x = a[i], y = a[j];
    a[j] = x, pos[x] = j;
    a[i] = y, pos[y] = i;
}
int main()
{
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=2;i<=n;++i)er[i]=1;
    for(int i=1;i<=n;++i)
        if(er[i])
            for(int j=2*i;j<=n;j+=i)er[j]=0;
    for(int i=1;i<=n;++i)
    {
        while(pos[i]!=i)
        {
            p=pos[i]-i+1;
            while(er[p]==0)--p;
            v.pb(mp(pos[i]-p+1,pos[i]));
            doSwap(pos[i],pos[i]-p+1);
        }
    }
    cout<<v.size()<<'\n';
    for(auto i:v)cout<<i.x<<" "<<i.y<<'\n';
    return 0;
}
