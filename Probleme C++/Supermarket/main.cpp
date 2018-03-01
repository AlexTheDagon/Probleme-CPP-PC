#include <iostream>
#include <iomanip>
using namespace std;
double a,b,minn=1000000,m;
int n;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a>>b;
        minn=min(minn,1.0*a/b*m);
    }
    cout<<fixed<<setprecision(8)<<minn;
    return 0;
}
