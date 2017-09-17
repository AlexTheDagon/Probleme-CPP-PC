#include <iostream>
#include <vector>
#define NM 1000005
#define pb push_back
#define inf 1000000000
using namespace std;
int n,k,lng,t,m,x;
string s;
char sol[10*NM];
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s>>m;
        k=s.size();
        t=-inf;
        for(int j=1;j<=m;++j)
        {
            cin>>x;
            --x;
            lng=max(lng,x+k);
            for(int l=max(t,x);l<x+k;++l)
                sol[l]=s[l-x];
            t=x+k;
        }
    }
    for(int i=0;i<lng;++i)
    {
        if(isalpha(sol[i]))cout<<sol[i];
        else cout<<"a";
    }
    return 0;
}
