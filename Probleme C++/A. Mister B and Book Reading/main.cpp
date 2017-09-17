#include <iostream>

using namespace std;
int c,init,inc,lim,cur,reg,zi,zile;
int main()
{
    cin>>c>>init>>lim>>inc>>reg;
    cur=init;
    while(zi<c)
    {
        zi+=cur;
        ++zile;
        if(zi<c)
        {
            cur+=inc;
            zi-=reg;
            if(cur>lim)cur=lim;
        }
    }
    cout<<zile;
    return 0;
}
