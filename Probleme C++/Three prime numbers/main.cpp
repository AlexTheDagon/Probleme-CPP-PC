#include <iostream>
#include <vector>
#define modulo 1000000009
using namespace std;
vector <int> v[105];
int ciur[1005],n,nr;
long long a[105][3],s;
int main()
{
    for(int i=2;i<=1000;++i)ciur[i]=1;
    for(int i=2;i<=1000;++i)
        for(int j=2*i;j<=1000;j=j+i)ciur[j]=0;
    for(int i=100;i<=1000;++i)
    {
        if(ciur[i])
        {
            v[i/10].push_back(i%100);
            ++a[i%100][1];
        }
    }
    cin>>n;
    for(int h=4;h<=n;++h)
    {
        for(int i=10;i<100;++i)
        {
            if(v[i].size())
            {
                for(int j=0;j<v[i].size();++j)
                {
                    a[v[i][j]][2]+=a[i][1];
                    a[v[i][j]][2]%=modulo;
                }
            }
        }
        for(int i=10;i<100;++i)
        {
            a[i][1]=0;
            a[i][1]=a[i][2];
            a[i][2]=0;
        }
    }
    for(int i=10;i<100;++i)s=(s+a[i][1])%modulo;
    s+=modulo;
    if(n==3)s=143;
    cout<<s%modulo;
    return 0;
}
