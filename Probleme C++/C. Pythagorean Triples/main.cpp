#include <iostream>

using namespace std;
long long a;
int main()
{
    cin>>a;
    if(a<3)cout<<"-1";
    else
    {
        if(a%2==1)cout<<(a*a-1)/2<<" "<<(a*a+1)/2;
        else cout<<a*a/4-1<<" "<<a*a/4+1;
    }
    return 0;
}
