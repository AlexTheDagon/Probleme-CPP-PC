#include <iostream>
#include <vector>
#include <algorithm>
#define f first
#define s second
#define NM 200005
using namespace std;

int n;
int vis[NM],cost[NM],fr[NM],sol[NM];
vector<int>diviz;
vector<int> v[NM];

int mm(int a, int b)
{
    if(b==0)return a;
    return mm(b,a%b);
}

void dfs1(int nod)
{
    vis[nod]=1;
    for(auto i:v[nod])
        if (!vis[i])
        {
            sol[i]=mm(sol[nod],cost[i]);
            dfs1(i);
        }
}

void dfs2(int nod, int dist)
{
    vis[nod]=1;
    for (int i=0;i<diviz.size();i++)
    {
        fr[i]+=(cost[nod]%diviz[i]==0);
        if (fr[i]>=dist)
            sol[nod]=max(sol[nod],diviz[i]);
    }
    for (auto i:v[nod])
        if (!vis[i])
            dfs2(i,dist+1);
    for (int i=0;i<diviz.size();i++)
        fr[i]-=(cost[nod]%diviz[i]==0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>cost[i];
    for(int i=0;i<n-1;i++)
    {
        int a, b;
        cin>>a>>b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cp=cost[0];
    cost[0]=0;
    dfs1(0);
    cost[0]=cp;
    for(int i=0;i<n;i++)
        vis[i]=0;
    for(int i=1;i*i<=cost[0];i++)
    {
        if(cost[0]%i==0)
        {
            diviz.push_back(i);
            diviz.push_back(cost[0]/i);
            if(i*i==cost[0])
                diviz.pop_back();
        }
    }
    sort(diviz.begin(),diviz.end());
    dfs2(0,0);
    for(int i=0;i<n;i++)
        cout<<sol[i]<<' ';
    return 0;
}
///editorial+sursa
