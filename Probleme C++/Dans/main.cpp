#include <iostream>
#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define NM 100005
#define mp make_pair
using namespace std;
ifstream in("dans.in");
ofstream out("dans.out");
int n,m,t,g[NM],a,b,beg,vec,leg,imp;
bool fol[500005];
stack<int> st;
vector<int> sol;
vector<pair<int,int> >v[NM];
int main()
{
    in.sync_with_stdio(false);
    out.sync_with_stdio(false);
    in>>t;
    while(t)
    {
        --t;
        imp=0;
        in>>n>>m;
        for(int i=1;i<=m;++i)
        {
            in>>a>>b;
            v[a].pb(mp(b,i));
            v[b].pb(mp(a,i));
            g[a]++;
            g[b]++;
        }
        for(int i=1;i<=n;++i)
            if(g[i]%2)beg=i;
        for(int i=1;i<=n;++i)
            if(g[i]%2)++imp;
        st.push(beg);
        while(!st.empty())
        {
            if(g[st.top()]==0)
            {
                sol.pb(st.top());
                st.pop();
            }
            else
            {
                while(fol[v[st.top()].back().y])
                    v[st.top()].pop_back();
                vec=v[st.top()].back().x;
                leg=v[st.top()].back().y;
                g[vec]--;
                g[st.top()]--;
                fol[leg]=1;
                st.push(vec);
            }
        }
        if(sol.size()==m+1 && (imp==2 || imp==0))
        {
            out<<"DA"<<'\n';
            for(auto i:sol)
                out<<i<<" ";
            out<<'\n';
        }
        else out<<"NU";
        ///de aici reset
        for(int i=1;i<=n;++i)v[i].clear();
        for(int i=1;i<=m;++i)fol[i]=0;
        for(int i=1;i<=n;++i)g[i]=0;
        sol.clear();
    }
    return 0;
}
