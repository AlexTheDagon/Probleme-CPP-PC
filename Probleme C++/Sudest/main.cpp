#include <iostream>
#include <fstream>
#define NM 105
using namespace std;
ifstream in("sudest.in");
ofstream out("sudest.out");
int n,k,a[NM][NM],c[NM][NM],pas[2*NM];
int p[NM][NM];
int ok(int i,int j)
{
    if(i<=n && j<=n && i>0 && j>0)return 1;
    return 0;
}
int drum(int i,int j,int P)
{
    int gasit=0;
    if(i==1 && j==1)out<<"1 1"<<'\n';
    else
    {
        if(ok(i,j-pas[P]))
        {
            if(c[i][j-pas[P]]==c[i][j]-a[i][j] && p[i][j-pas[P]]==P-1)
            {
                drum(i,j-pas[P],P-1);
                out<<i<<" "<<j<<'\n';
                gasit=1;
            }
        }
        if(gasit==0)
        {
            if(ok(i-pas[P],j))
            {
                if(c[i-pas[P]][j]==c[i][j]-a[i][j] && p[i-pas[P]][j]==P-1)
                {
                    drum(i-pas[P],j,P-1);
                    out<<i<<" "<<j<<'\n';
                }
            }
        }
    }
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            in>>a[i][j];
            c[i][j]=-1;
            p[i][j]=300;
        }
    }
    in>>k;
    for(int i=1;i<=k;++i)in>>pas[i];
    p[1][1]=0;
    c[1][1]=a[1][1];
    for(int h=1;h<=k;++h)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(p[i][j]==h-1)
                {
                    if(ok(i+pas[h],j))
                    {
                        if(c[i][j]+a[i+pas[h]][j]>c[i+pas[h]][j])
                        {
                            p[i+pas[h]][j]=h;
                            c[i+pas[h]][j]=c[i][j]+a[i+pas[h]][j];
                        }
                    }
                    if(ok(i,j+pas[h]))
                    {
                        if(c[i][j]+a[i][j+pas[h]]>c[i][j+pas[h]])
                        {
                            p[i][j+pas[h]]=h;
                            c[i][j+pas[h]]=c[i][j]+a[i][j+pas[h]];
                        }
                    }
                }
            }
        }
    }
    out<<c[n][n]<<'\n';
    drum(n,n,k);
    return 0;
}
