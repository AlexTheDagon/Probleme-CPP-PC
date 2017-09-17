#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;
int n,k,a,b,nodulet;
vector <int> v[1005];
int viz[1005],c[1005];
void dfs(int nod)
{
    int sem=0;
    for(int i=0;i<v[nod].size();++i)
    {
        if(viz[v[nod][i]]==0)
        {
            viz[v[nod][i]]=1;
            dfs(v[nod][i]);
            if(c[v[nod][i]]==0)sem=1;
        }
    }
    c[nod]=sem;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    viz[k]=1;
    dfs(k);
    if(c[k]==0 && n!=2)cout<<"First player loses";
    else
    {
        if(n==2)cout<<"First player wins flying to airport "<<v[k][0];
        else
        {
            sort(v[k].begin(),v[k].end());
            for(int i=0;i<v[k].size() && nodulet==0;++i)if(c[v[k][i]]==0)nodulet=v[k][i];
            cout<<"First player wins flying to airport "<<nodulet;
        }
    }
    return 0;
}
