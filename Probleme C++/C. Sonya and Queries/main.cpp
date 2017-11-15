#include <iostream>

using namespace std;
int l1,l2,l3,x,y,cnt;
int main()
{
    cin>>x>>y;
    l1=l2=l3=y;
    while(l1<x || l2<x || l3<x)
    {
        ++cnt;
        if(cnt%3==1)l1=l2+l3-1;
        if(cnt%3==2)l2=l1+l3-1;
        if(cnt%3==0)l3=l2+l1-1;
    }
    cout<<cnt;
    return 0;
}
