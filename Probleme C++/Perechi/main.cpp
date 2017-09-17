#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in("perechi.in");
ofstream out("perechi.out");
int n,d,dpr[30],dpr2[30],nrdiv,nr=1,limit;
int main()
{
    in>>n;
    d=2;
    limit=sqrt(n)+1;
    while(d<=limit)
    {
        if(n%d==0)
        {
            ++nrdiv;
            while(n%d==0)
            {
                n=n/d;
                ++dpr[nrdiv];
            }
        }
        ++d;
    }
    if(n>1)++dpr[++nrdiv];
    if(nrdiv>0)
    {
        nr=dpr[nrdiv]+1;
        dpr2[nrdiv+1]=1;
        for(int i=1;i<=nrdiv;++i)dpr2[i]=dpr[i]*2+1;
        for(int i=nrdiv-1;i>0;--i)dpr2[i]*=dpr2[i+1];
        for(int i=nrdiv-1;i>0;--i)nr+=(dpr2[i+1]*dpr[i]);
    }
    out<<nr;
    return 0;
}
