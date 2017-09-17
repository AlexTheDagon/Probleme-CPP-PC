#include <iostream>

using namespace std;

long long a[11][2000],s,n,k;
int main()
{
    cin>>n>>k;
    for(int i=1;i<k;++i)a[i][1]=1;
    for(int i=2;i<=n;++i)
    {
        s=0;
        for(int j=0;j<k;++j)s+=a[j][i-1];
        a[0][i]=s-a[0][i-1];
        for(int j=1;j<k;++j)a[j][i]=s;
    }
    cout<<k*s-a[0][n-1];
    return 0;
}
