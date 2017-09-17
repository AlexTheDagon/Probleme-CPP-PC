#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#define x first
#define y second
#define pb push_back
using namespace std;
ifstream in("costuri.in");
ofstream out("costuri.out");
int n,q,k,c,l;
vector <int>::iterator low;
vector <int> a;
vector < pair<int,pair<int,int> > > s;
int pcif(int o)
{
    int p=min(1,o);
    while(o)
    {
        p=p*(o%10);
        o/=10;
    }
    return p;
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>k;
        a.pb(pcif(k));
        s.pb(make_pair(pcif(k),make_pair(i,k)));
    }
    sort(a.begin(),a.end());
    sort(s.begin(),s.end());
    in>>q;
    for(int i=1;i<=q;++i)
    {
        in>>k>>c;
        low=lower_bound(a.begin(),a.end(),c);
        l=distance(a.begin(),low);
        l=l+k-1;
        if(a[l]!=c)out<<"-1"<<'\n';
        else out<<s[l].y.y<<'\n';
    }
    return 0;
}
