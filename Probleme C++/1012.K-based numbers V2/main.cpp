#include <iostream>

using namespace std;
long long a[2000],n,k,nr,comb;
void recurs(int p)
{
    if(p>n)
    {
        comb=1;
        for(int i=1;i<=n+1;++i)
        {
            if(a[i]==1)comb*=(k-1);
        }
        nr+=comb;
        return;
    }
    if(a[p-1]==1)
    {
        a[p]=0;
        recurs(p+1);
    }
    a[p]=1;
    recurs(p+1);
}
int main()
{
    a[1]=1;
    cin>>n>>k;
    recurs(1);
    cout<<nr;
    return 0;
}
