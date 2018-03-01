#include <iostream>
#include <fstream>
#include <map>
#include <set>
#define NM 305
using namespace std;
ifstream in("submatrix.in");
ofstream out("submatrix.out");
int fr[NM*NM],n,m,a[NM][NM],ind,k;
set<int> s;
int sol;
int verif(int l)
{
    for(int i=1;i<=n-l+1;++i)
    {
        for(int j=1;j<=m-l+1;++j)
        {
            for(int ii=i;ii<i+l;++ii)
                for(int jj=j;jj<j+l;++jj)
                    s.insert(a[ii][jj]);
            if(s.size()<=k)return 1;
            s.clear();
        }
    }
    return 0;
}
map<int,int> norm;
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
    for(int i=10;i>=0;--i)
        if((1<<i)<=min(n,m))
            if(verif(sol+(1<<i)))sol+=(1<<i);
    out<<sol;
    return 0;
}
