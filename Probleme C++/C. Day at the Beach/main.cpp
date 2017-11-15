#include <iostream>
#define NM 100005
using namespace std;
int minn[NM],maxx[NM],sol=1,n,a[NM];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        maxx[i]=max(maxx[i-1],a[i]);
    }
    minn[n]=a[n];
    for(int i=n-1;i>0;--i)minn[i]=min(minn[i+1],a[i]);
    for(int i=1;i<=n;++i)if(minn[i+1]>=maxx[i])++sol;
    cout<<sol;
    return 0;
}
