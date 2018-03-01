#include <iostream>

using namespace std;
int n,sol;
int main()
{
    cin>>n;
    for(int i=1;i<=n/2;++i)
        if(n%i==0)++sol;
    cout<<sol;
    return 0;
}
