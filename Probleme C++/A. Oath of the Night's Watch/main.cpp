#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100005],minn=(1<<30),maxx,s;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a+1,a+n+1);
    minn=a[1],maxx=a[n];
    for(int i=1;i<=n;++i)
    {
        if(a[i]>minn && a[i]<maxx)++s;
    }
    cout<<s;
    return 0;
}
