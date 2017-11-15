#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
ifstream in("monezi2.in");
ofstream out("monezi2.out");
int n,a[55],dp[100005],q,x;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        a[i]+=a[i-1];
    }
    dp[0]=1;
    for(int i=1;i<=n;++i)
        for(int s=a[i];s<=100002;++s)
            if(dp[s-a[i]]==1)dp[s]=1;
    in>>q;
    for(int i=1;i<=q;++i)
    {
        in>>x;
        if(dp[x])out<<"DA"<<'\n';
        else out<<"NU"<<'\n';
    }
    return 0;
}
