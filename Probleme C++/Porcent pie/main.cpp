#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265
using namespace std;
ifstream in("progress_pie.txt");
ofstream out("date.out");
double x,y,ipotenuza,x1,y2,procent,masura,unghi,s;
int t;
int cadran(int i,int j)
{
    if(i>=0 && j>0)return 0;
    if(i>0 && j<=0)return 1;
    if(i<=0 && j<0)return 2;
    return 3;
}
int main()
{
    in>>t;
    for(int i=1;i<=t;++i)
    {
        out<<"Case #"<<i<<": ";
        in>>procent>>x>>y;
        x1=abs(x-50);
        y2=abs(y-50);
        ipotenuza=(x1*x1+y2*y2);
        ipotenuza=sqrt(ipotenuza);
        if(ipotenuza>50)out<<"white"<<'\n';
        else
        {
            unghi=360.0/100.0*procent;
            masura=cadran(x-50,y-50)*90.0;
            if(y2>25)s=x1*1.0/ipotenuza;
            else s=y2*1.0/ipotenuza;
            masura=masura+asin(s)*180.0/PI;
            if(unghi<masura || procent==0)out<<"white"<<'\n';
            else out<<"black"<<'\n';
        }

    }
    return 0;
}
