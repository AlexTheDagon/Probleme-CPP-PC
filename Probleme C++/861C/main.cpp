#include <iostream>
#include <algorithm>
#define NM 100005
using namespace std;
long long n,a[NM],sol,v[NM],ind;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=n-1;i>0;--i)
    {
        if (a[i+1]-a[i]<2)
        {
            v[++ind]=a[i];
            --i;
        }
    }
    for(int i=1;i<ind;i+=2)
    {
        sol+=v[i]*v[i+1];
    }
    cout<<sol<<endl;
    return 0;
}
