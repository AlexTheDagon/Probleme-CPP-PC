#include <iostream>
#include <algorithm>
#define mp make_pair
#define pp pair<int,pair<int,int> >
#define w first
#define h second.first
#define ord second.second
using namespace std;
int n,wc,hc,ind,p[5005],sol[5005];
pp d[5005];
int dp[5005],maxx;
int main()
{
    cin>>n>>wc>>hc;
    for(int i=1;i<=n;++i)
    {
        cin>>d[i].w>>d[i].h;
        d[i].ord=i;
    }
    sort(d+1,d+n+1);
    for(int i=1;i<=n;++i)if(d[i].w>wc && d[i].h>hc)dp[i]=1;
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<i;++j)
            if(d[i].w>d[j].w && d[i].h>d[j].h && dp[i]<=dp[j]+1 && dp[i]!=0)
            {
                dp[i]=dp[j]+1;
                p[i]=j;
            }
        if(dp[i]>maxx)
        {
            maxx=dp[i];
            ind=i;
        }
    }
    cout<<maxx<<endl;
    n=maxx;
    while(maxx>0)
    {
        sol[maxx--]=d[ind].ord;
        ind=p[ind];
    }
    for(int i=1;i<=n;++i)cout<<sol[i]<<" ";
    return 0;
}
