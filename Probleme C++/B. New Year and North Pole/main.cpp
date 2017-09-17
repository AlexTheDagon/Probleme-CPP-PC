#include <iostream>

using namespace std;
int n,t,dN,sem;
string dir;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>t>>dir;
        if(dN==0 && dir!="South")sem=1;
        if(dN<0 || dN>20000)sem=1;
        if(dN==20000 && dir!="North")sem=1;
        if(dir=="North")dN-=t;
        if(dir=="South")dN+=t;
        dir="";
    }
    if(dN!=0)sem=1;
    if(sem==1)cout<<"NO";
    else cout<<"YES";
    return 0;
}
