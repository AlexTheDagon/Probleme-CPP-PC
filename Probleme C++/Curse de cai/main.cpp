#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("cai.in");
ofstream out("cai.out");
long long a[1005],b[1005],p,n,t,g,io,sarit,s,smax=-(1<<30),ramas;
int main()
{
    in>>t;
    for(int k=1;k<=t;++k)
    {
        in>>n;
        smax=-(1<<30);
        for(int i=1;i<=n;++i)in>>a[i];
        for(int i=1;i<=n;++i)in>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for(int i=1;i<=n;++i)
        {
            s=0;
            ramas=a[1];
            for(int j=1;j<n;++j)a[j]=a[j+1];
            a[n]=ramas;
            for(int j=1;j<=n;++j)
            {
                if(a[j]>b[j])s+=200;
                else
                {
                    if(a[j]<b[j])s-=200;
                }
            }
            if(s>smax)smax=s;
        }
        out<<smax<<'\n';
    }
    return 0;
}
