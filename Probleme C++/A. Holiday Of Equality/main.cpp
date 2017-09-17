#include <iostream>

using namespace std;
int n,maxx,s,a;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        maxx=max(maxx,a);
        s+=a;
    }
    cout<<n*maxx-s;
    return 0;
}
