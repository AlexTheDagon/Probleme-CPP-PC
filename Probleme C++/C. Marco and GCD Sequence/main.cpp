#include <iostream>

using namespace std;
int n,a[100005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]%a[1])
        {
            cout<<"-1";
            return 0;
        }
    }
    cout<<2*n-1<<'\n';
    cout<<a[1]<<" ";
    for(int i=2;i<n;++i)cout<<a[i]<<" "<<a[1]<<" ";
    cout<<a[n];
    return 0;
}
