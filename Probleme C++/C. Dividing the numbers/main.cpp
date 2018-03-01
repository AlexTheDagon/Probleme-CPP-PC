#include <iostream>
#include <bits/stdc++.h>
#define pbp ush_back
using namespace std;
long long n,s1,s2,s,fr[60005],cnt;
int main()
{
    cin>>n;
    s=n*(n+1)/2;
    cout<<s%2<<'\n';
    for(int i=n;i>0;--i)
    {
        if(s1<s2)
        {
            s1+=i;
            fr[i]=1;
        }
        else s2+=i;
    }
    for(int i=1;i<=n;++i)if(fr[i])++cnt;
    cout<<cnt<<" ";
    for(int i=1;i<=n;++i)if(fr[i])cout<<i<<" ";
    return 0;
}
