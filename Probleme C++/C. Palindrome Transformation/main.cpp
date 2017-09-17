#include <iostream>
#include <stdlib.h>
using namespace std;
string s,ss;
int n,p,l,r,cost;
int dist(char a,char b)
{
    if(a>b)swap(a,b);
    return(min(b-a,a-b+26));
}
int main()
{
    cin>>n>>p>>ss;
    s=' '+ss;
    /////////////////
    l=n+1;
    r=0;
    if(p>n/2)p=n+1-p;
    for(int i=1;i<=n/2;++i)
    {
        if(s[i]!=s[n+1-i])
        {
            l=min(l,i);
            r=max(r,i);
            cost+=dist(s[i],s[n+1-i]);
        }
    }
    if(r==0)
    {
        cout<<"0";
        return 0;
    }
    cost+=r-l+min(abs(l-p),abs(r-p));
    cout<<cost;
    return 0;
}
