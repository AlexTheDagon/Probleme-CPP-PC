#include <iostream>
#include <bits/stdc++.h>
#define NM 30005
using namespace std;
ifstream in("schi.in");
ofstream out("schi.out");
int n,a[NM],sol[NM],ait[4*NM];
void upd(int poz,int st,int dr,int pers,int ind)
{
    if(st==dr && st==ind)
    {
        ait[poz]=1;
        sol[ind]=pers;
        return;
    }
    int mid=(st+dr)/2;
    if(ind+ait[2*poz]<=mid)upd(2*poz,st,mid,pers,ind);
    else upd(2*poz+1,mid+1,dr,pers,ind+ait[2*poz]);
    ait[poz]=ait[2*poz]+ait[2*poz+1];
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    for(int i=n;i>0;--i)upd(1,1,n,i,a[i]);
    for(int i=1;i<=n;++i)out<<sol[i]<<'\n';
    return 0;
}
