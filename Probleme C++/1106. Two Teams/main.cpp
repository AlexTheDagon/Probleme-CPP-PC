#include <iostream>
#include <vector>
#define pb push_back
#define NM 105
using namespace std;
int n,viz[NM],a,sem;
vector <int> v[NM],t[2];
void dfs(int nod,int team)
{
    t[team].pb(nod);
    viz[nod]=1;
    for(auto i:v[nod])
        if(!viz[i])
            dfs(i,1-team);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        if(a==0)sem=1;
        while(a!=0)
        {
            v[i].pb(a);
            cin>>a;
        }
    }
    if(sem)cout<<"0";
    else
    {
        for(int i=1;i<=n;++i)
        {
            if(!viz[i])
                dfs(i,0);
        }
        cout<<t[0].size()<<'\n';
        for(auto i:t[0])cout<<i<<" ";
    }
    return 0;
}
