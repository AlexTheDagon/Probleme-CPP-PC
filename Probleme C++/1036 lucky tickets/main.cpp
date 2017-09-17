#include <iostream>

using namespace std;
int n,s;
int a[55][455][100],sum[100],rez[200];
void mul()
{
      int i, j, t;
      for (i = 1; i <= sum[0]; i++)
      {
              for (t=0, j=1; j <= sum[0] || t; j++, t/=10)
                      rez[i+j-1]=(t+=rez[i+j-1]+sum[i]*sum[j])%10;
              if (i + j - 2 > rez[0]) rez[0] = i + j - 2;
      }
}
int main()
{
    cin>>n>>s;
    if(s%2==1 || s>18*n)cout<<"0";
    else
    {
        s=s/2;
        for(int i=0;i<=9;++i)
        {
            a[1][i][0]=1;
            a[1][i][1]=1;
        }
        for(int l=2;l<=n;++l)
        {
            for(int k=0;k<=min(s,9*l);++k)
            {
                for(int j=k;j>=k-9 && j>=0;--j)
                {
                    int i,t=0;
                    for (i=1; i<=a[l][k][0] || i<=a[l-1][j][0] || t;i++,t/=10)
                        a[l][k][i] = (t += a[l][k][i] + a[l-1][j][i]) % 10;
                    a[l][k][0] = i - 1;
                }
            }
        }
        for(int i=a[n][s][0];i>=0;--i)sum[i]=a[n][s][i];
        mul();
        for(int i=rez[0];i>0;--i)cout<<rez[i];
    }
    return 0;
}
