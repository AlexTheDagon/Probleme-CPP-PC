#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define pb push_back
#define NM 200005
using namespace std;
ifstream in("apm.in");
ofstream out("apm.out");
struct eee
{
    int cost,nod1,nod2;
};
bool cmp(eee a,eee b)
{
    return a.cost<b.cost;
}
eee ms(int a,int b,int ccost)
{
    eee fr;
    fr.nod1=a;
    fr.nod2=b;
    fr.cost=ccost;
    return fr;
}

int n,m,p[NM],a,b,c;
long long minn;
vector<eee> sol,srt;
eee fr;
int father(int nod)
{
    if(p[nod]==nod)return nod;
    return p[nod]=father(p[nod]);
}
void unire(int x,int y)
{
    p[father(x)]=father(y);
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=m;++i)
    {
        in>>a>>b>>c;
        srt.pb(ms(a,b,c));
    }
    for(int i=1;i<=n;++i)p[i]=i;
    sort(srt.begin(),srt.end(),cmp);
    for(auto s:srt)
    {
        if(n==1)break;
        if(father(s.nod1)!=father(s.nod2))
        {
            minn+=s.cost;
            unire(s.nod1,s.nod2);
            sol.pb(s);
        }
    }
    out<<minn<<'\n';
    out<<sol.size()<<'\n';
    for(auto s:sol)
    {
        out<<s.nod1<<" "<<s.nod2<<'\n';
    }
    return 0;
}
