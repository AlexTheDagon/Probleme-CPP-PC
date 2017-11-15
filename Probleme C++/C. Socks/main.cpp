#include <iostream>
#include <vector>
#include <algorithm>
#define NM 200005
#define pb push_back
using namespace std;
vector<int> v[NM],cmp;
int n,m,c[NM],k,fr,cur,frs,sol,viz[NM],a,b,rep,parc[NM];
void dfs(int nod)
{
    viz[nod]=1;
    cmp.pb(c[nod]);
    for(auto i:v[nod])
        if(!viz[i])dfs(i);
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        parc[i]=a;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(int j=1,i;j<=m;++j)
    {
        i=parc[j];
        if(!viz[i])
        {
            cmp.clear();
            dfs(i);
            frs=0;
            fr=0;
            sol=0;
            cur=0;
            sort(cmp.begin(),cmp.end());
            for(auto i:cmp)
            {
                if(i!=cur)
                {
                    if(fr>frs)
                    {
                        sol=cur;
                        frs=fr;
                    }
                    cur=i;
                    fr=1;
                }
                else ++fr;
            }
            if(fr>frs)
            {
                sol=cur;
                frs=fr;
            }
            rep+=(cmp.size()-frs);
        }
    }
    cout<<rep<<endl;
    return 0;
}
