#include <iostream>
#define NM 200005
using namespace std;
int par[NM],vis[NM];
int t,n,m,nc,pos=-1,ans,nod;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>par[i];
        if(par[i]==i)pos=i;
    }///cititre
    for(int i=1;i<=n;++i)
    {
        if(vis[i]!=0)continue;
        nod=i;
        vis[nod]=++nc;
        while(vis[par[nod]]==0)
        {
            nod=par[nod];
            vis[nod]=nc;
        }///determin elementele ciclului cu numarul nc
        if(vis[par[nod]]==nc)
        {
            if(pos==-1)pos=nod;
            if(par[nod]!=pos)
            {
                ans++;
                par[nod]=pos;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;++i)cout<<par[i]<<" ";
    return 0;
}
