#include <iostream>
#include <fstream>

using namespace std;
ifstream in("crescator3.in");
ofstream out("crescator3.out");
long long n,a[100005],x,termen,poz,comuni;
long long sumcif(long long a)
{
    long long s=0;
    while(a)
    {
        s=s+a%10;
        a/=10;
    }
    return s;
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
    }
    termen=a[1];
    poz=1;
    while(a[n]>=termen)
    {
        if(a[poz]>termen)termen=termen+sumcif(termen);
        else
        {
            if(a[poz]==termen)++comuni;
            ++poz;
        }
    }
    out<<comuni;
    return 0;
}
