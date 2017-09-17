#include <iostream>
#include <fstream>
using namespace std;
ifstream in("kbiti.in");
ofstream out("kbiti.out");
string s;
long long t,l,p,poz,put[40];
int main()
{
    in>>t;
    p=1;
    put[1]=1;
    for(int i=2;i<=32;++i)
    {
        p=p*2;
        put[i]=p;
    }
    for(int j=1;j<=t;++j)
    {
        in>>s;
        l=s.size();
        poz=1;
        for(int i=l-1;i>=0;--i)
        {
            if(s[i]=='1')poz+=put[l-i];
        }
        out<<poz<<'\n';
    }
    return 0;
}
