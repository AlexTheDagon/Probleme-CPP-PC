#include <iostream>
#include <fstream>
#define NM 2005
#define inf 1000000000
using namespace std;
ifstream in("permutare4.in");
ofstream out("permutare4.out");
int n,caz,poz,dp[NM][NM],l,c,el,sp[NM][NM];
int perm[NM],fol[NM];
int main()
{
    n=1000;
    for(int i=n;i<2*n;++i)
        dp[n][i]=1;
    for(int i=n-1;i>0;--i)
    {
        for(int j=2*n;j>=i;--j)
            dp[i][j]=min(inf,dp[i+1][j+1]+dp[i][j+1]);
        for(int j=2*n;j>(2*i-1);--j)
            dp[i][j]=0;
    }
    for(int i=1;i<=n;++i)
        for(int j=2*n;j>0;--j)
            sp[i][j]=min(inf,dp[i][j]+sp[i][j+1]);
    while(in>>caz)
    {
        in>>n;
        l=1001-n;
        c=2001-2*n;
        el=1;
        if(caz==1)
        {
            in>>poz;
            while(l<1001)
            {
                while(dp[l][c]<poz)
                {
                    poz-=dp[l][c];
                    ++c;
                    ++el;
                }
                fol[el]=1;
                out<<el<<" ";
                ++l;
                ++c;
                ++el;
            }
            for(int i=1;i<=2*n;++i)
            {
                if(fol[i]==1)fol[i]=0;
                else out<<i<<" ";
            }
            out<<'\n';
        }
        else
        {
            for(int i=1;i<=2*n;++i)in>>perm[i];
            poz=dp[l][c];
            for(int i=1;i<=n;++i)
                if(sp[l+i-1][c+perm[i]]<inf)poz-=sp[l+i-1][c+perm[i]];
            out<<poz<<'\n';
        }
    }
    return 0;
}
