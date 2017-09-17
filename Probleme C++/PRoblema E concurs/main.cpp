#include <iostream>
#include <algorithm>
#define x first
#define y second
using namespace std;
int n,st,fn,maxx=1;
pair <int,int> p[100005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>p[i].y>>p[i].x;
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;++i)swap(p[i].x,p[i].y);
    st=p[1].x;
    fn=p[1].y;
    maxx=1;
    for(int i=2;i<=n;++i)
    {
        if(p[i].x>fn)
        {
            st=p[i].x;
            fn=p[i].y;
            maxx++;
        }
    }
    cout<<maxx;
    return 0;
}
