#include <iostream>
#include <fstream>
#define NM 15005
using namespace std;
ifstream in("datorii.in");
ofstream out("datorii.out");
int a[NM],n,m,x,y,c;
int query(int poz)
{
    int pos=poz,sum=0;
    while(pos>0)
    {
        sum+=a[pos];
        pos=pos-(pos&-pos);
    }
    return sum;
}
void update(int pos,int val)
{
    for(int i=pos;i<=n;i+=(i&-i))a[i]-=val;
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
        in>>c>>x>>y;
        if(c==0)update(x,y);
        else out<<query(y)-query(x-1)<<'\n';
    }
    return 0;
}
