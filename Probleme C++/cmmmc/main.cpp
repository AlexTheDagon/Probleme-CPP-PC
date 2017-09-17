#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
ifstream in("cmmmc.in");
ofstream out("cmmmc.out");
int t,x,l1,l2,lim;
int perechi(int n)
{
    int d=2,dpr[30]={0},dpr2[30]={0},nrdiv=0,nr=1,limit;
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
    return nr;
}
int main()
{
    in>>t;
    for(int j=1;j<=t;++j)
    {
        in>>x;
        l1=1;
        l2=x;
        out<<"1 ";
        lim=sqrt(x);
        for(int d=1;d<=lim;++d)
        {
            if(((d+x/d)<(l1+l2)) && x%d==0 && d*d!=x)
            {
                l1=d;
                l2=x/d;
            }
        }
        if(l1>l2)swap(l2,l1);
        out<<l1<<" "<<l2<<'\n';
    }

    return 0;
}
