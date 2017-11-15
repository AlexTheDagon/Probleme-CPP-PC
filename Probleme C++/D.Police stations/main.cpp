#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define NM 300005
#define x first
#define y second
using namespace std;
int n,k,d,viz[NM],a,b,elim[NM],cnt;
vector <pii> v[NM];
queue <pii> q;
pii fr;
int main()
{
    cin>>n>>k>>d;
    for(int i=1;i<=k;++i)
    {
        cin>>a;
        q.push(mp(a,0));
    }
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        v[a].pb(mp(b,i));
        v[b].pb(mp(a,i));
    }
    while(!q.empty())
    {
        fr=q.front();
        q.pop();
        if(!viz[fr.x])
        {
            viz[fr.x]=1;
            for(auto i:v[fr.x])
            {
                if(i.x!=fr.y)
                {
                    if(viz[i.x])
                    {
                        elim[i.y]=1;
                        ++cnt;
                    }
                    else q.push(mp(i.x,fr.x));
                }
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<n;++i)if(elim[i])cout<<i<<" ";
    return 0;
}
