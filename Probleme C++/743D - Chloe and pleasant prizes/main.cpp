#include <iostream>
#include <vector>
#define pb push_back
#define NM 200005
#define minf -1000000000000000000
using namespace std;
long long a[NM],x,y,viz[NM],dp[NM],maxx[NM],sol=minf;
vector <int> v[NM];
int n;
void dfsdp(int nod)
{
    viz[nod]=1;
    dp[nod]=a[nod];
    maxx[nod]=minf;
    long long m1=minf,m2=minf;
    for(auto i:v[nod])
    {
        if(!viz[i])
        {
            dfsdp(i);
            dp[nod]+=dp[i];
            maxx[nod]=max(maxx[nod],maxx[i]);
            if(m1<=maxx[i])
            {
                m2=m1;
                m1=maxx[i];
            }
            else if(m2<maxx[i])m2=maxx[i];
        }
    }
    maxx[nod]=max(maxx[nod],dp[nod]);
    sol=max(sol,m1+m2);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<n;++i)
    {
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfsdp(1);
    if(sol<-10000000000)cout<<"Impossible";
    else cout<<sol;
    return 0;
}
