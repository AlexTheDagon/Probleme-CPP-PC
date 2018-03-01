#include <iostream>
#include <fstream>
#include <map>
#include <set>
#define NM 305
using namespace std;
ifstream in("submatrix.in");
ofstream out("submatrix.out");
int fr[NM*NM],n,m,a[NM][NM],ind,k,el;
int best[NM][NM];
int sol;
map<int,int> norm;
int calc(int ii,int jj)
{
    for(int i=1;i<=n*m;++i)fr[i]=0;
    best[ii][jj]=1;
    ++fr[a[ii][jj]];
    el=1;
    ++ii;
    ++jj;
    while(ii<=n && jj<=m)
    {
        int l=best[ii-1][jj-1]+1;
        for(int i=ii;i>ii-l;--i)
        {
            ++fr[a[i][jj]];
            if(fr[a[i][jj]]==1)++el;
        }
        for(int j=jj;j>jj-l;--j)
        {
            ++fr[a[ii][j]];
            if(fr[a[ii][j]]==1)++el;
        }
        --fr[a[ii][jj]];
        while(el>k)
        {
            for(int i=ii;i>ii-l;--i)
            {
                --fr[a[i][jj-l+1]];
                if(fr[a[i][jj-l+1]]==0)--el;
            }
            for(int j=jj;j>jj-l;--j)
            {
                --fr[a[ii-l+1][j]];
                if(fr[a[ii-l+1][j]]==0)--el;
            }
            ++fr[a[ii-l+1][jj-l+1]];
            if(fr[a[ii-l+1][jj-l+1]]==1)++el;
            --l;
        }
        best[ii][jj]=l;
        sol=max(sol,l);
        ++ii;
        ++jj;
    }
}
int main()
{
    in>>n>>m>>k;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            in>>a[i][j];
            if(norm.find(a[i][j])==norm.end())
                norm[a[i][j]]=++ind;
            a[i][j]=norm[a[i][j]];
        }
    }
    for(int i=1;i<=n;++i)calc(i,1);
    for(int j=2;j<=m;++j)calc(1,j);
    out<<sol;
    return 0;
}
