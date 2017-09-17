#include <iostream>
#include <fstream>
using namespace std;
ifstream in("triunghi.in");
ofstream out("triunghi.out");
int s,n,a[3][25],sum[1000005],parinte[1000005],cr[20],si,sem,m[20][20];
int main()
{
    in>>n>>s;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)a[2][j]=a[1][j];
        for(int j=1;j<=i;++j)a[1][j]=1;
        for(int j=1;j<i;++j)
        {
            a[1][j]+=a[2][j];
            a[1][j+1]+=a[2][j];
        }
    }
    for(int i=1;i<=n;++i)si+=a[1][i];
    sum[si]=1;
    for(int i=si+1;i<=s;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i>a[1][j] && sum[i-a[1][j]]==1)
            {
                sum[i]=1;
                parinte[i]=i-a[1][j];
            }
        }
    }
    if(sum[s]==0)out<<"imposibil";
    else
    {
        while(s>si)
        {
            sem=1;
            for(int i=1;i<=n && sem==1;++i)
            {
                if(a[1][i]==s-parinte[s])
                {
                    ++cr[i];
                    sem=0;
                }
            }
            s=parinte[s];
        }
        for(int i=1;i<=n;++i)m[n][i]=cr[i]+1;
        for(int i=n-1;i>0;--i)
        {
            for(int j=1;j<=i;++j)
            {
                m[i][j]=m[i+1][j]+m[i+1][j+1];
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=i;++j)out<<m[i][j]<<" ";
            out<<'\n';
        }
    }
    return 0;
}
