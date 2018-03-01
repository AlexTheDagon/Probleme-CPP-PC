#include <iostream>
#include <bits/stdc++.h>
#define NM 405
#define KM 305
#define inf 1000000000
using namespace std;
ifstream in("petrom.in");
ofstream out("petrom.out");
int cmin[KM][NM],cost[NM][NM],poz[NM][NM],par[KM][NM],sol=inf,dep;
int n,k,lng[NM],p;
int main()
{
    in>>n>>k;
    for(int i=1; i<=n; ++i)in>>lng[i];
    lng[0]=lng[1];
    lng[n+1]=lng[n];
    ///calcul cost[i][j]
    for(int i=1; i<=n; ++i)
    {
        cost[0][i]=cost[0][i-1]+(i-1)*(lng[i]-lng[i-1]);
        cost[i][i+1]=0;
        poz[i][i+1]=i;
        for(int j=i+2; j<=n; ++j)
        {
            p=poz[i][j-1];
            cost[i][j]=cost[i][j-1]+(j-p-1)*(lng[j]-lng[j-1]);
            while(lng[p+1]-lng[i]<=lng[j]-lng[p+1] && p<j)
            {
                cost[i][j]=cost[i][j]-(lng[j]-lng[p+1])+(lng[p+1]-lng[i]);
                ++p;
            }
            poz[i][j]=p;
        }
    }
    ///pare bine de verificat
    for(int i=n; i>0; --i)
        cost[i][n+1]=cost[i+1][n+1]+(n-i)*(lng[i+1]-lng[i]);
    ///sper ca e bine
    ///acum voi calcula cmin.Doamne ajuta!
    for(int i=1; i<=k; ++i)
        for(int j=1; j<=n+1; ++j)cmin[i][j]=inf;
    for(int i=1; i<=n; ++i)cmin[1][i]=cost[0][i];
    for(int i=2; i<=k; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            for(int l=1; l<j; ++l)
            {
                if(cmin[i][j]>cmin[i-1][l]+cost[l][j])
                {
                    cmin[i][j]=cmin[i-1][l]+cost[l][j];
                    par[i][j]=l;
                }
            }
        }
    }
    for(int i=1; i<=n; ++i)cmin[k][i]+=cost[i][n+1];
    for(int i=1; i<=n; ++i)
    {
        if(cmin[k][i]<sol)
        {
            sol=cmin[k][i];
            dep=i;
        }
    }
    out<<sol<<'\n';
    out<<dep<<'\n';
    while(par[k][dep]!=0)
    {
        dep=par[k][dep];
        --k;
        out<<dep<<'\n';
    }
    return 0;
}
///cost[i][j]--costul pe sectiunea i,j daca se amplaseaza depozite la i si j
///cmin[i][j]--costul min daca am plasat i depozite si ultimul e j
