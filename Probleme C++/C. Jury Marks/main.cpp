#include <iostream>
#include <map>
#define NM 2005
using namespace std;
long long n,k,a[NM],b[NM],nrsol,sol[NM],st,ind,numarsolutii,gasit;
map<long long,long long> m,verif;
int main()
{
    cin>>k>>n;
    for(int i=1;i<=k;++i)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;++i)cin>>b[i];
    for(int i=1;i<=k;++i)
    {
        if(m.find(b[1]-a[i])==m.end())
        {
            sol[++nrsol]=b[1]-a[i];
            m[b[1]-a[i]]=i;
        }
    }
    ///bine
    for(int h=1;h<=nrsol;++h)
    {
        for(int i=1;i<=k;++i)verif[sol[h]+a[i]]=1;
        for(int i=1;i<=n;++i)
            if(verif.find(b[i])!=verif.end())++gasit;
        if(gasit==n)++numarsolutii;
        gasit=0;
        verif.clear();
    }
    cout<<numarsolutii;;
    return 0;
}
