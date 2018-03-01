#include <iostream>

using namespace std;
int n,m,p=1,cnt;
int main()
{
    cin>>n>>m;
    while(p<m)
    {
        ++cnt;
        p*=2;
    }
    if(cnt<n)cout<<m;
    else
    {
        cout<<m%(1<<n);
    }
    return 0;
}
