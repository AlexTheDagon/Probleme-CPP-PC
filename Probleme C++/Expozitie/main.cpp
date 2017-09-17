#include <iostream>
#include <fstream>
using namespace std;
ifstream in("expozitie.in");
ofstream out("expozitie.out");
int n,d,ap,k,t;
char a[505][505][30],exp[100];
void add(int i,int j)
{
    t=0;
    for(k=1;k<=a[i-1][j][0] || k<=a[i][j-1][0] || t;++k,t/=10)
    {
        a[i][j][k]=(t+=a[i-1][j][k]+a[i][j-1][k])%10;
    }
    a[i][j][0]=k-1;
}
void addd(int i)
{
      t=0;
      for(k=1;k<=a[n][i][0] || k<=exp[0] || t;k++,t/=10)
              exp[k]=(t+=a[n][i][k]+exp[k])%10;
      exp[0]=k-1;
}
int main()
{
    in>>n>>d>>ap;
    if(n<d*ap)out<<"0";
    else
    {
        n=n-d*ap;
        if(n==0)
        {
            exp[0]=1;
            exp[1]=1;
        }
        for(int i=1;i<=d;++i)
        {
            a[1][i][1]=1;
            a[1][i][0]=1;
        }
        for(int i=2;i<=n;++i)
        {
            for(int j=1;j<=d;++j)
            {
                add(i,j);
            }
        }
        for(int i=1;i<=d;++i)addd(i);
        for(int i=exp[0];i>0;--i)out<<int(exp[i]);
    }
    return 0;
}
///dp[i][j]--->ultimul desen put pe primele i scanduri e de tip j
///dp[i][j]=dp[i-1][j]+dp[i][j-1];
