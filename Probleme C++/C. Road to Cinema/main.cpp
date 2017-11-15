#include <iostream>
#include <algorithm>
#define NM 200005
#define inf 1<<30
using namespace std;
long long n,k,s,t,c[NM],v[NM],p[NM],st,dr=inf,m,sem,aux,minn=inf;
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n>>k>>s>>t;
    for(int i=1;i<=n;++i)cin>>c[i]>>v[i];
    for(int i=1;i<=k;++i)cin>>p[i];
    sort(p+1,p+k+1);
    p[++k]=s;
    while(dr-st>1)
    {
        m=(st+dr)/2;
        sem=1;
        aux=0;
        for(int i=1;i<=k;++i)
        {
            if(p[i]-p[i-1]>m)sem=0;
            else aux+=2*(p[i]-p[i-1])-min(m-(p[i]-p[i-1]),p[i]-p[i-1]);
        }
        if(sem && aux<=t)dr=m;
        else st=m;
    }
    for(int i=1;i<=n;++i)
        if(v[i]>=dr)
            minn=min(minn,c[i]);
    if (minn==inf)cout<<"-1"<<endl;
    else cout<<minn<<endl;
    return 0;
}
///ajutor din sursa
