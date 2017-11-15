#include <iostream>
#include <vector>
#define pb push_back
#define NM 100005
#define M 1000000007
using namespace std;
long long w[NM],b[NM],x,y,viz[NM],c[NM],n;
vector <int> v[NM];
void dfs(int nod)
{
    viz[nod]=1;
    if(c[nod])b[nod]=1;
    else w[nod]=1;
    long long black,white;
    for(auto i:v[nod])
    {
        if(!viz[i])
        {
            dfs(i);
            white=0;
            black=0;
            white+=w[nod]*w[i];
            white%=M;
            black+=b[nod]*w[i]+b[i]*w[nod];
            black%=M;
            white+=w[nod]*b[i];
            black+=b[nod]*b[i];
            white%=M;
            black%=M;
            w[nod]=white;
            b[nod]=black;

        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<n;++i)
    {
        cin>>x;
        v[i].pb(x);
        v[x].pb(i);
    }
    for(int i=0;i<n;++i)cin>>c[i];
    dfs(0);
    cout<<b[0];
    return 0;
}
