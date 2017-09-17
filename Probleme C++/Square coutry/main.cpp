#include <iostream>

using namespace std;
int s,a[60005];
int main()
{
    cin>>s;
    for(int i=1;i*i<=s;++i)a[i*i]=1;
    for(int i=1;i<=s;++i)
    {
        for(int j=1;j*j<=i;++j)
        {
            if(a[i]==0 || a[i]>a[j*j]+a[i-j*j])a[i]=a[j*j]+a[i-j*j];
        }
    }
    cout<<a[s];
    return 0;
}
