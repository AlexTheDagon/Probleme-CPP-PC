#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <map>
#include <stdlib.h>
#define pb push_back
#define NM 100005
#define MM 200005
using namespace std;
ifstream in("drum4.in");
ofstream out("drum4.out");
vector<int> v[NM],sol[NM],v2[NM];
int low[NM],viz[NM],viz2[NM],a,b,n,m,init[NM],h,ins[NM],nrsol,ctc[NM],fr1[NM],fr2[NM],lies,lint;
stack<int> s;
map<pair<int,int>,int> mp;
void dfs(int nod)
{
    ++h;
    low[nod]=init[nod]=h;
    s.push(nod);
    viz[nod]=1;
    ins[nod]=1;
    for(auto i:v[nod])
    {
        if(viz[i]==0)
        {
            dfs(i);
            low[nod]=min(low[nod],low[i]);
        }
        else
        {
            if(ins[i]==1)low[nod]=min(low[nod],low[i]);
        }
    }
    if(init[nod]==low[nod])
    {
        ++nrsol;
        while(s.top()!=nod)
        {
            ins[s.top()]=0;
            sol[nrsol].pb(s.top());
            s.pop();
        }
        ins[s.top()]=0;
        sol[nrsol].pb(s.top());
        s.pop();
    }
}
void dfs2(int nod)
{
    viz2[nod]=1;
    for(auto i:v[nod])
    {
        if(mp.find(make_pair(ctc[nod],ctc[i]))==mp.end() && ctc[nod]!=ctc[i])
            {
                mp[make_pair(ctc[nod],ctc[i])]=1;
                ++fr2[ctc[i]];
                ++fr1[ctc[nod]];
            }
        if(!viz2[i])
        {
            dfs2(i);
        }
    }
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b;
        v[a].pb(b);
    }
    for(int i=1;i<=n;++i)
    {
        if(viz[i]==0)
        {
            h=0;
            dfs(i);
        }
    }
    for(int i=1;i<=nrsol;++i)
        for(auto j:sol[i])ctc[j]=i;
    for(int i=1;i<=n;++i)
    {
        if(!viz2[i])dfs2(i);
    }
    int nrleg=0;
    for(int i=1;i<=nrsol;++i)
    {
        if(!fr1[i])
        {
            ++lies;
        }
        if(!fr2[i])
        {
            ++lint;
        }
    }
    nrleg=min(lint,lies)+abs(lint-lies);
    out<<nrleg;
    return 0;
}
