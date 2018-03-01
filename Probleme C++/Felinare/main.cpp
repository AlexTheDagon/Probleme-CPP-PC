#include <iostream>
#include <fstream>
#include <vector>
#define NM 8200
#define MM 20005
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
ifstream in("felinare.in");
ofstream out("felinare.out");
vector<pii> v[2][NM];///1 pt graf transpus,0 graf normal
int ramas,felinare;
int stins[2][NM],dim[2][NM];///0 daca is cele care pleaca sau 1 care intra
int x,y,fol[MM];
int n,m,caz;
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)
    {
        in>>x>>y;
        v[0][x].pb({y,i});
        v[1][y].pb({x,i});///ca sa verific cele are pleaca
        ++dim[0][x];
        ++dim[1][y];
    }
    ramas=m;
    felinare=2*n;
    while(ramas)
    {
        --felinare;
        int maxx=0,tip,poz;
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<=1;++j)
            {
                if(dim[j][i]>maxx)
                {
                    maxx=dim[j][i];
                    tip=j;
                    poz=i;
                }
            }
        }
        stins[tip][poz]=1;
        dim[tip][poz]=0;
        for(auto i:v[tip][poz])
        {
            if(!fol[i.s])
            {
                --ramas;
                fol[i.s]=1;
            }
        }
    }
    out<<felinare<<'\n';
    for(int i=1;i<=n;++i)
    {
        caz=3;
        for(int j=0;j<2;++j)
            if(stins[j][i])caz-=(j+1);
        out<<caz<<'\n';
    }
    return 0;
}
