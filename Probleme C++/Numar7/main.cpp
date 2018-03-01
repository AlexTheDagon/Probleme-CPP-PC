#include <iostream>
#include <fstream>
#define NM 25
using namespace std;
ifstream in("numere7.in");
ofstream out("numere7.out");
long long fact[NM],f[NM],p,n,s,sm,j;
char c;
int main()
{
    in>>p;
    while(in>>c)
    {
        ++n;
        ++f[c-'0'];
    }
    fact[0]=1;
    for(int i=1;i<=20;++i)
        fact[i]=fact[i-1]*i;
    for(int i=1;i<=n;++i)
    {
        sm=0;
        for(j=1;j<9;++j)
        {
            if(f[j])
            {
                --f[j];
                s=fact[n-i];
                for(int k=1;k<=9;++k)
                    s/=fact[f[k]];
                ++f[j];
                if(sm+s>=p)
                    break;
                sm+=s;
            }
        }
        p-=sm;
        f[j]--;
        out<<j;
    }
    return 0;
}
