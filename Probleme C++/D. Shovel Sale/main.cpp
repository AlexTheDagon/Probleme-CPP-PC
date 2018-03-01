#include <iostream>

using namespace std;
long long n9,p=1;
long long gen(long long n)
{
    if(n<=4)return n*(n-1)/2;
    p=1;
    long long sol=0;
    n9=0;
    while(n9<=2*n-1)
    {
        n9=n9*10+9;
        p*=10;
    }
    n9/=10;
    p/=10;
    while(n9<2*n)
    {
        if(n9<=n)sol+=n9/2;
        else sol+=(n-(n9-n)+1)/2;
        n9+=p;
    }
    return sol;
}
long long n,T,sol,sol1;
int main()
{
    cin>>n;
    cout<<gen(n);
    return 0;
}
