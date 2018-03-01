#include <iostream>
#define NM 2005
using namespace std;
char c[NM][NM];
long long n,m,k,sol,cnt;
int main()
{
    cin.sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)cin>>c[i][j];
    for(int i=1;i<=n;++i)
    {
        cnt=0;
        for(int j=1;j<=m;++j)
        {
            if(c[i][j]=='.')++cnt;
            else cnt=0;
            if(cnt>=k)++sol;
        }
    }
    for(int j=1;j<=m;++j)
    {
        cnt=0;
        for(int i=1;i<=n;++i)
        {
            if(c[i][j]=='.')++cnt;
            else cnt=0;
            if(cnt>=k)++sol;
        }
    }
    if(k==1)
    {
        sol=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)if(c[i][j]=='.')++sol;
    }
    cout<<sol;
    return 0;
}
