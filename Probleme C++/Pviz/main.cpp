#include <iostream>
#include <fstream>
#define NM 2005
#define prim 10007
using namespace std;
ifstream in("pviz.in");
ofstream out("pviz.out");
int dp[NM][NM],n,m,a[NM],sol;
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)in>>a[i];
    dp[1][1]=1;
    for(int i=2;i<=n;++i)
        for(int j=1;j<=m;++j)
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]*(a[j]-i+1))%prim;
    out<<dp[n][m];
    return 0;
}
