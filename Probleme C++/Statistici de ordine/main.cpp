#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream in("sdo.in");
ofstream out("sdo.out");
int n,k,a[3000005];
int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)in>>a[i];
    nth_element(a+1,a+k,a+n+1);
    out<<a[k];
    return 0;
}
