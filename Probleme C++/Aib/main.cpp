#include <iostream>
#include <fstream>
#define NM 100005
using namespace std;
ifstream in("aib.in");
ofstream out("aib.out");
int n,a[NM],m,c,x,y,pos;
int querysum(int poz)
{
    int suma=0;
    for(int poss=poz;poss>0;poss-=(poss&-poss))suma+=a[poss];
    return suma;
}
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        a[i]+=a[i-1];
    }
    for(int i=n;i>0;--i)
        a[i]-=a[i-(i&-i)];
    for(int i=1;i<=m;++i)
    {
        in>>c>>x;
        if(c==0)
        {
            in>>y;
            for(int pos=x;pos<=n;pos+=(pos&-pos))a[pos]+=y;
        }
        if(c==1)
        {
            in>>y;
            out<<querysum(y)-querysum(x-1)<<'\n';
        }
        if(c==2)
        {
            int st=1,dr=n,mid,sol=-1;
            while(st<=dr && sol==-1)
            {
                    mid=(dr+st)/2;
                    if(querysum(mid)==x)sol=mid;
                    else
                    {
                        if(querysum(mid)>x)dr=mid-1;
                        else st=mid+1;
                    }
            }
            if(sol==-1)out<<"-1";
            else out<<sol;
            out<<'\n';
        }
    }
    return 0;
}
