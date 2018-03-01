#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
#include <vector>
#include <functional>
#define LM 16005
#define NM 4*LM
#define INF 1000000000
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
ifstream in("base3.in");
ofstream out("base3.out");
int dmin[2*NM];
int viz[2*NM],l[4],st,dr,dif,nod,dist,newnod,newdist;
char A[LM];
pii fr;
priority_queue<pii,vector<pii>,greater<pii> > q;
int main()
{
    for(int i=0;i<2*NM;++i)dmin[i]=INF;
    for(int i=1;i<=3;++i)
    {
        in>>A+1;
        l[i]=strlen(A+1);
        for(int j=1;j<=l[i];++j)
        {
            if(A[j]=='1')
            {
                st=j-1;
                dr=l[i]-j;
                dif=dr-st;
                dmin[NM+dif]=min(l[i],dmin[NM+dif]);
                q.push({l[i],NM+dif});
            }
        }
    }
    while(!q.empty())
    {
        fr=q.top();
        q.pop();
        nod=fr.y;
        dist=fr.x;
        if(viz[nod])
            continue;
        viz[nod]=1;
        for(int i=1;i<=3;++i)
        {
            for(int semn=-1;semn<=1;semn+=2)
            {
                newdist=dist+l[i];
                newnod=nod+semn*l[i];
                if(newnod<2*NM && newnod>0 && newdist<dmin[newnod])
                {
                    dmin[newnod]=newdist;
                    q.push({newdist,newnod});
                }
            }
        }
    }
    if(dmin[NM]!=INF)out<<dmin[NM];
    else out<<0;
    return 0;
}
