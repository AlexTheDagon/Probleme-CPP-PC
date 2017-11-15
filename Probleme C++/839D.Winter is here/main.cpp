#include <iostream>
#define AM 1000005
#define NM 300005
#define M 1000000007
using namespace std;
long long p2[AM],sol[AM],fr[AM],ans;
int cnt[NM],a[AM],n;
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        for(int j=1;j*j<=a[i];++j)
        {
            if(a[i]!=j*j && a[i]%j==0)++fr[a[i]/j];
            if(a[i]%j==0)++fr[j];
        }
    }
    p2[0]=1;
    for(int i=1;i<=AM-3;++i)p2[i]=p2[i-1]*2%M;
    for(int i=AM-3;i>1;--i)
    {
        if(fr[i])
        {
            sol[i]=(fr[i]*p2[fr[i]-1])%M;
            for(int j=i+i;j<AM-2;j+=i)
                sol[i]=(sol[i]-sol[j])%M;
            sol[i]%=M;
            while(sol[i]<0)sol[i]+=M;
            ans+=i*sol[i];
            ans%=M;
        }
    }
    cout<<ans;
    return 0;
}
