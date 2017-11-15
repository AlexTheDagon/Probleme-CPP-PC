#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define NM 20
using namespace std;
ifstream in("ture.in");
ofstream out("ture.out");
int n,m,k,p,x,y,kkk;
long long dp[260][70000],sol;
bool nu[255][20],swp;
int main()
{
    in>>n>>m>>k;
    if(n<m)
    {
        swap(n,m);
        swp=1;
    }
    in>>p;
    for(int i=1;i<=p;++i)
    {
        in>>x>>y;
        if(swp)swap(x,y);
        nu[x][y]=1;
    }
    ///n max   m min
    dp[0][0]=1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<(1<<m);++j)
        {
            dp[i+1][j]+=dp[i][j];
            for(int s=0;s<m;++s)
                if(!(j&(1<<s)) && !nu[i+1][s+1])dp[i+1][j|(1<<s)]+=dp[i][j];
        }
    }
    for(int i=0;i<(1<<m);++i)
    {
        kkk=0;
        for(int j=0;j<m;++j)
            if(i&(1<<j))++kkk;
        if(kkk==k)
            sol+=dp[n][i];
    }
    if(k>m)sol=0;
    out<<sol;
    return 0;
}
