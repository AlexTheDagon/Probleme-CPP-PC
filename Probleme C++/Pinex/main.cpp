#include <iostream>
#include <fstream>
#define NM 1000005
#define PM 80000
using namespace std;
ifstream in("pinex.in");
ofstream out("pinex.out");
bool ep[NM];
long long  prim[PM];
long long a,b,fact[PM],t,p;
long long pinex()
{
    long long prod=1,nrt=a;
    int nr=0,sem=0;
    for(int i=1;prim[i]*prim[i]<=b && i<=p;++i)
    {
        if(b%prim[i]==0)
        {
            fact[++nr]=prim[i];
            while(b%prim[i]==0)b/=prim[i];
        }
    }
    if(b>1)fact[++nr]=b;
    for(int i=1;i<(1<<nr);++i)
    {
        prod=1;
        for(int j=sem=0;j<nr;++j)
        {
            if(i&(1<<j))
            {
                prod*=fact[j+1];
                sem=(sem+1)%2;
            }
        }
        if(sem)nrt-=a/prod;
        else nrt+=a/prod;
    }
    return nrt;
}
int main()
{
    for(int i=2;i<NM;++i)
    {
        if(!ep[i])
        {
            prim[++p]=i;
            for(int j=2*i;j<NM;j+=i)ep[j]=1;
        }
    }
    ///bine
    in>>t;
    for(int i=1;i<=t;++i)
    {
        in>>a>>b;
        out<<pinex()<<'\n';
    }
    return 0;
}
