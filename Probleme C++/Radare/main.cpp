#include <iostream>
#include <bits/stdc++.h>
#define NM 3005
#define PM 3505
#define pb push_back
#define mm 31333
using namespace std;
ifstream in("radare.in");
ofstream out("radare.out");
int n,p,a,b,cost[NM],dp[NM][PM],viz[NM];
vector<int> v[NM];
int main()
{
    in>>n>>p;
    for(int i=1;i<n;++i)
    {
        in>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    return 0;
}
