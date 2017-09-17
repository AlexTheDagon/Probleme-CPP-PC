#include <iostream>
#include <fstream>
#define pb push_back
#include <vector>
using namespace std;
ifstream in("sortare2.in");
ofstream out("sortare2.out");
int n,d,poz[100005],pas=1,a;
vector <int> v[100005];
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a;
        if(poz[a-1]==0)
        {
            poz[a]=pas;
            v[pas].pb(a);
            ++pas;
        }
        else
        {
            poz[a]=poz[a-1];
            v[a-1].pb(a);
        }
    }
    out<<pas-2;
    return 0;
}
