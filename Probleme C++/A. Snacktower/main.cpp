#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define x first
#define y second
using namespace std;
int n;
pair<int,int> a[100005];
vector <int> v[100005];
int ind[100005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].x;
        a[i].y=i;
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;--i)
    {
        ind[i]=max(ind[i+1],a[i].y);
        v[ind[i]].pb(i);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<v[i].size();++j)cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
