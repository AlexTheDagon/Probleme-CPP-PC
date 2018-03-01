#include <iostream>
#include <bits/stdc++.h>
#define pb push_back
#define NM 50005
#define f first
#define s second
using namespace std;
ifstream in("domino.in");
ofstream out("domino.out");
struct piesa
{
    int x,y,z;
};
vector<piesa> v[12],sol;
piesa p;
int g[10],fol[NM],n,m,a,b,beg,ok,act;
stack<piesa> st;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a>>b;
        beg=a;
        v[a].pb({b,i,0});
        v[b].pb({a,i,1});
        g[a]++;
        g[b]++;
    }
    for(int i=1;i<10;++i)
        if(g[i]%2)beg=i;

    st.push({beg,0,0});
    while(!st.empty())
    {
        p=st.top();
        if(g[p.x]==0)
        {
            if(st.size()>1)sol.pb({p.y,p.z,0});
            st.pop();
        }
        else
        {
            act=p.x;
            while(fol[v[act].back().y])
                v[act].pop_back();
            p=v[act].back();
            --g[act];
            --g[p.x];
            fol[p.y]=1;
            st.push(p);
        }
    }
    if(sol.size()!=n)out<<"0"<<'\n';
    else
    {
        out<<"1"<<'\n';
        for(int i=sol.size()-1;i>=0;--i)
            out<<sol[i].x<<" "<<sol[i].y<<'\n';
    }
    return 0;
}
