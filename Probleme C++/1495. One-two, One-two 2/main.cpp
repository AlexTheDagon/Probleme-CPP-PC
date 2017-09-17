#include <iostream>
#include <vector>
#define pb push_back
using namespace std;
int d;
vector <int> v[60],sursa[50];
int pozi,pozj,sem,l,sir[40],k,fol[1000105],copie;
long long nr;
int main()
{
    cin>>d;
    v[1].pb(1);
    v[1].pb(2);
    fol[1]=1;
    fol[2]=2;
    sursa[1].pb(1);
    sursa[1].pb(2);
    pozi=1;
    pozj=-1;
    copie=d;
    while(copie)
    {
        if(copie%10!=1 && copie%10!=2)sem=1;
        copie/=10;
    }
    if(sem==0)cout<<d;
    else
    {
        while(pozj==-1)
        {
            ++pozi;
            if(pozi>30)pozj=-2;
            for(int i=0;i<v[pozi-1].size() && pozj==-1;++i)
            {
                nr=(v[pozi-1][i]*10+1)%d;
                if(fol[nr]==0)
                {
                    v[pozi].pb(nr);
                    sursa[pozi].pb(i);
                    fol[nr]=1;
                    if(nr==0)pozj=v[pozi].size()-1;
                }
                nr=(nr+1)%d;
                if(fol[nr]==0)
                {
                    v[pozi].pb(nr);
                    sursa[pozi].pb(i);
                    fol[nr]=2;
                    if(nr==0)pozj=v[pozi].size()-1;
                }
            }
        }
        if(pozj==-2)cout<<"Impossible";
        else
        {
            sir[0]=pozi;
            while(pozi)
            {
                sir[++k]=fol[v[pozi][pozj]];
                pozj=sursa[pozi][pozj];
                --pozi;
            }
            for(int i=sir[0];i>0;--i)cout<<sir[i];
        }
    }
    return 0;
}
