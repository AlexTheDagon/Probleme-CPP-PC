#include <iostream>

using namespace std;
int n,a[105],k;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>k;
        a[k]=i;
    }
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";
    return 0;
}
