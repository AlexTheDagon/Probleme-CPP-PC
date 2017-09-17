#include <iostream>

using namespace std;
long long n,w[100],r[100],b[100];
int main()
{
    cin>>n;
    w[1]=1;
    r[1]=1;
    for(int i=2;i<=n;++i)
    {
        b[i]=w[i-1]+r[i-1];
        w[i]=r[i-1]-w[i-2]+b[i-1];
        r[i]=w[i-1]+b[i-1]-r[i-2];
    }
    cout<<w[n]+r[n];
    return 0;
}
