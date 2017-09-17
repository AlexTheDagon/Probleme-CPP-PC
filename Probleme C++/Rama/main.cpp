#include <iostream>
#include <fstream>
#define Nmax 705
#define Mmax 705
using namespace std;
ifstream in("rama.in");
ofstream out("rama.out");
int n,m,sl[Nmax][Mmax],sc[Nmax][Mmax],i2,j2,i1,j1,maxx=0,h;
char r[Nmax][Mmax];
int main()
{
    in>>n>>m;
    for(int i=0;i<=m;i++)r[0][i]='0';
    for(int i=0;i<=n;i++)r[i][0]='0';
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)in>>r[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)sl[i][j]=sl[i][j-1]+(r[i][j]-'0');
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)sc[j][i]=sc[j-1][i]+(r[j][i]-'0');
    for(int h=0;h<m;++h)
    {
        for(int i=1;i+h<=m;++i)
        {
            for(j2=1;j2<=m;++j2)
            {
                if(r[i][j2-1]=='0' && r[i+h][j2-1]=='0' && r[i][j2]=='1' && r[i+h][j2]=='1' && sc[i+h][j2]-sc[i-1][j2]==h+1)j1=j2;
                if(sl[i][j2]-sl[i][j1-1]==j2-j1+1 && sl[i+h][j2]-sl[i+h][j1-1]==j2-j1+1 && sc[i+h][j1]-sc[i-1][j1]==h+1 && sc[i+h][j2]-sc[i-1][j2]==h+1)
                {
                    if((h+1)*(j2-j1+1)>maxx)maxx=(h+1)*(j2-j1+1);
                }
            }
        }
    }
    out<<maxx;


 return 0;
}
