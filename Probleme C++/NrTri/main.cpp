#include <iostream>
#include <algorithm>
#include <fstream>
#define NM 805
using namespace std;
ifstream in("nrtri.in");
ofstream out("nrtri.out");
int a[NM],s,nr,n;
long long hi,low,mid;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)in>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n-1;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            hi=n;
            low=j;
            s=a[i]+a[j];
            while(hi-low>1)
            {
                mid=(hi+low)/2;
                if(a[mid]>s)hi=mid;
                else low=mid;
            }
            if(a[hi]>s)--hi;
            nr+=(hi-j);
        }
    }
    out<<nr;
    return 0;
}
