#include <iostream>

using namespace std;
int n,s,aux,k;
int main()
{
    cin>>k;
    for(int i=1;i<=20000000;++i)
    {
        aux=i;
        s=0;
        while(aux)
        {
            s+=aux%10;
            aux/=10;
        }
        if(s==10)
        {
            ++n;
            if(n==k)
            {
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}
