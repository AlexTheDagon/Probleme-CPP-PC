#include <iostream>
#include <algorithm>
#define NM 200005
using namespace std;
int a[NM],r[NM],t[NM],cnt,n,m,ord[NM],st,dr;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=m;++i)
    {
        ++cnt;
        cin>>t[cnt]>>r[cnt];
        while(cnt>1 && r[cnt]>=r[cnt-1])
        {
            r[cnt-1]=r[cnt];
            t[cnt-1]=t[cnt];
            --cnt;
        }
    }
    for(int i=1;i<=n;++i)ord[i]=a[i];
    sort(ord+1,ord+r[1]+1);
    dr=r[1];
    st=1;
    for(int i=1;i<cnt;++i)
    {
        for(int j=r[i];j>r[i+1];--j)
        {
            if(t[i]==2)a[j]=ord[st++];
            else a[j]=ord[dr--];
        }
    }
    for(int j=r[cnt];j>0;--j)
    {
        if(t[cnt]==2)a[j]=ord[st++];
        else a[j]=ord[dr--];
    }
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";
    return 0;
}
