#include <iostream>

using namespace std;
int a,b,mst,mdr,n,m;
int main()
{
    cin>>n>>m>>mst>>mdr;
    for(int i=2;i<=n;++i)
    {
        cin>>a>>b;
        if(mst<=a && a<=mdr && mdr<b)mdr=b;
    }
    if(m>=mst && m<=mdr)cout<<"YES";
    else cout<<"NO";
    return 0;
}
