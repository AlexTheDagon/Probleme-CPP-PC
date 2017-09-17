#include <iostream>

using namespace std;
long long a,b,c,n,sem;
int main()
{
    cin>>n;
    for(int i=0;i*1234567<=n;++i)
    {
        for(int j=0;j*123456+i*1234567<=n;++j)
        {
            if((n-i*1234567-j*123456)%1234==0)sem=1;
        }
    }
    if(sem)cout<<"YES";
    else cout<<"NO";
    return 0;
}
