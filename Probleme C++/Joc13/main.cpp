#include <iostream>
#include <fstream>
#define inf 1000000000
#define NM 5005
using namespace std;
ifstream in("joc13.in");
ofstream out("joc13.out");
int n,k,a[2][NM],sp[2][NM],dp[2][NM];
int main()
{
    in>>n>>k;
    for(int j=0;j<2;++j)
        for(int i=1;i<=n;++i)
        {
            in>>a[j][i];
            dp[j][i]=-inf;
            sp[j][i]=sp[j][i-1]+a[j][i];
        }
    ///bine
    for(int i=1;i<=k;++i)dp[0][i]=sp[0][i];
    dp[0][1]=a[0][1];
    dp[1][1]=a[1][1]+a[0][1];
    dp[1][2]=dp[1][1]+a[1][2];
    for(int i=2;i<=n;++i)
        for(int j=0;j<2;++j)
            for(int ii=i-1;ii>0 && i-ii<k;--ii)
                if(j!=0 || ii>1)dp[j][i]=max(dp[j][i],dp[1-j][ii]+sp[j][i]-sp[j][ii-1]);
    out<<max(dp[1][n],dp[0][n]+a[1][n]);
    return 0;
}
