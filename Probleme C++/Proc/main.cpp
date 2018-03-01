#include <iostream>
#include <fstream>
using namespace std;
ifstream in("proc.in");
ofstream out("proc.out");
int n,k,p,hi,low,mid;
int verif(int timp)
{
    int f1=k,f2=n-k,ramas,el;
    for(int i=1;i<=p;++i)
    {
        ramas=timp;
        el=ramas/2/i;
        el=min(el,f2);
        f2-=el;
        ramas-=el*2*i;
        el=ramas/i;
        el=min(el,f1);
        f1-=el;
        ramas-=el*i;
    }
    if(0==f2 && f1==0)return 1;
    return 0;
}
int main()
{
    in>>n>>k>>p;
    hi=2000000005;
    low=-1;
    while(hi-low>1)
    {
        mid=(hi+low)/2;
        if(verif(mid))hi=mid;
        else low=mid;
    }
    out<<hi;
    return 0;
}
