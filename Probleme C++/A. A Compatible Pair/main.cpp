#include <iostream>
#include <bits/stdc++.h>
#define NM 550
using namespace std;
long long n,m,a[NM],b[NM],maxx,ind;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)cin>>b[i];
    maxx=-2000000000000000000;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i]*b[j]>=maxx)
            {
                maxx=a[i]*b[j];
                ind=i;
            }
    maxx=-2000000000000000000;
    a[ind]=a[n];
    --n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i]*b[j]>=maxx)
            {
                maxx=a[i]*b[j];
                ind=i;
            }
    cout<<maxx;
    return 0;
}
