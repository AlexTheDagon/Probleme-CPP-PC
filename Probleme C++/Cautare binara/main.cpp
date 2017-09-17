#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("cautbin.in");
ofstream out("cautbin.out");
int n,m,a[100005],c,x;
long long st,dr,mid;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    sort(a+1,a+n+1);
    in>>m;
    for(int i=1;i<=m;++i)
    {
        in>>c>>x;
        dr=n+1;
        st=0;
        if(c!=2)
        {
            while(dr-st>1)
            {
                mid=(st+dr)/2;
                if(a[mid]>x)dr=mid;
                else st=mid;
            }
            if(c==0)
            {
                if(a[dr-1]!=x)out<<"-1"<<'\n';
                else out<<dr-1<<'\n';
            }
            if(c==1)out<<dr-1<<'\n';
        }
        if(c==2)
        {
            while(dr-st>1)
            {
                mid=(st+dr)/2;
                if(a[mid]<x)st=mid;
                else dr=mid;
            }
            out<<dr<<'\n';
        }
    }
    return 0;
}
