#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;
ifstream in("luffxor.in");
ofstream out("luffxor.out");
multiset <int> s;
int o,x,k,n,contor,val;
multiset <int>::iterator low,up;
multiset <int>::iterator p;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>o>>x;
        if(o==0)s.insert(x);
        if(o==1)
        {
            p=s.find(x);
            if(p!=s.end())s.erase(p);
        }
        if(o==2)
        {
            in>>k;
            k=k^x;
            low=(lower_bound(s.begin(),s.end(),0));
            up=upper_bound(s.begin(),s.end(),k);
            out<<low-up<<'\n';
        }
    }
    return 0;
}
