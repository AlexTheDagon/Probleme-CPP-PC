#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define MM 500005
#define x first
#define y second
#define pii pair<int,int>
#define NM 100005
#define mp make_pair
using namespace std;
ifstream in("ciclueuler.in");
ofstream out("ciclueuler.out");
vector<pii> v[NM];
int grad[NM],fol[MM],revin,n,m,a,b,viz[NM];
stack<int> s;
void dfs(int nod)
{
    viz[nod]=1;
    for(auto i:v[nod])
        if(!viz[i.x])
            dfs(i.x);
}
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
    dfs(1);
    for(int i=1;i<=n;++i)
        if(!viz[i] || grad[i]%2)
        {
            out<<"-1";
            return 0;
        }
    s.push(1);
    while(!s.empty())
    {
        if(grad[s.top()]==0)
        {
            if(revin)out<<s.top()<<" ";
            else revin=1;
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
    return 0;
}
