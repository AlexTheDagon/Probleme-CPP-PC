#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
using namespace std;
ifstream in("numere8.in");
ofstream out("numere8.out");
int a[10],limit=(1<<10)-1,smax,s,perechi,pmax1,pmax2;
vector <int> v[1006];
int main()
{
    for(int i=0;i<10;++i)
    {
        in>>a[i];
    }
    for(int i=1;i<=limit;++i)
    {
        s=0;
        for(int j=0;j<10;++j)///de verif limita
        {
            if(i&(1<<j))s+=a[j];
        }
        v[s].pb(i);
    }
    for(int i=1;i<1000;++i)
    {
        if(v[i].size()>1)
        {
            for(int j=0;j<v[i].size();++j)
            {
                for(int k=j+1;k<v[i].size();++k)
                {
                    if((v[i][j]&v[i][k])==0)
                    {
                        ++perechi;
                        if(i>smax)
                        {
                            smax=i;
                            pmax1=v[i][j];
                            pmax2=v[i][k];
                        }
                    }
                }
            }
        }
    }
    out<<perechi<<" "<<smax<<'\n';
    for(int j=0;j<10;++j)
    {
        if(pmax1&(1<<j))out<<a[j]<<" ";
    }
    out<<'\n';
    for(int j=0;j<10;++j)
    {
        if((pmax2&(1<<j)))out<<a[j]<<" ";
    }
    return 0;
}
