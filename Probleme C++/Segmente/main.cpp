#include <iostream>
#include <fstream>
#include <stdlib.h>
#define fs first.second
#define sf second.first
#define ss second.second
#define ff first.first
using namespace std;
ifstream in("segmente.in");
ofstream out("segmente.out");
int a[1005][1005],n;
int nv,no;
int x1,y1,x2,y2;
long long minn1=1<<30,minn2=1<<30,minn=1<<30;
pair<pair<int,int>,pair<int,int> >  v[1005],o[1005],fr,fro,frv;
int dist(int i,int j)
{
    frv=v[i];
    fro=o[j];
    if(fro.fs>=frv.fs && fro.fs<=frv.ss && frv.ff>=fro.ff && frv.ff<=fro.sf)return 0;
    if(fro.fs>=frv.fs && fro.fs<=frv.ss)return min(abs(fro.ff-frv.ff),abs(fro.sf-frv.ff));
    if(frv.ff>=fro.ff && frv.ff<=fro.sf)return min(abs(fro.fs-frv.fs),abs(fro.fs-frv.ss));
    return max(min(abs(fro.fs-frv.fs),abs(fro.fs-frv.ss)),min(abs(fro.ff-frv.ff),abs(fro.sf-frv.ff)));

}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>fr.ff>>fr.fs>>fr.sf>>fr.ss;
        if(fr.ff>fr.sf)swap(fr.ff,fr.sf);
        if(fr.fs>fr.ss)swap(fr.fs,fr.ss);
        if(fr.ff==fr.sf)v[++nv]=fr;
        else o[++no]=fr;
    }
    for(int i=1;i<=nv;++i)
        for(int j=1;j<=no;++j)
            a[i][j]=dist(i,j);
    ///bine
    if(nv<=no)
    {
        for(int i=1;i<nv;++i)
        {
            for(int j=i+1;j<=nv;++j)
            {
                minn1=1<<30;
                minn2=1<<30;
                for(int k=1;k<=no;++k)
                {
                    if(max(a[i][k],a[j][k])<=minn1)
                    {
                        minn2=minn1;
                        minn1=max(a[i][k],a[j][k]);
                    }
                    else if(max(a[i][k],a[j][k])<minn2)minn2=max(a[i][k],a[j][k]);
                }
                if(minn>minn2)minn=minn2;
            }
        }
    }
    else
    {
        for(int i=1;i<no;++i)
        {
            for(int j=i+1;j<=no;++j)
            {
                minn1=1<<30;
                minn2=1<<30;
                for(int k=1;k<=nv;++k)
                {
                    if(max(a[k][i],a[k][j])<=minn1)
                    {
                        minn2=minn1;
                        minn1=max(a[k][i],a[k][j]);
                    }
                    else if(max(a[k][i],a[k][j])<minn2)minn2=max(a[k][i],a[k][j]);
                }
                if(minn>minn2)minn=minn2;
            }
        }
    }
    out<<minn;
    return 0;
}
