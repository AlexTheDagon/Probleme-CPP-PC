#include <iostream>
#include <fstream>
using namespace std;
ifstream in("fact.in");
ofstream out("fact.out");
long long n,p,put=1,val,aux,sem;
int main()
{
    in>>p;
    aux=p;
    while(p>0)
    {
        put=1;
        val=0;
        while(val<=p)
        {
            put=put*5;
            val=val*5+1;
        }
        val=val-1;
        val/=5;
        put=put/5;
        n+=put;
        p-=val;
    }
    p=aux;
    put=5;
    val=0;
    while(put<=n)
    {
        val=val+n/put;
        put=put*5;
    }
    if(n==0)n=1;
    if(val==p)out<<n;
    else out<<"-1";
    return 0;
}
