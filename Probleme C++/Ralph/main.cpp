#include <iostream>
#include <math.h>
using namespace std;
long long n,m,k,x,sol=1,b=2,mod=1000000007;
int main()
{
    cin.sync_with_stdio(false);
    cin>>n>>m>>k;

    if(k==-1 && n%2!=m%2)cout<<0;
    else
    {
        x=(n-1);

        for(int i=0; i<63; i++)
        {
            if(x&(1LL<<i))sol=sol*b;

            b=b*b;
            sol=sol%mod;
            b=b%mod;
        }
        b=sol;
        sol=1;
        x=m-1;
        for(int i=0; i<63; i++)
        {
            if(x&(1LL<<i))sol=sol*b;

            b=b*b;
            sol=sol%mod;
            b=b%mod;
        }
        cout<<sol;
    }



    return 0;
}
