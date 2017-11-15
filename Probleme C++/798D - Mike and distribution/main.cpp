#include <iostream>
#include <algorithm>
#define x first.first
#define y first.second
#define z second
#define NM 100005
using namespace std;
pair<pair<int,int>,int> a[NM];
int ind[NM],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i].x;
    for(int i=1;i<=n;++i)cin>>a[i].y;
    for(int i=1;i<=n;++i)a[i].z=i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n-(2-n%2);i+=2)
    {
        if(a[i].y<a[i+1].y)ind[a[i].z]=1;
		else ind[a[i+1].z]=1;
    }
    cout<<n/2+1<<endl;
    for(int i=1;i<=n;++i)if(!ind[i])cout<<i<<" ";
    return 0;
}
