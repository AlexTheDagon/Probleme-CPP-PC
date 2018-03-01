#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long k,p,sum;
long long rev(long long nr)
{
    long long nou=0;
    while(nr)
    {
        nou=nou*10+nr%10;
        nr/=10;
    }
    return nou;
}
long long cif(long long nr)
{
    int cif=0;
    while(nr)
    {
        nr/=10;
        ++cif;
    }
    return cif;
}
long long put[20],act,nc;
int main()
{
    put[0]=1;
    for(int i=1;i<=16;++i)put[i]=put[i-1]*10;
    cin>>k>>p;
    while(k)
    {
        ++act;
        nc=cif(act);
        sum=sum+act*put[nc]+rev(act);
        sum%=p;
        --k;
    }
    cout<<sum;
    return 0;
}
