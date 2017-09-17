#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cern.in");
ofstream out("cern.out");
int t,s,poz[3000],start,cerc[3000];
char c;
int st[]={0,60,720,780,360,420};
int main()
{
    in>>c;
    start=st[c-'A'];
    in>>s>>t;
    t=t%1080;
    for(int i=0;i<=180;++i)poz[i]=i;///bine
    for(int i=181;i<=240;++i)poz[i]=540-i;///bine
    for(int i=241;i<480;++i)poz[i]=i-120;///bine
    for(int i=480;i<=540;++i)poz[i]=i-480;///bine
    for(int i=541;i<=600;++i)poz[i]=780-i;///bine
    for(int i=601;i<=900;++i)poz[i]=i-600;///bine
    for(int i=901;i<=960;++i)poz[i]=1020-i;///bine
    for(int i=961;i<1080;++i)poz[i]=i-720;///bine
    for(int i=0;i<1080;++i)poz[i+1080]=poz[i];///bine


    for(int i=0;i<=180;++i)cerc[i]=1;
    for(int i=181;i<=240;++i)cerc[i]=2;
    for(int i=241;i<480;++i)cerc[i]=3;
    for(int i=480;i<=540;++i)cerc[i]=3;
    for(int i=541;i<=600;++i)cerc[i]=1;
    for(int i=601;i<=900;++i)cerc[i]=2;
    for(int i=901;i<=960;++i)cerc[i]=3;
    for(int i=961;i<1080;++i)cerc[i]=1;
    for(int i=0;i<1080;++i)cerc[i+1080]=cerc[i];
    if(s==-1)start+=1080;
    cout<<start+s*t;
    out<<poz[start+s*t]<<" "<<cerc[start+s*t];
    return 0;
}
