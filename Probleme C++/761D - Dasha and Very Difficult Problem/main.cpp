#include <iostream>
#define NM 100005
using namespace std;
int n,l,r,a[NM],pos[NM],p,ult=-1000000000,sem,b[NM],ind,c[NM];
int main()
{
    cin>>n>>l>>r;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        cin>>p;
        pos[p]=i;
    }
    for(int i=1;i<=n;++i)
    {
        ind=pos[i];
        if(ult<l-a[ind])ult=l-a[ind];
        else ++ult;
        c[ind]=ult;
        b[ind]=c[ind]+a[ind];
        if(b[ind]<l || b[ind]>r)sem=1;
    }
    if(sem==1)cout<<"-1";
    else for(int i=1;i<=n;++i)cout<<b[i]<<" ";
    return 0;
}
