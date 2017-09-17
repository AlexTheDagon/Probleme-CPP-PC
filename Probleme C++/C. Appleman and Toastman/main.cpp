#include <iostream>
#include <algorithm>
#define NM 300005
using namespace std;
long long a[NM],sum,n,sol;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)sum+=a[i];
    if(n==1)
    {
        cout<<a[1];
        return 0;
    }
    sol+=sum;
    sort(a+1,a+n+1);
    for(int i=1;i<n-1;++i)
    {
        sol+=sum;
        sum-=a[i];
    }
    sol+=sum;
    cout<<sol;
    return 0;
}
