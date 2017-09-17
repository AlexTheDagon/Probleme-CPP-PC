#include <iostream>
#include <fstream>
#define NM 100005
using namespace std;
ifstream in("crescator.in");
ofstream out("crescator.out");
long long a[NM],dp[NM],lm[NM],n,lmax;
long long sum;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        dp[i]=1;
        lm[i]=1;
        in>>a[i];
        if(a[i]>=a[i-1])
        {
            dp[i]+=dp[i-1];
            lm[i]=lm[i-1]+1;
        }
        sum+=dp[i];
        lmax=max(lmax,lm[i]);
    }
    out<<sum<<" "<<lmax<<'\n';
    return 0;
}
