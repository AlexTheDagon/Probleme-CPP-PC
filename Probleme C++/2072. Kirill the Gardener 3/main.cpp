#include <iostream>
#include <algorithm>
#include <stdlib.h>
#define x first
#define y second
using namespace std;
int n,water;
pair<int,int> a[100005];
int main()
{
    cin>>n;
    water=n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].x;
        a[i].y=i;
    }
    sort(a+1,a+n+1);
    a[0].y=1;
    for(int i=1;i<=n;++i)
    {
        water+=abs(a[i].y-a[i-1].y);
    }
    cout<<water;
    return 0;
}
