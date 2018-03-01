#include <iostream>

using namespace std;
int a[20];
int main()
{
    cin.sync_with_stdio(false);
    a[0]=1;
    for(int i=1;i<=15;++i)
        for(int j=1;j<=i;++j)a[i]+=a[i-j];
    for(int i=1;i<=10;++i)cout<<a[i]<<" ";
    return 0;
}
