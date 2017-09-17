#include <iostream>

using namespace std;
int n,a[105][105],sp[105][105],s,smax=-1<<29;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            a[i][j]+=a[i][j-1];
        }
    }
    for(int k=0;k<n;++k)
    {
        for(int j=k+1;j<=n;++j)
        {
            s=0;
            for(int i=1;i<=n;++i)
            {
                if(s<0)s=0;
                s+=a[i][j]-a[i][k];
                smax=max(s,smax);
            }
        }
    }
    cout<<smax;
    return 0;
}
