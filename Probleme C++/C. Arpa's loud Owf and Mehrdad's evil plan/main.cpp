#include <iostream>
#define NM 105
#define LL long long
using namespace std;
LL a[NM],b[NM],c[NM],viz[NM],lc[NM],nc,n,v,lng;

int cmmdc(int a, int b)
{
    if(b==0)return a;
    return cmmdc(b,a%b);
}
void dfs(int nod)
{
    viz[nod]=1;
    ++lng;
    if(!viz[a[nod]])dfs(a[nod]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>v;
        a[i]=v;
        c[v]=1;
        b[i]=1;
    }
    for(int i=1;i<=n;++i)
    {
        if(c[i]+b[i]!=2)
        {
            cout<<"-1";
            return 0;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(viz[i]==0)
        {
            lng=0;
            dfs(i);
            if(lng%2==1)lc[++nc]=lng;
            else lc[++nc]=lng/2;
        }
    }
    for(int i=2;i<=nc;++i)
        lc[i]=lc[i]/cmmdc(lc[i],lc[i-1])*lc[i-1];
    cout<<lc[nc];
    return 0;
}

///lc lungime cicli
///nc numar cicli
