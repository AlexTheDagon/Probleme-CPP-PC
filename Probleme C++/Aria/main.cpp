#include <iostream>
#include <fstream>
#include <iomanip>
#define pdd pair<long double,long double>
#define mp make_pair
#define x first
#define y second
using namespace std;
ifstream in("aria.in");
ofstream out("aria.out");
long double det(pdd A,pdd B,pdd C)
{
    return(A.x*B.y+B.x*C.y+C.x*A.y-B.x*A.y-C.x*B.y-A.x*C.y);
}
pdd P1,P2,P,PP;
long double arie;
int n;
int main()
{
    in>>n;
    if(n<=2)
    {
        out<<"0";
        return 0;
    }
    in>>P1.x>>P1.y;
    PP=P1;
    for(int i=2;i<=n;++i)
    {
        in>>P2.x>>P2.y;
        arie+=det(P,P1,P2);
        P1=P2;
    }
    arie+=det(P,P1,PP);
    out<<fixed<<setprecision(5)<<arie/2.0;
    return 0;
}
