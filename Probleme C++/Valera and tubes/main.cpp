#include <iostream>
#include <vector>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define NM 305*305
#define x first
#define y second
using namespace std;
int n,m,k,nr;
vector<pii> v[NM];
int main()
{
    cin>>n>>m>>k;
    int j=1;
    for(int i=1;i<=n;++i)
    {
        if(i%2)
        {
            for(j=1;j<m;j+=2)
            {
                if(nr<k)++nr;
                v[nr].pb(mp(i,j));
                v[nr].pb(mp(i,j+1));
            }
            if(m%2==1)
            {
                if(nr<k)++nr;
                v[nr].pb(mp(i,j));
                if(i<n)v[nr].pb(mp(i+1,j));
            }
        }
        else
        {
            for(j=m/2*2;j>1;j-=2)
            {
                if(nr<k)++nr;
                v[nr].pb(mp(i,j));
                v[nr].pb(mp(i,j-1));
            }
        }
    }
    for(int i=1;i<=k;++i)
    {
        cout<<v[i].size()<<" ";
        for(auto j:v[i])cout<<j.x<<" "<<j.y<<" ";
        cout<<endl;
    }
    return 0;
}
