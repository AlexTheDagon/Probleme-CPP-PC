#include <iostream>

using namespace std;
int a,b,c,poz=-1,pas,init;
int main()
{
    cin>>a>>b>>c;
    init=a;
    a=a*10;
    while(a!=init && poz==-1 && pas<=1000000)
    {
        ++pas;
        if(c==a/b)poz=pas;
        a=a%b;
        a*=10;
    }
    cout<<poz<<'\n';
    return 0;
}
