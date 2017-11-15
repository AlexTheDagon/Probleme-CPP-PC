#include <iostream>
#include <algorithm>
#include <stdlib.h>
#define NM 1000000
using namespace std;
long long a[NM],b[NM],n,m,sol;
bool cmp(long long a,long long b){return a>b;}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1,cmp);
    for(int i=1;i<=min(m,n) && a[i]<b[i];++i)sol+=abs(a[i]-b[i]);
    cout<<sol;
    return 0;
}
