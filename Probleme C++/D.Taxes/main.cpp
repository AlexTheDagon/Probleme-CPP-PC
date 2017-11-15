#include <iostream>
#include <math.h>
using namespace std;
int n;
int eprim(int x)
{
    if(x==2 || x==3)return 1;
    for(int d=2;d<=sqrt(x);++d)if(x%d==0)return 0;
    return 1;
}
int main()
{
    cin>>n;
    if(eprim(n))cout<<"1";
    else
    {
        if(n%2==0)cout<<"2";
        else
        {
            if(eprim(n-3) || eprim(n-2))cout<<"2";///cauzrile 5,3
            else cout<<"3";
        }
    }
    return 0;
}
