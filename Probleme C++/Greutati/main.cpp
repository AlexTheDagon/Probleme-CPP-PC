#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define N 1000005
using namespace std;
ifstream in("greutati.in");
ofstream out("greutati.out");
int n,a[N],b[N],mmin=1000000005,mmax,dr,st,mid,ind,h=0;
int g[N],aux[N],v[N];
int verifa(int m)
{
    int k=0;
    for(int i=1;i<=n;++i)if(a[i]>m)v[++k]=a[i];
    if(k%2==1)return 0;
    if(k>=2)
    {
        for(int i=1;i<=k;i+=2)if(v[i]!=v[i+1])return 0;
    }
    return 1;
}
int verifb(int m)
{
    int k=0;
    for(int i=1;i<=n;++i)if(b[i]>m)v[++k]=b[i];
    if(k%2==1)return 0;
    if(k>=2)
    {
        for(int i=1;i<=k;i+=2)if(v[i]!=v[i+1])return 0;
    }
    return 1;
}
int main()
{
    in>>n;
    if(n>1)
    {
        for(int i=1;i<=n;++i)
        {
            in>>a[i];
            aux[++ind]=a[i];
        }
        for(int i=1;i<=n;++i)
        {
            in>>b[i];
            aux[++ind]=b[i];
        }
        sort(aux+1,aux+ind+1);
        for(int i=1;i<=ind;i=i+2)g[i/2]=aux[i];
        dr=n;
        st=1;
        while(st<dr)
        {
            mid=(st+dr)/2;
            if(verifa(g[mid])==0 || verifb(g[mid])==0)st=mid+1;
            else dr=mid;
        }
        out<<g[st];
    }
    else
    {
        in>>a[1];
        out<<a[1];
    }
///aaaaaaaaaaaaaaaaaaaaa

    return 0;
}
