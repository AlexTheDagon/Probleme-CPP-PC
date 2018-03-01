#include <iostream>
#include <bits/stdc++.h>
#define NM 50005
#define MM 100005
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
ifstream in("johnie.in");
ofstream out("johnie.out");
vector<pii> v[NM];
int grad[NM],fol[2*MM],revin,n,m,a,b,viz[NM],nrsol;
vector<int> sol,ans[NM];
stack<int> s;
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b;
        v[a].pb(mp(b,i));
        v[b].pb(mp(a,i));
        grad[a]++;
        grad[b]++;
    }
    for(int i=1;i<=n;++i)
    {
        if(grad[i]%2==1)
        {
            nrsol++;
            grad[0]++;
            grad[i]++;///aici fac legatura de la 0 la i
            v[0].pb(mp(i,m+nrsol));
            v[i].pb(mp(0,m+nrsol));
        }
    }
    s.push(0);
    while(!s.empty())
    {
        if(grad[s.top()]==0)
        {
            sol.pb(s.top());
            s.pop();
        }
        else
        {
            int nod=s.top();
            while(fol[v[nod].back().y])
                v[nod].pop_back();
            int vecin=v[nod].back().x;
            int leg=v[nod].back().y;
            fol[leg]=1;
            grad[nod]--;
            grad[vecin]--;
            v[nod].pop_back();
            s.push(vecin);
        }
    }
    out<<nrsol/2<<'\n';
    nrsol=1;
    for(auto i:sol)
    {
        if(i==0 && ans[nrsol].size())++nrsol;
        else if(i!=0)ans[nrsol].pb(i);
    }
    for(int i=1;i<nrsol;++i)
    {
        out<<ans[i].size()<<" ";
        for(auto j:ans[i])out<<j<<" ";
        out<<'\n';
    }
    return 0;
}
///se leaga nodurile impare de nodul 0 si se formeaza toate ciclurile
