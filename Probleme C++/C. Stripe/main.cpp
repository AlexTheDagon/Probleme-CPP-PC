#include <iostream>

using namespace std;
int sp[100005],s,n,m;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>sp[i];
        s+=sp[i];
        sp[i]+=sp[i-1];
    }
    for(int i=1;i<n;++i)
        if(sp[i]==s-sp[i])++m;
    cout<<m;
    return 0;
}
