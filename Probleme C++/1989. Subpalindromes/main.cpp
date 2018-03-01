
#include <iostream>
#include <bits/stdc++.h>
#define NM 100005
#define prim 1000000007
#include <string.h>
using namespace std;
int aib1[NM],aib2[NM],n,a,b,p[NM],l,v1,v2;
char c,s[NM],q[NM],sr[NM];
///functie pentru update
void update(int pos,int aib[],int val)
{
    ///primul aib
    while(pos<=l)
    {
        aib[pos]+=val;
        pos+=(pos&(-pos));
    }
}///bine
///functie pentru suma in aib
int suma(int pos,int aib[])
{
    int sum=0;
    while(pos>0)
    {
        sum+=aib[pos];
        pos-=(pos&(-pos));
    }
    return sum;
}///bine
///suma pe portiunea st dr
int suma_portiune(int st,int dr,int aib[])
{
    return suma(dr,aib)-suma(st-1,aib);
}///bine
///funcite pentru verificare
int main()
{
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin>>s+1>>n;
    l=strlen(s+1);
    for(int i=1;i<=l;++i)
        sr[i]=s[l-i+1];///bine
    p[0]=1;
    for(int i=1;i<=l;++i)
        p[i]=p[i-1]*prim;///bine
    for(int i=1;i<=l;++i)///bine
    {
        update(i,aib1,(s[i]-'a')*p[i-1]);
        update(i,aib2,(sr[i]-'a')*p[i-1]);
    }///bine
    ///intiializarile mai sus
    for(int i=1;i<=n;++i)
    {
        cin>>q+1;
        if(q[1]=='c')
        {
            cin>>a>>c;
            int dif=c-s[a];
            s[a]=c;
            sr[l-a+1]=c;
            update(a,aib1,dif*p[a-1]);
            update(l-a+1,aib2,dif*p[l-a]);
        }
        else
        {
            cin>>a>>b;
            v1=suma_portiune(a,b,aib1);
            v1*=p[l-a+1];
            v2=suma_portiune(l-b+1,l-a+1,aib2);
            v2*=p[b];
            if(v1==v2)cout<<"Yes";
            else cout<<"No";
            cout<<'\n';
        }
    }
    return 0;
}
