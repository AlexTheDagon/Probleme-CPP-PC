#include <iostream>

using namespace std;
int n;
int main()
{
    cin>>n;
    cout<<(n-1)/2;
    return 0;
}
///conectez 1,n   2,n-1 ... costul 0
///conectez 2,n  n-1,3 pana la jumate
///2  1-2
///3  1-3 1-2 cost
///4 1 4 2 5 2 4 cost 1
