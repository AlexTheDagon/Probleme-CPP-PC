#include <iostream>

using namespace std;
long long n,m,k,x,y,maxx,minn,ser,md,ture;
int main()
{
    cin>>n>>m>>k>>x>>y;
    if(n<=2)
    {
        md=n*m;
        maxx=k/md;
        minn=maxx;
        ser=maxx;
        if(k%md>0)++maxx;
        if(k%md==0)++minn;
        if((k%md)-((x-1)*m)>=y)++ser;
        cout<<maxx<<'\n'<<minn<<'\n'<<ser;
    }
    else
    {
        md=(n-1)*m;
        ture=k/md;
        minn=ture/2;
        if(ture%2==1 && k%md>=m)++minn;///bine
        maxx=ture;
        if(k%md>m)++maxx;
        if(x==1 || x==n)
        {
            ser=(ture)/2;
            if(k%md>=y)++ser;
        }
        else
        {
            ser=ture;
            if(ture%2==0 && k%md-(x-1)*m>=y)++ture;
            if(ture%2==1 && k%md-(n-x)*m>=y)++ture;
        }
        if(maxx==0)maxx=1;
        cout<<maxx<<'\n'<<minn<<'\n'<<ser;
    }
    return 0;
}
