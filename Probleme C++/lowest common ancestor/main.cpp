#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
#define NM 200005
#define MM 2000005
using namespace std;
ifstream in("lca.in");
ofstream out("lca.out");
int lg[NM],rmq[20][NM];
int n,m,x,y;
int euler[NM],euler_lvl[NM],ind,first[NM],h[NM];
vector<int> v[NM];
void dfs(int nod,int lvl)
{
    h[nod]=lvl;
    euler[++ind]=nod;
    for(auto i:v[nod])
    {
        dfs(i,lvl+1);
        euler[++ind]=nod;
    }
}
int main()
{
    ///Citire
    in>>n>>m;
    for(int i=2;i<=n;++i)
    {
        in>>x;
        v[x].pb(i);
    }
    ///Euler
    dfs(1,1);
    for(int i=1;i<=ind;++i)
        euler_lvl[i]=h[euler[i]];
    ///Prima aparitie a fiecarui nod
    for(int i=1;i<=ind;++i)
        if(first[euler[i]]==0)first[euler[i]]=i;
    ///RMQ
    for(int i=2;i<=ind;++i)lg[i]=lg[i/2]+1;
    for(int i=1;i<=ind;++i)
        rmq[0][i]=i;
    for(int i=1;i<=lg[ind];++i)
    {
        for(int j=1;j+(1<<i)-1<=ind;++j)
        {
            int nod1=rmq[i-1][j];
            int nod2=rmq[i-1][j+(1<<(i-1))];
            if(euler_lvl[nod1]<euler_lvl[nod2])
                rmq[i][j]=nod1;
            else rmq[i][j]=nod2;
        }
    }
    while(m--)
    {
        in>>x>>y;
        x=first[x];
        y=first[y];
        if(x>y)swap(x,y);
        int lng=lg[y-x+1];
        int nod1=rmq[lng][x];
        int nod2=rmq[lng][y-(1<<lng)+1];
        int sol;
        if(euler_lvl[nod1]<euler_lvl[nod2])sol=nod1;
        else sol=nod2;
        out<<euler[sol]<<'\n';
    }
    return 0;
}
