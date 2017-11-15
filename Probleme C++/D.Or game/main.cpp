#include <iostream>
#define NM 200005
using namespace std;
long long suf[NM],pref[NM],x,k,a[NM],n,p=1,maxx;
int main()
{
    cin>>n>>k>>x;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)pref[i]=(pref[i-1]|a[i]);
    for(int i=n;i>0;--i)suf[i]=(suf[i+1]|a[i]);
    for(int i=1;i<=k;++i)p*=x;
    for(int i=1;i<=n;++i)maxx=max(maxx,pref[i-1]|suf[i+1]|(p*a[i]));
    cout<<maxx;


    return 0;
}
