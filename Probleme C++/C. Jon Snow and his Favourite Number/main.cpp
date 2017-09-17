#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100005],k,x,minn=10000,maxx;
int main()
{
    cin>>n>>k>>x;
    k=k%100;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=k;++i)
    {
        sort(a+1,a+n+1);
        for(int j=1;j<=n;j+=2)a[j]=(a[j]^x);
    }
    for(int i=1;i<=n;++i)
    {
        minn=min(a[i],minn);
        maxx=max(maxx,a[i]);
    }
    cout<<maxx<<" "<<minn;
    return 0;
}
