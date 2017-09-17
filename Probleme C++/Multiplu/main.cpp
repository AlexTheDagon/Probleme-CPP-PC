#include <iostream>
#include <fstream>
#include <vector>
#define pb push_back
using namespace std;
ifstream in("multiplu.in");
ofstream out("multiplu.out");
int a,b,c,x,y,d;
vector <int> v[60],sursa[50];
int pozi,pozj,sem,l,sir[40],k,fol[2000105];
long long nr;
int main()
{
    in>>a>>b;
    x=a,y=b;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    d=x*y/a;
    v[1].pb(1);
    fol[1]=1;
    sursa[1].pb(1);
    pozi=1;
    pozj=-1;
    while(pozj==-1)
    {
        ++pozi;
        for(int i=0;i<v[pozi-1].size() && pozj==-1;++i)
        {
            nr=v[pozi-1][i]*10%d;
            if(fol[nr]==0)
            {
                v[pozi].pb(nr);
                sursa[pozi].pb(i);
                fol[nr]=-1;
                if(nr==0)pozj=v[pozi].size()-1;
            }
            nr=(nr+1)%d;
            if(fol[nr]==0)
            {
                v[pozi].pb(nr);
                sursa[pozi].pb(i);
                fol[nr]=1;
                if(nr==0)pozj=v[pozi].size()-1;
            }
        }
    }
    sir[0]=pozi;
    while(pozi)
    {
        if(fol[v[pozi][pozj]]==1)sir[++k]=1;
        else sir[++k]=0;
        pozj=sursa[pozi][pozj];
        --pozi;
    }
    for(int i=sir[0];i>0;--i)out<<sir[i];
    return 0;
}
