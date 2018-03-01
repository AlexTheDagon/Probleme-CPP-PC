#include <iostream>
#include <fstream>
#define NM 100005
using namespace std;
ifstream in("pod.in");
ofstream out("pod.out");
int n,p,l;
int d[NM];
int verif(int lng)
{
    int fr=1;
    int k=1;
    for(int i=1;i<=n;++i)
        if(d[i]-d[k]>=lng)
        {
            k=i;
            ++fr;
        }
    if(fr>=p)return 1;
    return 0;
}
int main()
{
    in>>l>>p>>n;
    for(int i=1;i<=n;++i)in>>d[i];
    int hi=10000000,low=0,mid;
    while(hi-low>1)
    {
        mid=(hi+low)/2;
        if(verif(mid))low=mid;
        else hi=mid;
    }
    --hi;
    int ind=1;
    out<<"1";
    for(int i=2;i<=n;++i)
    {
        if(d[i]-d[ind]>=hi)
        {
            out<<"1";
            ind=i;
        }
        else out<<"0";
    }
    return 0;
}
