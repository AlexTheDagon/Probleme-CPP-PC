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
ifstream in("plan.in");
ofstream out("plan.out");
vector<int> v[NM],sol[NM],v2[NM],s1,s2;
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
            s1.push_back(i);
        }
        if(!fr2[i])
        {
            ++lint;
            s2.push_back(i);
        }
    }
    nrleg=min(lint,lies)+abs(lint-lies);
    if(nrsol==1)
    {
        out<<"0";
    }
    else
    {
        out<<nrleg<<'\n';
        for(int i=0;i+1<min(lint,lies);++i)
        {
            out<<sol[s1[i]][0]<<" "<<sol[s2[i+1]][0]<<'\n';
        }
        out<<sol[s1[min(lint,lies)-1]][0]<<" "<<sol[s2[0]][0]<<'\n';
        if(lint<lies)
        {
            for(int i=lint;i<lies;++i)
            {
                out<<sol[s1[i]][0]<<" "<<sol[s1[0]][0]<<'\n';
            }
        }
        else
        {
            for(int i=lies;i<lint;++i)
            {
                out<<sol[s2[0]][0]<<" "<<sol[s2[i]][0]<<'\n';
            }
        }
    }
    return 0;
}
///s1-din care nu iese
///s2 din care nu intra
