#include <iostream>
#include <set>
#include <vector>
#define pb push_back
using namespace std;
set<pair<int,int> > forbid;
set<int> remaining;
int n,m,l,deg,x,y,comp,k;
bool ok(int a,int b)
{
    if(a>b)swap(a,b);
    return (forbid.find({a,b})==forbid.end());
}
void dfs(int nod)
{
    vector<int> v;
    for(auto i:remaining)
        if(ok(nod,i))v.pb(i);
    for(auto i:v)
        remaining.erase(i);
    for(auto i:v)
        dfs(i);
}
int main()
{
    cin>>n>>m>>k;
    for(int i=2;i<=n;++i)remaining.insert(i);
    deg=n-1;///grad 1
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        if(x>y)swap(x,y);
        if(x==1)--deg;
        forbid.insert({x,y});
    }
    if(deg<k)
    {
        cout<<"impossible";
        return 0;
    }
    for(int i=2;i<=n;++i)
    {
        if(ok(1,i) && remaining.find(i)!=remaining.end())
        {
            ++comp;
            dfs(i);
        }
    }
    if(!remaining.empty() || comp>k)
    {
        cout<<"impossible";
        return 0;
    }
    cout<<"possible";
    return 0;
}
