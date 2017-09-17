#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#define NM 1005
#define x first.first
#define y first.second
#define z second
using namespace std;
ifstream in("mosia.in");
ofstream out("mosia.out");
double d[NM],gx,gy,dp1[NM],dp2[NM],dist[NM];
pair<pair<double,double>,double> crd[NM];
int n;
int cmp(pair<pair<double,double>,double> a,pair<pair<double,double>,double> b)
{
    return atan2(a.y-gy,a.x-gx)<atan2(b.y-gy,b.x-gx);
}
double arie(int i)
{
    return sqrt((crd[i-1].x-crd[i+1].x)*(crd[i-1].x-crd[i+1].x)+(crd[i-1].y-crd[i+1].y)*(crd[i-1].y-crd[i+1].y))*1.0*crd[i].z/2;
}
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>crd[i].x>>crd[i].y>>crd[i].z;
        gx+=crd[i].x;
        gy+=crd[i].y;
    }
    gx=gx*1.0/n;
    gy=gy*1.0/n;
    sort(crd+1,crd+n+1,cmp);
    crd[0]=crd[n];
    crd[n+1]=crd[1];
    for(int i=0;i<=n+1;++i)dist[i]=crd[i].z;
    dp1[1]=arie(1);
    dp2[2]=arie(2);
    for(int i=3;i<n;++i)dp1[i]=max(dp1[i-2],dp1[i-3])+arie(i);
    for(int i=4;i<=n;++i)dp2[i]=max(dp2[i-2],dp2[i-3])+arie(i);
    out<<fixed<<setprecision(8)<<max(max(dp1[n-1],dp1[n-2]),max(dp2[n],dp2[n-1]));
    return 0;
}
