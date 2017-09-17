#include <iostream>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#define PI 3.14159265
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int procent,t;
float masura,rezultat,sinus,l1,l2,L1,L2;
int cadran(int x,int y)
{
    if(x-50>=0)
    {
        if(y-50<0)return 2;
        return 1;
    }
    else
    {
        if(y-50<0)return 3;
        return 4;
    }
}
int main()
{
    in>>t;
    for(int i=1;i<=t;++i)
    {
        out<<"Case #"<<i<<": ";
        in>>procent>>L1>>L2;
        masura=procent*360.0/100.0;
        l1=abs(L1-50);
        l2=abs(L2-50);
        if(abs((L1-50)*(L1-50))+abs((L2-50)*(L2-50))>2500)out<<"white"<<'\n';
        else
        {

            if(l2!=0)sinus=(float)l1*1.0/l2;
            rezultat=asin(sinus)*180.0/PI;
            out<<rezultat<<'\n';
        }
    }
    return 0;
}
