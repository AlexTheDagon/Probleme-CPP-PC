#include <iostream>

using namespace std;
string home,a,b,act;
int n;
char c;
int main()
{
    cin>>n;
    cin>>home;
    act=home;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=3;++j)
        {
            cin>>c;
            a+=c;
        }
        cin>>c;
        cin>>c;
        for(int j=1;j<=3;++j)
        {
            cin>>c;
            b+=c;
        }
        if(a==act)act=b;
        a="";
        b="";
    }
    if(n%2==0)cout<<"home";
    else cout<<"contest";
    return 0;
}
