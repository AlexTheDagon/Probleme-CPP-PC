#include <iostream>

using namespace std;
int maxx,a,b,n,c;
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a>>b;
        c=c-a+b;
        maxx=max(maxx,c);
    }
    cout<<maxx;
    return 0;
}
