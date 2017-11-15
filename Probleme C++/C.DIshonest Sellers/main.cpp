#include <iostream>
#include <algorithm>
#define NM 200005
#define x first.first
#define y first.second
#define z second
#define mp make_pair
using namespace std;
pair<pair<int,int>,int> v[NM];
int n,k,sol;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>v[i].y;
    for(int i=1;i<=n;++i)
    {
        cin>>v[i].z;
        v[i].x=v[i].y-v[i].z;
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=n;++i)
    {
        if(i<=k)sol+=v[i].y;
        else
        {
            sol+=min(v[i].y,v[i].z);
        }
    }
    cout<<sol;
    return 0;
}
