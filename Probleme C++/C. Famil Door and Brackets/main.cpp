#include <iostream>
#define NM 2005
#define M 1000000007
using namespace std;
string s;
long long bals,stbal,dp[NM][NM],n,m;///dp[i][j]--nr secventelor de lungime i ce au balanta=j   balanta=nr(  -- nr)
long long sol;
int main()
{
    cin>>n>>m>>s;
    dp[0][0]=1;
    for(int i=1;i<=2000;++i)
    {
        for(int j=0;j<=2000;++j)
        {
            if(j<i)dp[i][j]+=dp[i-1][j+1];///siru lde paranteze se temrina in )
            if(j>0)dp[i][j]+=dp[i-1][j-1];///se termina in (
            dp[i][j]%=M;
        }
    }
    for(auto c:s)
    {
        if(c=='(')++bals;
        else --bals;
        stbal=min(stbal,bals);
    }
    stbal*=-1;
    for(int i=0;i<=(n-m);++i)
        for(int j=stbal;j<=i;++j)
            if(j+bals<=n-m-i)sol=(sol+(dp[i][j]*dp[n-m-i][j+bals])%M)%M;
    cout<<sol<<endl;
    return 0;
}
