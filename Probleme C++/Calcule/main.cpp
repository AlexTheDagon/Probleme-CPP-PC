#include <iostream>
#include <fstream>

using namespace std;
ifstream in("calcule.in");
ofstream out("calcule.out");
int n,k,x,a[100005],sub=1,st,dr,mid,l;
long long nr,rest[50005],s;

int main()
{
    in>>n>>k;
    for(int i=1;i<=n;++i)
    {
        in>>x;
        s=s+x;
        ++rest[s%k];
        st=0;
        dr=l;
        while(st<dr)
        {
            mid=(st+dr)/2;
            if(a[mid]>=x)st=mid+1;
            else dr=mid;
        }
        a[st]=x;
        if(st==l)++l;
    }


    out<<l<<'\n';
    nr=rest[0];
    for(int i=0;i<k;++i)
    {
        nr=nr+(rest[i]-1)*rest[i]/2;
    }
    out<<nr%20011;
    return 0;
}
