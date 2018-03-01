#include <iostream>

using namespace std;
long long n,p[50],l,sol;
int main()
{
    cin>>n>>l;
    for(int i=0;i<31;++i)p[i]=2000000000000000000;
    for(int i=0;i<n;++i)cin>>p[i];
    for(int i=0;i<31;++i)
        for(int j=i+1;j<31;++j)
            if(p[i]*(1LL<<(j-i))<p[j])p[j]=p[i]*(1LL<<(j-i));
    for(int i=0;i<31;++i)
    {
        if((1LL<<i)&l)sol+=p[i];
        else if(p[i]<sol)sol=p[i];
    }
    for(int i=0;i<31;++i)
        if((1LL<<i)>=l)sol=min(sol,p[i]);
    cout<<sol;
    return 0;
}
