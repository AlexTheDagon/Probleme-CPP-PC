#include <iostream>
#define MAXN 200010
#define mod 1000000007
using namespace std;
int n,a[MAXN];

long long q_pow(long long x,long long n)
{
    long long res=1,tmp=x;
    while(n)
    {
        if(n&1)res=res*tmp%mod;
        tmp=tmp*tmp%mod;
        n/=2;
    }
    return res;
}
int main()
{
    int i,j,c=1;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    while(n%4!=1)
    {
        for(i=1;i<n;i++)
        {
            if(c)a[i]=(a[i]+a[i+1])%mod;
            else a[i]=(a[i]-a[i+1]+mod)%mod;
            c=1-c;
        }
        n--;
    }
    long long p=n/2,C=1,ans=0;
    for(i=0;i<=p;i++)
    {
        if(i>0)C=C*(p-i+1)%mod*q_pow(i,mod-2)%mod;///generare coeficient
        cout<<C<<endl;
        ans+=C*a[2*i+1];
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
///editorial +sursa
