#include <iostream>
#include <fstream>
#define NM 100005
#define mp make_pair
using namespace std;
ifstream in("diff.in");
ofstream out("diff.out");
int sp[NM],x,n,m,mi,ma,pmi,pma,val;
pair<int,int> sol[4*NM];
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;++i)
    {
        in>>x;
        sp[i]=sp[i-1];
        if(x)++sp[i];
        else --sp[i];
    }
    for(int i=1;i<=n;++i)
    {
        sol[sp[i]-mi+NM]={pmi+1,i};
        sol[sp[i]-ma+NM]={pma+1,i};
        if(sp[i]>ma)
        {
            ma=sp[i];
            pma=i;
        }
        if(sp[i]<mi)
        {
            mi=sp[i];
            pmi=i;
        }
    }
    for(int i=1;i<=m;++i)
    {
        in>>val;
        if(val<-n || val>n)out<<"-1"<<'\n';
        else
        {
            if(sol[val+NM].second==0)out<<"-1"<<'\n';
            else out<<sol[val+NM].first<<" "<<sol[val+NM].second<<'\n';
        }
    }
    return 0;
}
