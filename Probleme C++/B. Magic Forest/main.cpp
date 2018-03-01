#include <iostream>

using namespace std;
int n,k,sol;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            k=i^j;
            if(j<=k && i+j>k && k<=n)++sol;
        }
    }
    cout<<sol;
    return 0;
}
