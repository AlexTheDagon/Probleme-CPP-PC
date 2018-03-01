#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define NM 1005
using namespace std;
int n,p[NM],viz[NM],fr[NM],sem;
vector<int> v[NM];
void dfs(int nod)
{
    for(auto i:v[nod])
    {
        if(v[i].size()==0)++fr[nod];
        dfs(i);
    }
}
int main()
{
    cin>>n;
    for(int i=2;i<=n;++i)
    {
        cin>>p[i];
        v[p[i]].pb(i);
    }
    dfs(1);
    for(int i=1;i<=n;++i)
    {
        if(fr[i]<3 && v[i].size()!=0)sem=1;
    }
    if(sem)cout<<"No";
    else cout<<"Yes";
    return 0;
}
