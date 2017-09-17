#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("triunghi5.in");
ofstream out("triunghi5.out");
long long v,n,k,a[100],minn=1<<30,b[100];
long long x,y,z,nr;
int main()
{
    in>>v>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        b[i]=a[i];
        minn=min(minn,a[i]);
    }
    sort(a+1,a+n+1);
    if(v==1)
    {
        x=0;
        y=minn;
        out<<minn<<" ";
        for(int i=2;i<=k;++i)
        {
            z=x+y;
            x=y;
            y=z;
            out<<y<<" ";
        }
    }
    else
    {
        int i=1;
        x=a[1];
        y=a[2];
        nr=n;
        if(x!=y)
        {
            x=0;
            y=1;
            ++nr;
            b[nr]=1;
        }
        while(nr<k && i<=n)
        {
            z=x+y;
            if(y+z<=a[i])
            {
                ++nr;
                b[nr]=z;
                x=y;
                y=z;
            }
            else
            {
                x=y;
                y=a[i];
                ++i;
            }
        }
        if(nr<k)
        {
            if(a[n-1]>b[nr])x=a[n-1];
            else x=b[nr];
            y=a[n];
            while(nr<k)
            {
                z=x+y;
                ++nr;
                b[nr]=z;
                x=y;
                y=z;
            }
        }
        for(i=1;i<=k;++i)out<<b[i]<<" ";
    }
    return 0;
}
