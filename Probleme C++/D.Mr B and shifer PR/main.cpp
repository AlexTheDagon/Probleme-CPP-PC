#include <iostream>
#include <stdlib.h>
#define N 1000010
using namespace std;
int n,p[N],cnt[N];
int neg;
long long res,ans,pos;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>p[i];
    for(int i=1;i<=n;++i)
    {
        res+=abs(p[i]-i);
        cnt[(p[i]-i+n)%n]++;
        if(p[i]<=i)neg++;
        else pos++;
    }
    ans=res;
    int idx=0;
    for(int k=1;k<n;++k)
    {
        res-=pos;
        res+=neg-1;
        res+=p[(n-k)%n+1]-n+p[(n-k)%n+1]-1;
        pos-=cnt[k]-1;
        neg+=cnt[k]-1;
        if(res<ans)
        {
            idx=k;
            ans=res;
        }
    }
    cout<<ans<<" "<<idx<<endl;
    return 0;
}
///editorial + sursa
