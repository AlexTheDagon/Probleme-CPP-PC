#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define NM 100005
#define x first
#define y second
using namespace std;
pii a[NM];
int n,k,leg[NM],ind=-1;
vector<int> d[NM];
vector<pii> sol;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].x;
        a[i].y=i;
    }
    sort(a+1,a+n+1);
    if(a[1].x!=0)
    {
        cout<<"-1";
        return 0;
    }
    d[0].pb(a[1].y);
    if(a[2].x==0)
    {
        cout<<"-1";
        return 0;
    }
    for(int i=2;i<=n;++i)
    {
        if(a[i].x!=a[i-1].x)ind=-1;
        if(d[a[i].x-1].empty())
        {
            cout<<"-1";
            return 0;
        }
        ++ind;
        if(ind==d[a[i].x-1].size())ind=0;
        if(leg[d[a[i].x-1][ind]]==k)
        {
            cout<<"-1";
            return 0;
        }
        else
        {
            sol.pb(mp(a[i].y,d[a[i].x-1][ind]));
            ++leg[d[a[i].x-1][ind]];
            ++leg[a[i].y];
            d[a[i].x].pb(a[i].y);
        }
    }
    cout<<sol.size()<<'\n';
    for(auto i:sol)cout<<i.x<<" "<<i.y<<endl;
    return 0;
}
