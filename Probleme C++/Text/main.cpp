#include <iostream>
#include <fstream>
using namespace std;
string s,c[1005];
int maxx,r,cuv;
int main()
{
    in>>maxx;
    while(in>>s)
    {
        if(r>=s.size())
        {
            c[++cuv]=s;
            r-=s.size();
            --r;
        }
    }
    return 0;
}
