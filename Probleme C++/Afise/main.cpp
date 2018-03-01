#include <iostream>
#include <bits/stdc++.h>
using namespace std;
ifstream in("afise.in");
ofstream out("afise.out");
struct point
{
    int x1,x2,y1,y2;
};
int n,sem,l,h;
point a[105];
int el[105],x,y,r;
int main()
{
    in>>l>>h>>n;
    for(int i=1;i<=n;++i)
    {
        in>>x>>y>>r;
        a[i].x1=x-r;
        a[i].y1=y-r;
        a[i].x2=x+r;
        a[i].y2=y+r;
    }
    for(int i=1;i<=n;++i)
    {
        sem=1;
        while(sem==1)
        {
            sem=0;
            for(int j=i-1;j>0;--j)
            {
                if(!el[j] && ((((a[i].x1<=a[j].x2 && a[j].x2<=a[i].x2)||(a[i].x1<=a[j].x1 && a[j].x1<=a[i].x2))&& ((a[i].y1<=a[j].y2 && a[j].y2<=a[i].y2)||(a[i].y1<=a[j].y1 && a[j].y1<=a[i].y2)))||(((a[j].x1<=a[i].x2 && a[i].x2<=a[j].x2)||(a[j].x1<=a[i].x1 && a[i].x1<=a[j].x2))&& ((a[j].y1<=a[i].y2 && a[i].y2<=a[j].y2)||(a[j].y1<=a[i].y1 && a[i].y1<=a[j].y2)))))
                {
                    el[j]=1;
                    a[i].x1=min(a[i].x1,a[j].x1);
                    a[i].y1=min(a[i].y1,a[j].y1);
                    a[i].x2=max(a[i].x2,a[j].x2);
                    a[i].y2=max(a[i].y2,a[j].y2);
                    sem=1;
                }
            }
        }
    }
    int sol=0;
    for(int i=1;i<=n;++i)
        if(!el[i])
            sol+=(a[i].x2-a[i].x1)*(a[i].y2-a[i].y1);
    out<<sol;
    return 0;
}
