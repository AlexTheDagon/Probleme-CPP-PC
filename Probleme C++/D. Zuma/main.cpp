#include <iostream>

using namespace std;
int n,a[505],dp[505][505];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int l=1;l<=n;++l)
    {
		for(int st=1,dr=l;dr<=n;++st,++dr)
		{
			if(l==1)dp[st][dr]=1;
            else
            {
				dp[st][dr]=1+dp[st + 1][dr];
				if(a[st]==a[st + 1])dp[st][dr]=min(1+dp[st+2][dr],dp[st][dr]);
				for(int i=st+2;i<=dr;++i)
					if(a[st]==a[i])
						dp[st][dr]=min(dp[st+ 1][i- 1]+dp[i+1][dr],dp[st][dr]);
			}
		}
	}
	cout<<dp[1][n];
    return 0;
}
///editorial
