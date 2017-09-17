#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define ff first.first
#define y first.second
#define z second.first
#define ss second.second
#define pb push_back
#define mp make_pair
using namespace std;
ifstream in("drept3.in");
ofstream out("drept3.out");
vector <pair<pair<int, int> ,pair<int, int> > > v;
int n,a,b,s,p,d,l,ymax,ymin=1000000,ux=-1;
int m[10010];
pair <pair<int, int> ,pair<int, int> > fr;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a>>b>>d;
        fr.ff=a;
        fr.y=1;
        fr.z=b;
        fr.ss=b+d-1;
        v.pb(fr);
        fr.ff=a+d;
        fr.y=-1;
        fr.z=b;
        fr.ss=b+d-1;
        v.pb(fr);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i)
    {
        s+=(v[i].ff-ux)*l;
        ux=v[i].ff;
        for(int j=v[i].z;j<=v[i].ss;++j)
        {
            if(v[i].y==-1 && m[j]==1)--l;
            if(v[i].y==1 && m[j]==0)++l;
            m[j]+=v[i].y;
            if(v[i].y==1)if(m[j]>p)p=m[j];
        }
    }
    out<<s<<'\n'<<p;
    return 0;
}
