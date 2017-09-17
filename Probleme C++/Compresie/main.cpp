#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>
#define DN 1005

using namespace std;
ifstream in("compresie.in");
ofstream out("compresie.out");
int n,nrn,poz;
char rez[DN][DN];
string sir;
void recurs(int x1,int y1, int x2, int y2)
{
    if(x1>x2 || y1>y2) return;
    if('*'==sir[poz])
    {
        int mx=(x1+x2)/2,my=(y1+y2)/2;
        ++poz;
        recurs(x1,y1,mx,my);
        recurs(x1,my+1,mx,y2);
        recurs(mx+1,y1,x2,my);
        recurs(mx+1,my+1,x2,y2);
    }
    else
    {
        for(;isdigit(sir[poz]);++poz);
        for(int i=x1;i<=x2;++i)
            for(int j=y1;j<=y2;++j)rez[i][j]=sir[poz];
        ++poz;
    }
}
int main()
{
    in>>sir;
    int sz=sir.size();
    int x=0,impartituri=0;
    for(int i=0;i<sz;)
    {
        if(isdigit(sir[i]))
        {
            for(;isdigit(sir[i]) && i<sz;x=x*10+sir[i]-'0',++i);
            nrn+=x;
            if(i>=sz)break;
        }
        else
        {
            if(isalpha(sir[i]))
            {
                if(x==0)++nrn;
                x=0;
                ++i;
            }
            else
            {
                ++i;
                ++impartituri;
            }
        }
    }
    n=sqrt(nrn);
    recurs(1,1,n,n);
    out<<impartituri<<'\n';
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)out<<rez[i][j];
        out<<'\n';
    }
    return 0;
}
