#include <iostream>

using namespace std;
int k,a,b,rep;
int main()
{
    cin>>k>>a>>b;
    rep=a/k+b/k;
    if(a/k==0 && b%k!=0)cout<<"-1";
    else
    {
        if(b/k==0 && a%k!=0)cout<<"-1";
        else cout<<rep;
    }
    return 0;
}
