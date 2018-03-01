#include <iostream>

using namespace std;
int poz,neg,x,y,n;
int main()
{
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x>>y;
        if(x<0)++neg;
        else ++poz;
    }
    if(neg<=1 || poz<=1)cout<<"Yes";
    else cout<<"No";
    return 0;
}
