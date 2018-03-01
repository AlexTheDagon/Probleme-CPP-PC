#include <iostream>
#include <bits/stdc++.h>
#define NM 200005
#define piii pair<pair<int,int>,int>
#define a first.first
#define t first.second
#define id second
#define pb push_back
#define pf pop_front
using namespace std;
int n,T;
piii v[NM];
vector <piii> sol,act;
piii mkp(int x,int y,int z)
{
    return make_pair(make_pair(x,y),y);
}
int x,y;
int main()
{
    cin>>n>>T;
    for(int i=1;i<=n;++i)
    {
        cin>>v[i].a>>v[i].t;
        v[i].id=i;
    }
    sort(v+1,v+n+1);
    return 0;
}
