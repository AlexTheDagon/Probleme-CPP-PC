#include <iostream>
#include <fstream>
#define NM 155
#define inf 1000000000
using namespace std;
ifstream in("lant.in");
ofstream out("lant.out");
string s[NM],l;
int dp[NM][NM],nrmin[NM],k,cuv=1,semm,sem[NM],a,b,semafor;
int fr[250],sim,viz[NM],dpn[NM];
int dfs(int nod)
{
    if(viz[nod])return dpn[nod];
    int sol=0;
    viz[nod]=1;
    for(int i=nod+1;i<=cuv;++i)
        if(dp[nod][i]<=k)
            sol+=dfs(i);
    sol=max(sol,1);
    dpn[nod]=sol;
    return dpn[nod];
}
int cmlsc(string s1,string s2)
{
    int d[50][50];
    for(int i=0;i<40;++i)
        for(int j=0;j<40;++j)d[i][j]=inf;
    for(int i=0;i<=s2.size();++i)d[s1.size()][i]=s2.size()-i;
    for(int i=0;i<=s1.size();++i)d[i][s2.size()]=s1.size()-i;
    for(int i=s1.size()-1;i>=0;--i)
        for(int j=s2.size()-1;j>=0;--j)
        {
            if(s1[i]==s2[j])d[i][j]=min(d[i][j],d[i+1][j+1]);
            d[i][j]=min(d[i][j],min(d[i][j+1],d[i+1][j])+1);
        }
    return d[0][0];
}
int main()
{
    in>>k;
    getline(in,l);
    while(getline(in,l))
    {
        for(auto i:l)
        {
            if(isalpha(i))s[cuv]+=i;
            else
            {
                if(s[cuv].size()!=0)
                {
                    ++cuv;
                    semafor=0;
                    for(int j=1;j<cuv-1;++j)if(s[cuv-1]==s[j])semafor=1;
                    cuv-=semafor;
                    s[cuv]="";
                }
            }
        }
        if(s[cuv].size()!=0)
        {
            ++cuv;
            semafor=0;
            for(int j=1;j<cuv-1;++j)if(s[cuv-1]==s[j])semafor=1;
            cuv-=semafor;
            s[cuv]="";
        }
        l="";
    }
    while(s[cuv].size()==0)--cuv;
    for(int i=1;i<=cuv;++i)
    {
        for(int j=i+1;j<=cuv;++j)
        {
            dp[i][j]=cmlsc(s[i],s[j]);
        }
    }
    ///ar tb sa fie bine
    out<<dfs(1);
    return 0;
}
