#include <iostream>

using namespace std;
int a,b;
int main()
{
    cin>>a>>b;
    if((a==b || a==b-1 || a-1==b) && (a!=0 || b!=0))cout<<"YES";
    else cout<<"NO";
    return 0;
}
