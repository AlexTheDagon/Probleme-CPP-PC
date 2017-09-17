#include <iostream>

using namespace std;
int n,m,x,y,a[5000],sol;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int j=1;j<=m;++j)
    {
        cin>>x>>y;
        sol+=min(a[x],a[y]);
    }
    cout<<sol;
    return 0;
}
