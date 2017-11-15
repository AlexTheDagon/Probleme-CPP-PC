#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
ifstream in("date.in");
ofstream out("date.out");
int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={1,-1,1,-1,2,-2,2,-2};
int a[30][30],sem,n,is,js,sol[30][30];
vector<pair<int,int> > v;
int ok(int i,int j)
{
    return(i>0 && i<=n && j>0 && j<=n && !a[i][j] && sem==0);
}
int cal(int i,int j,int ocupat)
{
    a[i][j]=ocupat;
    if(ocupat==n*n)
    {
        sem=1;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)sol[i][j]=a[i][j];
    }
    else
    {
        for(int d=0;d<8;++d)
            if(ok(i+dx[d],j+dy[d]))
                cal(i+dx[d],j+dy[d],ocupat+1);
    }
    a[i][j]=0;
}
int main()
{
    in>>n;
    in>>is>>js;
    cal(is,js,1);
    if(sem==0)out<<"nu se poate";
    else
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)out<<sol[i][j]<<" ";
            out<<'\n';
        }
    }
    return 0;
}
