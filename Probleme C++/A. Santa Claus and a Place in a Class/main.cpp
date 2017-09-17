#include <iostream>

using namespace std;
int n,m,k,linie,col,rest;
int main()
{
    cin>>n>>m>>k;
    cout<<(k-1)/(2*m)+1<<" ";
    rest=k;
    if(rest%2==0)--rest;
    cout<<(rest%(2*m))/2+1<<" ";
    if(k%2)cout<<"L";
    else cout<<"R";
    return 0;
}
