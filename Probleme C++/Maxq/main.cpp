#include <iostream>
#include <fstream>
#define NM 200005
using namespace std;
ifstream in("maxq.in");
ofstream out("maxq.out");
long long v[NM],s,smax,a,b,c,n,m;
int main()
{
    int aaa=0;
    for(int i=1;i<=2015;++i)
        if(i%5==0 || i%3==0)++aaa;
    cout<<aaa;
    return 0;
}
