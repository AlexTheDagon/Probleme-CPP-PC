#include <iostream>
#define NM 3005
#define IN 1<<30
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
using namespace std;
long long n,d1[2*NM],d2[2*NM],m1,m2,a[NM][NM],x;
pii b1,b2;
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>x;
            a[i][j]=x;
            d1[n+i-j]+=x;
            d2[i+j]+=x;
        }
    }
    b1={1,2};
    b2={1,1};
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if((i+j)%2 && d1[n+i-j]+d2[i+j]-a[i][j]>m1)
            {
                b1=mp(i,j);
                m1=d1[n+i-j]+d2[i+j]-a[i][j];
            }
            if((i+j)%2==0 && d1[n+i-j]+d2[i+j]-a[i][j]>m2)
            {
                b2=mp(i,j);
                m2=d1[n+i-j]+d2[i+j]-a[i][j];
            }
        }
    }
    cout<<m1+m2<<endl;
    cout<<b1.x<<" "<<b1.y<<" "<<b2.x<<" "<<b2.y;
    return 0;
}
