#include <iostream>
#include <queue>
#include <vector>
#define mp make_pair
#define pii pair<long long,long long>
#define pb push_back
#define x first
#define y second
#define NM 300005
using namespace std;
pii a[NM],fr;
long long n,k,sol[NM],ind;
long long cost;
priority_queue <pii,vector<pii> > q;
int main()
{
    cin>>n>>k;
    for(long long i=1;i<=n;++i)
    {
        cin>>a[i].x;
        a[i].y=i;
    }
    for(long long i=1;i<=k;++i)q.push(a[i]);
    for(long long i=k+1;i<=n+k;++i)
    {
        if(i<=n)q.push(a[i]);
        fr=q.top();
        q.pop();
        sol[fr.y]=i;
        cost+=fr.x*(i-fr.y);
    }
    cout<<cost<<endl;
    for(long long i=1;i<=n;++i)cout<<sol[i]<<" ";
    return 0;
}
