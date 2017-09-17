#include <iostream>

using namespace std;
int interval=1,cr,descr,a,b,n1,n2,n;
int main()
{
    cin>>n1>>n2;
    cin>>b>>a;
    if(a>b)cr=1;
    else descr=1;
    n=n2-n1+1;
    for(int i=3;i<=n;++i)
    {
        cin>>a;
        if(a>b && descr==1)
        {
            ++interval;
            descr=0;
            cr=1;
        }
        if(a<b && cr==1)
        {
            ++interval;
            cr=0;
            descr=1;
        }
        b=a;
    }
    cout<<interval;
    return 0;
}
