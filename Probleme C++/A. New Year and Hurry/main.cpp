#include <iostream>

using namespace std;
int n,k,t,p;
int main()
{

    cin>>n>>k;
    t=240-k;
    for(int i=1;i<=n;++i)
    {
        if(t>=5*i)
        {
            t=t-5*i;
            ++p;
        }
    }
    cout<<p;
    return 0;
}
