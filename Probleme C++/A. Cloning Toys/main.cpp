#include <iostream>

using namespace std;
int x,y;
int main()
{
    cin>>y>>x;
    if(x==1 && y!=0)
    {
        cout<<"No";
        return 0;
    }
    --x;
    y-=x;
    if(y%2==0 && y>=0 && x!=0)cout<<"Yes";
    else cout<<"No";
    return 0;
}
