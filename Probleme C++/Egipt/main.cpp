#include <iostream>
#include <queue>
#include <fstream>
#include <algorithm>
#define mp make_pair
using namespace std;
ifstream in("egipt.in");
ofstream out("egipt.out");
int a[10005],cor[10005],n,t;
queue<int> q12,q13,q21,q23,q31,q32;
queue <pair<int,int> > q;
int main()
{
    in>>n;
    for(int i=1;i<=n;++i)
    {
        in>>a[i];
        cor[i]=a[i];
    }
    sort(cor+1,cor+n+1);
    for(int i=1;i<=n;++i)
    {
        if(a[i]==1 && cor[i]==2)q12.push(i);
        if(a[i]==2 && cor[i]==1)q21.push(i);
        if(a[i]==1 && cor[i]==3)q13.push(i);
        if(a[i]==3 && cor[i]==1)q31.push(i);
        if(a[i]==2 && cor[i]==3)q23.push(i);
        if(a[i]==3 && cor[i]==2)q32.push(i);
    }
    while(!q12.empty() && !q21.empty())
    {
        q.push(mp(q12.front(),q21.front()));
        q21.pop();
        q12.pop();
    }///bine
    while(!q13.empty() && !q31.empty())
    {
        q.push(mp(q13.front(),q31.front()));
        q31.pop();
        q13.pop();
    }
    while(!q32.empty() && !q23.empty())
    {
        q.push(mp(q23.front(),q32.front()));
        q23.pop();
        q32.pop();
    }
    if(!q21.empty())
    {
        t=q21.size();
        for(int i=1;i<=t;++i)
        {
            q.push(mp(q21.front(),q32.front()));
            q21.push(q32.front());
            q32.push(q21.front());
            q21.pop();
            q32.pop();
        }
        for(int i=1;i<=t;++i)
        {
            q.push(mp(q32.front(),q13.front()));
            q32.push(q13.front());
            q13.push(q32.front());
            q32.pop();
            q13.pop();
        }
    }
    else
    {
        if(!q31.empty())
        {
            t=q31.size();
            for(int i=1;i<=t;++i)
            {
                q.push(mp(q31.front(),q12.front()));
                q12.push(q31.front());
                q31.push(q12.front());
                q12.pop();
                q31.pop();
            }
            for(int i=1;i<=t;++i)
            {
                q.push(mp(q31.front(),q23.front()));
                q31.push(q23.front());
                q23.push(q31.front());
                q31.pop();
                q23.pop();
            }
        }
    }
    out<<q.size()<<'\n';
    while(!q.empty())
    {
        out<<q.front().first<<" "<<q.front().second<<'\n';
        q.pop();
    }
    return 0;
}
