#include <iostream>
#include <fstream>
#define prim 100003
using namespace std;
ifstream in("spion.in");
ofstream out("spion.out");
string s;
long long l,c,a,b,p,numitor=1;
int main()
{
    in>>p>>s;
    for(auto i:s)
    {
        ++l;
        if(i=='E')++c;
    }
    if(p==1)out<<c+1;
    else
    {
        a=b=1;
        for(int i=c+1;i<=l;++i)
        {
            a=a*i;
            a%=prim;
        }
        for(int i=2;i<=l-c;++i)
        {
            b=b*i;
            b%=prim;
        }
        numitor=b;
        for(int i=2;i<=prim-2;++i)
        {
            numitor*=b;
            numitor%=prim;
        }
        out<<(a*numitor)%prim;
    }
    return 0;
}
