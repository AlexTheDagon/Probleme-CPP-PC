#include <iostream>
#define NM 100005
using namespace std;
int n,m,a[NM],mid,aux[2*NM],w,st,dr,adaos[2*NM];
int verif(int h)
{
    int ma=m,sem=0,ad;
    for(int i=1;i<=n;++i)aux[i]=a[i];
    for(int i=1;i<=n;++i)adaos[i]=0;
    for(int i=1;i<=n && ma>=0;++i)
    {
        adaos[i]+=adaos[i-1];
        if(aux[i]+adaos[i]<h)
        {
            ad=h-aux[i]-adaos[i];
            adaos[i]+=ad;
            adaos[i+w]-=ad;
            ma-=ad;
        }
    }
    if(ma<0)return 0;
    for(int i=1;i<=n;++i)if(aux[i]+adaos[i]<h)return 0;
    return 1;
}
int main()
{
    cin.sync_with_stdio(false);
    cin>>n>>m>>w;
    for(int i=1;i<=n;++i)cin>>a[i];
    dr=(1<<30);
    st=0;
    while(dr-st>1)
    {
        mid=(dr+st)/2;
        if(verif(mid))st=mid;
        else dr=mid;
    }
    while(!verif(st))--st;
    while(verif(st))++st;
    cout<<st-1;
    return 0;
}
