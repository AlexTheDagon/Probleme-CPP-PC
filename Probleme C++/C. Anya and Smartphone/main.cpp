#include <iostream>
#define pair<int,int> pii
#define x first
#define y second
using namespace std;
int n,m,k,app,a1,a2,p1,pos[100005],a[100005];
long long sol;
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>app;
        pos[app]=i;
        a[i]=app;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>app;
        p1=pos[app];
        sol+=1;
        if(p1>1)
        {
        sol+=(p1-1)/k;
        a2=a[p1-1];
        swap(pos[app],pos[a2]);
        swap(a[p1],a[p1-1]);}
    }
    cout<<sol;
    return 0;
}
