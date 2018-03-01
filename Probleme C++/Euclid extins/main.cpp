#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid3.in");
ofstream out("euclid3.out");
int euclid(int a,int b,int &d,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        d=a;
        y=0;
    }
    else
    {
        int x0,y0;
        euclid(b,a%b,d,x0,y0);
        x=y0;
        y=x0-(a/b)*y0;
    }
}
int a,b,d,x,y,n,c;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a>>b>>c;
        euclid(a,b,d,x,y);
        cout<<d<<endl;
        if(c%d)out<<"0 0"<<'\n';
        else out<<(long long)x*c/d<<" "<<(long long)y*c/d<<'\n';
    }
    return 0;
}
