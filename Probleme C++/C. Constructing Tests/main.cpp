#include <iostream>
#include <math.h>
using namespace std;
long long x,n,m,act,t,root,b,a,sem;
void gen(long long xi)
{
    sem=0;
    if(x==0)
    {
        sem=1;
        cout<<"1 1"<<'\n';
        return;
    }
    for(b=1;b*b<=xi;++b)
    {
        if(xi%b==0)
        {
            a=(xi/b-b)/2;
            if(a==0)continue;
            n=a+b;
            m=(a+b)/a;
            if(n*n-(n/m)*(n/m)==xi)
            {
                sem=1;
                cout<<n<<" "<<m<<'\n';
                return;
            }
        }
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>x;
        gen(x);
        if(sem==0)cout<<"-1"<<'\n';
    }
    return 0;
}
