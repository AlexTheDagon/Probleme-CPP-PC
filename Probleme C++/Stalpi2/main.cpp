#include <iostream>
#include <fstream>
#include <stdlib.h>
#define NM 55
using namespace std;
ifstream in("stalpi2.in");
ofstream out("stalpi2.out");
int n,a[NM],e;
int best[2][10005],dd[10005];
int u,p,use;
int verif(int d)
{
    best[1][0]=0;
    for(int i=1;i<=a[n];++i)best[1][i]=(1<<30);
    for(int i=2;i<=n;++i)
    {
        u=0;
        p=1;
        use=i%2;
        for(int j=0;j<=a[n];++j)
        {
            best[use][j]=(1<<30);
            while(p<=u && best[1-use][dd[u]]>=best[1-use][j])u--;
            while(p<=u && j-dd[p]>d)++p;
            ++u;
            dd[u]=j;
            best[use][j]=best[1-use][dd[p]]+abs(a[i]-j);
        }
    }
    return (best[use][a[n]]<=e);
}
int main()
{
    in>>n>>e;
    for(int i=2;i<=n;++i)in>>a[i];
    int sol=10005;
    for(int i=16;i>=0;--i)
        if((1<<i)<sol && verif(sol-(1<<i))==1)
            sol-=(1<<i);
    out<<sol;
    return 0;
}
