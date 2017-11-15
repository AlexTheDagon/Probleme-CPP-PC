#include <iostream>
#define NM 500005
#define pb pop_back();
using namespace std;
int n,lc;
string s[NM];
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>s[i];
    for(int i=n-1;i>0;--i)
    {
        if(s[i]>s[i+1])
        {
			lc= 0;
			while(lc<min(s[i].size(),s[i+1].size()) && s[i][lc]==s[i+1][lc])lc++;
			s[i].resize(lc);
		}
    }
    for(int i=1;i<=n;++i)cout<<s[i]<<endl;
    return 0;
}
