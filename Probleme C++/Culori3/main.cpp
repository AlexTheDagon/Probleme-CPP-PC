#include <iostream>
#include <fstream>
using namespace std;
ifstream in("culori3.in");
ofstream out("culori3.out");
int cur[2][7][1000],cif[2][7],n,nr[1000],cifnr,s,ad,k;
int sum(int y,int x)
{
    for(int i=1;i<=5;++i)
    {
        cif[x][i]=cif[y][i];
    }
    for(int i=1;i<=5;++i)
    {
        cif[y][i]=max(cif[x][i-1],cif[x][i+1]);
        for(int j=1;j<=cif[y][i];++j)
        {
            cur[y][i][j]=cur[y][i][j]+cur[x][i-1][j]+cur[x][i+1][j];
            cur[y][i][j+1]=cur[y][i][j]/10;
            cur[y][i][j]=cur[y][i][j]%10;
        }
        if(cur[y][i][cif[y][i]+1]!=0)cif[y][i]++;
    }
}
int main()
{
    in>>n;
    for(int i=1;i<=5;++i)
    {
        cif[2][i]=1;
        cur[2][i][1]=1;
    }
    for(k=2;k<=n;++k)
    {
        sum(k%2,(k+1)%2);
    }
    k=(k)%2;
    for(int i=1;i<=5;++i)cifnr=max(cifnr,cif[k][i]);
    for(int i=1;i<=cifnr;++i)
    {
        for(int j=1;j<=5;++j)
        {
            nr[i]+=cur[k][j][i];
        }
        if(nr[i]>9)
        {
            nr[i+1]=nr[i]/10;
            nr[i]=nr[i]%10;
        }
    }
    if(nr[cifnr+1]!=0)++cifnr;
    for(int i=cifnr;i>0;--i)out<<nr[i];
    return 0;
}
