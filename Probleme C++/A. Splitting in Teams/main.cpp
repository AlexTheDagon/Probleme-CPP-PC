#include <iostream>

using namespace std;
int n,x,a[2],t;
int main()
{
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        ++a[x%2];
    }
    t=min(a[0],a[1]);
    if(a[0]<a[1])t+=(a[1]-a[0])/3;
    cout<<t;
    return 0;
}
