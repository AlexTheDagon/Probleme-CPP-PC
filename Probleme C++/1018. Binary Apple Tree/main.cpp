#include <iostream>
#include <vector>
#define pb push_back
#define NM 105
using namespace std;
int dp[NM][NM],ap[NM],mere[NM][NM],n,q,a,b,c,viz[NM];
vector<int> v[NM],urm[NM];
void dfs(int nod)
{
    viz[nod]=1;
    for(auto i:v[nod])
    {
        if(!viz[i])
        {
            urm[nod].pb(i);
            dp[i][1]=ap[i]=mere[nod][i];
            dfs(i);
        }
    }
    if(urm[nod].size()==0)return;
    for(int i=0;i<=q+1;++i)
    {
        a=urm[nod][0];
        b=urm[nod][1];
        for(int j=0;j<i;++j)
            dp[nod][i]=max(dp[nod][i],dp[nod][1]+dp[a][j]+dp[b][i-1-j]);
    }
}
int main()
{
    cin>>n>>q;
    for(int i=1;i<n;++i)
    {
        cin>>a>>b>>c;
        v[a].pb(b);
        v[b].pb(a);
        mere[a][b]=mere[b][a]=c;
    }
    dfs(1);
    cout<<dp[1][q+1];
    return 0;
}
///dp[rad][ram]-->nr max de mere pe care le am in subarborele cu radacina in rad si care are ram ramuri
