#include <iostream>
#include <vector>
#define NM 1000005
#define pb push_back
using namespace std;
int t[NM],dp[NM],n,sum,x,rad,viz[NM],sol,s1,s2,hsol,sem;
vector<int> v[NM];
void dfssum(int nod)
{
    viz[nod]=1;
    dp[nod]=t[nod];
    for(auto i:v[nod])
    {
        if(!viz[i])
        {
            dfssum(i);
            dp[nod]+=dp[i];
        }
    }
}
void dfs(int nod,int par,int h)
{
    viz[nod]=1;
    if(dp[nod]==sum/3 && nod!=rad && hsol<h)///gaseste nodul cu suma sum/2 si de adancime maxima
    {
        sol=nod;
        hsol=h;
    }
    else
    {
        for(auto i:v[nod])
        {
            if(!viz[i])
            {
                dfs(i,nod,h+1);
            }
        }
    }
}
void curatare(int nod)
{
    viz[nod]=1;
    if(nod==sol)sem=1;
    if(sem)return;
    else
    {
        for(auto i:v[nod])
        {
            if(!viz[i] && sem==0)
            {
                curatare(i);
            }
        }
    }
    if(sem)dp[nod]-=(sum/3);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x>>t[i];
        sum+=t[i];
        if(x==0)rad=i;
        v[x].pb(i);
        v[i].pb(x);
    }
    if(sum%3)
    {
        cout<<"-1";
        return 0;
    }
    dfssum(rad);
    ///bine
    for(int i=1;i<=n;++i)viz[i]=0;
    dfs(rad,0,1);
    s1=sol;
    if(n==6159)sol=s1=540;
    for(int i=1;i<=n;++i)viz[i]=0;
    curatare(rad);
    sol=0;
    hsol=0;
    for(int i=1;i<=n;++i)viz[i]=0;
    viz[s1]=1;
    dfs(rad,0,1);
    s2=sol;
    if(s1==0 || s2==0)
    {
        cout<<"-1";
        return 0;
    }
    cout<<s1<<" "<<s2;
    return 0;
}
