#include <iostream>
#include <stdlib.h>
using namespace std;
long long n,m,a[100005],time,minn,maxx;
int main()
{
    cin>>n>>m;
    a[0]=1;
    for(int i=1;i<=m;++i)
    {
        cin>>a[i];
        if(a[i]<a[i-1])time=time+(n-a[i-1]+a[i]);
        else time=time+a[i]-a[i-1];
    }
    cout<<time;
    return 0;
}
