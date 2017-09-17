#include <iostream>
#include <fstream>
using namespace std;
ifstream in("compus.in");
ofstream out("compus.out");
int m,sol,h,l,limi,limc;
int main()
{
    in>>m;
    limc=m/5;
    for(int c=1;c<=limc;++c)
    {
        limi=(m-5*c)/3;
        for(int i=1;i<=limi;++i)
        {
            h=(m-5*c-3*i);
            l=2*c-2*i-h+2;
            if(h>0 && l>=0 && l<=(c-1)*4 && 5*c+3*i+h==m && l%2==0)++sol;
        }
    }
    out<<sol;
    return 0;
}
