#include <iostream>
#include <algorithm>\
#define x first
#define y second
using namespace std;
long long avg,ma,r,pr[100005];
long long  n,cost;
pair<long long ,long long > a[100005];
int main()
{
    cin.sync_with_stdio(false);
    cin>>n>>r>>avg;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].y>>a[i].first;
        ma+=a[i].y;
    }
    sort(a+1,a+n+1);
    avg=avg*n;
    for(int i=1;avg>ma;++i)
    {
        cost+=a[i].first*min(avg-ma,r-a[i].y);
        ma+=min(avg-ma,r-a[i].y);
    }
    cout<<cost<<endl;
    return 0;
}
