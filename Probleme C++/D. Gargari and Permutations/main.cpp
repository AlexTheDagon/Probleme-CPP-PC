#include <iostream>
#define NM 1005
#define KM 10
using namespace std;
int a[KM][NM],poz[KM][NM],dp[NM],n,k,sol,maxx,ind;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            poz[i][a[i][j]]=j;
        }
    }
    for(int i=1;i<=n;++i)
    {
        maxx=0;
        for(int p=1;p<i;++p)
        {
            ind=2;
            while(ind<=k && poz[ind][a[1][p]]<poz[ind][a[1][i]])++ind;
            if(ind==k+1 && dp[p]>maxx)maxx=dp[p];
        }
        dp[i]=maxx+1;
        sol=max(sol,dp[i]);
    }
    cout<<sol;
    return 0;
}
