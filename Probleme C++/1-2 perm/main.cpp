#include <iostream>
#include <fstream>
#define m 1048576
using namespace std;
ifstream in("12perm.in");
ofstream out("12perm.out");
int n,a[10];
int main()
{
    in>>n;
    a[4]=12;
    a[3]=6;
    a[2]=2;
    a[1]=1;
    for(int i=5;i<=n;++i)
    {
        a[5]=a[4]+a[2]+2*(i-2);
        a[5]%=m;
        a[1]=a[2];
        a[2]=a[3];
        a[3]=a[4];
        a[4]=a[5];
    }
    if(n>4)out<<a[5];
    else out<<a[n];
    return 0;
}
