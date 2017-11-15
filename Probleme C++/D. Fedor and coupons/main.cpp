#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#define NM 300005
#define x first.first
#define y first.second
#define z second
#define mp make_pair
using namespace std;
pair<pair<int,int>,int> a[NM];
priority_queue<int,vector<int>,greater<int> > q;
int n,k,ans,l;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].x>>a[i].y;
        a[i].z=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
	{
		if(q.size()<k)q.push(a[i].y);
		else
        {
            if(q.top()<a[i].y)
            {
                q.pop();
                q.push(a[i].y);
            }
        }
		if(ans<(q.top()-a[i].x+1) && q.size()==k)
        {
			ans=q.top()-a[i].x+1;
			l=a[i].x;///limita inferioara
        }
	}
	cout<<ans<<endl;
	if(ans==0)
	{
		for(int i=1;i<=k;++i)cout<<i<<" ";
		return 0;
	}
	for(int i=1;i<=n && k;++i)
    {
		if(a[i].x<=l && l+ans-1<=a[i].y)
        {
			cout<<a[i].z<<" ";
			--k;
        }
    }
    return 0;
}
///ajutor sursa
