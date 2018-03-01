#include <iostream>

using namespace std;
int sol,n,x,y;
char c,ca;
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        ca=c;
        cin>>c;
        if(ca==c && x==y)++sol;
        if(c=='U')++y;
        else ++x;
    }
    cout<<sol;
    return 0;
}
