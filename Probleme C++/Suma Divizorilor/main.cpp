#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
ifstream in("sumdiv.in");
ofstream out("sumdiv.out");
long long  a,b,aux,d,e,r=1,prim=9901;
long long  lgput(long long  baza,long long  exp)
{
    baza%=prim;
    long long rez=1;
    while(exp)
    {
        if(exp&1)rez*=baza;
        baza*=baza;
        baza%=prim;
        rez%=prim;
        exp>>=1;
    }
    return rez;
}
int main()
{
    in>>a>>b;
    for(d=2;d*d<=a && a>1;++d)
    {
        e=0;
        while(a%d==0)
        {
            a/=d;
            ++e;
        }
        if(e!=0 && d%prim!=0)
        {
            if(d%prim==1)r=r*(e*b+1);
            else
            {
                aux=(lgput(d,e*b+1)-1)%prim;
                if(aux<0)aux+=prim;
                r=r*aux;
                r%=prim;
                r=r*lgput(d-1,prim-2);
                r%=prim;
            }
        }
    }
    if(a>1 && a%prim!=0)
    {
        if(a%prim==1)r=(r*(b+1))%prim;
        else
        {
            aux=(lgput(a,b+1)-1);
            if(aux<0)aux+=prim;
            r=r*aux;
            r%=prim;
            r=r*lgput(a-1,prim-2);
            r%=prim;
        }
    }
    out<<r;
    return 0;
}
