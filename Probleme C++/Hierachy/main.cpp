#include <iostream>

using namespace std;
long long m[60],c,d,cost,lc,a,b;
int dp(int st,int fn)
{
    cost=0;
    c=st;
    d=fn;
    lc=0;
    long long upr=0,dwr=0;
    while(c!=d)
    {
        upr=c+(1<<lc);
        dwr=c+1;
        if(d>=upr)
        {
            while(d>=upr)
            {
                c=upr;
                ++lc;
                upr=c+(1<<lc);
            }
            cost=cost+m[lc-1]+lc-1;
        }
        else
        {
            cost+=lc-1;
            lc=0;
            ++c;
        }
    }
    return cost;
}
int main()
{
    cin>>a>>b;
    for(int i=1;i<=32;++i)
        m[i]=2*m[i-1]+2*(i-1);
    if(a>b)swap(a,b);
    cout<<dp(1,b)-dp(1,a);
    return 0;
}
