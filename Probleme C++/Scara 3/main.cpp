#include <iostream>
#include <fstream>
#define NM 1205
#define inf 1000000000
using namespace std;
ifstream in("scara3.in");
ofstream out("scara3.out");
int e[NM],a[NM],dmin[NM],cmin[NM],k,l,n,t,d;
int main()
{
    in>>n;
    in>>k;
    for(int i=1;i<=k;++i)
    {
        in>>t>>d;
        a[t]=d;
    }
    in>>l;
    for(int i=1;i<=l;++i)
    {
        in>>t>>d;
        e[t]=d;
    }
    for(int i=1;i<=n;++i)dmin[i]=cmin[i]=inf;
    for(int i=0;i<n;++i)
    {
        if(a[i])
        {
            for(int j=1;j<=a[i] && i+j<=n;++j)
            {
                if(dmin[i]+1<dmin[i+j])
                {
                    dmin[i+j]=dmin[i]+1;
                    cmin[i+j]=cmin[i];
                }
                else if(dmin[i]+1==dmin[i+j])cmin[i+j]=min(cmin[i+j],cmin[i]);
            }
        }
        if(e[i])
        {
            for(int j=1;j<=2*e[i] && i+j<=n;++j)
            {
                if(dmin[i+j]>dmin[i]+1)
                {
                    dmin[i+j]=dmin[i]+1;
                    cmin[i+j]=cmin[i]+(j+1)/2;
                }
                else if(dmin[i+j]==dmin[i]+1)cmin[i+j]=min(cmin[i+j],cmin[i]+(j+1)/2);
            }
        }
        if(dmin[i]+1<dmin[i+1])
        {
            dmin[i+1]=dmin[i]+1;
            cmin[i+1]=cmin[i];
        }
        else if(dmin[i]+1==dmin[i+1])cmin[i+1]=min(cmin[i+1],cmin[i]);
    }
    out<<dmin[n]<<" "<<cmin[n];
    return 0;
}
