#include <iostream>
#include <algorithm>
#define NM 100005
using namespace std;
int a[NM],n,k,act,sol,sem;
bool cmp(int a,int b)
{
    return (a%10>b%10);
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        act+=(100-a[i]);
    }
    k=min(k,act);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;++i)
    {
        sem=0;
        while(a[i]%10 && k>0)
        {
            ++a[i];
            --k;
        }
        sol+=a[i]/10;
    }
    sol+=k/10;
    cout<<sol;
    return 0;
}
