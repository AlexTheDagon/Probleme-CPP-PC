#include <iostream>
#include <fstream>
#define NM 10005
using namespace std;
ifstream in("perle.in");
ofstream out("perle.out");
int ultperlB(int cur);
int ultperlC(int cur);
int l,n,a[NM];
int main()
{
    in>>n;
    for(int k=1;k<=n;++k)
    {
        in>>l;
        for(int i=1;i<=l;++i)in>>a[i];
        if(l==1 || ultperlB(1)==l || ultperlC(1)==l)out<<"1"<<'\n';
        else out<<"0"<<'\n';
    }
    return 0;
}
int ultperlB(int cur)
{
    if(cur+1<=l && a[cur]==2)return ultperlB(cur+1);
    if(cur+4<=l && a[cur]==1 && a[cur+2]==3)return ultperlC(cur+4);
    return -1;
}
int ultperlC(int cur)
{
    if(cur<=l && a[cur]==2)return cur;
    if(cur+2<=l && a[cur]==3)
    {
        int noucurent=ultperlB(cur+1);
        return ultperlC(noucurent+1);
    }
    if(cur+2<=l && a[cur]==1 && a[cur+1]==2)return cur+2;
    return -1;
}
