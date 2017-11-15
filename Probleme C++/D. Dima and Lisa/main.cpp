#include <iostream>

using namespace std;
int n,act;
int eprim(int x)
{
    for(int d=2;d*d<=x;++d)if(x%d==0)return 0;
    return 1;
}
int main()
{
    cin>>n;
    if(eprim(n))cout<<"1"<<'\n'<<n;
    else
    {
        cout<<"3"<<'\n';
        cout<<"3 ";
        n-=3;
        act=n/2;
        while(!eprim(act) || !eprim(n-act))--act;
        cout<<act<<" "<<n-act<<'\n';
    }
    return 0;
}
