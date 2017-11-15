#include <iostream>
#include <algorithm>
#define x first
#define y second
using namespace std;
pair<int,int> a[5005];
int sol,n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
    {
        if(sol<=a[i].y)sol=a[i].y;
        else sol=a[i].x;
    }
    cout<<sol;
    return 0;
}
