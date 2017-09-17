#include <iostream>

using namespace std;
int n,sol,aux,auxx,m;
int main()
{
    cin>>n;
    for(int i=1;i<=512;++i)
    {
        auxx=0;
        m=1;
        aux=i;
        while(aux)
        {
            auxx+=m*(aux%2);
            m*=10;
            aux/=2;
        }
        if(auxx<=n)++sol;
    }
    cout<<sol;
    return 0;
}
///editorial
