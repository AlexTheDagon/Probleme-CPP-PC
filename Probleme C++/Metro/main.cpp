#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int m,n,scurtaturi,x,y;
double a[1005][1005],s[1005][1005];
int main()
{
    cin>>n>>m>>scurtaturi;
    for(int i=1;i<=scurtaturi;++i)
    {
        cin>>x>>y;
        s[x][y]=1;
    }
    for(int i=1;i<=n;++i)a[i][0]=i*100;
    for(int i=1;i<=m;++i)a[0][i]=i*100;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            a[i][j]=min(a[i-1][j],a[i][j-1])+100;
            if(s[i][j]==1)a[i][j]=min(a[i][j],a[i-1][j-1]+sqrt(2)*100);
        }

    }
    cout<<fixed<<setprecision(0)<<a[n][m];
    return 0;
}
