#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#define pb push_back
#define NM 10001
using namespace std;
ifstream in("cezar.in");
ofstream out("cezar.out");
int n,k;
vector <short> v[NM];
short cost[NM];

struct Compare
{
    inline bool operator () (const short &a, const short &b) const
    {
        return cost[a] > cost[b];
    }
};
priority_queue<short,vector<short>,Compare > q;
int main()
{
    in>>n>>k;
    for(short i=1;i<n;++i)
    {
        cost[i]=1;
        int a,b;
        in>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    in.close();
    cost[n]=1;
    ///cost stabilit
    ///legaturile stabilite
    for(short i=1;i<=n;++i)
        if(v[i].size()==1)
            q.push(i);
    ///initializat coada
    int sol=0;
    for(short i=n-1;i>k;--i)
    {
        short fr=q.top();
        q.pop();
        sol+=cost[fr];
        short p=v[fr][0];
        v[fr].clear();
        cost[p]+=cost[fr];
        v[p].erase(find(v[p].begin(),v[p].end(),fr));
        if(v[p].size()==1)q.push(p);
    }
    out<<sol;
    out.close();
    return 0;
}
