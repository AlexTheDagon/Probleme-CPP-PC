#include <iostream>

using namespace std;
long long sol,n;
int main()
{
    cin>>n;
    sol=1;
    for(int i=1;i<=n+1;++i)sol*=2;
    cout<<sol-2;
    return 0;
}
