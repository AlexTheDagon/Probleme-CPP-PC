#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream in("algsort.in");
ofstream out("algsort.out");
int n,a[500005];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)out<<a[i]<<" ";
    return 0;
}
