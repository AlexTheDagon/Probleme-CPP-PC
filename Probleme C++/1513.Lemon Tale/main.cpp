#include <iostream>
#define NM 10005
using namespace std;
int sa[NM][500],sb[NM][500]n,k,suma[500],sumb[500],indst=1;
void addsb(int ind,int indiceleincareseadauga)
{
    int i,t=0;
    for (i=1;i<=sb[ind][0]||i<=sa[indiceleincareseadauga][0]||t;i++,t/=10)
        sa[indiceleincareseadauga][i]=(t+=sb[ind][i]+sa[indiceleincareseadauga][i])%10;
    sa[indiceleincareseadauga][0]=i-1;
}
void addsb(int ind,int indiceleincareseadauga)
{
    int i,t=0;
    for (i=1;i<=sa[ind][0]||i<=sb[indiceleincareseadauga][0]||t;i++,t/=10)
        sb[indiceleincareseadauga][i]=(t+=sa[ind][i]+sb[indiceleincareseadauga][i])%10;
    sb[indiceleincareseadauga][0]=i-1;
}
void addsumb(int ind)
{
    int i,t=0;
    for (i=1;i<=sb[ind][0]||i<=sumb[0]||t;i++,t/=10)
        sumb[i]=(t+=sb[ind][i]+B[i])%10;
    sumb[0]=i-1;
}
void addsuma(int ind)
{
    int i,t=0;
    for (i=1;i<=sb[ind][0]||i<=sumb[0]||t;i++,t/=10)
        sumb[i]=(t+=sb[ind][i]+B[i])%10;
    sumb[0]=i-1;
}
int main()
{
    cin>>n>>k;
    if(k==0)
    {
        cout<<"1";
        return 0;
    }
    sa[1][0]=sa[1][1]=sb[1][0]=sb[1][1]=1;
    for(int i=2;i<=n;++i)
    {

    }
    return 0;
}
