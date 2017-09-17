#include <iostream>

using namespace std;
int n,a[105],sem;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    if(a[1]%2==0 || a[n]%2==0 || n%2==0)sem=1;
    if(sem)cout<<"NO";
    else cout<<"YES";
    return 0;
}
