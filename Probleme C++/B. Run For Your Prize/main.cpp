#include <iostream>

using namespace std;
int n,sol,x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x;
        sol=max(sol,min(x-1,1000000-x));
    }
    cout<<sol;
    return 0;
}
