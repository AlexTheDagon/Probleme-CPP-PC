#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define NM 10005
using namespace std;
int n,p[NM],f,c[NM],sol=1,viz[NM];
vector<int> v[NM];
void dfs(int nod)
{
    viz[nod]=1;
    for(auto i:v[nod])
    {
        if(!viz[i])
        {
            if(c[nod]!=c[i])++sol;
            dfs(i);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=2;i<=n;++i)
    {
        cin>>p[i];
        v[p[i]].pb(i);
        v[i].pb(p[i]);
    }
    for(int i=1;i<=n;++i)cin>>c[i];
    dfs(1);
    cout<<sol;
    return 0;
}
