#include <iostream>
#define modulo 1000000007
using namespace std;
long long x,y,a[305],b[305],n,sa,sb;
int main()
{
    cin>>n>>x>>y;
    a[1]=1;
    b[1]=1;
    for(int i=2;i<=n;++i)
    {
        sa=0;
        sb=0;
        for(int j=x;j>0;--j)
        {
            sa+=a[j];
            a[j]=a[j-1];
        }
        for(int j=y;j>0;--j)
        {
            sb+=b[j];
            b[j]=b[j-1];
        }
        a[1]=sb%modulo;
        b[1]=sa%modulo;
    }
    sa=0;
    sb=0;
    for(int j=x;j>0;--j)
    {
        sa+=a[j];
        a[j]=a[j-1];
    }
    for(int j=y;j>0;--j)
    {
        sb+=b[j];
        b[j]=b[j-1];
    }
    cout<<(sa+sb)%modulo;
    return 0;
}
